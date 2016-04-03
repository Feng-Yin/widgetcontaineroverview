#-------------------------------------------------
#
# Project created by QtCreator 2016-04-01T20:45:20
#
#-------------------------------------------------

QT       += core gui
CONFIG   += qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HDRR
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    cpupiemarker.cpp \
    cpuplot.cpp \
    cpustat.cpp \
    oscilloscopeplot.cpp \
    oscilloscopewheelbox.cpp \
    oscilloscopewidget.cpp \
    oscilloscopeknob.cpp \
    curvedata.cpp \
    samplingthread.cpp \
    signaldata.cpp \
    curvesplot.cpp \
    curvesplotwidget.cpp \
    attitude_indicator.cpp \
    cockpit_grid.cpp \
    speedo_meter.cpp \
    widgetcontaineroverview.cpp

HEADERS  += mainwindow.h\
    cpupiemarker.h \
    cpuplot.h \
    cpustat.h \
    oscilloscopeplot.h \
    oscilloscopewheelbox.h \
    oscilloscopewidget.h \
    oscilloscopeknob.h \
    curvedata.h \
    samplingthread.h \
    signaldata.h \
    curvesplot.h \
    curvesplotwidget.h \
    attitude_indicator.h \
    cockpit_grid.h \
    speedo_meter.h \
    widgetcontaineroverview.h

DISTFILES += \
    osci.css
