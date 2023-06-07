QT += testlib network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_exam.cpp \
    ../server/functions.cpp \
    ../server/mytcpserver.cpp

HEADERS += \
    ../server/functions.h \
    ../server/mytcpserver.h
