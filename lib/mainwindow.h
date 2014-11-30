#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidget>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>

class Matrix;
class GaussTemplate;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_spinBox_QtdC_valueChanged(int valN);
    void setDimensionNxN(int N,QTableWidget *table);
    void setDimensionNx1(int N,QTableWidget *table);

    void setMatrixCandD();

    void setTable(Matrix *matrix, QTableWidget *table);
    void on_pushButton_clicked();

    void setResultMethod(GaussTemplate *method,int type); //Type: 0 = Gauss; 1 = Gauss-Jordan; 2 = GaussComp; 3 = Gauss-JordanComp

    void desenhar(int, Matrix*);

    void on_radioButtonGauss_toggled(bool checked);

    void on_radioButtonGaussJordan_toggled(bool checked);

    void on_radioButtonComp_toggled(bool checked);

    void showMessage(bool cheked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
