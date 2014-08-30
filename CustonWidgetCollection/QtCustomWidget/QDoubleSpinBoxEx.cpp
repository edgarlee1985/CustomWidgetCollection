#include "QDoubleSpinBoxEx.h"
#include <QDebug>
#include <QKeyEvent>

QDoubleSpinBoxEx::QDoubleSpinBoxEx( QWidget* parent )
: QDoubleSpinBox( parent )
, m_bStepBy( false )
{
}

QDoubleSpinBoxEx::~QDoubleSpinBoxEx()
{

}

void QDoubleSpinBoxEx::stepBy( int nSteps )
{
    m_bStepBy = true;
    QDoubleSpinBox::stepBy( nSteps );
}

void QDoubleSpinBoxEx::mousePressEvent( QMouseEvent* pEevent )
{
    QDoubleSpinBox::mousePressEvent( pEevent );
}

void QDoubleSpinBoxEx::mouseMoveEvent( QMouseEvent* pEevent )
{
    QDoubleSpinBox::mouseMoveEvent( pEevent );
}

void QDoubleSpinBoxEx::mouseReleaseEvent( QMouseEvent* pEevent )
{
    if ( m_bStepBy )
    {
        m_bStepBy = false;
        EmitRecordEditingValue();
    }
    QDoubleSpinBox::mouseReleaseEvent( pEevent );
}

void QDoubleSpinBoxEx::wheelEvent( QWheelEvent* pEevent )
{
    if ( !hasFocus() )
    {
        pEevent->ignore();
        return;
    }

    QDoubleSpinBox::wheelEvent( pEevent );
}

void QDoubleSpinBoxEx::keyPressEvent( QKeyEvent* pEevent )
{
    if ( pEevent->key() == Qt::Key_Enter || pEevent->key() == Qt::Key_Return )
    {
        int nNew = valueFromText( text() );
        if ( nNew != value() )
        {
            setValue( nNew );
        }
        pEevent->ignore();
        return;
    }
    QDoubleSpinBox::keyPressEvent( pEevent );
}

void QDoubleSpinBoxEx::keyReleaseEvent( QKeyEvent* pEevent )
{
    if ( pEevent->key() == Qt::Key_Enter || pEevent->key() == Qt::Key_Return )
    {
        if ( m_nLastRecordValue != value() )
        {
            EmitRecordEditingValue();
        }
    }
    QDoubleSpinBox::keyReleaseEvent( pEevent );
}

void QDoubleSpinBoxEx::focusInEvent( QFocusEvent* pEevent )
{
    setFocusPolicy(Qt::WheelFocus);
    m_nLastRecordValue = value();
    QDoubleSpinBox::focusInEvent( pEevent );
}

void QDoubleSpinBoxEx::focusOutEvent( QFocusEvent* pEevent )
{
    setFocusPolicy(Qt::StrongFocus);
    if ( m_nLastRecordValue != value() )
    {
        EmitRecordEditingValue();
    }
    QDoubleSpinBox::focusOutEvent( pEevent );
}

void QDoubleSpinBoxEx::EmitRecordEditingValue()
{
    m_nLastRecordValue = value();
    Q_EMIT RecordEditingValue();
}

void QDoubleSpinBoxEx::showEvent( QShowEvent* pEevent )
{
    QDoubleSpinBox::showEvent( pEevent );
}

void QDoubleSpinBoxEx::hideEvent( QHideEvent* pEevent )
{
    QDoubleSpinBox::hideEvent( pEevent );
}