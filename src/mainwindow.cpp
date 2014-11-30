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

    //Teste de desenho:
//    double raiosTeste[5] = {1,1,2,2,4};
//    this->desenhar(5,raiosTeste);
    //Fim do teste de desenho


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

void MainWindow::setResultMethod(GaussTemplate *method, int type){
    QLabel *time;
    QLabel *interations;
    QLabel *error;

    QTableWidget *tableRaio;
    QTableWidget *tableArea;

    Matrix *raios;
    Matrix *areas;

    Area *area;

    bool pivoteamento;

    QString sTime;
    QString sInterations;
    QString sError;

    switch(type){
    case 0:
        time = ui->labelTimeGauss;
        interations = ui->labelInterationsGauss;
        error = ui->labelErrorGauss;
        tableRaio = tableRGauss;
        tableArea = tableAreaGauss;
        pivoteamento = ui->radioButtonGauss->isChecked();
        break;
    case 1:
        time = ui->labelTimeGaussJordan;
        interations = ui->labelInterationsGaussJordan;
        error = ui->labelErrorGaussJordan;
        tableRaio = tableRGaussJordan;
        tableArea = tableAreaGaussJordan;
        pivoteamento = ui->radioButtonGaussJordan->isChecked();
        break;
    case 2:
        time = ui->labelTimeGaussComp;
        interations = ui->labelInterationsGaussComp;
        error = ui->labelErrorGaussComp;
        tableRaio = tableRGaussComp;
        tableArea = tableAreaGaussComp;
        pivoteamento = ui->radioButtonComp->isChecked();
        break;
    case 3:
        time = ui->labelTimeGaussJordanComp;
        interations = ui->labelInterationsGaussJordanComp;
        error = ui->labelErrorGaussJordanComp;
        tableRaio = tableRGaussJordanComp;
        tableArea = tableAreaGaussJordanComp;
        pivoteamento = ui->radioButtonComp->isChecked();
        break;
    }
    method->resolveSytem(pivoteamento);
    if(method->isSolvable()){
        raios = method->getUnknownsMatrix();

        area = new Area(raios);
        areas = area->getArea();

        sError = QString::number(method->getError(),'g',12);

    }
    else{
        raios = new Matrix(matrixC->getHeight(),matrixD->getWidth());
        areas = new Matrix(matrixC->getHeight(),matrixD->getWidth());
        sError = QString("Nao foi possivel calcular os raios utilizando o metodo escolhido");
    }
    sTime = QString::number(method->getExecutionTime(),'g',12);
    sInterations = QString::number(method->getExecutionTime(),'g',12);

    setTable(raios,tableRaio);
    setTable(areas,tableArea);
    time->setText(sTime);
    interations->setText(sInterations);
    error->setText(sError);
}

void MainWindow::on_pushButton_clicked()
{
    setMatrixCandD();

    //resolução por Gauss
    Gauss *gauss = new Gauss(matrixC,matrixD);
    setResultMethod(gauss,0);
    if(gauss->isSolvable())
        desenhar(spinBox_QtdC->value() ,gauss->getUnknownsMatrix());
    else
        ui->graphicsView->setScene(NULL);
    setResultMethod(gauss,2);
    //resolução por Gauss fim

    //Gauss-Jordan
    GaussJordan *gaussJordan = new GaussJordan(matrixC,matrixD);
    setResultMethod(gaussJordan,1);
    setResultMethod(gaussJordan,3);
    //Gauss-jordan FIM

    Dialog *dialog = new Dialog(NULL,"Confirmado","Configurações confirmadas");
    dialog->show();


//    delete gauss;
//    delete gaussJordan;
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

//TODO:passo a passo e labels
void MainWindow::setTable(Matrix *matrix, QTableWidget *table){
    double lines = matrix->getHeight();
    double collumns = matrix->getWidth();
    for(int i = 0 ; i < lines ; i++){
        for(int j = 0 ; j < collumns;j++){
            QTableWidgetItem *cell = table->item(i,j);
            cell->setText(QString::number(matrix->getValue(i,j),'g',10));
        }
    }

}

//Desenhar as circunferencias:
void MainWindow::desenhar(int n, Matrix* raiosM){ //extends PoG_DESIGN_PATTERN

    //Função que vai desenhar os circulos e embaixo linhas com raios/áreas
    QGraphicsView *tela = ui->graphicsView;
    int largura = ui->graphicsView->width();
    int altura = ui->graphicsView->height();
    QGraphicsScene *cena = new QGraphicsScene(0,0,largura-40,altura+150);
    tela->setScene(cena);

    //Conversão de Matrix* para raios[]:
    double raios[n];
    bool achouPositivo = false;

    for(int i = 0; i < n; i++){
        raios[i] = raiosM->getValue(i,0);
        if (raios[i] < 0){ //Teste se há um raio negativo
            QGraphicsTextItem *textoErro = new QGraphicsTextItem("Erro!\nPelo menos um dos raios descoberto pelos métodos é negativo.\n");
            textoErro->setX(50);
            textoErro->setY(50);
            cena->addItem(textoErro);
            return;
        }
        if (raios[i] > 0){
            achouPositivo = true;
        }

    }
    if (!achouPositivo){
        QGraphicsTextItem *textoErro = new QGraphicsTextItem("Erro!\nTodos os raios descobertos são iguais a 0.\n");
        textoErro->setX(50);
        textoErro->setY(50);
        cena->addItem(textoErro);
        return;
    }

    //Fim da conversão, Aleluia irmãos.

    int borda = 20;

    int tamanhoMaxRaio = 250;

    double maiorRaio = raios[0];
    for(int i=1;i<n;i++){
        if(raios[i]>maiorRaio){
            maiorRaio = raios[i];
        }
    }

    double raiosNormalizados[n];
    for(int k = 0;k<n;k++){
        raiosNormalizados[k] = ((tamanhoMaxRaio*raios[k])/maiorRaio);
    }

    QGraphicsTextItem *textoLegenda = new QGraphicsTextItem("Legenda:");
    QFont fonteLegenda;
    int tamanhoLegenda = 15;
    fonteLegenda.setPixelSize(tamanhoLegenda);

    textoLegenda->setX((2*borda)+(tamanhoMaxRaio));
    textoLegenda->setY(borda);
    textoLegenda->setFont(fonteLegenda);
    int xLegendaItem = textoLegenda->x();
    int yLegendaItem = textoLegenda->y()+tamanhoLegenda+15;

    QGraphicsTextItem *textoAreas = new QGraphicsTextItem("Areas:");



    int xArea = borda;
    int yArea = 2*borda+tamanhoMaxRaio+40;
    textoAreas->setX(xArea);
    textoAreas->setY(yArea);
    textoAreas->setFont(fonteLegenda);

    cena->addItem(textoLegenda);
    cena->addItem(textoAreas);

    xArea = borda;
    yArea = yArea+25;

    double areas[n];
    for(int j = 0; j<n;j++){
        areas[j] = M_PI*raios[j]*raios[j];
    }


    double tamanhoMaxArea = M_PI*(tamanhoMaxRaio/2)*(tamanhoMaxRaio/2);
    //Início da normalização das áreas:

    double maiorArea = areas[0];
    for(int i = 1;i<n;i++){
        if(maiorArea<areas[i]){
            maiorArea = areas[i];
        }
    }

    //Parte da regra de 3:
    for (int i =0;i<n;i++){
        areas[i] = (tamanhoMaxArea*areas[i])/maiorArea;
        //cout<<"Area "<<i+1<<"= "<<areas[i]<<endl;
    }

    //Fim da normalização

    //Criação do vetor de cores para cada raio
    QBrush corQuadrado[n];
    for (int i = 0;i<n;i++){
        QColor corAleatoria(rand()%255,rand()%255,rand()%255);
        corQuadrado[i].setColor(corAleatoria);
    }

    //Adicionar traço definindo a escala

    int xEscala = borda;
    int yEscala = 2*borda+tamanhoMaxRaio;


    QGraphicsLineItem *escala = new QGraphicsLineItem(xEscala,yEscala,(tamanhoMaxRaio/2)+borda,yEscala);
    QGraphicsLineItem *tracinho1 = new QGraphicsLineItem(borda,yEscala-5,borda,yEscala+5);
    QGraphicsLineItem *tracinho2 = new QGraphicsLineItem(borda+(tamanhoMaxRaio/2),yEscala-5,borda+(tamanhoMaxRaio/2),yEscala+5);

    QGraphicsTextItem *numeroEscala = new QGraphicsTextItem(QString::number(maiorRaio));
    numeroEscala->setX(tracinho1->x()+1.1*(tamanhoMaxRaio/4));
    numeroEscala->setY(yEscala);

    cena->addItem(numeroEscala);
    cena->addItem(escala);
    cena->addItem(tracinho1);
    cena->addItem(tracinho2);


    //Fim da adição do traço

    //Ordenação guardando indice das áreas:

    int indices[n];
    for(int i = 0; i<n;i++){
        indices[i] = i;
    }


    int aux;
    for(int i=n-1; i >= 1; i--) {

      for( int j=0; j < i ; j++) {

        if(areas[j]<areas[j+1]) {

          aux = areas[j];
          areas[j] = areas[j+1];
          areas[j+1] = aux;

          aux = indices[j];
          indices[j] = indices[j+1];
          indices[j+1] = aux;

          }
        }
      }

    //Fim da ordenação

    //Vetor de booleanos que auxiliarão no print da área da legenda
    bool legendado[n];
    for(int i = 0; i<n;i++){
        legendado[i] = false;
    }
    int contRepeticoes;





    //LAÇO PRINCIPAL:
    for(int i = 0; i<n;i++){
        //QColor corAleatoria(rand()%255,rand()%255,rand()%255);
        QPen linha(corQuadrado[i].color());
        linha.setWidth(2);
        QGraphicsEllipseItem *circulo = new QGraphicsEllipseItem(borda+(tamanhoMaxRaio/2)-(raiosNormalizados[i]/2),
                                                                 borda+(tamanhoMaxRaio/2)-(raiosNormalizados[i]/2),
                                                                 raiosNormalizados[i],
                                                                 raiosNormalizados[i]);
        circulo->setPen(linha);

        cena->addItem(circulo);

        //Mostrar quadradinhos com cores:
        if(legendado[i] == false){
            legendado[i] = true;
            contRepeticoes = 0;
            QGraphicsRectItem *legendaItem = new QGraphicsRectItem(xLegendaItem,yLegendaItem,15,15);
            legendaItem->setBrush(corQuadrado[i].color());

            cena->addItem(legendaItem);



            QString textRaio("r");
            textRaio.append(QString::number(i+1));
            QGraphicsTextItem *textoLegendaItem = new QGraphicsTextItem(textRaio);
            textoLegendaItem->setX(xLegendaItem+20);
            textoLegendaItem->setY(yLegendaItem-3);
            textoLegendaItem->setFont(fonteLegenda);
            cena->addItem(textoLegendaItem);

            for(int k = i+1;k<n;k++){
                if(raios[i]==raios[k]){
                    contRepeticoes++;
                    corQuadrado[k].setColor(corQuadrado[i].color());
                    legendado[k] = true;
                    QString textRaio("r");
                    textRaio.append(QString::number(k+1));
                    QGraphicsTextItem *textoLegendaItem = new QGraphicsTextItem(textRaio);
                    textoLegendaItem->setX(xLegendaItem+20+(contRepeticoes*20));
                    textoLegendaItem->setY(yLegendaItem-3);
                    textoLegenda->setFont(fonteLegenda);
                    cena->addItem(textoLegendaItem);

                }

            }


            yLegendaItem = yLegendaItem + 25;
        }

        //COMEÇO DO DESENHO DAS AREAS




        QGraphicsRectItem *area = new QGraphicsRectItem(xArea,yArea,sqrt(areas[i]),sqrt(areas[i]));
        area->setBrush(corQuadrado[indices[i]].color());

        cena->addItem(area);
        //FIM DO DESENHO DAS AREAS


    }

}

void MainWindow::on_radioButtonGauss_toggled(bool checked)
{
    Gauss *gauss = new Gauss(matrixC,matrixD);
    setResultMethod(gauss,0);
    if(gauss->isSolvable())
        desenhar(spinBox_QtdC->value() ,gauss->getUnknownsMatrix());
    else
        ui->graphicsView->setScene(NULL);
    showMessage(checked);

//    delete gauss;
}

void MainWindow::on_radioButtonGaussJordan_toggled(bool checked)
{
    GaussJordan *gaussJordan = new GaussJordan(matrixC,matrixD);
    setResultMethod(gaussJordan,1);

    showMessage(checked);

//    delete gaussJordan;
}

void MainWindow::on_radioButtonComp_toggled(bool checked)
{
    Gauss *gauss = new Gauss(matrixC,matrixD);
    setResultMethod(gauss,2);

    GaussJordan *gaussJordan = new GaussJordan(matrixC,matrixD);
    setResultMethod(gaussJordan,3);

    showMessage(checked);

//    delete gauss;
//    delete gaussJordan;
}

void MainWindow::showMessage(bool cheked){
    if(cheked){
        Dialog *dialog = new Dialog(NULL,"Confirmado","Pivoteamento ativado");
        dialog->show();
    }
    else{
        Dialog *dialog = new Dialog(NULL,"Confirmado","Pivoteamento desativado");
        dialog->show();
    }
}
