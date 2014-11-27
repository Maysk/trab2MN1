#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
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
    void on_spinBox_QtdC_valueChanged(int arg1);
    void setDimensionNxN(int N,QTableWidget *table);
    void setDimensionNx1(int N,QTableWidget *table);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
