#ifndef ROUTERREPLYOSMAWALK_H
#define ROUTERREPLYOSMAWALK_H

#include <QtNetwork/QNetworkReply>
#include <QtLocation/QGeoRouteReply>

QT_BEGIN_NAMESPACE

class RouterReplyOsmawalk : public QGeoRouteReply
{
    Q_OBJECT
public:
    explicit RouterReplyOsmawalk(QObject *parent = 0);
    RouterReplyOsmawalk(QNetworkReply *reply,
                        const QGeoRouteRequest &request,
                        QObject *parent = 0);
    ~RouterReplyOsmawalk();
private Q_SLOTS:
    void networkReplyFinished();
    void networkReplyError(QNetworkReply::NetworkError error);
};

QT_END_NAMESPACE

#endif // ROUTERREPLYOSMAWALK_H
