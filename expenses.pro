QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    io/reader.cpp \
    io/writer.cpp \
    main.cpp \
    mainwindow.cpp \
    model/transactions.cpp \
    model/wallet.cpp \
    newtransaction.cpp \
    transactiondialog.cpp

HEADERS += \
    io/reader.h \
    io/writer.h \
    mainwindow.h \
    model/transactions.h \
    model/wallet.h \
    newtransaction.h \
    transactiondialog.h

FORMS += \
    mainwindow.ui \
    newtransaction.ui \
    transactiondialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
