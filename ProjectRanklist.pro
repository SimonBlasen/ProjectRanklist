#-------------------------------------------------
#
# Project created by QtCreator 2017-02-16T10:10:01
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectRanklist
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Participant.cpp \
    trackborders.cpp \
    util.cpp \
    serialport.cpp

HEADERS  += mainwindow.h \
    sharedmemory.h \
    sms_memmapsample.h \
    Participant.h \
    trackborders.h \
    util.h \
    serialport.h

FORMS    += mainwindow.ui
