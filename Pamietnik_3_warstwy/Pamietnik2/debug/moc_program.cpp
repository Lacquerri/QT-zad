/****************************************************************************
** Meta object code from reading C++ file 'program.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../program.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'program.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Program_t {
    const uint offsetsAndSize[16];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Program_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Program_t qt_meta_stringdata_Program = {
    {
QT_MOC_LITERAL(0, 7), // "Program"
QT_MOC_LITERAL(8, 11), // "odswiezOkna"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 12), // "wyswietlTypy"
QT_MOC_LITERAL(34, 15), // "typ_wspomnienia"
QT_MOC_LITERAL(50, 14), // "signalDarkmode"
QT_MOC_LITERAL(65, 14), // "stworzonoKopie"
QT_MOC_LITERAL(80, 13) // "przywrocKopie"

    },
    "Program\0odswiezOkna\0\0wyswietlTypy\0"
    "typ_wspomnienia\0signalDarkmode\0"
    "stworzonoKopie\0przywrocKopie"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Program[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   44,    2, 0x06,    1 /* Public */,
       3,    3,   51,    2, 0x06,    5 /* Public */,
       5,    1,   58,    2, 0x06,    9 /* Public */,
       6,    1,   61,    2, 0x06,   11 /* Public */,
       7,    1,   64,    2, 0x06,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4,    2,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void Program::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Program *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->odswiezOkna((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 1: _t->wyswietlTypy((*reinterpret_cast< std::add_pointer_t<typ_wspomnienia>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<typ_wspomnienia>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<typ_wspomnienia>>(_a[3]))); break;
        case 2: _t->signalDarkmode((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->stworzonoKopie((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->przywrocKopie((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Program::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Program::odswiezOkna)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Program::*)(typ_wspomnienia , typ_wspomnienia , typ_wspomnienia );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Program::wyswietlTypy)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Program::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Program::signalDarkmode)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Program::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Program::stworzonoKopie)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Program::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Program::przywrocKopie)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Program::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Program.offsetsAndSize,
    qt_meta_data_Program,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Program_t
, QtPrivate::TypeAndForceComplete<Program, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<typ_wspomnienia, std::false_type>, QtPrivate::TypeAndForceComplete<typ_wspomnienia, std::false_type>, QtPrivate::TypeAndForceComplete<typ_wspomnienia, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>



>,
    nullptr
} };


const QMetaObject *Program::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Program::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Program.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Program::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Program::odswiezOkna(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Program::wyswietlTypy(typ_wspomnienia _t1, typ_wspomnienia _t2, typ_wspomnienia _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Program::signalDarkmode(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Program::stworzonoKopie(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Program::przywrocKopie(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
