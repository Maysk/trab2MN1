/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../trabalho2MN1/lib/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 28),
QT_MOC_LITERAL(2, 40, 0),
QT_MOC_LITERAL(3, 41, 4),
QT_MOC_LITERAL(4, 46, 15),
QT_MOC_LITERAL(5, 62, 1),
QT_MOC_LITERAL(6, 64, 13),
QT_MOC_LITERAL(7, 78, 5),
QT_MOC_LITERAL(8, 84, 15),
QT_MOC_LITERAL(9, 100, 14),
QT_MOC_LITERAL(10, 115, 8),
QT_MOC_LITERAL(11, 124, 7),
QT_MOC_LITERAL(12, 132, 6),
QT_MOC_LITERAL(13, 139, 21),
QT_MOC_LITERAL(14, 161, 15),
QT_MOC_LITERAL(15, 177, 14),
QT_MOC_LITERAL(16, 192, 6),
QT_MOC_LITERAL(17, 199, 4),
QT_MOC_LITERAL(18, 204, 8),
QT_MOC_LITERAL(19, 213, 27),
QT_MOC_LITERAL(20, 241, 7),
QT_MOC_LITERAL(21, 249, 33),
QT_MOC_LITERAL(22, 283, 26),
QT_MOC_LITERAL(23, 310, 11),
QT_MOC_LITERAL(24, 322, 6)
    },
    "MainWindow\0on_spinBox_QtdC_valueChanged\0"
    "\0valN\0setDimensionNxN\0N\0QTableWidget*\0"
    "table\0setDimensionNx1\0setMatrixCandD\0"
    "setTable\0Matrix*\0matrix\0on_pushButton_clicked\0"
    "setResultMethod\0GaussTemplate*\0method\0"
    "type\0desenhar\0on_radioButtonGauss_toggled\0"
    "checked\0on_radioButtonGaussJordan_toggled\0"
    "on_radioButtonComp_toggled\0showMessage\0"
    "cheked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    2,   77,    2, 0x08 /* Private */,
       8,    2,   82,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    2,   88,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,
      14,    2,   94,    2, 0x08 /* Private */,
      18,    2,   99,    2, 0x08 /* Private */,
      19,    1,  104,    2, 0x08 /* Private */,
      21,    1,  107,    2, 0x08 /* Private */,
      22,    1,  110,    2, 0x08 /* Private */,
      23,    1,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    5,    7,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    5,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 6,   12,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,   16,   17,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11,    2,    2,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   24,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_spinBox_QtdC_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setDimensionNxN((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QTableWidget*(*)>(_a[2]))); break;
        case 2: _t->setDimensionNx1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QTableWidget*(*)>(_a[2]))); break;
        case 3: _t->setMatrixCandD(); break;
        case 4: _t->setTable((*reinterpret_cast< Matrix*(*)>(_a[1])),(*reinterpret_cast< QTableWidget*(*)>(_a[2]))); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->setResultMethod((*reinterpret_cast< GaussTemplate*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->desenhar((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Matrix*(*)>(_a[2]))); break;
        case 8: _t->on_radioButtonGauss_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_radioButtonGaussJordan_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_radioButtonComp_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->showMessage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
