#include "mainwindow.h"
#include "widgetcontaineroverview.h"
#include "samplingthread.h"
#include "curvesplotwidget.h"
#include "cpuplot.h"
#include "oscilloscopewidget.h"
#include "cockpit_grid.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    CurvesPlotWidget *curvesPlotWidget = new CurvesPlotWidget();
    CpuPlot *cpuPlot = new CpuPlot();
    OscilloscopeWidget *oscilloscopeWidget = new OscilloscopeWidget();
    SamplingThread *samplingThread = new SamplingThread();
    samplingThread->setFrequency(oscilloscopeWidget->frequency());
    samplingThread->setAmplitude(oscilloscopeWidget->amplitude());
    samplingThread->setInterval(oscilloscopeWidget->signalInterval());
    connect(oscilloscopeWidget, SIGNAL(frequencyChanged(double)),
        samplingThread, SLOT(setFrequency(double)));
    connect(oscilloscopeWidget, SIGNAL(amplitudeChanged(double)),
        samplingThread, SLOT(setAmplitude(double)));
    connect(oscilloscopeWidget, SIGNAL(signalIntervalChanged(double)),
        samplingThread, SLOT(setInterval(double)));
    samplingThread->start();
    oscilloscopeWidget->start();
    QWidget *cockpitGrid = new CockpitGrid();

    WidgetContainerOverview *wc = new WidgetContainerOverview();
    wc->addWidget(curvesPlotWidget);
    wc->addWidget(cpuPlot);
    wc->addWidget(oscilloscopeWidget);
    wc->addWidget(cockpitGrid);
    wc->addWidget(new CpuPlot());
    //wc->addWidget(new CurvesPlotWidget());


    this->setCentralWidget(wc);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{

}
