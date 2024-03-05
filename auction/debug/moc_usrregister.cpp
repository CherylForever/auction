/****************************************************************************
** Meta object code from reading C++ file 'usrregister.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../usrregister.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usrregister.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_usrRegister_t {
    QByteArrayData data[7];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_usrRegister_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_usrRegister_t qt_meta_stringdata_usrRegister = {
    {
QT_MOC_LITERAL(0, 0, 11), // "usrRegister"
QT_MOC_LITERAL(1, 12, 13), // "my_jump_slots"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "regiBtn_clicked"
QT_MOC_LITERAL(4, 43, 14), // "connected_slot"
QT_MOC_LITERAL(5, 58, 14), // "readyRead_slot"
QT_MOC_LITERAL(6, 73, 17) // "disconnected_slot"

    },
    "usrRegister\0my_jump_slots\0\0regiBtn_clicked\0"
    "connected_slot\0readyRead_slot\0"
    "disconnected_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_usrRegister[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void usrRegister::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        usrRegister *_t = static_cast<usrRegister *>(_o);
        switch (_id) {
        case 0: _t->my_jump_slots(); break;
        case 1: _t->regiBtn_clicked(); break;
        case 2: _t->connected_slot(); break;
        case 3: _t->readyRead_slot(); break;
        case 4: _t->disconnected_slot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject usrRegister::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_usrRegister.data,
      qt_meta_data_usrRegister,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *usrRegister::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *usrRegister::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_usrRegister.stringdata))
        return static_cast<void*>(const_cast< usrRegister*>(this));
    return QWidget::qt_metacast(_clname);
}

int usrRegister::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
