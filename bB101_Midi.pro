QT       += core gui opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(MidiLib/QMidi.pri)

SOURCES += \
    adsr.cpp \
    delay.cpp \
    main.cpp \
    bb101_midi_mainwindow.cpp \
    program_manager.cpp \
    system.cpp \
    vcf.cpp \
    waveforms.cpp

HEADERS += \
    bb101_midi_mainwindow.h

FORMS += \
    bb101_midi_mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Fonts.qrc \
    Icons.qrc

DISTFILES += \
    Fonts/Bauhaus_.ttf \
    Fonts/Directive Four Bold Italic.otf \
    Fonts/Directive Four Bold.otf \
    Fonts/Directive Four Condensed Bold Italic.otf \
    Fonts/Directive Four Condensed Bold.otf \
    Fonts/Directive Four Condensed Italic.otf \
    Fonts/Directive Four Condensed.otf \
    Fonts/Directive Four Italic.otf \
    Fonts/Directive Four.otf \
    Fonts/Godzilla.ttf \
    Fonts/Mandala Bold Italic.otf \
    Fonts/Mandala Bold.otf \
    Fonts/Mandala Italic.otf \
    Fonts/data-latin.ttf \
    Fonts/data-unifon.ttf
