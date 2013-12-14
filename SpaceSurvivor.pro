TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    Vecteur.cpp \
    Vaisseau.cpp \
    Projectile.cpp \
    Missile.cpp \
    Asteroid.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/SFML-2.1/lib/release/ -lsfml-audio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/SFML-2.1/lib/debug/ -lsfml-audio
else:unix: LIBS += -L$$PWD/SFML-2.1/lib/ -lsfml-audio

INCLUDEPATH += $$PWD/SFML-2.1/lib
DEPENDPATH += $$PWD/SFML-2.1/lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/SFML-2.1/lib/release/ -lsfml-graphics
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/SFML-2.1/lib/debug/ -lsfml-graphics
else:unix: LIBS += -L$$PWD/SFML-2.1/lib/ -lsfml-graphics

INCLUDEPATH += $$PWD/SFML-2.1/include
DEPENDPATH += $$PWD/SFML-2.1/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/SFML-2.1/lib/release/ -lsfml-network
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/SFML-2.1/lib/debug/ -lsfml-network
else:unix: LIBS += -L$$PWD/SFML-2.1/lib/ -lsfml-network

INCLUDEPATH += $$PWD/SFML-2.1/include
DEPENDPATH += $$PWD/SFML-2.1/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/SFML-2.1/lib/release/ -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/SFML-2.1/lib/debug/ -lsfml-system
else:unix: LIBS += -L$$PWD/SFML-2.1/lib/ -lsfml-system

INCLUDEPATH += $$PWD/SFML-2.1/include
DEPENDPATH += $$PWD/SFML-2.1/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/SFML-2.1/lib/release/ -lsfml-window
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/SFML-2.1/lib/debug/ -lsfml-window
else:unix: LIBS += -L$$PWD/SFML-2.1/lib/ -lsfml-window

INCLUDEPATH += $$PWD/SFML-2.1/include
DEPENDPATH += $$PWD/SFML-2.1/include

HEADERS += \
    Vecteur.h \
    Vaisseau.h \
    Projectile.h \
    Missile.h \
    Asteroid.h

