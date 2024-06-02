QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Account/account.cpp \
    Credit/credits.cpp \
    Deposit/deposit.cpp \
    Main/financemanager.cpp \
    Main/main.cpp \
    Main/mainwindow.cpp \
    Credit/opencredit.cpp \
    Deposit/opendeposit.cpp

HEADERS += \
    Account/account.h \
    Credit/credits.h \
    Deposit/deposit.h \
    Main/financemanager.h \
    Main/mainwindow.h \
    Credit/opencredit.h \
    Deposit/opendeposit.h

FORMS += \
    Account/account.ui \
    Credit/credits.ui \
    Deposit/deposit.ui \
    Main/financemanager.ui \
    Main/mainwindow.ui \
    Credit/opencredit.ui \
    Deposit/opendeposit.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
