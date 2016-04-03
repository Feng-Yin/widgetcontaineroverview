#include "curvesplotwidget.h"
#include "curvesplot.h"
#include <qwt_plot_canvas.h>
#include <QVBoxLayout>

CurvesPlotWidget::CurvesPlotWidget(QWidget *parent) : QWidget(parent)
{

    CurvesPlot *plot = new CurvesPlot();
    QwtPlotCanvas *canvas = new QwtPlotCanvas();
    canvas->setFrameStyle( QFrame::NoFrame );
    canvas->setPaintAttribute( QwtPlotCanvas::BackingStore, false );

    plot->setCanvas( canvas );
    plot->setCanvasBackground( QColor( 30, 30, 50 ) );

    QVBoxLayout *vl = new QVBoxLayout();
    vl->addWidget(plot);
    setLayout(vl);
}
