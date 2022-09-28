/****************************************************************************
** Meta object code from reading C++ file 'pdf-image-worker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/workers/pdf-image-worker.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pdf-image-worker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_hpdf__workers__PdfImageWorker_t {
    uint offsetsAndSizes[20];
    char stringdata0[30];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[11];
    char stringdata5[10];
    char stringdata6[6];
    char stringdata7[26];
    char stringdata8[8];
    char stringdata9[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_hpdf__workers__PdfImageWorker_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_hpdf__workers__PdfImageWorker_t qt_meta_stringdata_hpdf__workers__PdfImageWorker = {
    {
        QT_MOC_LITERAL(0, 29),  // "hpdf::workers::PdfImageWorker"
        QT_MOC_LITERAL(30, 11),  // "resultReady"
        QT_MOC_LITERAL(42, 0),  // ""
        QT_MOC_LITERAL(43, 18),  // "pageRenderedFinish"
        QT_MOC_LITERAL(62, 10),  // "pageNumber"
        QT_MOC_LITERAL(73, 9),  // "imageSize"
        QT_MOC_LITERAL(83, 5),  // "image"
        QT_MOC_LITERAL(89, 25),  // "QPdfDocumentRenderOptions"
        QT_MOC_LITERAL(115, 7),  // "options"
        QT_MOC_LITERAL(123, 9)   // "requestId"
    },
    "hpdf::workers::PdfImageWorker",
    "resultReady",
    "",
    "pageRenderedFinish",
    "pageNumber",
    "imageSize",
    "image",
    "QPdfDocumentRenderOptions",
    "options",
    "requestId"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_hpdf__workers__PdfImageWorker[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    5,   27,    2, 0x0a,    2 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QSize, QMetaType::QImage, 0x80000000 | 7, QMetaType::ULongLong,    4,    5,    6,    8,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject hpdf::workers::PdfImageWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_hpdf__workers__PdfImageWorker.offsetsAndSizes,
    qt_meta_data_hpdf__workers__PdfImageWorker,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_hpdf__workers__PdfImageWorker_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PdfImageWorker, std::true_type>,
        // method 'resultReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pageRenderedFinish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSize, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPdfDocumentRenderOptions, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint64, std::false_type>
    >,
    nullptr
} };

void hpdf::workers::PdfImageWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PdfImageWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resultReady(); break;
        case 1: _t->pageRenderedFinish((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QImage>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QPdfDocumentRenderOptions>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<quint64>>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 3:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPdfDocumentRenderOptions >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PdfImageWorker::*)();
            if (_t _q_method = &PdfImageWorker::resultReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *hpdf::workers::PdfImageWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hpdf::workers::PdfImageWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hpdf__workers__PdfImageWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int hpdf::workers::PdfImageWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void hpdf::workers::PdfImageWorker::resultReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
