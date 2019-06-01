#-------------------------------------------------
#
# Project created by QtCreator 2019-05-28T16:12:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FilmApp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        add.cpp \
        datamodel.cpp \
        discover.cpp \
        error.cpp \
        exportwindow.cpp \
        film.cpp \
        filmalreadyaddedexception.cpp \
        filmalreadyinwatchlistexception.cpp \
        filmnotfoundexception.cpp \
        filmnotvalidexception.cpp \
        filmsmodel.cpp \
        filmtitletakenexception.cpp \
        main.cpp \
        mainwindow.cpp \
        modify.cpp \
        myexception.cpp \
        rate.cpp \
        repository.cpp \
        repositoryfilm.cpp \
        repositorywatchlist.cpp \
        validate.cpp \
        watchlistmodel.cpp

HEADERS += \
        add.h \
        datamodel.h \
        discover.h \
        error.h \
        exportwindow.h \
        film.h \
        filmalreadyaddedexception.h \
        filmalreadyinwatchlistexception.h \
        filmnotfoundexception.h \
        filmnotvalidexception.h \
        filmsmodel.h \
        filmtitletakenexception.h \
        mainwindow.h \
        modify.h \
        myexception.h \
        rate.h \
        repository.h \
        repositoryfilm.h \
        repositorywatchlist.h \
        validate.h \
        watchlistmodel.h

FORMS += \
        add.ui \
        discover.ui \
        error.ui \
        exportwindow.ui \
        mainwindow.ui \
        modify.ui \
        rate.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
