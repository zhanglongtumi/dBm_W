#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <qmath.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    float input_value;
    float dbm;
    ///unit        为   W,mW,uW,nW
    ///unit_id    为   0,1,2,3
    int unit_id = ui->comboBox->currentIndex(); //// 获得功率输入值的单位
    input_value = ui->lineEdit->text().toFloat(); /// 输入功率值
    dbm = 10 * log10(input_value/(pow(10, 3 * (unit_id - 1))));

    ui->label->setText(QString::number(dbm, 'f', 2) + "dBm");
}

void MainWindow::on_pushButton_2_clicked()
{
    float input_value, dBm;
    input_value = ui->lineEdit_2->text().toFloat(); /// 获得dBm值
    dBm = pow(10,(input_value/10) - 3);
    ui->label_2->setText(QString::number(dBm) + " W");
}
