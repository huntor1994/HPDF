include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

HEADERS += \
    source/controllers/command-controller.h \
    source/controllers/database-controller.h \
    source/controllers/master-controller.h \
    source/data/data-decorator.h \
    source/data/datetime-decorator.h \
    source/data/entity.h \
    source/data/image-decorator.h \
    source/data/int-decorator.h \
    source/data/string-decorator.h \
    source/framework/command.h \
    source/hpdf-lib_global.h \
    source/models/recently-opened-file-search.h \
    source/models/recently-opened-file.h \
    source/workers/pdf-image-provider.h \
    source/workers/pdf-image-worker.h

SOURCES += \
    source/controllers/command-controller.cpp \
    source/controllers/database-controller.cpp \
    source/controllers/master-controller.cpp \
    source/data/data-decorator.cpp \
    source/data/datetime-decorator.cpp \
    source/data/entity.cpp \
    source/data/image-decorator.cpp \
    source/data/int-decorator.cpp \
    source/data/string-decorator.cpp \
    source/framework/command.cpp \
    source/models/recently-opened-file-search.cpp \
    source/models/recently-opened-file.cpp \
    source/workers/pdf-image-provider.cpp \
    source/workers/pdf-image-worker.cpp

QT -= gui
QT+=pdf sql quick
DEFINES += HPDFLIB_LIBRARY
TARGET=hpdf-lib
TEMPLATE = lib
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH+=source

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =$$PWD

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui
