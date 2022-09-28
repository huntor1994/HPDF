/****************************************************************************
** Meta object code from reading C++ file 'recently-opened-file.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/models/recently-opened-file.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recently-opened-file.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_hpdf__models__RecentlyOpenedFile_t {
    uint offsetsAndSizes[20];
    char stringdata0[33];
    char stringdata1[13];
    char stringdata2[31];
    char stringdata3[12];
    char stringdata4[29];
    char stringdata5[13];
    char stringdata6[26];
    char stringdata7[13];
    char stringdata8[14];
    char stringdata9[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_hpdf__models__RecentlyOpenedFile_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_hpdf__models__RecentlyOpenedFile_t qt_meta_stringdata_hpdf__models__RecentlyOpenedFile = {
    {
        QT_MOC_LITERAL(0, 32),  // "hpdf::models::RecentlyOpenedFile"
        QT_MOC_LITERAL(33, 12),  // "ui_closeTime"
        QT_MOC_LITERAL(46, 30),  // "hpdf::data::DateTimeDecorator*"
        QT_MOC_LITERAL(77, 11),  // "ui_filePath"
        QT_MOC_LITERAL(89, 28),  // "hpdf::data::StringDecorator*"
        QT_MOC_LITERAL(118, 12),  // "ui_pageCount"
        QT_MOC_LITERAL(131, 25),  // "hpdf::data::IntDecorator*"
        QT_MOC_LITERAL(157, 12),  // "ui_closePage"
        QT_MOC_LITERAL(170, 13),  // "ui_coverImage"
        QT_MOC_LITERAL(184, 27)   // "hpdf::data::ImageDecorator*"
    },
    "hpdf::models::RecentlyOpenedFile",
    "ui_closeTime",
    "hpdf::data::DateTimeDecorator*",
    "ui_filePath",
    "hpdf::data::StringDecorator*",
    "ui_pageCount",
    "hpdf::data::IntDecorator*",
    "ui_closePage",
    "ui_coverImage",
    "hpdf::data::ImageDecorator*"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_hpdf__models__RecentlyOpenedFile[] = {

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
       7, 0x80000000 | 6, 0x00015409, uint(-1), 0,
       8, 0x80000000 | 9, 0x00015409, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject hpdf::models::RecentlyOpenedFile::staticMetaObject = { {
    QMetaObject::SuperData::link<data::Entity::staticMetaObject>(),
    qt_meta_stringdata_hpdf__models__RecentlyOpenedFile.offsetsAndSizes,
    qt_meta_data_hpdf__models__RecentlyOpenedFile,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_hpdf__models__RecentlyOpenedFile_t,
        // property 'ui_closeTime'
        QtPrivate::TypeAndForceComplete<hpdf::data::DateTimeDecorator*, std::true_type>,
        // property 'ui_filePath'
        QtPrivate::TypeAndForceComplete<hpdf::data::StringDecorator*, std::true_type>,
        // property 'ui_pageCount'
        QtPrivate::TypeAndForceComplete<hpdf::data::IntDecorator*, std::true_type>,
        // property 'ui_closePage'
        QtPrivate::TypeAndForceComplete<hpdf::data::IntDecorator*, std::true_type>,
        // property 'ui_coverImage'
        QtPrivate::TypeAndForceComplete<hpdf::data::ImageDecorator*, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RecentlyOpenedFile, std::true_type>
    >,
    nullptr
} };

void hpdf::models::RecentlyOpenedFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hpdf::data::DateTimeDecorator* >(); break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hpdf::data::ImageDecorator* >(); break;
        case 3:
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hpdf::data::IntDecorator* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hpdf::data::StringDecorator* >(); break;
        }
    }
else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<RecentlyOpenedFile *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< hpdf::data::DateTimeDecorator**>(_v) = _t->closeTime; break;
        case 1: *reinterpret_cast< hpdf::data::StringDecorator**>(_v) = _t->filePath; break;
        case 2: *reinterpret_cast< hpdf::data::IntDecorator**>(_v) = _t->pageCount; break;
        case 3: *reinterpret_cast< hpdf::data::IntDecorator**>(_v) = _t->closePage; break;
        case 4: *reinterpret_cast< hpdf::data::ImageDecorator**>(_v) = _t->coverImage; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_o;
}

const QMetaObject *hpdf::models::RecentlyOpenedFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hpdf::models::RecentlyOpenedFile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hpdf__models__RecentlyOpenedFile.stringdata0))
        return static_cast<void*>(this);
    return data::Entity::qt_metacast(_clname);
}

int hpdf::models::RecentlyOpenedFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = data::Entity::qt_metacall(_c, _id, _a);
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
