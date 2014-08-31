#include "QComboDoubleSpinBox.h"
#include <math.h>

QComboDoubleSpinBox::QComboDoubleSpinBox(QWidget *parent)
: QWidget(parent)
{
    ui.setupUi( this );

    setLayout( ui.horizontalLayout );

    double dPow = pow( 10.0, ui.qtDoubleSpinBox->decimals() );
    ui.qtHorizontalSlider->setMinimum( static_cast< int >( ui.qtHorizontalSlider->minimum() * dPow ) );
    ui.qtHorizontalSlider->setMaximum( static_cast< int >( ui.qtHorizontalSlider->maximum() * dPow ) );
    ui.qtHorizontalSlider->setValue( static_cast< int >( ui.qtHorizontalSlider->value() * dPow ) );
    ui.qtHorizontalSlider->setSingleStep( static_cast< int >( ui.qtHorizontalSlider->singleStep() * dPow ) );
    ui.qtHorizontalSlider->setPageStep( static_cast< int >( ui.qtHorizontalSlider->pageStep() * dPow ) );

    typedef void ( QDoubleSpinBox::*ValueChangedFunc )( double );
    ValueChangedFunc pValueChanged = static_cast< ValueChangedFunc > ( &QDoubleSpinBox::valueChanged );
    connect( ui.qtDoubleSpinBox, pValueChanged, this, &QComboDoubleSpinBox::OnSpinBoxValueChanged );
    connect( ui.qtHorizontalSlider, &QSlider::valueChanged, this, &QComboDoubleSpinBox::OnSliderValueChanged );
}

QComboDoubleSpinBox::~QComboDoubleSpinBox()
{

}

void QComboDoubleSpinBox::OnSpinBoxValueChanged( double dValue )
{
    ui.qtHorizontalSlider->blockSignals( true );
    int nValue = static_cast< int >( dValue * pow( 10.0, ui.qtDoubleSpinBox->decimals() ) );
    ui.qtHorizontalSlider->setValue( nValue );
    ui.qtHorizontalSlider->blockSignals( false );
    Q_EMIT ValueChanged( dValue );
}

void QComboDoubleSpinBox::OnSliderValueChanged( int nValue )
{
    ui.qtDoubleSpinBox->blockSignals( true );
    double dValue = nValue / pow( 10.0, ui.qtDoubleSpinBox->decimals() );
    ui.qtDoubleSpinBox->setValue( dValue );
    ui.qtDoubleSpinBox->blockSignals( false );
    Q_EMIT ValueChanged( dValue );
}

int QComboDoubleSpinBox::Decimals() const
{
    return ui.qtDoubleSpinBox->decimals();
}

void QComboDoubleSpinBox::SetDecimals( int nDecimals )
{
//     int nOldDeciamals = ui.qtDoubleSpinBox->decimals();
//     double dPow = pow( 10.0, nDecimals );
//     ui.qtHorizontalSlider->setMinimum( static_cast< int >( ui.qtHorizontalSlider->minimum() * dPow ) );
//     ui.qtHorizontalSlider->setMaximum( static_cast< int >( ui.qtHorizontalSlider->maximum() * dPow ) );
//     ui.qtHorizontalSlider->setValue( static_cast< int >( ui.qtHorizontalSlider->value() * dPow ) );
//     ui.qtHorizontalSlider->setSingleStep( static_cast< int >( ui.qtHorizontalSlider->singleStep() * dPow ) );
//     ui.qtHorizontalSlider->setPageStep( static_cast< int >( ui.qtHorizontalSlider->pageStep() * dPow ) );

    ui.qtDoubleSpinBox->setDecimals( nDecimals );
}

int QComboDoubleSpinBox::Spacing()
{
    return layout()->spacing();
}

void QComboDoubleSpinBox::SetSpacing( int nSpacing )
{
    layout()->setSpacing( nSpacing );
}

double QComboDoubleSpinBox::Value()
{
    return ui.qtDoubleSpinBox->value();
}

void QComboDoubleSpinBox::SetValue( double dValue )
{
    ui.qtDoubleSpinBox->setValue( dValue );
}

double QComboDoubleSpinBox::Minimum()
{
    return ui.qtDoubleSpinBox->minimum();
}

void QComboDoubleSpinBox::SetMinimum( double dValue )
{
    ui.qtDoubleSpinBox->setMinimum( dValue );
    int nValue = static_cast< int >( dValue * pow( 10.0, ui.qtDoubleSpinBox->decimals() ) );
    ui.qtHorizontalSlider->setMinimum( nValue );
}

double QComboDoubleSpinBox::Maximum()
{
    return ui.qtDoubleSpinBox->maximum();
}

void QComboDoubleSpinBox::SetMaximum( double dValue )
{
    ui.qtDoubleSpinBox->setMaximum( dValue );
    int nValue = static_cast< int >( dValue * pow( 10.0, ui.qtDoubleSpinBox->decimals() ) );
    ui.qtHorizontalSlider->setMaximum( nValue );
}

double QComboDoubleSpinBox::SingleStep()
{
    return ui.qtDoubleSpinBox->singleStep();
}

void QComboDoubleSpinBox::SetSingleStep( double dValue )
{
    ui.qtDoubleSpinBox->setSingleStep( dValue );
    int nValue = static_cast< int >( dValue * pow( 10.0, ui.qtDoubleSpinBox->decimals() ) );
    ui.qtHorizontalSlider->setSingleStep( nValue );
}

double QComboDoubleSpinBox::PageStep()
{
    double dPageStep = ui.qtHorizontalSlider->pageStep() / pow( 10.0, ui.qtDoubleSpinBox->decimals() );
    return dPageStep;
}

void QComboDoubleSpinBox::SetPageStep( double dValue )
{
    int nValue = static_cast< int >( dValue * pow( 10.0, ui.qtDoubleSpinBox->decimals() ) );
    ui.qtHorizontalSlider->setPageStep( nValue );
}

QAbstractSpinBox::ButtonSymbols QComboDoubleSpinBox::buttonSymbols() const
{
    return ui.qtDoubleSpinBox->buttonSymbols();
}

void QComboDoubleSpinBox::setButtonSymbols( QAbstractSpinBox::ButtonSymbols eButtonSymbol )
{
    ui.qtDoubleSpinBox->setButtonSymbols( eButtonSymbol );
}

QString QComboDoubleSpinBox::specialValueText() const
{
    return ui.qtDoubleSpinBox->specialValueText();
}

void QComboDoubleSpinBox::setSpecialValueText( const QString& kText )
{
    ui.qtDoubleSpinBox->setSpecialValueText( kText );
}

bool QComboDoubleSpinBox::wrapping() const
{
    return ui.qtDoubleSpinBox->wrapping();
}

void QComboDoubleSpinBox::setWrapping( bool bWraping )
{
    ui.qtDoubleSpinBox->setWrapping( bWraping );
}

void QComboDoubleSpinBox::setReadOnly( bool bReadOnly )
{
    ui.qtDoubleSpinBox->setReadOnly( bReadOnly );
}

bool QComboDoubleSpinBox::isReadOnly() const
{
    return ui.qtDoubleSpinBox->isReadOnly();
}

void QComboDoubleSpinBox::setKeyboardTracking( bool bEnable )
{
    ui.qtDoubleSpinBox->setKeyboardTracking( bEnable );
}

bool QComboDoubleSpinBox::keyboardTracking() const
{
    return ui.qtDoubleSpinBox->keyboardTracking();
}

void QComboDoubleSpinBox::setAlignment( Qt::Alignment eFlag )
{
    ui.qtDoubleSpinBox->setAlignment( eFlag );
}

Qt::Alignment QComboDoubleSpinBox::alignment() const
{
    return ui.qtDoubleSpinBox->alignment();
}

void QComboDoubleSpinBox::setFrame( bool bEnable )
{
    ui.qtDoubleSpinBox->setFrame( bEnable );
}

bool QComboDoubleSpinBox::hasFrame() const
{
    return ui.qtDoubleSpinBox->hasFrame();
}

void QComboDoubleSpinBox::setAccelerated(bool bEnable )
{
    ui.qtDoubleSpinBox->setAccelerated( bEnable );
}

bool QComboDoubleSpinBox::isAccelerated() const
{
    return ui.qtDoubleSpinBox->isAccelerated();
}

void QComboDoubleSpinBox::setGroupSeparatorShown( bool bShow )
{
    ui.qtDoubleSpinBox->setGroupSeparatorShown( bShow );
}

bool QComboDoubleSpinBox::isGroupSeparatorShown() const
{
    return ui.qtDoubleSpinBox->isGroupSeparatorShown();
}

void QComboDoubleSpinBox::setCorrectionMode( QAbstractSpinBox::CorrectionMode eCorrectMode )
{
    ui.qtDoubleSpinBox->setCorrectionMode( eCorrectMode );
}

QAbstractSpinBox::CorrectionMode QComboDoubleSpinBox::correctionMode() const
{
    return ui.qtDoubleSpinBox->correctionMode();
}

bool QComboDoubleSpinBox::hasAcceptableInput() const
{
    return ui.qtDoubleSpinBox->hasAcceptableInput();
}

void QComboDoubleSpinBox::setTickPosition( QSlider::TickPosition nPosition )
{
    ui.qtHorizontalSlider->setTickPosition( nPosition );
}

QSlider::TickPosition QComboDoubleSpinBox::tickPosition() const
{
    return ui.qtHorizontalSlider->tickPosition();
}

void QComboDoubleSpinBox::setTickInterval( int nTickInterval )
{
    ui.qtHorizontalSlider->setTickInterval( nTickInterval );
}

int QComboDoubleSpinBox::tickInterval() const
{
    return ui.qtHorizontalSlider->tickInterval();
}

void QComboDoubleSpinBox::setTracking( bool bEnable )
{
    ui.qtHorizontalSlider->setTracking( bEnable );
}

bool QComboDoubleSpinBox::hasTracking() const
{
    return ui.qtHorizontalSlider->hasTracking();
}

void QComboDoubleSpinBox::setSliderDown( bool bIsDown )
{
    ui.qtHorizontalSlider->setSliderDown( bIsDown );
}

bool QComboDoubleSpinBox::isSliderDown() const
{
    return ui.qtHorizontalSlider->isSliderDown();
}

void QComboDoubleSpinBox::setInvertedAppearance( bool bEnable )
{
    ui.qtHorizontalSlider->setInvertedAppearance( bEnable );
}

bool QComboDoubleSpinBox::invertedAppearance() const
{
    return ui.qtHorizontalSlider->invertedAppearance();
}

void QComboDoubleSpinBox::setInvertedControls( bool bEnable )
{
    ui.qtHorizontalSlider->setInvertedControls( bEnable );
}

bool QComboDoubleSpinBox::invertedControls() const
{
    return ui.qtHorizontalSlider->invertedControls();
}

Qt::Orientation QComboDoubleSpinBox::orientation() const
{
    return ui.qtHorizontalSlider->orientation();
}

void QComboDoubleSpinBox::setOrientation( Qt::Orientation eOrientation )
{
    ui.qtHorizontalSlider->setOrientation( eOrientation );
}