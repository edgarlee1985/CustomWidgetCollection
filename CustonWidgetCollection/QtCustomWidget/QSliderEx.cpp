#include "QSliderEx.h"
#include <QDebug>
#include <QKeyEvent>

QSliderEx::QSliderEx( QWidget* parent )
: QSlider( parent )
, m_bPress( false )
, m_bIsSliderDown( false )
{
}

QSliderEx::~QSliderEx()
{

}
void QSliderEx::mousePressEvent( QMouseEvent* pEevent )
{
    m_bPress = true;
    QSlider::mousePressEvent( pEevent );
}

void QSliderEx::mouseMoveEvent( QMouseEvent* pEevent )
{
    if ( m_bPress )
    {
        m_bIsSliderDown = isSliderDown();
    }
    QSlider::mouseMoveEvent( pEevent );
}

void QSliderEx::mouseReleaseEvent( QMouseEvent* pEevent )
{
    m_bPress = false;
    SliderAction eAction = repeatAction();
    if ( ( m_bIsSliderDown || eAction == SliderPageStepAdd || eAction == SliderPageStepSub )
        && m_nLastRecordValue != value() )
    {
        EmitRecordEditingValue();
    }
    QSlider::mouseReleaseEvent( pEevent );
}

void QSliderEx::wheelEvent( QWheelEvent* pEevent )
{
    if ( !hasFocus() )
    {
        pEevent->ignore();
        return;
    }

    QSlider::wheelEvent( pEevent );
}

void QSliderEx::keyPressEvent( QKeyEvent* pEevent )
{
    QSlider::keyPressEvent( pEevent );
}

void QSliderEx::keyReleaseEvent( QKeyEvent* pEevent )
{
    QSlider::keyReleaseEvent( pEevent );
}

void QSliderEx::focusInEvent( QFocusEvent* pEevent )
{
    setFocusPolicy(Qt::WheelFocus);
    m_nLastRecordValue = value();
    QSlider::focusInEvent( pEevent );
}

void QSliderEx::focusOutEvent( QFocusEvent* pEevent )
{
    setFocusPolicy(Qt::StrongFocus);
    if ( m_nLastRecordValue != value() )
    {
        EmitRecordEditingValue();
    }
    QSlider::focusOutEvent( pEevent );
}

void QSliderEx::EmitRecordEditingValue()
{
    m_nLastRecordValue = value();
    Q_EMIT RecordEditingValue();
}

void QSliderEx::showEvent( QShowEvent* pEevent )
{
    QSlider::showEvent( pEevent );
}

void QSliderEx::hideEvent( QHideEvent* pEevent )
{
    QSlider::hideEvent( pEevent );
}
