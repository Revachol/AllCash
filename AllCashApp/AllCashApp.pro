QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    credits.cpp \
    deposit.cpp \
    financemanager.cpp \
    main.cpp \
    mainwindow.cpp \
    opencredit.cpp

HEADERS += \
    account.h \
    credits.h \
    deposit.h \
    financemanager.h \
    mainwindow.h \
    opencredit.h

FORMS += \
    account.ui \
    credits.ui \
    deposit.ui \
    financemanager.ui \
    mainwindow.ui \
    opencredit.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
