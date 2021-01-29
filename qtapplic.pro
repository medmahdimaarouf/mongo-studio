QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    collectionitem.cpp \
    connectionitem.cpp \
    databaseitem.cpp \
    dialogconnect.cpp \
    documentitem.cpp \
    documentview.cpp \
    main.cpp \
    mainwindow.cpp \
    mongodriver.cpp

HEADERS += \
    collectionitem.h \
    connectionitem.h \
    databaseitem.h \
    dialogconnect.h \
    documentitem.h \
    documentview.h \
    mainwindow.h \
    mongodriver.h \
    mongodriverutils.h

FORMS += \
    dialogconnect.ui \
    documentview.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

## #################################### LIB BSON ####################################

# + ********** C *********************
win32: LIBS += -L$$PWD/lib-mongo-cxx/lib/ -llibbson-1.0.dll
INCLUDEPATH += $$PWD/lib-mongo-cxx/include/libbson-1.0
DEPENDPATH += $$PWD/lib-mongo-cxx/include/libbson-1.0
# + ********** C++ *******************
win32: LIBS += -L$$PWD/lib-mongo-cxx/lib/ -llibbsoncxx.dll
INCLUDEPATH += $$PWD/lib-mongo-cxx/include/bsoncxx/v_noabi
DEPENDPATH += $$PWD/lib-mongo-cxx/include/bsoncxx/v_noabi

## ################################### LIB MONGO ####################################

# + ********** C *********************
win32: LIBS += -L$$PWD/lib-mongo-cxx/lib/ -llibmongoc-1.0.dll
INCLUDEPATH += $$PWD/lib-mongo-cxx/include/libmongoc-1.0
DEPENDPATH += $$PWD/lib-mongo-cxx/include/libmongoc-1.0
# + ********** C++ *******************
win32: LIBS += -L$$PWD/lib-mongo-cxx/lib/ -llibmongocxx.dll
INCLUDEPATH += $$PWD/lib-mongo-cxx/include/mongocxx/v_noabi
DEPENDPATH += $$PWD/lib-mongo-cxx/include/mongocxx/v_noabi

#****************************** BOOST *********************************************


win32: LIBS += -LC:/boost/lib/ -lboost_context-mgw8-mt-x64-1_75

INCLUDEPATH += C:/boost/include/boost-1_75
DEPENDPATH += C:/boost/include/boost-1_75

RESOURCES += \
    resource.qrc
