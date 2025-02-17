QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bird.cpp \
    changeskin.cpp \
    main.cpp \
    menu.cpp \
    pillar.cpp \
    restart.cpp \
    scene.cpp \
    widget.cpp

HEADERS += \
    bird.h \
    changeskin.h \
    menu.h \
    pillar.h \
    restart.h \
    scene.h \
    widget.h

FORMS += \
    changeskin.ui \
    menu.ui \
    restart.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
