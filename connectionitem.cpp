#include "connectionitem.h"
#include<mongodriver.h>

ConnectionItem::ConnectionItem(ConnectionUri uri) : QStandardItem(uri.getHost())
{
    this->uri = uri;
    setEditable(false);
    setCheckable(false);
    setIcon(QIcon(":/icons/icons/connection.ico"));

    MongoConnection connection(uri);
    for(DataBase db : connection.getDataBases()){
        DataBaseItem * databaseitem = new DataBaseItem(db);
        this->appendRow(databaseitem);
    }
}
