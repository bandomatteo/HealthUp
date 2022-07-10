#-------------------------------------------------
#
# Project created by QtCreator 2022-06-26T13:41:41
#
#-------------------------------------------------

QT       += core gui
QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HealthUp
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


SOURCES += \
    main.cpp \
    models/piatto.cpp \
    models/item.cpp \
    models/giorno.cpp \
    models/model.cpp \
    models/calendarmodel.cpp \
    helpers/piatti.cpp \
    views/view.cpp \
    views/calendarview.cpp \
    views/chartview.cpp \
    models/piechartmodel.cpp \
    models/barchartmodel.cpp \
    views/piechartview.cpp \
    controllers/controller.cpp \
    controllers/calendarcontroller.cpp \
    controllers/piechartcontroller.cpp \
    helpers/jsonparser.cpp \
    views/barchartview.cpp \
    controllers/barchartcontroller.cpp \
    models/linechartmodel.cpp \
    views/linechartview.cpp \
    controllers/linechartcontroller.cpp

HEADERS += \
    models/piatto.h \
    models/item.h \
    models/giorno.h \
    models/model.h \
    models/calendarmodel.h \
    helpers/piatti.h \
    views/view.h \
    views/calendarview.h \
    views/chartview.h \
    models/piechartmodel.h \
    models/barchartmodel.h \
    views/piechartview.h \
    controllers/controller.h \
    controllers/calendarcontroller.h \
    controllers/piechartcontroller.h \
    helpers/jsonparser.h \
    views/barchartview.h \
    controllers/barchartcontroller.h \
    models/linechartmodel.h \
    views/linechartview.h \
    controllers/linechartcontroller.h

RESOURCES += \
    resources.qrc

QMAKE_LFLAGS += -no-pie

