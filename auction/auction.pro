#-------------------------------------------------
#
# Project created by QtCreator 2024-02-29T09:56:38
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = auction
TEMPLATE = app


SOURCES += main.cpp\
    adminwidget.cpp \
        widget.cpp \
    usrlogin.cpp \
    adminlogin.cpp \
    usrregister.cpp \
    usrwidget.cpp \
    usrinsertdate.cpp \
    usrdeletedate.cpp \
    usrupdatedate.cpp \
    usrauctable.cpp \
    usrbuygoods.cpp \
    adminprofit.cpp \
    usrsellgood.cpp \
    adminupdate.cpp \
    admindelete.cpp \
    adminallgood.cpp

HEADERS  += widget.h \
    adminwidget.h \
    usrlogin.h \
    adminlogin.h \
    usrregister.h \
    struct.h \
    usrwidget.h \
    usrinsertdate.h \
    usrdeletedate.h \
    usrupdatedate.h \
    usrauctable.h \
    usrbuygoods.h \
    adminprofit.h \
    usrsellgood.h \
    adminupdate.h \
    admindelete.h \
    adminallgood.h

FORMS    += widget.ui \
    adminwidget.ui \
    usrlogin.ui \
    adminlogin.ui \
    usrregister.ui \
    usrwidget.ui \
    usrinsertdate.ui \
    usrdeletedate.ui \
    usrupdatedate.ui \
    usrauctable.ui \
    usrbuygoods.ui \
    adminprofit.ui \
    usrsellgood.ui \
    adminupdate.ui \
    admindelete.ui \
    adminallgood.ui

RESOURCES += \
    src.qrc
