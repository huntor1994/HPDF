include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)
QT += testlib
QT -= gui
QT += sql

TARGET=client-tests
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

