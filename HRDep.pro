QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authorization.cpp \
    changepassword.cpp \
    database.cpp \
    editwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    registration.cpp \
    requestcertificate.cpp \
    user.cpp

HEADERS += \
    authorization.h \
    changepassword.h \
    database.h \
    editwindow.h \
    mainwindow.h \
    registration.h \
    requestcertificate.h \
    user.h

FORMS += \
    authorization.ui \
    changepassword.ui \
    editwindow.ui \
    editwindow.ui \
    mainwindow.ui \
    registration.ui \
    requestcertificate.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
