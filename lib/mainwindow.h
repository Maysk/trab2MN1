#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidget>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>

class Matrix;
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

    void desenhar(int n, double raios[]);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
