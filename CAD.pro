#-------------------------------------------------
#
# Project created by QtCreator 2018-04-05T18:23:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CAD
TEMPLATE = app
CONFIG += c++11

DESTDIR=bin #Target file directory
OBJECTS_DIR= build #Intermediate object files directory
MOC_DIR=build#Intermediate moc files directory

SOURCES += \
    src/basicLoopEdgeSet.cpp \
    src/bodyLoop.cpp \
    src/EdgeList2D.cpp \
    src/faceLoop.cpp \
    src/generalMethods.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/options.cpp \
    src/Plane.cpp \
    src/selection.cpp \
    src/showprojections.cpp \
    src/structs.cpp \
    src/TwoDObj.cpp \
    src/VertexList2D.cpp \
    src/wireframe.cpp

HEADERS  += \
    include/basicLoopEdgeSet.h \
    include/bodyLoop.h \
    include/EdgeList2D.h \
    include/faceLoop.h \
    include/generalMethods.h \
    include/mainwindow.h \
    include/options.h \
    include/Plane.h \
    include/selection.h \
    include/showprojections.h \
    include/structs.h \
    include/TwoDObj.h \
    include/ui_mainwindow.h \
    include/ui_selection.h \
    include/ui_showprojections.h \
    include/VertexList2D.h \
    include/wireframe.h

FORMS    += \
    include/selection.ui \
    include/mainwindow.ui \
    include/showprojections.ui
