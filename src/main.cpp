#include "../lib/imports.h"
#include "../lib/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();


//    Matrix *iTM = new Matrix(3,3);
//    Matrix *cM = new Matrix (3,1);

//    iTM->setValue(0,0,10);    iTM->setValue(0,1,1);    iTM->setValue(0,2,1);
//    iTM->setValue(1,0,1);     iTM->setValue(1,1,10);   iTM->setValue(1,2,1);
//    iTM->setValue(2,0,1);     iTM->setValue(2,1,1);    iTM->setValue(2,2,10);

//    cM->setValue(0,0,12);
//    cM->setValue(1,0,12);
//    cM->setValue(2,0,12);

//    cM->printMatrix();
//    iTM->printMatrix();

//    Gauss* g = new Gauss(iTM, cM);

<<<<<<< HEAD
    g->resolveSytem();
    cM->printMatrix();
    iTM->printMatrix();
    g->getUnknownsMatrix()->printMatrix();
    cout << "Tempo: " <<  g->getExecutionTime() <<endl;
=======
//    g->resolveSytem();
//    g->getUnknownsMatrix()->printMatrix();
>>>>>>> 8ffe3eef8664ca275627e5b32bbf507e4ed11df9
 }
