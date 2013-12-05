TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/SFML
SOURCES += main.cpp

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
