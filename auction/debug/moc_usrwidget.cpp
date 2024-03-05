/****************************************************************************
** Meta object code from reading C++ file 'usrwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../usrwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usrwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_usrWidget_t {
    QByteArrayData data[15];
    char stringdata[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_usrWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_usrWidget_t qt_meta_stringdata_usrWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "usrWidget"
QT_MOC_LITERAL(1, 10, 13), // "insert_signal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 13), // "delete_signal"
QT_MOC_LITERAL(4, 39, 13), // "update_signal"
QT_MOC_LITERAL(5, 53, 15), // "auctable_signal"
QT_MOC_LITERAL(6, 69, 15), // "sellgood_signal"
QT_MOC_LITERAL(7, 85, 20), // "auctionrecord_signal"
QT_MOC_LITERAL(8, 106, 13), // "my_jump_slots"
QT_MOC_LITERAL(9, 120, 14), // "insertBtn_slot"
QT_MOC_LITERAL(10, 135, 14), // "deleteBtn_slot"
QT_MOC_LITERAL(11, 150, 14), // "updateBtn_slot"
QT_MOC_LITERAL(12, 165, 16), // "auctableBtn_slot"
QT_MOC_LITERAL(13, 182, 16), // "sellgoodBtn_slot"
QT_MOC_LITERAL(14, 199, 21) // "auctionrecordBtn_slot"

    },
    "usrWidget\0insert_signal\0\0delete_signal\0"
    "update_signal\0auctable_signal\0"
    "sellgood_signal\0auctionrecord_signal\0"
    "my_jump_slots\0insertBtn_slot\0"
    "deleteBtn_slot\0updateBtn_slot\0"
    "auctableBtn_slot\0sellgoodBtn_slot\0"
    "auctionrecordBtn_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_usrWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void usrWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        usrWidget *_t = static_cast<usrWidget *>(_o);
        switch (_id) {
        case 0: _t->insert_signal(); break;
        case 1: _t->delete_signal(); break;
        case 2: _t->update_signal(); break;
        case 3: _t->auctable_signal(); break;
        case 4: _t->sellgood_signal(); break;
        case 5: _t->auctionrecord_signal(); break;
        case 6: _t->my_jump_slots(); break;
        case 7: _t->insertBtn_slot(); break;
        case 8: _t->deleteBtn_slot(); break;
        case 9: _t->updateBtn_slot(); break;
        case 10: _t->auctableBtn_slot(); break;
        case 11: _t->sellgoodBtn_slot(); break;
        case 12: _t->auctionrecordBtn_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (usrWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usrWidget::insert_signal)) {
                *result = 0;
            }
        }
        {
            typedef void (usrWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usrWidget::delete_signal)) {
                *result = 1;
            }
        }
        {
            typedef void (usrWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usrWidget::update_signal)) {
                *result = 2;
            }
        }
        {
            typedef void (usrWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usrWidget::auctable_signal)) {
                *result = 3;
            }
        }
        {
            typedef void (usrWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usrWidget::sellgood_signal)) {
                *result = 4;
            }
        }
        {
            typedef void (usrWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&usrWidget::auctionrecord_signal)) {
                *result = 5;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject usrWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_usrWidget.data,
      qt_meta_data_usrWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *usrWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *usrWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_usrWidget.stringdata))
        return static_cast<void*>(const_cast< usrWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int usrWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void usrWidget::insert_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void usrWidget::delete_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void usrWidget::update_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void usrWidget::auctable_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void usrWidget::sellgood_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void usrWidget::auctionrecord_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
