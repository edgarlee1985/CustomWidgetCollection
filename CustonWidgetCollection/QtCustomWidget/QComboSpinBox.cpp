#include "QComboSpinBox.h"

QComboSpinBox::QComboSpinBox(QWidget *parent)
: QWidget(parent)
{
    ui.setupUi( this );

    setLayout( ui.horizontalLayout );

    typedef void ( QSpinBox::*ValueChangedFunc )( int );
    ValueChangedFunc pValueChanged = static_cast< ValueChangedFunc > ( &QSpinBox::valueChanged );
    connect( ui.qtSpinBox, pValueChanged, this, &QComboSpinBox::OnSpinBoxValueChanged );
    connect( ui.qtHorizontalSlider, &QSlider::valueChanged, this, &QComboSpinBox::OnSliderValueChanged );
}

QComboSpinBox::~QComboSpinBox()
{

}

void QComboSpinBox::OnSpinBoxValueChanged( int nValue )
{
    ui.qtHorizontalSlider->blockSignals( true );
    ui.qtHorizontalSlider->setValue( nValue );
    ui.qtHorizontalSlider->blockSignals( false );
    Q_EMIT ValueChanged( nValue );
}

void QComboSpinBox::OnSliderValueChanged( int nValue )
{
    ui.qtSpinBox->blockSignals( true );
    ui.qtSpinBox->setValue( nValue );
    ui.qtSpinBox->blockSignals( false );
    Q_EMIT ValueChanged( nValue );
}

int QComboSpinBox::Spacing()
{
    return layout()->spacing();
}

void QComboSpinBox::SetSpacing( int nSpacing )
{
    layout()->setSpacing( nSpacing );
}

int QComboSpinBox::Value()
{
    return ui.qtSpinBox->value();
}

void QComboSpinBox::SetValue( int nValue )
{
    ui.qtSpinBox->setValue( nValue );
}

int QComboSpinBox::Minimum()
{
    return ui.qtSpinBox->minimum();
}

void QComboSpinBox::SetMinimum( int nValue )
{
    ui.qtSpinBox->setMinimum( nValue );
    ui.qtHorizontalSlider->setMinimum( nValue );
}

int QComboSpinBox::Maximum()
{
    return ui.qtSpinBox->maximum();
}

void QComboSpinBox::SetMaximum( int nValue )
{
    ui.qtSpinBox->setMaximum( nValue );
    ui.qtHorizontalSlider->setMaximum( nValue );
}

int QComboSpinBox::SingleStep()
{
    return ui.qtSpinBox->singleStep();
}

void QComboSpinBox::SetSingleStep( int nValue )
{
    ui.qtSpinBox->setSingleStep( nValue );
    ui.qtHorizontalSlider->setSingleStep( nValue );
}

int QComboSpinBox::PageStep()
{
    return ui.qtHorizontalSlider->pageStep();
}

void QComboSpinBox::SetPageStep( int nValue )
{
    ui.qtHorizontalSlider->setPageStep( nValue );
}

QAbstractSpinBox::ButtonSymbols QComboSpinBox::buttonSymbols() const
{
    return ui.qtSpinBox->buttonSymbols();
}

void QComboSpinBox::setButtonSymbols( QAbstractSpinBox::ButtonSymbols eButtonSymbol )
{
    ui.qtSpinBox->setButtonSymbols( eButtonSymbol );
}

QString QComboSpinBox::specialValueText() const
{
    return ui.qtSpinBox->specialValueText();
}

void QComboSpinBox::setSpecialValueText( const QString& kText )
{
    ui.qtSpinBox->setSpecialValueText( kText );
}

bool QComboSpinBox::wrapping() const
{
    return ui.qtSpinBox->wrapping();
}

void QComboSpinBox::setWrapping( bool bWraping )
{
    ui.qtSpinBox->setWrapping( bWraping );
}

void QComboSpinBox::setReadOnly( bool bReadOnly )
{
    ui.qtSpinBox->setReadOnly( bReadOnly );
}

bool QComboSpinBox::isReadOnly() const
{
    return ui.qtSpinBox->isReadOnly();
}

void QComboSpinBox::setKeyboardTracking( bool bEnable )
{
    ui.qtSpinBox->setKeyboardTracking( bEnable );
}

bool QComboSpinBox::keyboardTracking() const
{
    return ui.qtSpinBox->keyboardTracking();
}

void QComboSpinBox::setAlignment( Qt::Alignment eFlag )
{
    ui.qtSpinBox->setAlignment( eFlag );
}

Qt::Alignment QComboSpinBox::alignment() const
{
    return ui.qtSpinBox->alignment();
}

void QComboSpinBox::setFrame( bool bEnable )
{
    ui.qtSpinBox->setFrame( bEnable );
}

bool QComboSpinBox::hasFrame() const
{
    return ui.qtSpinBox->hasFrame();
}

void QComboSpinBox::setAccelerated(bool bEnable )
{
    ui.qtSpinBox->setAccelerated( bEnable );
}

bool QComboSpinBox::isAccelerated() const
{
    return ui.qtSpinBox->isAccelerated();
}

void QComboSpinBox::setGroupSeparatorShown( bool bShow )
{
    ui.qtSpinBox->setGroupSeparatorShown( bShow );
}

bool QComboSpinBox::isGroupSeparatorShown() const
{
    return ui.qtSpinBox->isGroupSeparatorShown();
}

void QComboSpinBox::setCorrectionMode( QAbstractSpinBox::CorrectionMode eCorrectMode )
{
    ui.qtSpinBox->setCorrectionMode( eCorrectMode );
}

QAbstractSpinBox::CorrectionMode QComboSpinBox::correctionMode() const
{
    return ui.qtSpinBox->correctionMode();
}

bool QComboSpinBox::hasAcceptableInput() const
{
    return ui.qtSpinBox->hasAcceptableInput();
}

void QComboSpinBox::setTickPosition( QSlider::TickPosition nPosition )
{
    ui.qtHorizontalSlider->setTickPosition( nPosition );
}

QSlider::TickPosition QComboSpinBox::tickPosition() const
{
    return ui.qtHorizontalSlider->tickPosition();
}

void QComboSpinBox::setTickInterval( int nTickInterval )
{
    ui.qtHorizontalSlider->setTickInterval( nTickInterval );
}

int QComboSpinBox::tickInterval() const
{
    return ui.qtHorizontalSlider->tickInterval();
}

void QComboSpinBox::setTracking( bool bEnable )
{
    ui.qtHorizontalSlider->setTracking( bEnable );
}

bool QComboSpinBox::hasTracking() const
{
    return ui.qtHorizontalSlider->hasTracking();
}

void QComboSpinBox::setSliderDown( bool bIsDown )
{
    ui.qtHorizontalSlider->setSliderDown( bIsDown );
}

bool QComboSpinBox::isSliderDown() const
{
    return ui.qtHorizontalSlider->isSliderDown();
}

void QComboSpinBox::setInvertedAppearance( bool bEnable )
{
    ui.qtHorizontalSlider->setInvertedAppearance( bEnable );
}

bool QComboSpinBox::invertedAppearance() const
{
    return ui.qtHorizontalSlider->invertedAppearance();
}

void QComboSpinBox::setInvertedControls( bool bEnable )
{
    ui.qtHorizontalSlider->setInvertedControls( bEnable );
}

bool QComboSpinBox::invertedControls() const
{
    return ui.qtHorizontalSlider->invertedControls();
}

Qt::Orientation QComboSpinBox::orientation() const
{
    return ui.qtHorizontalSlider->orientation();
}

void QComboSpinBox::setOrientation( Qt::Orientation eOrientation )
{
    ui.qtHorizontalSlider->setOrientation( eOrientation );
}