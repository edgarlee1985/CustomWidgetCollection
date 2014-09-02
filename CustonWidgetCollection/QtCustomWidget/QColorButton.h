#ifndef QCOLORBUTTON_H
#define QCOLORBUTTON_H

#include <QtWidgets/QPushButton>
#include <QColorDialog>

class QColorButton : public QPushButton
{
    Q_OBJECT

    Q_PROPERTY( QColor Color READ GetColor WRITE SetColor )
    Q_PROPERTY( QSize iconSize READ iconSize WRITE setIconSize )
public:
    QColorButton(QWidget *parent = 0);
    ~QColorButton();

public:
    void setIconSize( const QSize& kSize );

    void SetColor( const QColor kColor );
    QColor GetColor() const;

    void Click();

protected:
    virtual void mouseReleaseEvent( QMouseEvent* pEevent ) override;

private:
    QColorDialog m_kColorDialog;
    QColor m_kColor;
};

#endif // QCOLORBUTTON_H
