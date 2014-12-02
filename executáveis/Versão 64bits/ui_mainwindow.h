/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QSpinBox *spinBox_QtdC;
    QTableWidget *tableC;
    QLabel *label_2;
    QLabel *label_3;
    QTableWidget *tableD;
    QLabel *label_4;
    QPushButton *pushButton;
    QWidget *tab_2;
    QLabel *label_5;
    QRadioButton *radioButtonGauss;
    QTableWidget *tableRGauss;
    QLabel *label_9;
    QLabel *labelTimeGauss;
    QLabel *labelInterationsGauss;
    QLabel *label_12;
    QLabel *labelErrorGauss;
    QLabel *label_14;
    QLabel *label_21;
    QPlainTextEdit *plainTextEditGauss;
    QLabel *label_23;
    QTableWidget *tableAreaGauss;
    QLabel *label_24;
    QWidget *tab_3;
    QTableWidget *tableRGaussJordan;
    QLabel *label_6;
    QRadioButton *radioButtonGaussJordan;
    QLabel *labelTimeGaussJordan;
    QLabel *labelErrorGaussJordan;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *labelInterationsGaussJordan;
    QLabel *label_10;
    QPlainTextEdit *plainTextEditGaussJordan;
    QLabel *label_22;
    QLabel *label_25;
    QTableWidget *tableAreaGaussJordan;
    QLabel *label_26;
    QWidget *tab_4;
    QRadioButton *radioButtonComp;
    QTableWidget *tableRGaussComp;
    QLabel *label_7;
    QLabel *label_8;
    QTableWidget *tableRGaussJordanComp;
    QLabel *labelTimeGaussComp;
    QLabel *label_16;
    QLabel *labelErrorGaussComp;
    QLabel *label_17;
    QLabel *label_11;
    QLabel *labelInterationsGaussComp;
    QLabel *label_18;
    QLabel *labelInterationsGaussJordanComp;
    QLabel *labelTimeGaussJordanComp;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *labelErrorGaussJordanComp;
    QLabel *label_27;
    QTableWidget *tableAreaGaussJordanComp;
    QLabel *label_28;
    QTableWidget *tableAreaGaussComp;
    QLabel *label_29;
    QLabel *label_30;
    QWidget *tab_5;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(920, 607);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 171, 17));
        spinBox_QtdC = new QSpinBox(tab);
        spinBox_QtdC->setObjectName(QStringLiteral("spinBox_QtdC"));
        spinBox_QtdC->setGeometry(QRect(170, 0, 71, 27));
        spinBox_QtdC->setMinimum(1);
        spinBox_QtdC->setValue(3);
        tableC = new QTableWidget(tab);
        tableC->setObjectName(QStringLiteral("tableC"));
        tableC->setGeometry(QRect(0, 50, 611, 471));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 30, 67, 17));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(750, 30, 67, 17));
        tableD = new QTableWidget(tab);
        tableD->setObjectName(QStringLiteral("tableD"));
        tableD->setGeometry(QRect(725, 50, 171, 471));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(620, 126, 101, 31));
        QFont font;
        font.setPointSize(34);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(620, 200, 99, 27));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 0, 181, 17));
        radioButtonGauss = new QRadioButton(tab_2);
        radioButtonGauss->setObjectName(QStringLiteral("radioButtonGauss"));
        radioButtonGauss->setGeometry(QRect(730, 0, 161, 22));
        tableRGauss = new QTableWidget(tab_2);
        tableRGauss->setObjectName(QStringLiteral("tableRGauss"));
        tableRGauss->setGeometry(QRect(0, 40, 151, 421));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 470, 81, 17));
        labelTimeGauss = new QLabel(tab_2);
        labelTimeGauss->setObjectName(QStringLiteral("labelTimeGauss"));
        labelTimeGauss->setGeometry(QRect(90, 470, 621, 17));
        labelInterationsGauss = new QLabel(tab_2);
        labelInterationsGauss->setObjectName(QStringLiteral("labelInterationsGauss"));
        labelInterationsGauss->setGeometry(QRect(90, 500, 621, 17));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 500, 81, 17));
        labelErrorGauss = new QLabel(tab_2);
        labelErrorGauss->setObjectName(QStringLiteral("labelErrorGauss"));
        labelErrorGauss->setGeometry(QRect(90, 530, 621, 17));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(0, 530, 91, 17));
        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(400, 0, 101, 17));
        plainTextEditGauss = new QPlainTextEdit(tab_2);
        plainTextEditGauss->setObjectName(QStringLiteral("plainTextEditGauss"));
        plainTextEditGauss->setEnabled(true);
        plainTextEditGauss->setGeometry(QRect(400, 20, 491, 441));
        plainTextEditGauss->setReadOnly(true);
        label_23 = new QLabel(tab_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(0, 20, 67, 17));
        tableAreaGauss = new QTableWidget(tab_2);
        tableAreaGauss->setObjectName(QStringLiteral("tableAreaGauss"));
        tableAreaGauss->setGeometry(QRect(200, 40, 161, 421));
        label_24 = new QLabel(tab_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(200, 20, 67, 17));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableRGaussJordan = new QTableWidget(tab_3);
        tableRGaussJordan->setObjectName(QStringLiteral("tableRGaussJordan"));
        tableRGaussJordan->setGeometry(QRect(0, 40, 151, 421));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(4, 0, 231, 17));
        radioButtonGaussJordan = new QRadioButton(tab_3);
        radioButtonGaussJordan->setObjectName(QStringLiteral("radioButtonGaussJordan"));
        radioButtonGaussJordan->setGeometry(QRect(730, 0, 161, 22));
        labelTimeGaussJordan = new QLabel(tab_3);
        labelTimeGaussJordan->setObjectName(QStringLiteral("labelTimeGaussJordan"));
        labelTimeGaussJordan->setGeometry(QRect(90, 470, 621, 17));
        labelErrorGaussJordan = new QLabel(tab_3);
        labelErrorGaussJordan->setObjectName(QStringLiteral("labelErrorGaussJordan"));
        labelErrorGaussJordan->setGeometry(QRect(90, 530, 621, 17));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(0, 500, 81, 17));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(0, 530, 91, 17));
        labelInterationsGaussJordan = new QLabel(tab_3);
        labelInterationsGaussJordan->setObjectName(QStringLiteral("labelInterationsGaussJordan"));
        labelInterationsGaussJordan->setGeometry(QRect(90, 500, 621, 17));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 470, 81, 17));
        plainTextEditGaussJordan = new QPlainTextEdit(tab_3);
        plainTextEditGaussJordan->setObjectName(QStringLiteral("plainTextEditGaussJordan"));
        plainTextEditGaussJordan->setGeometry(QRect(400, 20, 491, 441));
        plainTextEditGaussJordan->setReadOnly(true);
        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(400, 0, 101, 17));
        label_25 = new QLabel(tab_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(200, 20, 67, 17));
        tableAreaGaussJordan = new QTableWidget(tab_3);
        tableAreaGaussJordan->setObjectName(QStringLiteral("tableAreaGaussJordan"));
        tableAreaGaussJordan->setGeometry(QRect(200, 40, 161, 421));
        label_26 = new QLabel(tab_3);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(0, 20, 67, 17));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        radioButtonComp = new QRadioButton(tab_4);
        radioButtonComp->setObjectName(QStringLiteral("radioButtonComp"));
        radioButtonComp->setGeometry(QRect(730, 0, 161, 22));
        tableRGaussComp = new QTableWidget(tab_4);
        tableRGaussComp->setObjectName(QStringLiteral("tableRGaussComp"));
        tableRGaussComp->setGeometry(QRect(0, 40, 151, 421));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 0, 181, 17));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(470, 0, 231, 17));
        tableRGaussJordanComp = new QTableWidget(tab_4);
        tableRGaussJordanComp->setObjectName(QStringLiteral("tableRGaussJordanComp"));
        tableRGaussJordanComp->setGeometry(QRect(470, 40, 161, 421));
        labelTimeGaussComp = new QLabel(tab_4);
        labelTimeGaussComp->setObjectName(QStringLiteral("labelTimeGaussComp"));
        labelTimeGaussComp->setGeometry(QRect(90, 470, 371, 17));
        label_16 = new QLabel(tab_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(0, 500, 81, 17));
        labelErrorGaussComp = new QLabel(tab_4);
        labelErrorGaussComp->setObjectName(QStringLiteral("labelErrorGaussComp"));
        labelErrorGaussComp->setGeometry(QRect(90, 530, 381, 17));
        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, 530, 91, 17));
        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 470, 81, 17));
        labelInterationsGaussComp = new QLabel(tab_4);
        labelInterationsGaussComp->setObjectName(QStringLiteral("labelInterationsGaussComp"));
        labelInterationsGaussComp->setGeometry(QRect(90, 500, 371, 17));
        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(470, 470, 81, 17));
        labelInterationsGaussJordanComp = new QLabel(tab_4);
        labelInterationsGaussJordanComp->setObjectName(QStringLiteral("labelInterationsGaussJordanComp"));
        labelInterationsGaussJordanComp->setGeometry(QRect(560, 500, 331, 17));
        labelTimeGaussJordanComp = new QLabel(tab_4);
        labelTimeGaussJordanComp->setObjectName(QStringLiteral("labelTimeGaussJordanComp"));
        labelTimeGaussJordanComp->setGeometry(QRect(560, 470, 331, 17));
        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(470, 530, 91, 17));
        label_20 = new QLabel(tab_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(470, 500, 81, 17));
        labelErrorGaussJordanComp = new QLabel(tab_4);
        labelErrorGaussJordanComp->setObjectName(QStringLiteral("labelErrorGaussJordanComp"));
        labelErrorGaussJordanComp->setGeometry(QRect(560, 530, 331, 17));
        label_27 = new QLabel(tab_4);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(690, 20, 67, 17));
        tableAreaGaussJordanComp = new QTableWidget(tab_4);
        tableAreaGaussJordanComp->setObjectName(QStringLiteral("tableAreaGaussJordanComp"));
        tableAreaGaussJordanComp->setGeometry(QRect(690, 40, 161, 421));
        label_28 = new QLabel(tab_4);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(200, 20, 67, 17));
        tableAreaGaussComp = new QTableWidget(tab_4);
        tableAreaGaussComp->setObjectName(QStringLiteral("tableAreaGaussComp"));
        tableAreaGaussComp->setGeometry(QRect(200, 40, 161, 421));
        label_29 = new QLabel(tab_4);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(0, 20, 67, 17));
        label_30 = new QLabel(tab_4);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(470, 20, 67, 17));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        graphicsView = new QGraphicsView(tab_5);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 891, 551));
        tabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MNI_P2", 0));
        label->setText(QApplication::translate("MainWindow", "Quantidade de C\303\255rculos:", 0));
        label_2->setText(QApplication::translate("MainWindow", "C\303\255rculos:", 0));
        label_3->setText(QApplication::translate("MainWindow", "D:", 0));
        label_4->setText(QApplication::translate("MainWindow", "* R =", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Calcular", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Configura\303\247\303\265es", 0));
        label_5->setText(QApplication::translate("MainWindow", "Resultado Usando Gauss:", 0));
        radioButtonGauss->setText(QApplication::translate("MainWindow", "Usar Pivoteamento", 0));
        label_9->setText(QApplication::translate("MainWindow", "Tempo:", 0));
        labelTimeGauss->setText(QApplication::translate("MainWindow", "0", 0));
        labelInterationsGauss->setText(QApplication::translate("MainWindow", "0", 0));
        label_12->setText(QApplication::translate("MainWindow", "Opera\303\247\303\265es:", 0));
        labelErrorGauss->setText(QApplication::translate("MainWindow", "0", 0));
        label_14->setText(QApplication::translate("MainWindow", "Erro residual:", 0));
        label_21->setText(QApplication::translate("MainWindow", "Passo a Passo:", 0));
        label_23->setText(QApplication::translate("MainWindow", "Raios:", 0));
        label_24->setText(QApplication::translate("MainWindow", "\303\201reas:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Gauss", 0));
        label_6->setText(QApplication::translate("MainWindow", "Resultado Usando Gauss-Jordan:", 0));
        radioButtonGaussJordan->setText(QApplication::translate("MainWindow", "Usar Pivoteamento", 0));
        labelTimeGaussJordan->setText(QApplication::translate("MainWindow", "0", 0));
        labelErrorGaussJordan->setText(QApplication::translate("MainWindow", "0", 0));
        label_13->setText(QApplication::translate("MainWindow", "Opera\303\247\303\265es:", 0));
        label_15->setText(QApplication::translate("MainWindow", "Erro residual:", 0));
        labelInterationsGaussJordan->setText(QApplication::translate("MainWindow", "0", 0));
        label_10->setText(QApplication::translate("MainWindow", "Tempo:", 0));
        label_22->setText(QApplication::translate("MainWindow", "Passo a Passo:", 0));
        label_25->setText(QApplication::translate("MainWindow", "\303\201reas:", 0));
        label_26->setText(QApplication::translate("MainWindow", "Raios:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Gauss-Jordan", 0));
        radioButtonComp->setText(QApplication::translate("MainWindow", "Usar Pivoteamento", 0));
        label_7->setText(QApplication::translate("MainWindow", "Resultado Usando Gauss:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Resultado Usando Gauss-Jordan:", 0));
        labelTimeGaussComp->setText(QApplication::translate("MainWindow", "0", 0));
        label_16->setText(QApplication::translate("MainWindow", "Opera\303\247\303\265es:", 0));
        labelErrorGaussComp->setText(QApplication::translate("MainWindow", "0", 0));
        label_17->setText(QApplication::translate("MainWindow", "Erro residual:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Tempo:", 0));
        labelInterationsGaussComp->setText(QApplication::translate("MainWindow", "0", 0));
        label_18->setText(QApplication::translate("MainWindow", "Tempo:", 0));
        labelInterationsGaussJordanComp->setText(QApplication::translate("MainWindow", "0", 0));
        labelTimeGaussJordanComp->setText(QApplication::translate("MainWindow", "0", 0));
        label_19->setText(QApplication::translate("MainWindow", "Erro residual:", 0));
        label_20->setText(QApplication::translate("MainWindow", "Opera\303\247\303\265es:", 0));
        labelErrorGaussJordanComp->setText(QApplication::translate("MainWindow", "0", 0));
        label_27->setText(QApplication::translate("MainWindow", "\303\201reas:", 0));
        label_28->setText(QApplication::translate("MainWindow", "\303\201reas:", 0));
        label_29->setText(QApplication::translate("MainWindow", "Raios:", 0));
        label_30->setText(QApplication::translate("MainWindow", "Raios:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Comparativo", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Analise das Circunferencias", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
