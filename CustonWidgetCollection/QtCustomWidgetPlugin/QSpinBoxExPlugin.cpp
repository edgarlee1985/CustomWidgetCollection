#include "QSpinBoxEx.h"

#include <QtCore/QtPlugin>
#include "QSpinBoxExPlugin.h"


QSpinBoxExPlugin::QSpinBoxExPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QSpinBoxExPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool QSpinBoxExPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QSpinBoxExPlugin::createWidget(QWidget *parent)
{
    return new QSpinBoxEx(parent);
}

QString QSpinBoxExPlugin::name() const
{
    return "QSpinBoxEx";
}

QString QSpinBoxExPlugin::group() const
{
    return "My Plugins";
}

QIcon QSpinBoxExPlugin::icon() const
{
    return QIcon();
}

QString QSpinBoxExPlugin::toolTip() const
{
    return QString();
}

QString QSpinBoxExPlugin::whatsThis() const
{
    return QString();
}

bool QSpinBoxExPlugin::isContainer() const
{
    return false;
}

QString QSpinBoxExPlugin::domXml() const
{
    return QLatin1String( "<ui language=\"c++\">\
                          <widget class=\"QSpinBoxEx\" name=\"qtSpinBoxEx\">\
                          <property name=\"focusPolicy\">\
                          <enum>Qt::StrongFocus</enum>\
                          </property>\
                          </widget>\
                          <customwidgets>\
                          <customwidget>\
                          <class>QSpinBoxEx</class>\
                          <extends>QSpinBox</extends>\
                          </customwidget>\
                          </customwidgets>\
                          </ui>" );
}

QString QSpinBoxExPlugin::includeFile() const
{
    return "QSpinBoxEx.h";
}

