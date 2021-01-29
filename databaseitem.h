#ifndef DATABASEITEM_H
#define DATABASEITEM_H

#include<QStandardItem>
#include<mongodriverutils.h>
#include<collectionitem.h>

class DataBaseItem:public QStandardItem
{
public:
    DataBaseItem(DataBase database);
};

#endif // DATABASEITEM_H
