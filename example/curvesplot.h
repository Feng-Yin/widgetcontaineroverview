#include <qwt_plot.h>
#include <qdatetime.h>

class Curve;

class CurvesPlot: public QwtPlot
{
public:
    CurvesPlot( QWidget * = NULL);

protected:
    virtual void timerEvent( QTimerEvent * );

private:
    void updateCurves();

    enum { CurveCount = 4 };
    Curve *d_curves[CurveCount];

    QTime d_time;
};
