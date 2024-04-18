QT       += core gui
<<<<<<< HEAD
QT       += sql
QT       += network
QT       += serialport
=======
QT       += network
>>>>>>> 260d6aef8108fd1cc5db7e0573321cb19adbff30
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    environment.cpp \
    main.cpp \
    mainwindow.cpp \
    pin.cpp \
    transactions.cpp

HEADERS += \
    environment.h \
<<<<<<< HEAD
    mainwindow.h \
    pin.h \
    transactions.h
=======
    mainwindow.h
>>>>>>> 260d6aef8108fd1cc5db7e0573321cb19adbff30

FORMS += \
    mainwindow.ui \
    pin.ui \
    transactions.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32: LIBS += -L$$PWD/rfidreader/build/debug/ -lrfidreader

INCLUDEPATH += $$PWD/rfidreader
DEPENDPATH += $$PWD/rfidreader
