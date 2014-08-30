#include "QSliderEx.h"

#include <QtCore/QtPlugin>
#include "QSliderExPlugin.h"


QSliderExPlugin::QSliderExPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QSliderExPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool QSliderExPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QSliderExPlugin::createWidget(QWidget *parent)
{
    return new QSliderEx(parent);
}

QString QSliderExPlugin::name() const
{
    return "QSliderEx";
}

QString QSliderExPlugin::group() const
{
    return "My Plugins";
}

QIcon QSliderExPlugin::icon() const
{
    return QIcon();
}

QString QSliderExPlugin::toolTip() const
{
    return QString();
}

QString QSliderExPlugin::whatsThis() const
{
    return QString();
}

bool QSliderExPlugin::isContainer() const
{
    return false;
}

QString QSliderExPlugin::domXml() const
{
    return QLatin1String( "<ui language=\"c++\">\
                          <widget class=\"QSliderEx\" name=\"qtSliderEx\">\
                          <property name=\"geometry\">\
                          <rect>\
                          <x>0</x>\
                          <y>0</y>\
                          <width>160</width>\
                          <height>19</height>\
                          </rect>\
                          </property>\
                          <property name=\"orientation\">\
                          <enum>Qt::Horizontal</enum>\
                          </property>\
                          <property name=\"focusPolicy\">\
                          <enum>Qt::StrongFocus</enum>\
                          </property>\
                          </widget>\
                          <customwidgets>\
                          <customwidget>\
                          <class>QSliderEx</class>\
                          <extends>QSlider</extends>\
                          </customwidget>\
                          </customwidgets>\
                          </ui>" );
}

QString QSliderExPlugin::includeFile() const
{
    return "QSliderEx.h";
}

