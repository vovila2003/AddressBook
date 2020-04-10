QT -= gui
QT += core sql
CONFIG += c++11
TEMPLATE = lib

DEFINES += BUILD_TESTS

DESTDIR =  $$PWD/../shared/lib

INCLUDEPATH += $$PWD/include
HEADERS += \
    include/ConnectionManager.h \
    include/Executor.h \
    include/Manipulator.h \
    include/Processor.h \
    include/Selector.h \
    include/dbmapper.h \
    include/dbtypes.h

SOURCES += \
    src/ConnectionManager.cpp \
    src/Executor.cpp \
    src/Manipulator.cpp \
    src/Processor.cpp \
    src/Selector.cpp

headers.path = $$PWD/../shared/include
headers.files = include/dbtypes.h \
                include/Processor.h
INSTALLS +=headers
