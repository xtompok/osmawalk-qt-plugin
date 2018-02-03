#include "routingmanagerengineosmawalk.h"
#include "routerreplyosmawalk.h"
#include <QUrlQuery>

RoutingManagerEngineOsmawalk::RoutingManagerEngineOsmawalk(const QVariantMap &parameters,
                             QGeoServiceProvider::Error *error,
                             QString * errorString)
    : QGeoRoutingManagerEngine(parameters),m_networkManager(new QNetworkAccessManager(this))
{
    qDebug() << "Engine created";
    if (parameters.contains(QStringLiteral("osmawalk.host"))){
        m_urlPrefix = parameters.value(QStringLiteral("osmawalk.host")).toString().toLatin1();
    } else {
        m_urlPrefix = QStringLiteral("http://dr-testing.bezva.org:5000/search");
    }
    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}

RoutingManagerEngineOsmawalk::~RoutingManagerEngineOsmawalk(){
}

QGeoRouteReply * RoutingManagerEngineOsmawalk::calculateRoute(const QGeoRouteRequest &request){    
    QList<QGeoCoordinate> waypoints;
    waypoints = request.waypoints();
    QGeoCoordinate from;
    QGeoCoordinate to;
    from = waypoints.first();
    to = waypoints.last();
    qDebug() << "Searching from " << from << " to " << to;

    QNetworkRequest networkRequest;

    QUrl url;
    url = RoutingManagerEngineOsmawalk::composeRequest(from,to);
    networkRequest.setUrl(url);
    QNetworkReply *reply = m_networkManager->get(networkRequest);
    RouterReplyOsmawalk * routeReply = new RouterReplyOsmawalk(reply,request,this);

    connect(routeReply,SIGNAL(finished()),this,SLOT(replyFinished()));
    connect(routeReply,SIGNAL(error(QGeoRouteReply::Error,QString)),
            this,SLOT(replyError(QGeoRouteReply::Error,QString)));
    return routeReply;
}

void RoutingManagerEngineOsmawalk::replyFinished()
{
    qDebug()<<"Reply finished";
    RouterReplyOsmawalk * reply = qobject_cast<RouterReplyOsmawalk *>(sender());
    if (reply)
        emit finished(reply);
}

void RoutingManagerEngineOsmawalk::replyError(QGeoRouteReply::Error errorCode,
                                              const QString &errorString)
{
    qDebug()<<"Reply error" << errorString;
    RouterReplyOsmawalk * reply = qobject_cast<RouterReplyOsmawalk *>(sender());
    if (reply)
        emit error(reply,errorCode,errorString);
}

QUrl RoutingManagerEngineOsmawalk::composeRequest(QGeoCoordinate from, QGeoCoordinate to){
    QUrlQuery query;
    query.addQueryItem("flon",QString::number(from.longitude()));
    query.addQueryItem("flat",QString::number(from.latitude()));
    query.addQueryItem("tlon",QString::number(to.longitude()));
    query.addQueryItem("tlat",QString::number(to.latitude()));
    QUrl url(m_urlPrefix);
    url.setQuery(query.query());
    return url;
}
