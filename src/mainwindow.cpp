/* Janela principal resposável pela interação com o usuário
 * Autor: Caio Viktor
*/
#include "../lib/imports.h"
#include "../lib/mainwindow.h"
#include "ui_mainwindow.h"
QTableWidget *tableC,*tableD,*tableRGauss,*tableRGaussJordan,*tableRGaussComp,*tableRGaussJordanComp,*tableAreaGauss,*tableAreaGaussJordan;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tableC                = ui->tableC;
    tableD                = ui->tableD;
    tableRGauss           = ui->tableRGauss;
    tableAreaGauss        = ui->tableAreaGauss;
    tableRGaussComp       = ui->tableRGaussComp;
    tableRGaussJordan     = ui->tableRGaussJordan;
    tableAreaGaussJordan  = ui->tableAreaGaussJordan;
    tableRGaussJordanComp = ui->tableRGaussJordanComp;

    int valN = ui->spinBox_QtdC->value();
    setDimensionNxN( valN,tableC);
    setDimensionNx1( valN,tableD);
    setDimensionNx1( valN,tableRGauss);
    setDimensionNx1( valN,tableAreaGauss);
    setDimensionNx1( valN,tableRGaussComp);
    setDimensionNx1( valN,tableRGaussJordan);
    setDimensionNx1( valN,tableAreaGaussJordan);
    setDimensionNx1( valN,tableRGaussJordanComp);
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

void MainWindow::on_pushButton_clicked()
{
    Dialog *dialog = new Dialog(NULL,"Confirmado","Configurações confirmadas");
    dialog->show();
    //TODO: Ler valores e chamar métodos.
}
//TODO: Criar função que seta os valores nas tabelas,passo a passo e labels
