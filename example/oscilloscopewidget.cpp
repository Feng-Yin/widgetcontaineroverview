#include "oscilloscopewidget.h"
#include "oscilloscopeplot.h"
#include "oscilloscopeknob.h"
#include "oscilloscopewheelbox.h"
#include <qwt_scale_engine.h>
#include <qlabel.h>
#include <qlayout.h>

OscilloscopeWidget::OscilloscopeWidget( QWidget *parent ):
    QWidget( parent )
{
    const double intervalLength = 10.0; // seconds

    d_plot = new OscilloscopePlot( this );
    d_plot->setIntervalLength( intervalLength );

    d_amplitudeKnob = new OscilloscopeKnob( "Amplitude", 0.0, 200.0, this );
    d_amplitudeKnob->setValue( 160.0 );

    d_frequencyKnob = new OscilloscopeKnob( "Frequency [Hz]", 0.1, 20.0, this );
    d_frequencyKnob->setValue( 17.8 );

    d_intervalWheel = new OscilloscopeWheelBox( "Displayed [s]", 1.0, 100.0, 1.0, this );
    d_intervalWheel->setValue( intervalLength );

    d_timerWheel = new OscilloscopeWheelBox( "Sample Interval [ms]", 0.0, 20.0, 0.1, this );
    d_timerWheel->setValue( 10.0 );

    QVBoxLayout* vLayout1 = new QVBoxLayout();
    vLayout1->addWidget( d_intervalWheel );
    vLayout1->addWidget( d_timerWheel );
    vLayout1->addStretch( 10 );
    vLayout1->addWidget( d_amplitudeKnob );
    vLayout1->addWidget( d_frequencyKnob );

    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->addWidget( d_plot, 10 );
    layout->addLayout( vLayout1 );

    connect( d_amplitudeKnob, SIGNAL( valueChanged( double ) ),
        SIGNAL( amplitudeChanged( double ) ) );
    connect( d_frequencyKnob, SIGNAL( valueChanged( double ) ),
        SIGNAL( frequencyChanged( double ) ) );
    connect( d_timerWheel, SIGNAL( valueChanged( double ) ),
        SIGNAL( signalIntervalChanged( double ) ) );

    connect( d_intervalWheel, SIGNAL( valueChanged( double ) ),
        d_plot, SLOT( setIntervalLength( double ) ) );
}

void OscilloscopeWidget::start()
{
    d_plot->start();
}

double OscilloscopeWidget::frequency() const
{
    return d_frequencyKnob->value();
}

double OscilloscopeWidget::amplitude() const
{
    return d_amplitudeKnob->value();
}

double OscilloscopeWidget::signalInterval() const
{
    return d_timerWheel->value();
}
