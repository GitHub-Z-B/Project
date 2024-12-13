/****************************************************************************
** Meta object code from reading C++ file 'taskwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../taskwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'taskwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTaskWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTaskWidgetENDCLASS = QtMocHelpers::stringData(
    "TaskWidget",
    "closeExe",
    "",
    "startTask",
    "SendStartFlag",
    "flag",
    "getTriggerTime",
    "readyRead",
    "task_start",
    "task_edit",
    "task_delete",
    "on_bind_btn_clicked",
    "initUserComboxAndTaskCombox",
    "setReceivingEnabled",
    "enabled",
    "ToJLConfig",
    "on_add_task_clicked",
    "on_buttonReturn_clicked",
    "on_buttonSave_clicked",
    "on_config_clicked",
    "on_addConfig_clicked",
    "on_configSave_clicked",
    "on_buttonBack_clicked",
    "on_buttonOpen_clicked",
    "on_add_question_clicked",
    "on_add_event_clicked",
    "on_task_return_clicked",
    "on_task_finish_clicked",
    "on_checkBox_type_left_clicked",
    "on_checkBox_type_right_clicked",
    "on_finish_edit_clicked",
    "on_return_JL_btn_clicked",
    "handleReadyRead",
    "getJsonFilenames",
    "QDir",
    "directory",
    "init_JL_List",
    "findJsonFiles",
    "deleteJsonFile",
    "fileName",
    "on_OpenExe_btn_clicked",
    "on_SetPosition_btn_clicked",
    "on_SetPosition_btn_clicked2",
    "on_CloseExe_btn__clicked",
    "on_StartJL_btn_clicked",
    "on_StopJL_btn_clicked",
    "on_JL_Combox_activated",
    "index",
    "on_StartTask_btn_clicked",
    "on_TaskConfig_clicked",
    "onCheckBoxToggled",
    "checked",
    "on_SetPosition_btn_2_clicked",
    "on_CloseExe_btn_1_clicked",
    "on_return_Task_btn_clicked",
    "on_task_Combox_currentTextChanged",
    "arg1",
    "on_create_task_clicked",
    "on_return_btn_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTaskWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  308,    2, 0x06,    1 /* Public */,
       3,    0,  309,    2, 0x06,    2 /* Public */,
       4,    1,  310,    2, 0x06,    3 /* Public */,
       6,    0,  313,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,  314,    2, 0x0a,    6 /* Public */,
       8,    0,  315,    2, 0x0a,    7 /* Public */,
       9,    0,  316,    2, 0x0a,    8 /* Public */,
      10,    0,  317,    2, 0x0a,    9 /* Public */,
      11,    0,  318,    2, 0x0a,   10 /* Public */,
      12,    0,  319,    2, 0x0a,   11 /* Public */,
      13,    1,  320,    2, 0x0a,   12 /* Public */,
      15,    0,  323,    2, 0x0a,   14 /* Public */,
      16,    0,  324,    2, 0x08,   15 /* Private */,
      17,    0,  325,    2, 0x08,   16 /* Private */,
      18,    0,  326,    2, 0x08,   17 /* Private */,
      19,    0,  327,    2, 0x08,   18 /* Private */,
      20,    0,  328,    2, 0x08,   19 /* Private */,
      21,    0,  329,    2, 0x08,   20 /* Private */,
      22,    0,  330,    2, 0x08,   21 /* Private */,
      23,    0,  331,    2, 0x08,   22 /* Private */,
      24,    0,  332,    2, 0x08,   23 /* Private */,
      25,    0,  333,    2, 0x08,   24 /* Private */,
      26,    0,  334,    2, 0x08,   25 /* Private */,
      27,    0,  335,    2, 0x08,   26 /* Private */,
      28,    0,  336,    2, 0x08,   27 /* Private */,
      29,    0,  337,    2, 0x08,   28 /* Private */,
      30,    0,  338,    2, 0x08,   29 /* Private */,
      31,    0,  339,    2, 0x08,   30 /* Private */,
      32,    0,  340,    2, 0x08,   31 /* Private */,
      33,    1,  341,    2, 0x08,   32 /* Private */,
      36,    0,  344,    2, 0x08,   34 /* Private */,
      37,    1,  345,    2, 0x08,   35 /* Private */,
      38,    2,  348,    2, 0x08,   37 /* Private */,
      40,    0,  353,    2, 0x08,   40 /* Private */,
      41,    0,  354,    2, 0x08,   41 /* Private */,
      42,    0,  355,    2, 0x08,   42 /* Private */,
      43,    0,  356,    2, 0x08,   43 /* Private */,
      44,    0,  357,    2, 0x08,   44 /* Private */,
      45,    0,  358,    2, 0x08,   45 /* Private */,
      46,    1,  359,    2, 0x08,   46 /* Private */,
      48,    0,  362,    2, 0x08,   48 /* Private */,
      49,    0,  363,    2, 0x08,   49 /* Private */,
      50,    1,  364,    2, 0x08,   50 /* Private */,
      52,    0,  367,    2, 0x08,   52 /* Private */,
      53,    0,  368,    2, 0x08,   53 /* Private */,
      54,    0,  369,    2, 0x08,   54 /* Private */,
      55,    1,  370,    2, 0x08,   55 /* Private */,
      57,    0,  373,    2, 0x08,   57 /* Private */,
      58,    0,  374,    2, 0x08,   58 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QStringList, 0x80000000 | 34,   35,
    QMetaType::Void,
    QMetaType::QStringList, 0x80000000 | 34,   35,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 34,   39,   35,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TaskWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSTaskWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTaskWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTaskWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TaskWidget, std::true_type>,
        // method 'closeExe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startTask'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SendStartFlag'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getTriggerTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'task_start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'task_edit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'task_delete'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bind_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initUserComboxAndTaskCombox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setReceivingEnabled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ToJLConfig'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_add_task_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buttonReturn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buttonSave_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_config_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_configSave_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buttonBack_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buttonOpen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_add_question_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_add_event_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_task_return_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_task_finish_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_type_left_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_type_right_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_finish_edit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_return_JL_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getJsonFilenames'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDir &, std::false_type>,
        // method 'init_JL_List'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'findJsonFiles'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDir &, std::false_type>,
        // method 'deleteJsonFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDir &, std::false_type>,
        // method 'on_OpenExe_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SetPosition_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SetPosition_btn_clicked2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CloseExe_btn__clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_StartJL_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_StopJL_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_JL_Combox_activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_StartTask_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_TaskConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCheckBoxToggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_SetPosition_btn_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CloseExe_btn_1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_return_Task_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_task_Combox_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_create_task_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_return_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TaskWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TaskWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->closeExe(); break;
        case 1: _t->startTask(); break;
        case 2: _t->SendStartFlag((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->getTriggerTime(); break;
        case 4: _t->readyRead(); break;
        case 5: _t->task_start(); break;
        case 6: _t->task_edit(); break;
        case 7: _t->task_delete(); break;
        case 8: _t->on_bind_btn_clicked(); break;
        case 9: _t->initUserComboxAndTaskCombox(); break;
        case 10: _t->setReceivingEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->ToJLConfig(); break;
        case 12: _t->on_add_task_clicked(); break;
        case 13: _t->on_buttonReturn_clicked(); break;
        case 14: _t->on_buttonSave_clicked(); break;
        case 15: _t->on_config_clicked(); break;
        case 16: _t->on_addConfig_clicked(); break;
        case 17: _t->on_configSave_clicked(); break;
        case 18: _t->on_buttonBack_clicked(); break;
        case 19: _t->on_buttonOpen_clicked(); break;
        case 20: _t->on_add_question_clicked(); break;
        case 21: _t->on_add_event_clicked(); break;
        case 22: _t->on_task_return_clicked(); break;
        case 23: _t->on_task_finish_clicked(); break;
        case 24: _t->on_checkBox_type_left_clicked(); break;
        case 25: _t->on_checkBox_type_right_clicked(); break;
        case 26: _t->on_finish_edit_clicked(); break;
        case 27: _t->on_return_JL_btn_clicked(); break;
        case 28: _t->handleReadyRead(); break;
        case 29: { QStringList _r = _t->getJsonFilenames((*reinterpret_cast< std::add_pointer_t<QDir>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->init_JL_List(); break;
        case 31: { QStringList _r = _t->findJsonFiles((*reinterpret_cast< std::add_pointer_t<QDir>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 32: _t->deleteJsonFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDir>>(_a[2]))); break;
        case 33: _t->on_OpenExe_btn_clicked(); break;
        case 34: _t->on_SetPosition_btn_clicked(); break;
        case 35: _t->on_SetPosition_btn_clicked2(); break;
        case 36: _t->on_CloseExe_btn__clicked(); break;
        case 37: _t->on_StartJL_btn_clicked(); break;
        case 38: _t->on_StopJL_btn_clicked(); break;
        case 39: _t->on_JL_Combox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 40: _t->on_StartTask_btn_clicked(); break;
        case 41: _t->on_TaskConfig_clicked(); break;
        case 42: _t->onCheckBoxToggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 43: _t->on_SetPosition_btn_2_clicked(); break;
        case 44: _t->on_CloseExe_btn_1_clicked(); break;
        case 45: _t->on_return_Task_btn_clicked(); break;
        case 46: _t->on_task_Combox_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 47: _t->on_create_task_clicked(); break;
        case 48: _t->on_return_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TaskWidget::*)();
            if (_t _q_method = &TaskWidget::closeExe; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TaskWidget::*)();
            if (_t _q_method = &TaskWidget::startTask; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TaskWidget::*)(bool );
            if (_t _q_method = &TaskWidget::SendStartFlag; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TaskWidget::*)();
            if (_t _q_method = &TaskWidget::getTriggerTime; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *TaskWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTaskWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TaskWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 49)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 49;
    }
    return _id;
}

// SIGNAL 0
void TaskWidget::closeExe()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TaskWidget::startTask()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TaskWidget::SendStartFlag(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TaskWidget::getTriggerTime()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
