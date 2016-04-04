#include "widgetcontaineroverview.h"
#include <qgridlayout.h>

const char* WidgetContainerOverview::idProperty = "ID";

WidgetContainerOverview::WidgetContainerOverview(int refreshrate, QWidget *parent) :
    QWidget(parent),
    gl(NULL),
    overviewUpdateTimer(NULL),
    stackedWidget(NULL),
    pixmap(NULL),
    refreshRate(refreshrate)
{
    gl = new QGridLayout();

    QWidget *overview = new QWidget();
    overview->setLayout(gl);

    overviewUpdateTimer = new QTimer(this);
    connect(overviewUpdateTimer, SIGNAL(timeout()), this, SLOT(updateOverView()));
    overviewUpdateTimer->start(refreshRate);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(overview);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stackedWidget);
    setLayout(layout);
}

void WidgetContainerOverview::addWidget(QWidget *widget)
{
    stackedWidget->addWidget(widget);

    ClickableLabel *label = new ClickableLabel("", this);
    connect(label, SIGNAL(clicked()), this, SLOT(labelClicked()));
    gl->addWidget(label, labelList.count() % 2, labelList.count() / 2);
    labelList.append(label);
    // ID is the total number(sequence number)
    label->setProperty(idProperty, labelList.count());
}

void WidgetContainerOverview::updateOverView()
{
    if (!pixmap)
    {
        initialWidgetSize = labelList[0]->size();
        // start after overview widget
        for (int i = 1; i < stackedWidget->count(); i++)
        {
            stackedWidget->widget(i)->resize(initialWidgetSize);
        }
        pixmap = new QPixmap(initialWidgetSize);
    }

    // start after overview widget
    for (int i = 1; i < stackedWidget->count(); i++)
    {
        stackedWidget->widget(i)->render(pixmap);
        pixmap->scaled(initialWidgetSize,
            Qt::KeepAspectRatioByExpanding,
            Qt::SmoothTransformation);
        labelList[i - 1]->setPixmap(*pixmap);
    }
}

void WidgetContainerOverview::labelClicked()
{
    QObject *sender = QObject::sender();
    ClickableLabel *label = qobject_cast<ClickableLabel *>(sender);
    if (label)
    {
        int stackedWidgetIndex = label->property(idProperty).toInt();
        // overview widget is not count
        if (stackedWidget->count() - 1 < stackedWidgetIndex)
            return;
        overviewUpdateTimer->stop();
        updateStackedWidget(stackedWidgetIndex);
    }
}

void WidgetContainerOverview::updateStackedWidget(int index)
{
    stackedWidget->setCurrentIndex(index);
    stackedWidget->update();
}

void WidgetContainerOverview::mouseDoubleClickEvent(QMouseEvent* )
{
    if (stackedWidget->currentIndex() > 0)
    {
        stackedWidget->currentWidget()->resize(initialWidgetSize);
        stackedWidget->setCurrentIndex(0);
        overviewUpdateTimer->start();
    }
}
