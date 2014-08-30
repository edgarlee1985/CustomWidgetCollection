#ifndef QCOMBOSPINBOX_H
#define QCOMBOSPINBOX_H

#include <QtWidgets/QWidget>

#include "ui_ComboSpinBox.h"
class QComboSpinBox : public QWidget
{
    Q_OBJECT

    Q_PROPERTY( int spacing READ Spacing WRITE SetSpacing )
    Q_PROPERTY( int value READ Value WRITE SetValue )
    Q_PROPERTY( int minimum READ Minimum WRITE SetMinimum )
    Q_PROPERTY( int maximum READ Maximum WRITE SetMaximum )
    Q_PROPERTY( int singleStep READ SingleStep WRITE SetSingleStep )
    Q_PROPERTY( int pageStep READ PageStep WRITE SetPageStep )

    // Spinox
    Q_PROPERTY( bool wrapping READ wrapping WRITE setWrapping )
    Q_PROPERTY( bool frame READ hasFrame WRITE setFrame )
    Q_PROPERTY( Qt::Alignment alignment READ alignment WRITE setAlignment )
    Q_PROPERTY (bool readOnly READ isReadOnly WRITE setReadOnly )
    Q_PROPERTY( QAbstractSpinBox::ButtonSymbols buttonSymbols READ buttonSymbols WRITE setButtonSymbols )
    Q_PROPERTY( QString specialValueText READ specialValueText WRITE setSpecialValueText )
    //Q_PROPERTY( QString text READ text )
    Q_PROPERTY( bool accelerated READ isAccelerated WRITE setAccelerated )
    Q_PROPERTY( QAbstractSpinBox::CorrectionMode correctionMode READ correctionMode WRITE setCorrectionMode )
    //Q_PROPERTY( bool acceptableInput READ hasAcceptableInput )
    Q_PROPERTY( bool keyboardTracking READ keyboardTracking WRITE setKeyboardTracking )
    Q_PROPERTY( bool showGroupSeparator READ isGroupSeparatorShown WRITE setGroupSeparatorShown )

    // Slider
    Q_PROPERTY( QSlider::TickPosition tickPosition READ tickPosition WRITE setTickPosition )
    Q_PROPERTY( int tickInterval READ tickInterval WRITE setTickInterval )
    Q_PROPERTY( bool tracking READ hasTracking WRITE setTracking )
    Q_PROPERTY( Qt::Orientation orientation READ orientation WRITE setOrientation )
    Q_PROPERTY( bool invertedAppearance READ invertedAppearance WRITE setInvertedAppearance )
    Q_PROPERTY( bool invertedControls READ invertedControls WRITE setInvertedControls )
    Q_PROPERTY( bool sliderDown READ isSliderDown WRITE setSliderDown DESIGNABLE false )


public:
    QComboSpinBox(QWidget *parent = 0);
    ~QComboSpinBox();

public:
    int Spacing();
    void SetSpacing( int nSpacing );

    int Value();
    void SetValue( int nValue );

    int Minimum();
    void SetMinimum( int nValue );

    int Maximum();
    void SetMaximum( int nValue );

    int SingleStep();
    void SetSingleStep( int nValue );

    int PageStep();
    void SetPageStep( int nValue );

    // SpinBox
    QAbstractSpinBox::ButtonSymbols buttonSymbols() const;
    void setButtonSymbols( QAbstractSpinBox::ButtonSymbols eButtonSymbol );

    QString specialValueText() const;
    void setSpecialValueText( const QString& kText );

    bool wrapping() const;
    void setWrapping( bool bWraping );

    void setReadOnly( bool bReadOnly );
    bool isReadOnly() const;

    void setKeyboardTracking( bool bEnable );
    bool keyboardTracking() const;

    void setAlignment( Qt::Alignment eFlag );
    Qt::Alignment alignment() const;

    void setFrame( bool bEnable );
    bool hasFrame() const;

    void setAccelerated(bool bEnable );
    bool isAccelerated() const;

    void setGroupSeparatorShown( bool bShow );
    bool isGroupSeparatorShown() const;

    void setCorrectionMode( QAbstractSpinBox::CorrectionMode eCorrectMode );
    QAbstractSpinBox::CorrectionMode correctionMode() const;

    bool hasAcceptableInput() const;

    // Slider
    void setTickPosition( QSlider::TickPosition nPosition );
    QSlider::TickPosition tickPosition() const;

    void setTickInterval( int nTickInterval );
    int tickInterval() const;

    void setTracking( bool bEnable );
    bool hasTracking() const;

    void setSliderDown( bool bIsDown );
    bool isSliderDown() const;
    
    void setInvertedAppearance( bool bEnable );
    bool invertedAppearance() const;

    void setInvertedControls( bool bEnable );
    bool invertedControls() const;

    Qt::Orientation orientation() const;
    void setOrientation( Qt::Orientation eOrientation );

signals:
    void ValueChanged( int vValue );

private:
    void OnSpinBoxValueChanged( int nValue );
    void OnSliderValueChanged( int nValue );
private:
    Ui::ComboSpinBox ui;
};

#endif // QCOMBOSPINBOX_H
