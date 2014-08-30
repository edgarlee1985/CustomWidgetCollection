#pragma once

#include <QDoubleSpinBox>

class QDoubleSpinBoxEx : public QDoubleSpinBox
{
    Q_OBJECT

public:
    QDoubleSpinBoxEx( QWidget* parent = 0 );
    ~QDoubleSpinBoxEx();

Q_SIGNALS:
    void RecordEditingValue();

public:
    virtual void stepBy( int nSteps );
protected:
    virtual void mousePressEvent( QMouseEvent* pEevent );
    virtual void mouseMoveEvent( QMouseEvent* pEevent );
    virtual void mouseReleaseEvent( QMouseEvent* pEevent );
    virtual void wheelEvent( QWheelEvent* pEevent );

    virtual void keyPressEvent( QKeyEvent* pEevent );
    virtual void keyReleaseEvent( QKeyEvent* pEevent );

    virtual void focusInEvent( QFocusEvent* pEevent );
    virtual void focusOutEvent( QFocusEvent* pEevent );

    virtual void showEvent( QShowEvent* pEevent );
    virtual void hideEvent( QHideEvent* pEevent );

private:
    void EmitRecordEditingValue();
private:
    int m_nLastRecordValue;
    bool m_bStepBy;
};