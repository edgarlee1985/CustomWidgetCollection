#ifndef QCOMBODOUBLESPINBOX
#define QCOMBODOUBLESPINBOX

#include <QtWidgets/QWidget>

#include "ui_ComboDoubleSpinbox.h"
class QComboDoubleSpinBox : public QWidget
{
    Q_OBJECT

    Q_PROPERTY( int decimals READ Decimals WRITE SetDecimals )
    Q_PROPERTY( int spacing READ Spacing WRITE SetSpacing )
    Q_PROPERTY( double value READ Value WRITE SetValue )
    Q_PROPERTY( double minimum READ Minimum WRITE SetMinimum )
    Q_PROPERTY( double maximum READ Maximum WRITE SetMaximum )
    Q_PROPERTY( double singleStep READ SingleStep WRITE SetSingleStep )
    Q_PROPERTY( double pageStep READ PageStep WRITE SetPageStep )

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
    QComboDoubleSpinBox(QWidget *parent = 0);
    ~QComboDoubleSpinBox();

public:

    int Decimals() const;
    void SetDecimals( int nDecimals );

    int Spacing();
    void SetSpacing( int nSpacing );

    double Value();
    void SetValue( double dValue );

    double Minimum();
    void SetMinimum( double dValue );

    double Maximum();
    void SetMaximum( double dValue );

    double SingleStep();
    void SetSingleStep( double dValue );

    double PageStep();
    void SetPageStep( double dValue );

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
    void ValueChanged( double dValue );

private:
    void OnSpinBoxValueChanged( double dValue );
    void OnSliderValueChanged( int nValue );
private:
    Ui::SliderDoubleSpinbox ui;

    double m_dPageStep;
};

#endif // QCOMBODOUBLESPINBOX
