#include "QItemLabel.h"

#include <QtCore/QtPlugin>
#include "QItemLabelPlugin.h"


QItemLabelPlugin::QItemLabelPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QItemLabelPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool QItemLabelPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QItemLabelPlugin::createWidget(QWidget *parent)
{
    return new QItemLabel(parent);
}

QString QItemLabelPlugin::name() const
{
    return "QItemLabel";
}

QString QItemLabelPlugin::group() const
{
    return "My Plugins";
}

QIcon QItemLabelPlugin::icon() const
{
    return QIcon();
}

QString QItemLabelPlugin::toolTip() const
{
    return QString();
}

QString QItemLabelPlugin::whatsThis() const
{
    return QString();
}

bool QItemLabelPlugin::isContainer() const
{
    return false;
}

QString QItemLabelPlugin::domXml() const
{
    return "<widget class=\"QItemLabel\" name=\"qItemLabel\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString QItemLabelPlugin::includeFile() const
{
    return "QItemLabel.h";
}

