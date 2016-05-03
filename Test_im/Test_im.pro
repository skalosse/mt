#-------------------------------------------------
#
# Project created by QtCreator 2016-03-18T14:41:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test_im
TEMPLATE = app

include(qextserialport/qextserialport.pri)

SOURCES += main.cpp\
        maintest.cpp \
    fonctions_map.cpp \
    Package.cpp

HEADERS  += maintest.h \
    fonctions_map.hpp \
    Package.hpp

FORMS    += maintest.ui
