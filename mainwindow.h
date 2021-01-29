#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtCore>
#include<QMessageBox>
#include<QStandardItemModel>

#include<mongodriverutils.h>
#include<connectionitem.h>
//#include
#include<documentview.h>
#include<dialogconnect.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void refreshConnections();

    void on_documentTabView_tabCloseRequested(int index);

    void on_actionConnect_triggered();

    void on_connectionsTree_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    void addNewDocumentView(DocumentView * documentView);
    QStandardItemModel * connectionsModel;
    QList<ConnectionUri> connectionsuris ;
    void initConnectionsTree();
    void connect(ConnectionUri uri);


};
#endif // MAINWINDOW_H
