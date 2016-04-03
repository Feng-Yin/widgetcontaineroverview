#include "clickablelabel.h"

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent)
    : QLabel(parent)
{
    setText(text);
    setFrameStyle(QFrame::StyledPanel);
    setScaledContents(true);
}

ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mouseDoubleClickEvent(QMouseEvent* event)
{
    emit clicked();
}
