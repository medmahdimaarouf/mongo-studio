#include "databaseitem.h"

DataBaseItem::DataBaseItem(DataBase database):QStandardItem(database.getName())
{
    this->setIcon(QIcon(":/icons/icons/current_db.ico"));
    this->setEditable(false);
    this->setCheckable(false);
    for(DataBaseCollection c:database.getCollections()){
        CollectionItem * collectionItem = new CollectionItem(c);
        this->appendRow(collectionItem);
    }
}
