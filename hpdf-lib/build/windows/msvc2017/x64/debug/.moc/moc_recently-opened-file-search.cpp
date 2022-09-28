/****************************************************************************
** Meta object code from reading C++ file 'recently-opened-file-search.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/models/recently-opened-file-search.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recently-opened-file-search.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_hpdf__models__RecentlyOpenedFileSearch_t {
    uint offsetsAndSizes[12];
    char stringdata0[39];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[15];
    char stringdata5[51];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_hpdf__models__RecentlyOpenedFileSearch_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_hpdf__models__RecentlyOpenedFileSearch_t qt_meta_stringdata_hpdf__models__RecentlyOpenedFileSearch = {
    {
        QT_MOC_LITERAL(0, 38),  // "hpdf::models::RecentlyOpenedF..."
        QT_MOC_LITERAL(39, 20),  // "searchResultsChanged"
        QT_MOC_LITERAL(60, 0),  // ""
        QT_MOC_LITERAL(61, 6),  // "search"
        QT_MOC_LITERAL(68, 14),  // "ui_readResults"
        QT_MOC_LITERAL(83, 50)   // "QQmlListProperty<hpdf::models..."
    },
    "hpdf::models::RecentlyOpenedFileSearch",
    "searchResultsChanged",
    "",
    "search",
    "ui_readResults",
    "QQmlListProperty<hpdf::models::RecentlyOpenedFile>"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_hpdf__models__RecentlyOpenedFileSearch[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   27,    2, 0x0a,    3 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       4, 0x80000000 | 5, 0x00015009, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject hpdf::models::RecentlyOpenedFileSearch::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_hpdf__models__RecentlyOpenedFileSearch.offsetsAndSizes,
    qt_meta_data_hpdf__models__RecentlyOpenedFileSearch,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_hpdf__models__RecentlyOpenedFileSearch_t,
        // property 'ui_readResults'
        QtPrivate::TypeAndForceComplete<QQmlListProperty<hpdf::models::RecentlyOpenedFile>, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RecentlyOpenedFileSearch, std::true_type>,
        // method 'searchResultsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'search'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void hpdf::models::RecentlyOpenedFileSearch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RecentlyOpenedFileSearch *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->searchResultsChanged(); break;
        case 1: _t->search(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RecentlyOpenedFileSearch::*)();
            if (_t _q_method = &RecentlyOpenedFileSearch::searchResultsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<RecentlyOpenedFileSearch *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQmlListProperty<hpdf::models::RecentlyOpenedFile>*>(_v) = _t->readResults(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *hpdf::models::RecentlyOpenedFileSearch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hpdf::models::RecentlyOpenedFileSearch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hpdf__models__RecentlyOpenedFileSearch.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int hpdf::models::RecentlyOpenedFileSearch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void hpdf::models::RecentlyOpenedFileSearch::searchResultsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
