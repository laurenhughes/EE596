/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "OpenImage"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "SaveImage"
QT_MOC_LITERAL(4, 32, 16), // "SaveDisplayImage"
QT_MOC_LITERAL(5, 49, 10), // "ResetImage"
QT_MOC_LITERAL(6, 60, 11), // "ToggleImage"
QT_MOC_LITERAL(7, 72, 8), // "AddNoise"
QT_MOC_LITERAL(8, 81, 15), // "BlackWhiteImage"
QT_MOC_LITERAL(9, 97, 13), // "MeanBlurImage"
QT_MOC_LITERAL(10, 111, 17), // "GaussianBlurImage"
QT_MOC_LITERAL(11, 129, 17), // "FirstDerivImage_x"
QT_MOC_LITERAL(12, 147, 17), // "FirstDerivImage_y"
QT_MOC_LITERAL(13, 165, 10), // "SobelImage"
QT_MOC_LITERAL(14, 176, 9), // "HalfImage"
QT_MOC_LITERAL(15, 186, 10), // "Brightness"
QT_MOC_LITERAL(16, 197, 3), // "val"
QT_MOC_LITERAL(17, 201, 4), // "Zoom"
QT_MOC_LITERAL(18, 206, 6), // "Scroll"
QT_MOC_LITERAL(19, 213, 20), // "ConvertQImage2Double"
QT_MOC_LITERAL(20, 234, 5), // "image"
QT_MOC_LITERAL(21, 240, 20), // "ConvertDouble2QImage"
QT_MOC_LITERAL(22, 261, 7) // "QImage*"

    },
    "MainWindow\0OpenImage\0\0SaveImage\0"
    "SaveDisplayImage\0ResetImage\0ToggleImage\0"
    "AddNoise\0BlackWhiteImage\0MeanBlurImage\0"
    "GaussianBlurImage\0FirstDerivImage_x\0"
    "FirstDerivImage_y\0SobelImage\0HalfImage\0"
    "Brightness\0val\0Zoom\0Scroll\0"
    "ConvertQImage2Double\0image\0"
    "ConvertDouble2QImage\0QImage*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    1,  117,    2, 0x08 /* Private */,
      17,    1,  120,    2, 0x08 /* Private */,
      18,    1,  123,    2, 0x08 /* Private */,
      19,    1,  126,    2, 0x08 /* Private */,
      21,    1,  129,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QImage,   20,
    QMetaType::Void, 0x80000000 | 22,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OpenImage(); break;
        case 1: _t->SaveImage(); break;
        case 2: _t->SaveDisplayImage(); break;
        case 3: _t->ResetImage(); break;
        case 4: _t->ToggleImage(); break;
        case 5: _t->AddNoise(); break;
        case 6: _t->BlackWhiteImage(); break;
        case 7: _t->MeanBlurImage(); break;
        case 8: _t->GaussianBlurImage(); break;
        case 9: _t->FirstDerivImage_x(); break;
        case 10: _t->FirstDerivImage_y(); break;
        case 11: _t->SobelImage(); break;
        case 12: _t->HalfImage(); break;
        case 13: _t->Brightness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->Zoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->Scroll((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->ConvertQImage2Double((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 17: _t->ConvertDouble2QImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
