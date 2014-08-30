#include "QDialEx.h"
#include <QDebug>
#include <QKeyEvent>

QDialEx::QDialEx( QWidget* parent )
: QDial( parent )
, m_bPress( false )
, m_bIsSliderDown( false )
{
}

QDialEx::~QDialEx()
{

}
void QDialEx::mousePressEvent( QMouseEvent* pEevent )
{
    m_bPress = true;
    QDial::mousePressEvent( pEevent );
}

void QDialEx::mouseMoveEvent( QMouseEvent* pEevent )
{
    if ( m_bPress )
    {
        m_bIsSliderDown = isSliderDown();
    }
    QDial::mouseMoveEvent( pEevent );
}

void QDialEx::mouseReleaseEvent( QMouseEvent* pEevent )
{
    m_bPress = false;
    SliderAction eAction = repeatAction();
    if ( ( m_bIsSliderDown || eAction == SliderPageStepAdd || eAction == SliderPageStepSub )
        && m_nLastRecordValue != value() )
    {
        EmitRecordEditingValue();
    }
    QDial::mouseReleaseEvent( pEevent );
}

void QDialEx::wheelEvent( QWheelEvent* pEevent )
{
    if ( !hasFocus() )
    {
        pEevent->ignore();
        return;
    }

    QDial::wheelEvent( pEevent );
}

void QDialEx::keyPressEvent( QKeyEvent* pEevent )
{
    QDial::keyPressEvent( pEevent );
}

void QDialEx::keyReleaseEvent( QKeyEvent* pEevent )
{
    QDial::keyReleaseEvent( pEevent );
}

void QDialEx::focusInEvent( QFocusEvent* pEevent )
{
    setFocusPolicy(Qt::WheelFocus);
    m_nLastRecordValue = value();
    QDial::focusInEvent( pEevent );
}

void QDialEx::focusOutEvent( QFocusEvent* pEevent )
{
    setFocusPolicy(Qt::StrongFocus);
    if ( m_nLastRecordValue != value() )
    {
        EmitRecordEditingValue();
    }
    QDial::focusOutEvent( pEevent );
}

void QDialEx::EmitRecordEditingValue()
{
    m_nLastRecordValue = value();
    Q_EMIT RecordEditingValue();
}

void QDialEx::showEvent( QShowEvent* pEevent )
{
    QDial::showEvent( pEevent );
}

void QDialEx::hideEvent( QHideEvent* pEevent )
{
    QDial::hideEvent( pEevent );
}