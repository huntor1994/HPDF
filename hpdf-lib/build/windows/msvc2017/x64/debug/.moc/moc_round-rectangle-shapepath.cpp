/****************************************************************************
** Meta object code from reading C++ file 'round-rectangle-shapepath.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/shape/round-rectangle-shapepath.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'round-rectangle-shapepath.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_RoundRectangleShapePath_t {
    uint offsetsAndSizes[14];
    char stringdata0[24];
    char stringdata1[13];
    char stringdata2[12];
    char stringdata3[13];
    char stringdata4[14];
    char stringdata5[16];
    char stringdata6[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_RoundRectangleShapePath_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_RoundRectangleShapePath_t qt_meta_stringdata_RoundRectangleShapePath = {
    {
        QT_MOC_LITERAL(0, 23),  // "RoundRectangleShapePath"
        QT_MOC_LITERAL(24, 12),  // "RoundCorners"
        QT_MOC_LITERAL(37, 11),  // "RoundCorner"
        QT_MOC_LITERAL(49, 12),  // "UpLeftCorner"
        QT_MOC_LITERAL(62, 13),  // "UpRightCorner"
        QT_MOC_LITERAL(76, 15),  // "DownRightCorner"
        QT_MOC_LITERAL(92, 14)   // "DownLeftCorner"
    },
    "RoundRectangleShapePath",
    "RoundCorners",
    "RoundCorner",
    "UpLeftCorner",
    "UpRightCorner",
    "DownRightCorner",
    "DownLeftCorner"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_RoundRectangleShapePath[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    2, 0x1,    4,   19,

 // enum data: key, value
       3, uint(RoundRectangleShapePath::UpLeftCorner),
       4, uint(RoundRectangleShapePath::UpRightCorner),
       5, uint(RoundRectangleShapePath::DownRightCorner),
       6, uint(RoundRectangleShapePath::DownLeftCorner),

       0        // eod
};

Q_CONSTINIT const QMetaObject RoundRectangleShapePath::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RoundRectangleShapePath.offsetsAndSizes,
    qt_meta_data_RoundRectangleShapePath,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_RoundRectangleShapePath_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RoundRectangleShapePath, std::true_type>
    >,
    nullptr
} };

void RoundRectangleShapePath::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *RoundRectangleShapePath::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoundRectangleShapePath::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RoundRectangleShapePath.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RoundRectangleShapePath::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
