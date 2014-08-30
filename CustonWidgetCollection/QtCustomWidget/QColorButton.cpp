#include "QColorButton.h"

QColorButton::QColorButton(QWidget *parent)
: QPushButton(parent)
{
    setIconSize( QSize( 32, 16 ) );
    QPixmap kPixmap( iconSize() );
    kPixmap.fill( Qt::black );
    setIcon( kPixmap );

    connect( this, &QPushButton::clicked, this, &QColorButton::Click );
}

QColorButton::~QColorButton()
{

}

void QColorButton::setIconSize( const QSize& kSize )
{
    QPushButton::setIconSize( kSize );

    QPixmap kPixmap( kSize );
    kPixmap.fill( m_kColor );
    setIcon( kPixmap );
}

void QColorButton::SetColor( const QColor kColor )
{
    m_kColor = kColor;
    QPixmap kPixmap( iconSize() );
    kPixmap.fill( m_kColor );
    setIcon( kPixmap );
}

QColor QColorButton::GetColor() const
{
    return m_kColor;
}

void QColorButton::Click()
{
    m_kColorDialog.setCurrentColor( m_kColor );
    if ( QDialog::Accepted != m_kColorDialog.exec() )
    {
        return;
    }

    m_kColor = m_kColorDialog.selectedColor();
    QPixmap kPixmap( iconSize() );
    kPixmap.fill( m_kColor );
    setIcon( kPixmap );
}
