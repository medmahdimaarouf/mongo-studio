#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtDebug>
#include<mongodriver.h>
//        QMessageBox::warning(this,"Monodb connection","Unable to connect to server mongodb:::localhost:27017");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MongoDriver * driver = MongoDriver::driverInstence(ConnectionUri("mongodb","127.0.0.1",27017));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    try{
        QMap<QString,DataBase> databses =  MongoDriver::driverInstence()->getDataBases();
        if(!databses.isEmpty()){
           DataBase database = databses.value("tutor");
           MongoDriver::driverInstence()->getDataBaseCollections(database);
        }
    }catch(ConnectionException ex){
        qDebug()<<"excpe conn "<<ex.reason;
    }catch(mongocxx::exception ex){
        qDebug()<<"excpe conn "<<ex.what();
    }
}
