QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formnowtime.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowcalendar.cpp \
    mainwindownote.cpp \
    mainwindowpet.cpp \
    mainwindowtimer.cpp

HEADERS += \
    formnowtime.h \
    mainwindow.h \
    mainwindowcalendar.h \
    mainwindownote.h \
    mainwindowpet.h \
    mainwindowtimer.h

FORMS += \
    formnowtime.ui \
    mainwindow.ui \
    mainwindowcalendar.ui \
    mainwindownote.ui \
    mainwindowpet.ui \
    mainwindowtimer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
#设置图标
RC_ICONS += icon2.ico

RESOURCES += \
    logo.qrc \
    mainIcons.qrc \
    pet.qrc

DISTFILES += \
    mainIcons/宠物.png \
    mainIcons/日历.png \
    mainIcons/更多.png \
    mainIcons/表单.png \
    mainIcons/选择时间段.png



