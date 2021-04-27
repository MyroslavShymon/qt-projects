#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ticket.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setValidator(new QIntValidator(0, 100, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QList<Ticket> tickets;

void MainWindow::on_pushButton_clicked()
{
    tickets.push_back({
                          ui->lineEdit->text(),
                          ui->lineEdit_2->text().toInt(),
                          ui->lineEdit_7->text(),
                          ui->lineEdit_3->text(),
                          ui->dateEdit->date()
                      });
}

void showPlainText(int i, Ui::MainWindow *ui){
    ui->plainTextEdit->appendPlainText(tickets[i].getPlace());
    ui->plainTextEdit->appendPlainText(QString::number(tickets[i].getNumberOfRace()));
    ui->plainTextEdit->appendPlainText(tickets[i].getSurname());
    ui->plainTextEdit->appendPlainText(tickets[i].getInitials());
    ui->plainTextEdit->appendPlainText(tickets[i].getData().toString("yyyy-MM-dd"));
}

void MainWindow::on_pushButton_5_clicked()
{
    for(int i = 0; i < tickets.size(); i++){
        showPlainText(i, ui);
    }
    ui->tableWidget->setRowCount(tickets.size());
    ui->tableWidget->setColumnCount(5);
    for (int i = 0; i < tickets.size(); i++) {
        for (int j = 0; j < 5;) {
            QTableWidgetItem *item1 = new QTableWidgetItem(tr("%1").arg(tickets[i].getPlace()));
            ui->tableWidget->setItem(i, j, item1);
            j++;
            QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(QString::number(tickets[i].getNumberOfRace())));
            ui->tableWidget->setItem(i, j, item2);
            j++;
            QTableWidgetItem *item3 = new QTableWidgetItem(tr("%1").arg(tickets[i].getSurname()));
            ui->tableWidget->setItem(i, j, item3);
            j++;
            QTableWidgetItem *item4 = new QTableWidgetItem(tr("%1").arg(tickets[i].getInitials()));
            ui->tableWidget->setItem(i, j, item4);
            j++;
            QTableWidgetItem *item5 = new QTableWidgetItem(tr("%1").arg(tickets[i].getData().toString("yyyy-MM-dd")));
            ui->tableWidget->setItem(i, j, item5);
            j++;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    tickets.remove(ui->lineEdit_4->text().toInt() - 1);
}

void MainWindow::on_pushButton_3_clicked()
{
    tickets.removeLast();
}

void MainWindow::on_pushButton_4_clicked()
{
    for(int i = 0; i < tickets.size(); i++){
        if(tickets[i].getNumberOfRace() == ui->lineEdit_5->text().toInt()){
            showPlainText(i, ui);
        }
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_pushButton_7_clicked()
{
    for(int i = 0; i < tickets.size(); i++){
        if(tickets[i].getData().toString("yyyy-MM-dd") == ui->lineEdit_6->text()){
            showPlainText(i, ui);
        }
    }
}
