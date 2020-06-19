/****************************************************************************
** Meta object code from reading C++ file 'MSaoLei.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MSaoLei.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MSaoLei.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MSaoLei_t {
    QByteArrayData data[16];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MSaoLei_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MSaoLei_t qt_meta_stringdata_MSaoLei = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MSaoLei"
QT_MOC_LITERAL(1, 8, 21), // "viurlClickblanksignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 1), // "X"
QT_MOC_LITERAL(4, 33, 1), // "Y"
QT_MOC_LITERAL(5, 35, 20), // "receiveButtonClicked"
QT_MOC_LITERAL(6, 56, 25), // "receiveButtonRightClicked"
QT_MOC_LITERAL(7, 82, 33), // "receiveButttonRightAndLeftCli..."
QT_MOC_LITERAL(8, 116, 33), // "receiveButttonRightAndLeftRel..."
QT_MOC_LITERAL(9, 150, 9), // "timerSlot"
QT_MOC_LITERAL(10, 160, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(11, 182, 18), // "recieveButtonPress"
QT_MOC_LITERAL(12, 201, 19), // "viurlClickblankslot"
QT_MOC_LITERAL(13, 221, 22), // "on_actionlow_triggered"
QT_MOC_LITERAL(14, 244, 27), // "on_actionMidhight_triggered"
QT_MOC_LITERAL(15, 272, 24) // "on_actionHight_triggered"

    },
    "MSaoLei\0viurlClickblanksignal\0\0X\0Y\0"
    "receiveButtonClicked\0receiveButtonRightClicked\0"
    "receiveButttonRightAndLeftClicked\0"
    "receiveButttonRightAndLeftRelease\0"
    "timerSlot\0on_pushButton_clicked\0"
    "recieveButtonPress\0viurlClickblankslot\0"
    "on_actionlow_triggered\0"
    "on_actionMidhight_triggered\0"
    "on_actionHight_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MSaoLei[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   79,    2, 0x0a /* Public */,
       6,    0,   80,    2, 0x0a /* Public */,
       7,    0,   81,    2, 0x0a /* Public */,
       8,    0,   82,    2, 0x0a /* Public */,
       9,    0,   83,    2, 0x0a /* Public */,
      10,    0,   84,    2, 0x0a /* Public */,
      11,    0,   85,    2, 0x0a /* Public */,
      12,    2,   86,    2, 0x0a /* Public */,
      13,    0,   91,    2, 0x0a /* Public */,
      14,    0,   92,    2, 0x0a /* Public */,
      15,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MSaoLei::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MSaoLei *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->viurlClickblanksignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->receiveButtonClicked(); break;
        case 2: _t->receiveButtonRightClicked(); break;
        case 3: _t->receiveButttonRightAndLeftClicked(); break;
        case 4: _t->receiveButttonRightAndLeftRelease(); break;
        case 5: _t->timerSlot(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->recieveButtonPress(); break;
        case 8: _t->viurlClickblankslot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->on_actionlow_triggered(); break;
        case 10: _t->on_actionMidhight_triggered(); break;
        case 11: _t->on_actionHight_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MSaoLei::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MSaoLei::viurlClickblanksignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MSaoLei::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MSaoLei.data,
    qt_meta_data_MSaoLei,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MSaoLei::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MSaoLei::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MSaoLei.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MSaoLei::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MSaoLei::viurlClickblanksignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
