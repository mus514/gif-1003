TEMPLATE = app
TARGET = ElectionsGUI
QT += core \
    gui
HEADERS += desinscriptioninterface.h \
    candidatinterface.h \
    electeurinterface.h \
    electionsgui.h
SOURCES += desinscriptioninterface.cpp \
    candidatinterface.cpp \
    electeurinterface.cpp \
    main.cpp \
    electionsgui.cpp
FORMS += desinscriptioninterface.ui \
    candidatinterface.ui \
    electeurinterface.ui \
    electionsgui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
