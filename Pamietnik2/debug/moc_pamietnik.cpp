/****************************************************************************
** Meta object code from reading C++ file 'pamietnik.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../pamietnik.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pamietnik.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pamietnik_t {
    const uint offsetsAndSize[22];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Pamietnik_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Pamietnik_t qt_meta_stringdata_Pamietnik = {
    {
QT_MOC_LITERAL(0, 9), // "Pamietnik"
QT_MOC_LITERAL(10, 22), // "on_dodajButton_clicked"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 21), // "on_nextButton_clicked"
QT_MOC_LITERAL(56, 21), // "on_prevButton_clicked"
QT_MOC_LITERAL(78, 10), // "closeEvent"
QT_MOC_LITERAL(89, 12), // "QCloseEvent*"
QT_MOC_LITERAL(102, 5), // "event"
QT_MOC_LITERAL(108, 21), // "on_usunButton_clicked"
QT_MOC_LITERAL(130, 22), // "on_radioButton_toggled"
QT_MOC_LITERAL(153, 7) // "checked"

    },
    "Pamietnik\0on_dodajButton_clicked\0\0"
    "on_nextButton_clicked\0on_prevButton_clicked\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "on_usunButton_clicked\0on_radioButton_toggled\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pamietnik[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    1,   53,    2, 0x08,    4 /* Private */,
       8,    0,   56,    2, 0x08,    6 /* Private */,
       9,    1,   57,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void Pamietnik::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pamietnik *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_dodajButton_clicked(); break;
        case 1: _t->on_nextButton_clicked(); break;
        case 2: _t->on_prevButton_clicked(); break;
        case 3: _t->closeEvent((*reinterpret_cast< std::add_pointer_t<QCloseEvent*>>(_a[1]))); break;
        case 4: _t->on_usunButton_clicked(); break;
        case 5: _t->on_radioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Pamietnik::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Pamietnik.offsetsAndSize,
    qt_meta_data_Pamietnik,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Pamietnik_t
, QtPrivate::TypeAndForceComplete<Pamietnik, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *Pamietnik::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pamietnik::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pamietnik.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Pamietnik::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
