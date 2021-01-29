#ifndef CONNECTIONITEM_H
#define CONNECTIONITEM_H

#include <QObject>
#include<QStandardItem>
#include<mongodriverutils.h>
#include<databaseitem.h>
class ConnectionItem : public QStandardItem
{
public:
    explicit ConnectionItem(ConnectionUri uri);

signals:
private:
    ConnectionUri uri;
};

#endif // CONNECTIONITEM_H
