/****************************************************************************
** Meta object code from reading C++ file 'windowbutton.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widgetframe/windowbutton.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowbutton.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQWKSCOPEWindowButtonENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQWKSCOPEWindowButtonENDCLASS = QtMocHelpers::stringData(
    "QWK::WindowButton",
    "doubleClicked",
    "",
    "iconNormal",
    "iconChecked",
    "iconDisabled"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQWKSCOPEWindowButtonENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       3,   21, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
       3, QMetaType::QIcon, 0x00015903, uint(-1), 0,
       4, QMetaType::QIcon, 0x00015903, uint(-1), 0,
       5, QMetaType::QIcon, 0x00015903, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QWK::WindowButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_CLASSQWKSCOPEWindowButtonENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQWKSCOPEWindowButtonENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQWKSCOPEWindowButtonENDCLASS_t,
        // property 'iconNormal'
        QtPrivate::TypeAndForceComplete<QIcon, std::true_type>,
        // property 'iconChecked'
        QtPrivate::TypeAndForceComplete<QIcon, std::true_type>,
        // property 'iconDisabled'
        QtPrivate::TypeAndForceComplete<QIcon, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WindowButton, std::true_type>,
        // method 'doubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QWK::WindowButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindowButton *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->doubleClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WindowButton::*)();
            if (_t _q_method = &WindowButton::doubleClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<WindowButton *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QIcon*>(_v) = _t->iconNormal(); break;
        case 1: *reinterpret_cast< QIcon*>(_v) = _t->iconChecked(); break;
        case 2: *reinterpret_cast< QIcon*>(_v) = _t->iconDisabled(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<WindowButton *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIconNormal(*reinterpret_cast< QIcon*>(_v)); break;
        case 1: _t->setIconChecked(*reinterpret_cast< QIcon*>(_v)); break;
        case 2: _t->setIconDisabled(*reinterpret_cast< QIcon*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *QWK::WindowButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWK::WindowButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQWKSCOPEWindowButtonENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int QWK::WindowButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QWK::WindowButton::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
