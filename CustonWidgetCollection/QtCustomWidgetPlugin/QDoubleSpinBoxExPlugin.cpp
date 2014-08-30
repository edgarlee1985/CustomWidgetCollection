#include "QDoubleSpinBoxEx.h"

#include <QtCore/QtPlugin>
#include "QDoubleSpinBoxExPlugin.h"


QDoubleSpinBoxExPlugin::QDoubleSpinBoxExPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QDoubleSpinBoxExPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool QDoubleSpinBoxExPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QDoubleSpinBoxExPlugin::createWidget(QWidget *parent)
{
    return new QDoubleSpinBoxEx(parent);
}

QString QDoubleSpinBoxExPlugin::name() const
{
    return "QDoubleSpinBoxEx";
}

QString QDoubleSpinBoxExPlugin::group() const
{
    return "My Plugins";
}

QIcon QDoubleSpinBoxExPlugin::icon() const
{
    return QIcon();
}

QString QDoubleSpinBoxExPlugin::toolTip() const
{
    return QString();
}

QString QDoubleSpinBoxExPlugin::whatsThis() const
{
    return QString();
}

bool QDoubleSpinBoxExPlugin::isContainer() const
{
    return false;
}

QString QDoubleSpinBoxExPlugin::domXml() const
{
    return QLatin1String( "<ui language=\"c++\">\
                          <widget class=\"QDoubleSpinBoxEx\" name=\"qtDoubleSpinBoxEx\">\
                          <property name=\"focusPolicy\">\
                          <enum>Qt::StrongFocus</enum>\
                          </property>\
                          </widget>\
                          <customwidgets>\
                          <customwidget>\
                          <class>QDoubleSpinBoxEx</class>\
                          <extends>QDoubleSpinBox</extends>\
                          </customwidget>\
                          </customwidgets>\
                          </ui>" );
}

QString QDoubleSpinBoxExPlugin::includeFile() const
{
    return "QDoubleSpinBoxEx.h";
}

