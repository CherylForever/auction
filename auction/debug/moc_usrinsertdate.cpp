/****************************************************************************
** Meta object code from reading C++ file 'usrinsertdate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../usrinsertdate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usrinsertdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_usrInsertDate_t {
    QByteArrayData data[7];
    char stringdata[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_usrInsertDate_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_usrInsertDate_t qt_meta_stringdata_usrInsertDate = {
    {
QT_MOC_LITERAL(0, 0, 13), // "usrInsertDate"
QT_MOC_LITERAL(1, 14, 21), // "inserttowidget_signal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "my_jump_slots"
QT_MOC_LITERAL(4, 51, 8), // "Btn_slot"
QT_MOC_LITERAL(5, 60, 14), // "connected_slot"
QT_MOC_LITERAL(6, 75, 14) // "readyRead_slot"

    },
    "usrInsertDate\0inserttowidget_signal\0"
    "\0my_jump_slots\0Btn_slot\0connected_slot\0"
    "readyRead_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_usrInsertDate[] = {

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

void usrInsertDate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        usrInsertDate *_t = static_cast<usrInsertDate *>(_o);
        switch (_id) {
        case 0: _t->inserttowidget_signal(); break;
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
            typedef void (usrInsertDate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usrInsertDate::inserttowidget_signal)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject usrInsertDate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_usrInsertDate.data,
      qt_meta_data_usrInsertDate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *usrInsertDate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *usrInsertDate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_usrInsertDate.stringdata))
        return static_cast<void*>(const_cast< usrInsertDate*>(this));
    return QWidget::qt_metacast(_clname);
}

int usrInsertDate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void usrInsertDate::inserttowidget_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
