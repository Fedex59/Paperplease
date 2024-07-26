QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    archivo.cpp \
    documento.cpp \
    inbasedatos.cpp \
    inmigrante.cpp \
    main.cpp \
    mainwindow.cpp \
    metagame.cpp \
    persona.cpp

HEADERS += \
    archivo.h \
    documento.h \
    inbasedatos.h \
    inmigrante.h \
    mainwindow.h \
    metagame.h \
    persona.h

FORMS += \
    mainwindow.ui

niveles.files = niveles/*
niveles.path = $$OUT_PWD/niveles
INSTALLS += niveles

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    niveles/1/reglasConfig
