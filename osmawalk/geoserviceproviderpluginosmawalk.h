#ifndef GEOSERVICEPROVIDERPLUGINOSMAWALK_H
#define GEOSERVICEPROVIDERPLUGINOSMAWALK_H

#include <QtLocation/QGeoServiceProviderFactory>

QT_BEGIN_NAMESPACE

class GeoServiceProviderFactoryOsmawalk: public QObject, public QGeoServiceProviderFactory
{
    Q_OBJECT
    Q_INTERFACES(QGeoServiceProviderFactory)
    Q_PLUGIN_METADATA(IID "org.qt-project.qt.geoservice.serviceproviderfactory/5.0"
                      FILE "osmawalk_plugin.json")
public:
    QGeoRoutingManagerEngine * createRoutingManagerEngine(
            const QVariantMap &parameters,
            QGeoServiceProvider::Error *error,
            QString *errorString) const;
};

QT_END_NAMESPACE

#endif // GEOSERVICEPROVIDERPLUGINOSMAWALK_H
