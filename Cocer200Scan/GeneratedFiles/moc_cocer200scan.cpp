/****************************************************************************
** Meta object code from reading C++ file 'cocer200scan.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cocer200scan.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cocer200scan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cs200__Cocer200Scan_t {
    QByteArrayData data[11];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cs200__Cocer200Scan_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cs200__Cocer200Scan_t qt_meta_stringdata_cs200__Cocer200Scan = {
    {
QT_MOC_LITERAL(0, 0, 19), // "cs200::Cocer200Scan"
QT_MOC_LITERAL(1, 20, 11), // "InfoChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "eDeviceInfo"
QT_MOC_LITERAL(4, 45, 4), // "info"
QT_MOC_LITERAL(5, 50, 14), // "ImageGenerated"
QT_MOC_LITERAL(6, 65, 6), // "uchar*"
QT_MOC_LITERAL(7, 72, 7), // "fImgBuf"
QT_MOC_LITERAL(8, 80, 7), // "fBufLen"
QT_MOC_LITERAL(9, 88, 7), // "bImgBuf"
QT_MOC_LITERAL(10, 96, 7) // "bBufLen"

    },
    "cs200::Cocer200Scan\0InfoChanged\0\0"
    "eDeviceInfo\0info\0ImageGenerated\0uchar*\0"
    "fImgBuf\0fBufLen\0bImgBuf\0bBufLen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cs200__Cocer200Scan[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       5,    4,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int, 0x80000000 | 6, QMetaType::Int,    7,    8,    9,   10,

       0        // eod
};

void cs200::Cocer200Scan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cocer200Scan *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->InfoChanged((*reinterpret_cast< eDeviceInfo(*)>(_a[1]))); break;
        case 1: _t->ImageGenerated((*reinterpret_cast< uchar*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< uchar*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cocer200Scan::*)(eDeviceInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cocer200Scan::InfoChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Cocer200Scan::*)(uchar * , int , uchar * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cocer200Scan::ImageGenerated)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cs200::Cocer200Scan::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_cs200__Cocer200Scan.data,
    qt_meta_data_cs200__Cocer200Scan,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cs200::Cocer200Scan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cs200::Cocer200Scan::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cs200__Cocer200Scan.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cs200::Cocer200Scan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void cs200::Cocer200Scan::InfoChanged(eDeviceInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cs200::Cocer200Scan::ImageGenerated(uchar * _t1, int _t2, uchar * _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
