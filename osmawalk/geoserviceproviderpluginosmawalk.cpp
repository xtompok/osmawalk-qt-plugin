#include "geoserviceproviderpluginosmawalk.h"
#include "routingmanagerengineosmawalk.h"
#include <QtDebug>

QT_BEGIN_NAMESPACE
QGeoRoutingManagerEngine *GeoServiceProviderFactoryOsmawalk::createRoutingManagerEngine(
       const QVariantMap &parameters,
       QGeoServiceProvider::Error *error,
       QString *errorString) const
{
    qDebug() << "Creating Routing engine";
    return new RoutingManagerEngineOsmawalk(parameters,error,errorString);
}

QT_END_NAMESPACE
