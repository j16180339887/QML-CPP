unix:!android {
    isEmpty(target.path) {
        qnx {
            target.path = /tmp/$${TARGET}/bin
        } else {
            target.path = /opt/$${TARGET}/bin
        }
        export(target.path)
    }
    INSTALLS += target
}

export(INSTALLS)

SOURCES += BackEnd/main.cpp \
    BackEnd/MainWindow.cpp \
    BackEnd/SettingDialog.cpp \
    BackEnd/NewDialog.cpp

HEADERS += \
    BackEnd/MainWindow.hpp \
    BackEnd/SettingDialog.hpp \
    BackEnd/NewDialog.hpp

FORMS += \
    FrontEnd/QML.ui \
    FrontEnd/SettingDialog.ui \
    FrontEnd/NewDialog.ui
