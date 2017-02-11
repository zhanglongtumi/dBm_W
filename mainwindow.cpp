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
    QString unit;
    QString input_value;
    unit = ui->comboBox->currentText();
    input_value = ui->lineEdit->text();
    qDebug() << input_value + unit;

    float dbm;
    if (unit == "W") {
        dbm = 10 * log10(input_value.toFloat()/(pow(10,-3)));
    }
    if (unit == "mW") {
        dbm = 10 * log10(input_value.toFloat()/(1));
    }
    if (unit == "uW") {
        dbm = 10 * log10(input_value.toFloat()/(pow(10,3)));
    }
    if (unit == "nW") {
        dbm = 10 * log10(input_value.toFloat()/(pow(10,6)));
    }

    ui->label->setText(QString::number(dbm, 'f', 2) + "dBm");
}

void MainWindow::on_pushButton_2_clicked()
{
    float input_value;
    input_value = ui->lineEdit_2->text().toFloat();

    ui->label_2->setText(QString::number(pow(10,(input_value/10)-3)) + "W");
}
