TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    test.cpp \
    reader.cpp

HEADERS += \
    node.hpp \
    catch.hpp \
    linkedlist.hpp \
    stack.hpp \
    adjlist.hpp \
    reader.h
