/****************************************************************************
** Meta object code from reading C++ file 'usrsellgood.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../usrsellgood.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usrsellgood.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_usrSellGood_t {
    QByteArrayData data[7];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_usrSellGood_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_usrSellGood_t qt_meta_stringdata_usrSellGood = {
    {
QT_MOC_LITERAL(0, 0, 11), // "usrSellGood"
QT_MOC_LITERAL(1, 12, 11), // "sell_signal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 13), // "my_jump_slots"
QT_MOC_LITERAL(4, 39, 8), // "Btn_slot"
QT_MOC_LITERAL(5, 48, 14), // "connected_slot"
QT_MOC_LITERAL(6, 63, 14) // "readyRead_slot"

    },
    "usrSellGood\0sell_signal\0\0my_jump_slots\0"
    "Btn_slot\0connected_slot\0readyRead_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_usrSellGood[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void usrSellGood::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        usrSellGood *_t = static_cast<usrSellGood *>(_o);
        switch (_id) {
        case 0: _t->sell_signal(); break;
        case 1: _t->my_jump_slots(); break;
        case 2: _t->Btn_slot(); break;
        case 3: _t->connected_slot(); break;
        case 4: _t->readyRead_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (usrSellGood::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usrSellGood::sell_signal)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject usrSellGood::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_usrSellGood.data,
      qt_meta_data_usrSellGood,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *usrSellGood::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *usrSellGood::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_usrSellGood.stringdata))
        return static_cast<void*>(const_cast< usrSellGood*>(this));
    return QWidget::qt_metacast(_clname);
}

int usrSellGood::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void usrSellGood::sell_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
