#include "routerreplyosmawalk.h"
#include "routingmanagerengineosmawalk.h"

RouterReplyOsmawalk::RouterReplyOsmawalk(QNetworkReply *reply,
                                         const QGeoRouteRequest &request,
                                         QObject *parent):QGeoRouteReply(request,parent)
{
    connect(reply,SIGNAL(finished()),this,SLOT(networkReplyFinished()));
    connect(reply,SIGNAL(error(QNetworkReply::NetworkError)),
            this,SLOT(networkReplyError(QNetworkReply::NetworkError)));
    connect(this,&QGeoRouteReply::aborted,reply,&QNetworkReply::abort);
    connect(this,&QObject::destroyed,reply,&QObject::deleteLater);
}

RouterReplyOsmawalk::~RouterReplyOsmawalk()
{
}

void RouterReplyOsmawalk::networkReplyFinished()
{
    QNetworkReply * reply = static_cast<QNetworkReply *>(sender());
    reply->deleteLater();

    if (reply->error() != QNetworkReply::NoError)
    {
        return;
    }

    QList<QGeoRoute> routes;
    QString errorString;


    //TODO parse response
}

void RouterReplyOsmawalk::networkReplyError(QNetworkReply::NetworkError error){
    Q_UNUSED(error)
    QNetworkReply *reply = static_cast<QNetworkReply *>(sender());
    reply->deleteLater();
    setError(QGeoRouteReply::CommunicationError, reply->errorString());

}
