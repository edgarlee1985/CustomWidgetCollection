#include "QColorButton.h"

#include <QtCore/QtPlugin>
#include "QColorButtonPlugin.h"


QColorButtonPlugin::QColorButtonPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QColorButtonPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool QColorButtonPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QColorButtonPlugin::createWidget(QWidget *parent)
{
    return new QColorButton(parent);
}

QString QColorButtonPlugin::name() const
{
    return "QColorButton";
}

QString QColorButtonPlugin::group() const
{
    return "My Plugins";
}

QIcon QColorButtonPlugin::icon() const
{
    return QIcon();
}

QString QColorButtonPlugin::toolTip() const
{
    return QString();
}

QString QColorButtonPlugin::whatsThis() const
{
    return QString();
}

bool QColorButtonPlugin::isContainer() const
{
    return false;
}

QString QColorButtonPlugin::domXml() const
{
    return "<widget class=\"QColorButton\" name=\"qColorButton\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>75</width>\n"
        "   <height>23</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString QColorButtonPlugin::includeFile() const
{
    return "QColorButton.h";
}

