#-------------------------------------------------------------------------------
# QtOpenGL Root Subdirs
#-------------------------------------------------------------------------------

TEMPLATE = lib
CONFIG += staticlib
TARGET = qtbaseExt
include(../config.pri)

HEADERS = gui/opengl/qopenglfunctions_es3_0.h
SOURCES = gui/opengl/qopenglfunctions_es3_0.cpp
