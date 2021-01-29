#ifndef COLLECTIONITEM_H
#define COLLECTIONITEM_H
#include<QStandardItem>
#include<mongodriverutils.h>
#include<documentitem.h>

class CollectionItem:public QStandardItem
{
public:
    CollectionItem(DataBaseCollection collection);
};

#endif // COLLECTIONITEM_H
