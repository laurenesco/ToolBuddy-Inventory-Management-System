QT       += core gui widgets multimedia multimediawidgets sql

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_item.cpp \
    data_dictionary.cpp \
    edit_item.cpp \
    main.cpp \
    main_menu.cpp \
    qr_search.cpp \
    search_results.cpp


HEADERS += \
    add_item.h \
    data_dictionary.h \
    edit_item.h \
    main_menu.h \
    qr_search.h \
    search_results.h


FORMS += \
    add_item.ui \
    data_dictionary.ui \
    edit_item.ui \
    main_menu.ui \
    qr_search.ui \
    search_results.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
