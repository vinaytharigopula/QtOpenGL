/****************************************************************************
** Meta object code from reading C++ file 'GlWidget2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tutorial2/GlWidget2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlWidget2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GlWidget2_t {
    QByteArrayData data[15];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GlWidget2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GlWidget2_t qt_meta_stringdata_GlWidget2 = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GlWidget2"
QT_MOC_LITERAL(1, 10, 18), // "sendMouseMoveEvent"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 1), // "p"
QT_MOC_LITERAL(4, 32, 13), // "onPosReceived"
QT_MOC_LITERAL(5, 46, 1), // "P"
QT_MOC_LITERAL(6, 48, 13), // "initGridLogic"
QT_MOC_LITERAL(7, 62, 8), // "showGrid"
QT_MOC_LITERAL(8, 71, 1), // "w"
QT_MOC_LITERAL(9, 73, 1), // "h"
QT_MOC_LITERAL(10, 75, 5), // "w_Div"
QT_MOC_LITERAL(11, 81, 5), // "h_Div"
QT_MOC_LITERAL(12, 87, 13), // "getGridNumber"
QT_MOC_LITERAL(13, 101, 13), // "showAllPoints"
QT_MOC_LITERAL(14, 115, 1) // "B"

    },
    "GlWidget2\0sendMouseMoveEvent\0\0p\0"
    "onPosReceived\0P\0initGridLogic\0showGrid\0"
    "w\0h\0w_Div\0h_Div\0getGridNumber\0"
    "showAllPoints\0B"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GlWidget2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x0a /* Public */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    4,   51,    2, 0x08 /* Private */,
      12,    1,   60,    2, 0x08 /* Private */,
      13,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int,    8,    9,   10,   11,
    QMetaType::Int, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::Bool,   14,

       0        // eod
};

void GlWidget2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GlWidget2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMouseMoveEvent((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->onPosReceived((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 2: _t->initGridLogic(); break;
        case 3: _t->showGrid((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: { int _r = _t->getGridNumber((*reinterpret_cast< QPointF(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->showAllPoints((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GlWidget2::*)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GlWidget2::sendMouseMoveEvent)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GlWidget2::staticMetaObject = { {
    &QOpenGLWidget::staticMetaObject,
    qt_meta_stringdata_GlWidget2.data,
    qt_meta_data_GlWidget2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GlWidget2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GlWidget2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GlWidget2.stringdata0))
        return static_cast<void*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int GlWidget2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void GlWidget2::sendMouseMoveEvent(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
