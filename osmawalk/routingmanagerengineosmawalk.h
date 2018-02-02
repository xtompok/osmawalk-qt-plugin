#ifndef ROUTINGMANAGERENGINEOSMAWALK_H
#define ROUTINGMANAGERENGINEOSMAWALK_H

#include <QtLocation/QGeoServiceProvider>
#include <QtLocation/QGeoRoutingManagerEngine>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE

class RoutingManagerEngineOsmawalk : public QGeoRoutingManagerEngine
{
    Q_OBJECT
public:
    RoutingManagerEngineOsmawalk(const QVariantMap &parameters,
                                 QGeoServiceProvider::Error *error,
                                 QString * errorString);
    ~RoutingManagerEngineOsmawalk();
    QGeoRouteReply * calculateRoute(const QGeoRouteRequest &request);
    // routeparser?
private Q_SLOTS:
    void replyFinished();
    void replyError(QGeoRouteReply::Error errorCode, const QString &errorString);

private:
    QNetworkAccessManager * m_networkManager;
    QString m_urlPrefix;
};

QT_END_NAMESPACE

#endif // ROUTINGMANAGERENGINEOSMAWALK_H
