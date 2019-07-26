/****************************************************************************
** Meta object code from reading C++ file 'stack.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/include/stack.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stack.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Stack_t {
    QByteArrayData data[8];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Stack_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Stack_t qt_meta_stringdata_Stack = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Stack"
QT_MOC_LITERAL(1, 6, 8), // "openPage"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 10), // "_isChanged"
QT_MOC_LITERAL(4, 27, 9), // "closePage"
QT_MOC_LITERAL(5, 37, 8), // "closeApp"
QT_MOC_LITERAL(6, 46, 14), // "prepareNewPage"
QT_MOC_LITERAL(7, 61, 5) // "index"

    },
    "Stack\0openPage\0\0_isChanged\0closePage\0"
    "closeApp\0prepareNewPage\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Stack[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       5,    1,   40,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void Stack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Stack *_t = static_cast<Stack *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->closePage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->closeApp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->prepareNewPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Stack::staticMetaObject = {
    { &QStackedWidget::staticMetaObject, qt_meta_stringdata_Stack.data,
      qt_meta_data_Stack,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Stack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Stack::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Stack.stringdata0))
        return static_cast<void*>(this);
    return QStackedWidget::qt_metacast(_clname);
}

int Stack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
