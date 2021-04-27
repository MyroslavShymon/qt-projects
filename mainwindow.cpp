#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QDir>
#include <QFile>
#include <QUrl>

int countOfFiles = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int rows = ui->spinBox->text().toInt();
    int colums = ui->spinBox_2->text().toInt();
    ui->tableWidget->setRowCount(rows);
    ui->tableWidget->setColumnCount(colums);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colums; j++) {
            QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(rand() % 5));
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem(tr(""));
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    QString lineText = ui->lineEdit->text();
    item->setText(lineText);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString path = "E:/QT_projects/Project3/build-Project3-Desktop_Qt_6_0_0_MinGW_64_bit-Debug/results";
    QDir dir( path );
    dir.setFilter( QDir::AllEntries | QDir::NoDotAndDotDot );
    ui->label_5->setText(QString::number(dir.count() + 1));

    countOfFiles = dir.count() + 1;

    QFile file(tr("E:/QT_projects/Project3/build-Project3-Desktop_Qt_6_0_0_MinGW_64_bit-Debug/results/out%1.txt").arg(countOfFiles));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    file.flush();
    QString result = "There are no saddle points in the matrix";

    ui->label_4->setText("There are no saddle points in the matrix");
    int n = ui->tableWidget->rowCount(), m = ui->tableWidget->columnCount(), maxi, countOfSaddlesPoints = 0;

    int ** x = new int * [n];
    for (int i = 0; i < n; i++)
        x[i] = new int[m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            x[i][j] = ui->tableWidget->item(i, j)->text().toInt();
            out << ui->tableWidget->item(i, j)->text() << "\t";
        }
        out << "\n";
    }
    int  max[m];
    for (int i = 0; i < m; i++){
        max[i] = -100;
    }
    for (int i = 0; i < n; i++) {
        int min = x[i][0];
        for (int j = 1; j < m; j++) {
            if ( min > x[i][j] ) {
                min = x[i][j];
            }
        }
        for (int j = 0; j < m; j++) {
            if (x[i][j] == min) {
                if (max[j] != -100){
                    maxi = max[j];
                }
                else {
                    maxi = x[i][j];
                    for (int l = 0; l < n; l++) {
                        if (maxi < x[l][j]){
                            maxi = x[l][j];
                        }
                    }
                    max[j] = maxi;
                }
                if ( maxi == min) {
                    countOfSaddlesPoints++;
                    if(countOfSaddlesPoints == 1)
                    {
                        result = "There is one saddle point in the matrix";
                    }
                    else{
                        result = "Count of saddle points in the matrix: " + QString::number(countOfSaddlesPoints);
                    }

                    ui->tableWidget->item(i, j)->setBackground(Qt::red);
                    ui->label_4->setText(result);
                }
            }
        }
    }
    out<< result;
    file.close();
}

void MainWindow::on_pushButton_4_clicked()
{
    QDesktopServices::openUrl(QUrl(tr("E:/QT_projects/Project3/build-Project3-Desktop_Qt_6_0_0_MinGW_64_bit-Debug/results/out%1.txt").arg(countOfFiles)));
}
