#include <qwidget.h>

class OscilloscopePlot;
class OscilloscopeKnob;
class OscilloscopeWheelBox;

class OscilloscopeWidget : public QWidget
{
    Q_OBJECT

public:
    OscilloscopeWidget( QWidget * = NULL );

    void start();

    double amplitude() const;
    double frequency() const;
    double signalInterval() const;

Q_SIGNALS:
    void amplitudeChanged( double );
    void frequencyChanged( double );
    void signalIntervalChanged( double );

private:
    OscilloscopeKnob *d_frequencyKnob;
    OscilloscopeKnob *d_amplitudeKnob;
    OscilloscopeWheelBox *d_timerWheel;
    OscilloscopeWheelBox *d_intervalWheel;

    OscilloscopePlot *d_plot;
};
