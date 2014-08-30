#include "QComboDoubleSpinBox.h"

#include <QtCore/QtPlugin>
#include "QComboDoubleSpinBoxPlugin.h"

QComboDoubleSpinBoxPlugin::QComboDoubleSpinBoxPlugin(QObject *parent)
: QObject(parent)
{
    initialized = false;
}

void QComboDoubleSpinBoxPlugin::initialize( QDesignerFormEditorInterface* formEditor )
{
    if (initialized)
        return;

    initialized = true;
}

bool QComboDoubleSpinBoxPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QComboDoubleSpinBoxPlugin::createWidget(QWidget *parent)
{
    return new QComboDoubleSpinBox(parent);
}

QString QComboDoubleSpinBoxPlugin::name() const
{
    return "QComboDoubleSpinBox";
}

QString QComboDoubleSpinBoxPlugin::group() const
{
    return "My Plugins";
}

QIcon QComboDoubleSpinBoxPlugin::icon() const
{
    return QIcon();
}

QString QComboDoubleSpinBoxPlugin::toolTip() const
{
    return QString();
}

QString QComboDoubleSpinBoxPlugin::whatsThis() const
{
    return QString();
}

bool QComboDoubleSpinBoxPlugin::isContainer() const
{
    return false;
}

QString QComboDoubleSpinBoxPlugin::domXml() const
{
    return QLatin1String("\
                         <ui language=\"c++\">\
                         <widget class=\"QComboDoubleSpinBox\" name=\"combodoublespinbox\">\
                         </widget>\
                         <customwidgets>\
                         <customwidget>\
                         <class>QComboDoubleSpinBox</class>\
                         <extends>QWidget</extends>\
                         <addpagemethod>addPage</addpagemethod>\
                         </customwidget>\
                         </customwidgets>\
                         </ui>");
}

QString QComboDoubleSpinBoxPlugin::includeFile() const
{
    return "QComboDoubleSpinBox.h";
}

