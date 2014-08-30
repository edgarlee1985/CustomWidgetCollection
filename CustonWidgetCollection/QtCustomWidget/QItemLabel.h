#ifndef QITEMLABEL_H
#define QITEMLABEL_H

#include <QtWidgets/QLabel>

class QItemLabel : public QLabel
{
    Q_OBJECT

    Q_PROPERTY( double FrameLineWidth READ GetLineWidth WRITE SetLineWidth )

    Q_PROPERTY( QColor SelectedOuterColor READ GetSelectOuterLineColor WRITE SetSelectOuterLineColor )
    Q_PROPERTY( QColor SelectedMiddleColor READ GetSelectMiddleLineColor WRITE SetSelectMiddleLineColor )
    Q_PROPERTY( QColor SelectedInnerColor READ GetSelectInnerLineColor WRITE SetSelectInnerLineColor )
    Q_PROPERTY( QColor HoverOuterColor READ GetHoverOuterLineColor WRITE SetHoverOuterLineColor )
    Q_PROPERTY( QColor HoverMiddleColor READ GetHoverMiddleLineColor WRITE SetHoverMiddleLineColor )
    Q_PROPERTY( QColor HoverInnerColor READ GetHoverInnerLineColor WRITE SetHoverInnerLineColor )
public:
    QItemLabel(QWidget *parent = 0);
    ~QItemLabel();
    
    void SetLineWidth( double dLineWidth ) { m_dLineWidth = dLineWidth; }
    double GetLineWidth() { return m_dLineWidth; }

    void SetSelectOuterLineColor( QColor kColor ) { m_kSelectOuterLineColor = kColor; }
    QColor GetSelectOuterLineColor() { return m_kSelectOuterLineColor; }

    void SetSelectMiddleLineColor( QColor kColor ) { m_kSelectMidldeLineColor = kColor; }
    QColor GetSelectMiddleLineColor() { return m_kSelectMidldeLineColor; }

    void SetSelectInnerLineColor( QColor kColor ) { m_kSelectInnerLineColor = kColor; }
    QColor GetSelectInnerLineColor() { return m_kSelectInnerLineColor; }

    void SetHoverOuterLineColor( QColor kColor ) { m_kHoverOuterLineColor = kColor; }
    QColor GetHoverOuterLineColor() { return m_kHoverOuterLineColor; }

    void SetHoverMiddleLineColor( QColor kColor ) { m_kHoverMidldeLineColor = kColor; }
    QColor GetHoverMiddleLineColor() { return m_kHoverMidldeLineColor; }

    void SetHoverInnerLineColor( QColor kColor ) { m_kHoverInnerLineColor = kColor; }
    QColor GetHoverInnerLineColor() { return m_kHoverInnerLineColor; }

signals:
    void clicked();

protected:
    
    void DrawItemFrame( QColor kOuterLineColor, QColor kMiddleLineColor, QColor kInnerLineColor );

    virtual void paintEvent( QPaintEvent* pPaintEvent );
    virtual void mousePressEvent( QMouseEvent* pMouseEvent );
    virtual void mouseDoubleClickEvent( QMouseEvent* pMouseEvent );

    virtual void enterEvent( QEvent* pEvent );
    virtual void leaveEvent( QEvent* pEvent );
    virtual void dragEnterEvent( QDragEnterEvent* pDragEnterEvent );
    virtual void dropEvent( QDropEvent* pDropEvent );

private:
    bool m_bSelected;
    bool m_bHovered;

    double m_dLineWidth;

    QColor m_kSelectOuterLineColor;
    QColor m_kSelectMidldeLineColor;
    QColor m_kSelectInnerLineColor;

    QColor m_kHoverOuterLineColor;
    QColor m_kHoverMidldeLineColor;
    QColor m_kHoverInnerLineColor;
};

#endif // QITEMLABEL_H
