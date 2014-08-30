#include "QDialEx.h"

#include <QtCore/QtPlugin>
#include "QDialExPlugin.h"


QDialExPlugin::QDialExPlugin(QObject *parent)
: QObject(parent)
{
    initialized = false;
}

void QDialExPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool QDialExPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QDialExPlugin::createWidget(QWidget *parent)
{
    return new QDialEx(parent);
}

QString QDialExPlugin::name() const
{
    return "QDialEx";
}

QString QDialExPlugin::group() const
{
    return "My Plugins";
}

QIcon QDialExPlugin::icon() const
{
    return QIcon();
}

QString QDialExPlugin::toolTip() const
{
    return QString();
}

QString QDialExPlugin::whatsThis() const
{
    return QString();
}

bool QDialExPlugin::isContainer() const
{
    return false;
}

QString QDialExPlugin::domXml() const
{
    return QLatin1String( "<ui language=\"c++\">\
                          <widget class=\"QDialEx\" name=\"qtDialEx\">\
                          <property name=\"geometry\">\
                          <rect>\
                          <x>0</x>\
                          <y>0</y>\
                          <width>50</width>\
                          <height>64</height>\
                          </rect>\
                          </property>\
                          <property name=\"focusPolicy\">\
                          <enum>Qt::StrongFocus</enum>\
                          </property>\
                          </widget>\
                          <customwidgets>\
                          <customwidget>\
                          <class>QDialEx</class>\
                          <extends>QDial</extends>\
                          </customwidget>\
                          </customwidgets>\
                          </ui>" );
}

QString QDialExPlugin::includeFile() const
{
    return "QDialEx.h";
}

