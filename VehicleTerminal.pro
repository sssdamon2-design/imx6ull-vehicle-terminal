QT += core gui widgets

CONFIG += c++11
CONFIG -= app_bundle

TEMPLATE = app
TARGET = vehicle_terminal

INCLUDEPATH += \
    src \
    src/pages \
    include

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/pages/homepage.cpp \
    src/pages/monitorpage.cpp \
    src/pages/settingspage.cpp

HEADERS += \
    src/mainwindow.h \
    src/pages/homepage.h \
    src/pages/monitorpage.h \
    src/pages/settingspage.h