#include "routingmanagerengineosmawalk.h"
#include "routerreplyosmawalk.h"

RoutingManagerEngineOsmawalk::RoutingManagerEngineOsmawalk(const QVariantMap &parameters,
                             QGeoServiceProvider::Error *error,
                             QString * errorString)
    : QGeoRoutingManagerEngine(parameters),m_networkManager(new QNetworkAccessManager(this))
{
    qDebug() << "Engine created";
    // TODO fill from parameters
    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}

RoutingManagerEngineOsmawalk::~RoutingManagerEngineOsmawalk(){
}

QGeoRouteReply * RoutingManagerEngineOsmawalk::calculateRoute(const QGeoRouteRequest &request){
    QNetworkRequest networkRequest;
    qDebug()<< "Searching route";
    // TODO compose Url
    QNetworkReply *reply = m_networkManager->get(networkRequest);
    RouterReplyOsmawalk * routeReply = new RouterReplyOsmawalk(reply,request,this);

    connect(routeReply,SIGNAL(finished()),this,SLOT(replyFinished()));
    connect(routeReply,SIGNAL(error(QGeoRouteReply::Error,QString)),
            this,SLOT(replyError(QGeoRouteReply::Error,QString)));
    return routeReply;
}

void RoutingManagerEngineOsmawalk::replyFinished()
{
    RouterReplyOsmawalk * reply = qobject_cast<RouterReplyOsmawalk *>(sender());
    if (reply)
        emit finished(reply);
}

void RoutingManagerEngineOsmawalk::replyError(QGeoRouteReply::Error errorCode,
                                              const QString &errorString)
{
    RouterReplyOsmawalk * reply = qobject_cast<RouterReplyOsmawalk *>(sender());
    if (reply)
        emit error(reply,errorCode,errorString);
}
