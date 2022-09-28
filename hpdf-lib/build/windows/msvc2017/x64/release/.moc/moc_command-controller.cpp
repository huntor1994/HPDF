/****************************************************************************
** Meta object code from reading C++ file 'command-controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/controllers/command-controller.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'command-controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_hpdf__controllers__CommandController_t {
    uint offsetsAndSizes[14];
    char stringdata0[37];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[26];
    char stringdata5[24];
    char stringdata6[43];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_hpdf__controllers__CommandController_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_hpdf__controllers__CommandController_t qt_meta_stringdata_hpdf__controllers__CommandController = {
    {
        QT_MOC_LITERAL(0, 36),  // "hpdf::controllers::CommandCon..."
        QT_MOC_LITERAL(37, 23),  // "onOpenFilesSaveExecuted"
        QT_MOC_LITERAL(61, 0),  // ""
        QT_MOC_LITERAL(62, 23),  // "onOpenFilesReadExecuted"
        QT_MOC_LITERAL(86, 25),  // "onOpenFilesDeleteExecuted"
        QT_MOC_LITERAL(112, 23),  // "ui_workAreaViewCommands"
        QT_MOC_LITERAL(136, 42)   // "QQmlListProperty<hpdf::framew..."
    },
    "hpdf::controllers::CommandController",
    "onOpenFilesSaveExecuted",
    "",
    "onOpenFilesReadExecuted",
    "onOpenFilesDeleteExecuted",
    "ui_workAreaViewCommands",
    "QQmlListProperty<hpdf::framework::Command>"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_hpdf__controllers__CommandController[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   35, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    2 /* Public */,
       3,    0,   33,    2, 0x0a,    3 /* Public */,
       4,    0,   34,    2, 0x0a,    4 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x00015409, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject hpdf::controllers::CommandController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_hpdf__controllers__CommandController.offsetsAndSizes,
    qt_meta_data_hpdf__controllers__CommandController,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_hpdf__controllers__CommandController_t,
        // property 'ui_workAreaViewCommands'
        QtPrivate::TypeAndForceComplete<QQmlListProperty<hpdf::framework::Command>, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CommandController, std::true_type>,
        // method 'onOpenFilesSaveExecuted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOpenFilesReadExecuted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOpenFilesDeleteExecuted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void hpdf::controllers::CommandController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommandController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onOpenFilesSaveExecuted(); break;
        case 1: _t->onOpenFilesReadExecuted(); break;
        case 2: _t->onOpenFilesDeleteExecuted(); break;
        default: ;
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CommandController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQmlListProperty<hpdf::framework::Command>*>(_v) = _t->ui_workAreaViewCommands(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *hpdf::controllers::CommandController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hpdf::controllers::CommandController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hpdf__controllers__CommandController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int hpdf::controllers::CommandController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
