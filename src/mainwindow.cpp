/* Janela principal resposável pela interação com o usuário
 * Autor: Caio Viktor
*/
#include "../lib/imports.h"
#include "../lib/mainwindow.h"
#include "ui_mainwindow.h"
QTableWidget *tableC,*tableD,*tableRGauss,*tableRGaussJordan,*tableRGaussComp,*tableRGaussJordanComp,*tableAreaGauss,*tableAreaGaussJordan, *tableAreaGaussComp, *tableAreaGaussJordanComp;
QSpinBox *spinBox_QtdC;

Matrix *matrixC,*matrixD;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tableC                   = ui->tableC;
    tableD                   = ui->tableD;
    tableRGauss              = ui->tableRGauss;
    spinBox_QtdC             = ui->spinBox_QtdC;
    tableAreaGauss           = ui->tableAreaGauss;
    tableRGaussComp          = ui->tableRGaussComp;
    tableRGaussJordan        = ui->tableRGaussJordan;
    tableAreaGaussComp       = ui->tableAreaGaussComp;
    tableAreaGaussJordan     = ui->tableAreaGaussJordan;
    tableRGaussJordanComp    = ui->tableRGaussJordanComp;
    tableAreaGaussJordanComp = ui->tableAreaGaussJordanComp;

    int valN = ui->spinBox_QtdC->value();
    setDimensionNxN( valN,tableC);
    setDimensionNx1( valN,tableD);
    setDimensionNx1( valN,tableRGauss);
    setDimensionNx1( valN,tableAreaGauss);
    setDimensionNx1( valN,tableRGaussComp);
    setDimensionNx1( valN,tableRGaussJordan);
    setDimensionNx1( valN,tableAreaGaussComp);
    setDimensionNx1( valN,tableAreaGaussJordan);
    setDimensionNx1( valN,tableRGaussJordanComp);
    setDimensionNx1( valN,tableAreaGaussJordanComp);


    setMatrixCandD();
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
    setDimensionNx1( valN,tableAreaGauss);
    setDimensionNx1( valN,tableRGaussComp);
    setDimensionNx1( valN,tableRGaussJordan);
    setDimensionNx1( valN,tableAreaGaussComp);
    setDimensionNx1( valN,tableAreaGaussJordan);
    setDimensionNx1( valN,tableRGaussJordanComp);
    setDimensionNx1( valN,tableAreaGaussJordanComp);
}

void MainWindow::on_pushButton_clicked()
{
    setMatrixCandD();
    Dialog *dialog = new Dialog(NULL,"Confirmado","Configurações confirmadas");
    dialog->show();
}
void MainWindow::setMatrixCandD(){
    delete matrixC;
    delete matrixD;
    int valN = spinBox_QtdC->value();
    matrixC = new Matrix(valN,valN);
    matrixD = new Matrix(valN,1);

    for(int i = 0 ;i < valN ;i++){
        QTableWidgetItem *cell = tableD->item(i,0);
        matrixD->setValue(i,0, cell->text().replace(",",".").toDouble());
    }
    for(int i = 0 ;i < valN ;i++){
        for(int j = 0; j < valN ; j++){
            QTableWidgetItem *cell = tableC->item(i,j);
            matrixC->setValue(i,j, cell->text().replace(",",".").toDouble());
        }
    }
}

//TODO: Criar função que seta os valores nas tabelas,passo a passo e labels
