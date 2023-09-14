QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


SOURCES += \
    ChatWindow.cpp \
    Client.cpp \
    InputChecker.cpp \
    LoginWindow.cpp \
    RegistrationWindow.cpp \
    SHA_1_Wrapper.cpp \
    ScreenController.cpp \
    main.cpp

HEADERS += \
    ChatWindow.h \
    Client.h \
    InputChecker.h \
    LoginWindow.h \
    RegistrationWindow.h \
    SHA_1_Wrapper.h \
    ScreenController.h \
    sha1.hpp

FORMS += \
    ChatWindow.ui \
    LoginWindow.ui \
    RegistrationWindow.ui \
    ScreenController.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
