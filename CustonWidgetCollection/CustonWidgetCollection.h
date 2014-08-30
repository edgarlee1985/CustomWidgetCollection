#ifndef CUSTONWIDGETCOLLECTION_H
#define CUSTONWIDGETCOLLECTION_H

#include <QDesignerCustomWidgetCollectionInterface>
#include <QObject>
#include <QtCore/qplugin.h>

class CustonWidgetCollection : public QObject, public QDesignerCustomWidgetCollectionInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface")
    Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)

public:
    CustonWidgetCollection(QObject *parent = 0);
    ~CustonWidgetCollection();

    virtual QList< QDesignerCustomWidgetInterface* > customWidgets() const;

private:
    QList< QDesignerCustomWidgetInterface* > m_kWidgets;

};

#endif // CUSTONWIDGETCOLLECTION_H