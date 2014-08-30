#include "QSpinboxEx.h"
#include <QDebug>
#include <QKeyEvent>

QSpinBoxEx::QSpinBoxEx( QWidget* parent )
: QSpinBox( parent )
, m_bStepBy( false )
{
}

QSpinBoxEx::~QSpinBoxEx()
{

}

void QSpinBoxEx::stepBy( int nSteps )
{
    m_bStepBy = true;
    QSpinBox::stepBy( nSteps );
}

void QSpinBoxEx::mousePressEvent( QMouseEvent* pEevent )
{
    QSpinBox::mousePressEvent( pEevent );
}

void QSpinBoxEx::mouseMoveEvent( QMouseEvent* pEevent )
{
    QSpinBox::mouseMoveEvent( pEevent );
}

void QSpinBoxEx::mouseReleaseEvent( QMouseEvent* pEevent )
{
    if ( m_bStepBy )
    {
        m_bStepBy = false;
        EmitRecordEditingValue();
    }
    QSpinBox::mouseReleaseEvent( pEevent );
}

void QSpinBoxEx::wheelEvent( QWheelEvent* pEevent )
{
    if ( !hasFocus() )
    {
        pEevent->ignore();
        return;
    }

    QSpinBox::wheelEvent( pEevent );
}

void QSpinBoxEx::keyPressEvent( QKeyEvent* pEevent )
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
    QSpinBox::keyPressEvent( pEevent );
}

void QSpinBoxEx::keyReleaseEvent( QKeyEvent* pEevent )
{
    if ( pEevent->key() == Qt::Key_Enter || pEevent->key() == Qt::Key_Return )
    {
        if ( m_nLastRecordValue != value() )
        {
            EmitRecordEditingValue();
        }
    }
    QSpinBox::keyReleaseEvent( pEevent );
}

void QSpinBoxEx::focusInEvent( QFocusEvent* pEevent )
{
    setFocusPolicy(Qt::WheelFocus);
    m_nLastRecordValue = value();
    QSpinBox::focusInEvent( pEevent );
}

void QSpinBoxEx::focusOutEvent( QFocusEvent* pEevent )
{
    setFocusPolicy(Qt::StrongFocus);
    if ( m_nLastRecordValue != value() )
    {
        EmitRecordEditingValue();
    }
    QSpinBox::focusOutEvent( pEevent );
}

void QSpinBoxEx::EmitRecordEditingValue()
{
    m_nLastRecordValue = value();
    Q_EMIT RecordEditingValue();
}

void QSpinBoxEx::showEvent( QShowEvent* pEevent )
{
    QSpinBox::showEvent( pEevent );
}

void QSpinBoxEx::hideEvent( QHideEvent* pEevent )
{
    QSpinBox::hideEvent( pEevent );
}