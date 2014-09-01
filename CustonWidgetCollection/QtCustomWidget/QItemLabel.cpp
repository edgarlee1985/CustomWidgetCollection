#include "QItemLabel.h"
#include <QMouseEvent>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QPainter>
#include <QPixmap>
#include <QMimeData>
#include <QFileDialog>

QItemLabel::QItemLabel(QWidget *parent)
: QLabel( parent )
, m_bSelected( false )
, m_bHovered( false )
, m_dLineWidth( 0.0 )
, m_kSelectOuterLineColor( 18, 18, 18 )
, m_kSelectMidldeLineColor( 80, 80, 80 )
, m_kSelectInnerLineColor( 230, 230, 230 )
, m_kHoverOuterLineColor( 85, 85, 255 )
, m_kHoverMidldeLineColor( 170, 170, 255 )
, m_kHoverInnerLineColor( 85, 255, 127 )
{
}

QItemLabel::~QItemLabel()
{

}

void QItemLabel::paintEvent( QPaintEvent* pPaintEvent )
{
    QLabel::paintEvent( pPaintEvent );
    if ( pixmap() && !pixmap()->isNull() && m_bSelected )
    {
        DrawItemFrame( m_kSelectOuterLineColor, m_kSelectMidldeLineColor, m_kSelectInnerLineColor );
    }

    if ( pixmap() && !pixmap()->isNull() && m_bHovered )
    {
        DrawItemFrame( m_kHoverOuterLineColor, m_kHoverMidldeLineColor, m_kHoverInnerLineColor );
    }
}

void QItemLabel::DrawItemFrame( QColor kOuterLineColor, QColor kMiddleLineColor, QColor kInnerLineColor )
{
    QRect kOuterRect( 0, 0, this->width() - 1, this->height() - 1 );
    QRect kMiddleRect( m_dLineWidth, m_dLineWidth, this->width() - 2 * m_dLineWidth - 1, this->height() - 2 * m_dLineWidth - 1 );
    double dSpace = 2.0;
    QRect kInnerRect( m_dLineWidth + dSpace,
                      m_dLineWidth + dSpace,
                      this->width() - 2 * ( m_dLineWidth + dSpace ) - 1,
                      this->height() - 2 * ( m_dLineWidth + dSpace ) - 1 );

    QPainter kPainter;
    kPainter.begin( this );
    QPen kQOuterPen( kOuterLineColor, m_dLineWidth );
    kPainter.setPen( kQOuterPen );
    kPainter.drawRect( kOuterRect );
    kPainter.setPen( kMiddleLineColor );
    kPainter.drawRect( kMiddleRect );
    kPainter.setPen( kInnerLineColor );
    kPainter.drawRect( kInnerRect );
    kPainter.end();
}

void QItemLabel::mousePressEvent( QMouseEvent* pMouseEvent )
{
    QLabel::mousePressEvent( pMouseEvent );

    m_bSelected = true;
    repaint();
    Q_EMIT clicked();
}

void QItemLabel::mouseDoubleClickEvent( QMouseEvent* pMouseEvent )
{
    QLabel::mouseDoubleClickEvent( pMouseEvent );

    if ( pMouseEvent->button() == Qt::LeftButton )
    {
        QString strPath = QFileDialog::getOpenFileName( this, tr( "Open Image" ),"", tr( "Image Files (*.png *.jpg *.bmp)" ) );
        if ( !strPath.isEmpty() )
        {
            QPixmap kPixmap;
            kPixmap.load( strPath );
            this->setPixmap( kPixmap );
            Q_EMIT ImageLoaded();
        }
    }
}

void QItemLabel::enterEvent( QEvent* pEvent )
{
    QLabel::enterEvent( pEvent );
    m_bHovered = true;
    repaint();
}

void QItemLabel::leaveEvent( QEvent* pEvent )
{
    QLabel::leaveEvent( pEvent );

    m_bHovered = false;
    repaint();
}

void QItemLabel::dragEnterEvent( QDragEnterEvent* pDragEnterEvent )
{
    QLabel::dragEnterEvent( pDragEnterEvent );

    const QMimeData* pMimeData = pDragEnterEvent->mimeData();
    if( pMimeData->hasUrls())
    {
        pDragEnterEvent->acceptProposedAction();
    }
}

void QItemLabel::dropEvent( QDropEvent* pDropEvent )
{
    QLabel::dropEvent( pDropEvent );

    const QMimeData* pMimeData = pDropEvent->mimeData();
    if ( pMimeData->hasUrls() )
    {
        QList<QUrl> urlList = pMimeData->urls();
        QString strPath = urlList.at( 0 ).toLocalFile();
        QPixmap kPixmap;
        if ( kPixmap.load( strPath ) )
        {
            this->setPixmap( kPixmap );
            Q_EMIT ImageLoaded();
        }
    }
}