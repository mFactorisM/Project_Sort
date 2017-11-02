#-------------------------------------------------
#
# Project created by QtCreator 2017-11-02T10:26:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SMD_Sort
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    SMD_Sort_pcap.cpp

HEADERS  += mainwindow.h \
    SMD_Sort_pcap.h \
    struct.h

FORMS    += mainwindow.ui


INCLUDEPATH += "C:\WpdPack\Include"
INCLUDEPATH += "C:\WpdPack\Lib"
LIBS += -L"C:\WpdPack\Lib" -lwpcap -lpacket
LIBS += -lws2_32


DEFINES += WPCAP

DEFINES += HAVE_REMOTE

