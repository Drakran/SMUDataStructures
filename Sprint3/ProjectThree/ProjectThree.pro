TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    reader.cpp \
    word.cpp

HEADERS += \
    DSvector.hpp \
    reader.h \
    word.h
