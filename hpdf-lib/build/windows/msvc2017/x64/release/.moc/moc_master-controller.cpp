/****************************************************************************
** Meta object code from reading C++ file 'master-controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/controllers/master-controller.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'master-controller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_hpdf__controllers__MasterController_t {
    uint offsetsAndSizes[22];
    char stringdata0[36];
    char stringdata1[21];
    char stringdata2[38];
    char stringdata3[14];
    char stringdata4[34];
    char stringdata5[22];
    char stringdata6[39];
    char stringdata7[20];
    char stringdata8[33];
    char stringdata9[28];
    char stringdata10[40];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_hpdf__controllers__MasterController_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_hpdf__controllers__MasterController_t qt_meta_stringdata_hpdf__controllers__MasterController = {
    {
        QT_MOC_LITERAL(0, 35),  // "hpdf::controllers::MasterCont..."
        QT_MOC_LITERAL(36, 20),  // "ui_commandController"
        QT_MOC_LITERAL(57, 37),  // "hpdf::controllers::CommandCon..."
        QT_MOC_LITERAL(95, 13),  // "newOpenedFile"
        QT_MOC_LITERAL(109, 33),  // "hpdf::models::RecentlyOpenedF..."
        QT_MOC_LITERAL(143, 21),  // "ui_databaseController"
        QT_MOC_LITERAL(165, 38),  // "hpdf::controllers::DatabaseCo..."
        QT_MOC_LITERAL(204, 19),  // "ui_pdfImageProvider"
        QT_MOC_LITERAL(224, 32),  // "hpdf::workers::PdfImageProvider*"
        QT_MOC_LITERAL(257, 27),  // "ui_recentlyOpenedFileSearch"
        QT_MOC_LITERAL(285, 39)   // "hpdf::models::RecentlyOpenedF..."
    },
    "hpdf::controllers::MasterController",
    "ui_commandController",
    "hpdf::controllers::CommandController*",
    "newOpenedFile",
    "hpdf::models::RecentlyOpenedFile*",
    "ui_databaseController",
    "hpdf::controllers::DatabaseController*",
    "ui_pdfImageProvider",
    "hpdf::workers::PdfImageProvider*",
    "ui_recentlyOpenedFileSearch",
    "hpdf::models::RecentlyOpenedFileSearch*"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_hpdf__controllers__MasterController[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x00015409, uint(-1), 0,
       3, 0x80000000 | 4, 0x00015409, uint(-1), 0,
       5, 0x80000000 | 6, 0x00015409, uint(-1), 0,
       7, 0x80000000 | 8, 0x00015409, uint(-1), 0,
       9, 0x80000000 | 10, 0x00015409, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject hpdf::controllers::MasterController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_hpdf__controllers__MasterController.offsetsAndSizes,
    qt_meta_data_hpdf__controllers__MasterController,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_hpdf__controllers__MasterController_t,
        // property 'ui_commandController'
        QtPrivate::TypeAndForceComplete<hpdf::controllers::CommandController*, std::true_type>,
        // property 'newOpenedFile'
        QtPrivate::TypeAndForceComplete<hpdf::models::RecentlyOpenedFile*, std::true_type>,
        // property 'ui_databaseController'
        QtPrivate::TypeAndForceComplete<hpdf::controllers::DatabaseController*, std::true_type>,
        // property 'ui_pdfImageProvider'
        QtPrivate::TypeAndForceComplete<hpdf::workers::PdfImageProvider*, std::true_type>,
        // property 'ui_recentlyOpenedFileSearch'
        QtPrivate::TypeAndForceComplete<hpdf::models::RecentlyOpenedFileSearch*, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MasterController, std::true_type>
    >,
    nullptr
} };

void hpdf::controllers::MasterController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hpdf::controllers::CommandController* >(); break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hpdf::controllers::DatabaseController* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hpdf::models::RecentlyOpenedFile* >(); break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hpdf::models::RecentlyOpenedFileSearch* >(); break;
        }
    }
else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MasterController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< hpdf::controllers::CommandController**>(_v) = _t->commandController(); break;
        case 1: *reinterpret_cast< hpdf::models::RecentlyOpenedFile**>(_v) = _t->newOpenedFile(); break;
        case 2: *reinterpret_cast< hpdf::controllers::DatabaseController**>(_v) = _t->databaseController(); break;
        case 3: *reinterpret_cast< hpdf::workers::PdfImageProvider**>(_v) = _t->pdfImageProvider(); break;
        case 4: *reinterpret_cast< hpdf::models::RecentlyOpenedFileSearch**>(_v) = _t->recentlyOpenedFileSearch(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_o;
}

const QMetaObject *hpdf::controllers::MasterController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hpdf::controllers::MasterController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hpdf__controllers__MasterController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int hpdf::controllers::MasterController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
