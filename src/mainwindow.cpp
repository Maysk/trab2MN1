/* Janela principal resposável pela interação com o usuário
 * Autor: Caio Viktor
*/
#include "../lib/imports.h"
#include "../lib/mainwindow.h"
#include "ui_mainwindow.h"
QTableWidget *tableC,*tableD,*tableRGauss,*tableRGaussJordan;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tableC = ui->tableC;
    tableD = ui->tableD;
    tableRGauss = ui->tableRGauss;
    tableRGaussJordan = ui->tableRGaussJordan;
    int valN = ui->spinBox_QtdC->value();
    setDimensionNxN( valN,tableC);
    setDimensionNx1( valN,tableD);
    setDimensionNx1( valN,tableRGauss);
    setDimensionNx1( valN,tableRGaussJordan);
}

void MainWindow::setDimensionNxN(int N,QTableWidget *table){
    table->setRowCount(N);
    table->setColumnCount(N);
    for (int i = 0; i < N;i++) {
        for(int j = 0; j < N;j++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(QString("0"));
            table->setItem(i,j,item);
        }

    }
}

void MainWindow::setDimensionNx1(int N,QTableWidget *table){
    table->setRowCount(N);
    table->setColumnCount(1);
    for (int i = 0; i < N; i++) {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString("0"));
        table->setItem(i,0,item);

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_QtdC_valueChanged(int valN)
{
    setDimensionNxN( valN,tableC);
    setDimensionNx1( valN,tableD);
    setDimensionNx1( valN,tableRGauss);
    setDimensionNx1( valN,tableRGaussJordan);
}
