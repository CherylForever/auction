/****************************************************************************
** Meta object code from reading C++ file 'usrlogin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../usrlogin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usrlogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_usrLogin_t {
    QByteArrayData data[9];
    char stringdata[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_usrLogin_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_usrLogin_t qt_meta_stringdata_usrLogin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "usrLogin"
QT_MOC_LITERAL(1, 9, 9), // "regi_jump"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "usr_jump"
QT_MOC_LITERAL(4, 29, 13), // "my_jump_slots"
QT_MOC_LITERAL(5, 43, 14), // "loginBtn_slots"
QT_MOC_LITERAL(6, 58, 13), // "regiBtn_slots"
QT_MOC_LITERAL(7, 72, 14), // "connected_slot"
QT_MOC_LITERAL(8, 87, 14) // "readyRead_slot"

    },
    "usrLogin\0regi_jump\0\0usr_jump\0my_jump_slots\0"
    "loginBtn_slots\0regiBtn_slots\0"
    "connected_slot\0readyRead_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_usrLogin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void usrLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        usrLogin *_t = static_cast<usrLogin *>(_o);
        switch (_id) {
        case 0: _t->regi_jump(); break;
        case 1: _t->usr_jump(); break;
        case 2: _t->my_jump_slots(); break;
        case 3: _t->loginBtn_slots(); break;
        case 4: _t->regiBtn_slots(); break;
        case 5: _t->connected_slot(); break;
        case 6: _t->readyRead_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (usrLogin::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usrLogin::regi_jump)) {
                *result = 0;
            }
        }
        {
            typedef void (usrLogin::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usrLogin::usr_jump)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject usrLogin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_usrLogin.data,
      qt_meta_data_usrLogin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *usrLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *usrLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_usrLogin.stringdata))
        return static_cast<void*>(const_cast< usrLogin*>(this));
    return QWidget::qt_metacast(_clname);
}

int usrLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void usrLogin::regi_jump()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void usrLogin::usr_jump()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
