#include "CustonWidgetCollection.h"
#include "QSliderExPlugin.h"
#include "QDoubleSpinBoxExPlugin.h"
#include "QSpinBoxExPlugin.h"
#include "QDialExPlugin.h"
#include "QColorButtonPlugin.h"
#include "QItemLabelPlugin.h"
#include "QComboSpinBoxPlugin.h"
#include "QComboDoubleSpinBoxPlugin.h"

CustonWidgetCollection::CustonWidgetCollection(QObject *parent)
    : QObject(parent)
{
    m_kWidgets.append( new QSliderExPlugin( this ) );
    m_kWidgets.append( new QDoubleSpinBoxExPlugin( this ) );
    m_kWidgets.append( new QSpinBoxExPlugin( this ) );
    m_kWidgets.append( new QDialExPlugin( this ) );
    m_kWidgets.append( new QColorButtonPlugin( this ) );
    m_kWidgets.append( new QItemLabelPlugin( this ) );
    m_kWidgets.append( new QComboSpinBoxPlugin( this ) );
    m_kWidgets.append( new QComboDoubleSpinBoxPlugin( this ) );
}

CustonWidgetCollection::~CustonWidgetCollection()
{

}

QList< QDesignerCustomWidgetInterface* > CustonWidgetCollection::customWidgets() const
{
    return m_kWidgets;
}