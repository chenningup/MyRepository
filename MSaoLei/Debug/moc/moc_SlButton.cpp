/****************************************************************************
** Meta object code from reading C++ file 'SlButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SlButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SlButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SlButton_t {
    QByteArrayData data[9];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SlButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SlButton_t qt_meta_stringdata_SlButton = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SlButton"
QT_MOC_LITERAL(1, 9, 18), // "emitClickedSignals"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "emitRightClicked"
QT_MOC_LITERAL(4, 46, 15), // "emitbuttonPress"
QT_MOC_LITERAL(5, 62, 21), // "emitRightAndLeftPress"
QT_MOC_LITERAL(6, 84, 23), // "emitRightAndLeftRelease"
QT_MOC_LITERAL(7, 108, 12), // "clickedSlots"
QT_MOC_LITERAL(8, 121, 10) // "pressSlots"

    },
    "SlButton\0emitClickedSignals\0\0"
    "emitRightClicked\0emitbuttonPress\0"
    "emitRightAndLeftPress\0emitRightAndLeftRelease\0"
    "clickedSlots\0pressSlots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SlButton[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SlButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SlButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emitClickedSignals(); break;
        case 1: _t->emitRightClicked(); break;
        case 2: _t->emitbuttonPress(); break;
        case 3: _t->emitRightAndLeftPress(); break;
        case 4: _t->emitRightAndLeftRelease(); break;
        case 5: _t->clickedSlots(); break;
        case 6: _t->pressSlots(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SlButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SlButton::emitClickedSignals)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SlButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SlButton::emitRightClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SlButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SlButton::emitbuttonPress)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SlButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SlButton::emitRightAndLeftPress)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SlButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SlButton::emitRightAndLeftRelease)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SlButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_SlButton.data,
    qt_meta_data_SlButton,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SlButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SlButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SlButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int SlButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
void SlButton::emitClickedSignals()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SlButton::emitRightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SlButton::emitbuttonPress()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SlButton::emitRightAndLeftPress()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SlButton::emitRightAndLeftRelease()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
