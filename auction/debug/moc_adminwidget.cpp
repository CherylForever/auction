/****************************************************************************
** Meta object code from reading C++ file 'adminwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../adminwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_adminWidget_t {
    QByteArrayData data[11];
    char stringdata[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_adminWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_adminWidget_t qt_meta_stringdata_adminWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "adminWidget"
QT_MOC_LITERAL(1, 12, 21), // "queryProfitBtn_signal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "update_signal"
QT_MOC_LITERAL(4, 49, 13), // "delete_signal"
QT_MOC_LITERAL(5, 63, 19), // "queryHistory_signal"
QT_MOC_LITERAL(6, 83, 13), // "my_jump_slots"
QT_MOC_LITERAL(7, 97, 19), // "queryProfitBtn_slot"
QT_MOC_LITERAL(8, 117, 14), // "updateBtn_slot"
QT_MOC_LITERAL(9, 132, 14), // "deleteBtn_slot"
QT_MOC_LITERAL(10, 147, 17) // "queryHistory_slot"

    },
    "adminWidget\0queryProfitBtn_signal\0\0"
    "update_signal\0delete_signal\0"
    "queryHistory_signal\0my_jump_slots\0"
    "queryProfitBtn_slot\0updateBtn_slot\0"
    "deleteBtn_slot\0queryHistory_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_adminWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
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

       0        // eod
};

void adminWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        adminWidget *_t = static_cast<adminWidget *>(_o);
        switch (_id) {
        case 0: _t->queryProfitBtn_signal(); break;
        case 1: _t->update_signal(); break;
        case 2: _t->delete_signal(); break;
        case 3: _t->queryHistory_signal(); break;
        case 4: _t->my_jump_slots(); break;
        case 5: _t->queryProfitBtn_slot(); break;
        case 6: _t->updateBtn_slot(); break;
        case 7: _t->deleteBtn_slot(); break;
        case 8: _t->queryHistory_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (adminWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&adminWidget::queryProfitBtn_signal)) {
                *result = 0;
            }
        }
        {
            typedef void (adminWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&adminWidget::update_signal)) {
                *result = 1;
            }
        }
        {
            typedef void (adminWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&adminWidget::delete_signal)) {
                *result = 2;
            }
        }
        {
            typedef void (adminWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&adminWidget::queryHistory_signal)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject adminWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_adminWidget.data,
      qt_meta_data_adminWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *adminWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *adminWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_adminWidget.stringdata))
        return static_cast<void*>(const_cast< adminWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int adminWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void adminWidget::queryProfitBtn_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void adminWidget::update_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void adminWidget::delete_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void adminWidget::queryHistory_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
