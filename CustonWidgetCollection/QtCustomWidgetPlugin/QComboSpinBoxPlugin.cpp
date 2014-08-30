#include "QComboSpinBox.h"

#include <QtCore/QtPlugin>
#include "QComboSpinBoxPlugin.h"

QComboSpinBoxPlugin::QComboSpinBoxPlugin(QObject *parent)
: QObject(parent)
{
    initialized = false;
}

void QComboSpinBoxPlugin::initialize( QDesignerFormEditorInterface* formEditor )
{
    if (initialized)
        return;

    initialized = true;
}

bool QComboSpinBoxPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QComboSpinBoxPlugin::createWidget(QWidget *parent)
{
    return new QComboSpinBox(parent);
}

QString QComboSpinBoxPlugin::name() const
{
    return "QComboSpinBox";
}

QString QComboSpinBoxPlugin::group() const
{
    return "My Plugins";
}

QIcon QComboSpinBoxPlugin::icon() const
{
    return QIcon();
}

QString QComboSpinBoxPlugin::toolTip() const
{
    return QString();
}

QString QComboSpinBoxPlugin::whatsThis() const
{
    return QString();
}

bool QComboSpinBoxPlugin::isContainer() const
{
    return false;
}

QString QComboSpinBoxPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\
                         <widget class=\"QComboSpinBox\" name=\"qtComboSpinBox\">\
                         </widget>\
                         <customwidgets>\
                         <customwidget>\
                         <class>QComboSpinBox</class>\
                         <extends>QWidget</extends>\
                         </customwidget>\
                         </customwidgets>\
                         </ui>");
}

QString QComboSpinBoxPlugin::includeFile() const
{
    return "QComboSpinBox.h";
}

