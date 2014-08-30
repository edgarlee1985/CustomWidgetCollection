#include "ComboWidget.h"

#include <QtCore/QtPlugin>
#include "ComboWidgetPlugin.h"
#include <QtDesigner/QDesignerFormWindowManagerInterface>
#include <QtDesigner/QDesignerFormWindowInterface>
#include <QtDesigner/QDesignerFormEditorInterface>

CComboWidgetPlugin::CComboWidgetPlugin(QObject *parent)
: QObject(parent)
, m_pManager( nullptr )
{
    initialized = false;
}

void CComboWidgetPlugin::initialize( QDesignerFormEditorInterface* pFormEditor )
{
    if (initialized)
        return;

    m_pManager = pFormEditor->formWindowManager();

    initialized = true;
}

bool CComboWidgetPlugin::isInitialized() const
{
    return initialized;
}

QWidget *CComboWidgetPlugin::createWidget(QWidget *parent)
{
    return new CComboWidget(parent);
}

QString CComboWidgetPlugin::name() const
{
    return "CComboWidget";
}

QString CComboWidgetPlugin::group() const
{
    return "My Plugins";
}

QIcon CComboWidgetPlugin::icon() const
{
    return QIcon();
}

QString CComboWidgetPlugin::toolTip() const
{
    return QString();
}

QString CComboWidgetPlugin::whatsThis() const
{
    return QString();
}

bool CComboWidgetPlugin::isContainer() const
{
    return false;
}

QString CComboWidgetPlugin::domXml() const
{
    return QLatin1String( "\
                         <ui language=\"c++\">\
                         <widget class=\"CComboWidget\" name=\"qtComboWidget\">\
                         </widget>\
                         <customwidgets>\
                         <customwidget>\
                         <class>CComboWidget</class>\
                         <extends>QWidget</extends>\
                         </customwidget>\
                         </customwidgets>\
                         </ui>" );
}

QString CComboWidgetPlugin::includeFile() const
{
    return "ComboWidget.h";
}

