TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        figuras.cpp \
        main.cpp \
        Tablero.cpp \
        movimiento.cpp

HEADERS += \
    Tablero.h \
    figuras.h \
    movimiento.h
