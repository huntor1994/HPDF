include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)
QT += testlib
QT -= gui
QT += sql pdf

TARGET=client-tests
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    source/controllers/master-controller-tests.cpp \
    source/main.cpp \
    source/test-suite.cpp

HEADERS += \
    source/controllers/master-controller-tests.h \
    source/test-suite.h


INCLUDEPATH+=source\
            ../hpdf-lib/source
