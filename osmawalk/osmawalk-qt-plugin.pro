#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T18:41:02
#
#-------------------------------------------------

QT       += core gui positioning location

TARGET = qtgeoservices_osmawalk
TEMPLATE = lib
CONFIG += plugin

PLUGIN_TYPE = geoservices
DESTDIR = $$[QT_INSTALL_PLUGINS]/$$PLUGIN_TYPE
TARGET = $$qt5LibraryTarget($$TARGET)

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    geoserviceproviderpluginosmawalk.cpp \
    routerreplyosmawalk.cpp \
    routingmanagerengineosmawalk.cpp

HEADERS += \
    geoserviceproviderpluginosmawalk.h \
    routerreplyosmawalk.h \
    routingmanagerengineosmawalk.h
OTHER_FILES += osmawalk_plugin.json

#DISTFILES += osmawalk_plugin.json

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
