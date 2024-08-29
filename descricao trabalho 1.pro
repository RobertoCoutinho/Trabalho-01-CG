TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += pessoal

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image -lIL

SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    pessoal/objeto.cpp \
    pessoal/peao.cpp \
    pessoal/tabuleiro.cpp \
    pessoal/bispo.cpp \
    pessoal/torre.cpp \
    pessoal/rei.cpp \
    pessoal/rainha.cpp \
    gui_glut/opentextures.cpp \
    pessoal/cavalo.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    pessoal/objeto.h \
    pessoal/peao.h \
    pessoal/tabuleiro.h \
    pessoal/bispo.h \
    pessoal/torre.h \
    pessoal/rei.h \
    pessoal/rainha.h \
    gui_glut/opentextures.h \
    pessoal/cavalo.h
