/****************************************************************************
** Meta object code from reading C++ file 'admindelete.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../admindelete.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admindelete.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_adminDelete_t {
    QByteArrayData data[7];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_adminDelete_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_adminDelete_t qt_meta_stringdata_adminDelete = {
    {
QT_MOC_LITERAL(0, 0, 11), // "adminDelete"
QT_MOC_LITERAL(1, 12, 21), // "deletetowidget_signal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "my_jump_slots"
QT_MOC_LITERAL(4, 49, 9), // "Btn_slots"
QT_MOC_LITERAL(5, 59, 15), // "connected_slots"
QT_MOC_LITERAL(6, 75, 15) // "readyRead_slots"

    },
    "adminDelete\0deletetowidget_signal\0\0"
    "my_jump_slots\0Btn_slots\0connected_slots\0"
    "readyRead_slots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_adminDelete[] = {

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

void adminDelete::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        adminDelete *_t = static_cast<adminDelete *>(_o);
        switch (_id) {
        case 0: _t->deletetowidget_signal(); break;
        case 1: _t->my_jump_slots(); break;
        case 2: _t->Btn_slots(); break;
        case 3: _t->connected_slots(); break;
        case 4: _t->readyRead_slots(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (adminDelete::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&adminDelete::deletetowidget_signal)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject adminDelete::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_adminDelete.data,
      qt_meta_data_adminDelete,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *adminDelete::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *adminDelete::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_adminDelete.stringdata))
        return static_cast<void*>(const_cast< adminDelete*>(this));
    return QWidget::qt_metacast(_clname);
}

int adminDelete::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void adminDelete::deletetowidget_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
