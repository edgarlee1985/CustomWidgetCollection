#pragma once

#include <QSlider>

class QSliderEx : public QSlider
{
    Q_OBJECT

public:
    QSliderEx( QWidget* parent = 0 );
    ~QSliderEx();

Q_SIGNALS:
    void RecordEditingValue();

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
    bool m_bPress;
    int m_nLastRecordValue;

    bool m_bIsSliderDown;
};