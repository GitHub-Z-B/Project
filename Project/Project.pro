QT += core gui widgets network sql openglwidgets charts

CONFIG += c++17

include(widgetframe/widgetframe.pri)

include(ffmpeg/ffmpeg.pri)

SOURCES += \
    Analyzeresults/verticalbarchart.cpp \
    EvaluationAlgorithms/evaluationalgorithms.cpp \
    adduserwidget.cpp \
    answerlistitem.cpp \
    configlistitem.cpp \
    confirmdialog.cpp \
    coordinatedialog.cpp \
    dynamicdatawidget.cpp \
    evaluatewidget.cpp \
    eventchilditem.cpp \
    eventitem.cpp \
    experimentaldata.cpp \
    main.cpp \
    mainwindow.cpp \
    questionitem.cpp \
    questionlistitem.cpp \
    questionnairebankmodel.cpp \
    questionnairelistitem.cpp \
    questionnairemanagementwidget.cpp \
    questiontypedialog.cpp \
    replaylistitem.cpp \
    replaywidget.cpp \
    screenimportitem.cpp \
    tasklistitem.cpp \
    taskwidget.cpp \
    triggeractiondialog.cpp \
    usermanagementwidget.cpp \
    userquery.cpp

HEADERS += \
    Analyzeresults/verticalbarchart.h \
    EvaluationAlgorithms/evaluationalgorithms.h \
    adduserwidget.h \
    answerlistitem.h \
    configlistitem.h \
    confirmdialog.h \
    coordinatedialog.h \
    dynamicdatawidget.h \
    evaluatewidget.h \
    eventchilditem.h \
    eventitem.h \
    experimentaldata.h \
    icd.h \
    mainwindow.h \
    packet.h \
    questionitem.h \
    questionlistitem.h \
    questionnairebankmodel.h \
    questionnairelistitem.h \
    questionnairemanagementwidget.h \
    questiontypedialog.h \
    replaylistitem.h \
    replaywidget.h \
    screenimportitem.h \
    tasklistitem.h \
    taskwidget.h \
    triggeractiondialog.h \
    usermanagementwidget.h \
    userquery.h

FORMS += \
    Analyzeresults/verticalbarchart.ui \
    EvaluationAlgorithms/evaluationalgorithms.ui \
    adduserwidget.ui \
    answerlistitem.ui \
    configlistitem.ui \
    confirmdialog.ui \
    evaluatewidget.ui \
    eventchilditem.ui \
    eventitem.ui \
    mainwindow.ui \
    questionitem.ui \
    questionlistitem.ui \
    questionnairelistitem.ui \
    questionnairemanagementwidget.ui \
    questiontypedialog.ui \
    replaylistitem.ui \
    replaywidget.ui \
    screenimportitem.ui \
    tasklistitem.ui \
    taskwidget.ui \
    triggeractiondialog.ui \
    usermanagementwidget.ui

RESOURCES += \
    res/mainwindow.qrc
