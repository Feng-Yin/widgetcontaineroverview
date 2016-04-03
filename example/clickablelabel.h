#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

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
	~ClickableLabel()  {}
signals:
    void clicked();
protected:
    void mouseDoubleClickEvent(QMouseEvent* )
	{
		emit clicked();
	}
};

#endif // CLICKABLELABEL_H
