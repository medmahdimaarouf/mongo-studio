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
    this->initConnectionsTree();
    this->showMaximized();
    this->connectionsuris.append(ConnectionUri("mongodb","127.0.0.1",27017));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshConnections()
{



}



void MainWindow::on_documentTabView_tabCloseRequested(int index)
{
    ui->documentTabView->removeTab(index);
}

void MainWindow::addNewDocumentView(DocumentView *documentView)
{
    ui->documentTabView->addTab(documentView,documentView->getName());
    ui->documentTabView->setCurrentIndex(ui->documentTabView->count() - 1);
}

void MainWindow::initConnectionsTree()
{
    this->connectionsModel = new QStandardItemModel(this);
    this->ui->connectionsTree->setModel(this->connectionsModel);
}

void MainWindow::connect(ConnectionUri uri)
{
    try{
        MongoConnection connection = MongoConnection(uri);
        ConnectionItem * connectionItem = new ConnectionItem(uri);
        this->connectionsModel->appendRow(connectionItem);
        this->connectionsuris<<uri;
    }catch(mongocxx::exception ex){
        QMessageBox::warning(this,"Monodb connection","Unable to connect to server "+ uri.toString());
    }

}

void MainWindow::on_actionConnect_triggered()
{
    DialogConnect * dialogConnect = new DialogConnect(this);
    if(dialogConnect->exec() == QDialog::Accepted){
       ConnectionUri uri("mongodb",dialogConnect->getHost(),dialogConnect->getPort());
       this->connect(uri);
    }
}

void MainWindow::on_connectionsTree_clicked(const QModelIndex &index)
{
    QStandardItem * item = this->connectionsModel->itemFromIndex(index);
    if(dynamic_cast<DocumentItem*>(item)){
        DocumentView * documentView = new DocumentView(static_cast<DocumentItem*>(item),NULL);
        this->addNewDocumentView(documentView);
    }
}
