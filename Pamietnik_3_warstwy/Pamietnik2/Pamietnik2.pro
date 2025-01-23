QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    main.cpp \
    pamietnik.cpp \
    pamietnik_backend.cpp \
    program.cpp \
    wpis.cpp

HEADERS += \
    dialog.h \
    pamietnik.h \
    pamietnik_backend.h \
    program.h \
    wpis.h

FORMS += \
    dialog.ui \
    pamietnik.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
