#ifndef WIDGETCONTAINER_H
#define WIDGETCONTAINER_H

#include <QtWidgets>
#include <QLabel>

class ClickableLabel : public QLabel
{
	Q_OBJECT
public:
	explicit ClickableLabel(const QString& text = "", QWidget* parent = 0)
		: QLabel(parent)
	{
		setText(text);
		setFrameStyle(QFrame::StyledPanel);
		setScaledContents(true);
	}
	~ClickableLabel() {}
signals:
	void clicked();
protected:
        void mouseDoubleClickEvent(QMouseEvent* )
	{
		emit clicked();
	}
};

class WidgetContainerOverview : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetContainerOverview(int refreshrate=500, QWidget *parent = 0);

signals:

public slots:
    void updateOverView();
	void addWidget(QWidget *widget);

protected:
    void mouseDoubleClickEvent(QMouseEvent* event);

private slots:
	void labelClicked();

private:
	void updateStackedWidget(int);

private:
    QGridLayout *gl;
	QList <ClickableLabel*> labelList;

    QTimer *overviewUpdateTimer;
    QStackedWidget *stackedWidget;
    QPixmap *pixmap;
    QSize initialWidgetSize;
	const static char *idProperty;
	int refreshRate;
};

#endif // WIDGETCONTAINER_H
