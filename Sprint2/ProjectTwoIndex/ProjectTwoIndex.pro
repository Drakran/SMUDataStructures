TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    test.cpp \
    reader.cpp

HEADERS += \
    catch.hpp \
    DSvector.hpp \
    reader.h
