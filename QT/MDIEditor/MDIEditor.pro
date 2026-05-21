QT       += core gui widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MDIEditor
TEMPLATE = app

SOURCES += \
    abstractdocument.cpp \
    main.cpp \
    abstractdocument.cpp \
    mdieditorframework.cpp \
    mdieditorframework.cpp

HEADERS += \
    abstractdocument.h \
    abstractdocument.h \
    mdieditorframework.h \
    mdieditorframework.h

FORMS += \
    mdieditorframework.ui