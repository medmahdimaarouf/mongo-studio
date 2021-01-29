#include "collectionitem.h"

CollectionItem::CollectionItem(DataBaseCollection collection):QStandardItem(collection.getName())
{
    this->setEditable(false);
    this->setCheckable(false);
    this->setIcon(QIcon(":/icons/icons/data.ico"));
    for(CollectionDocument document : collection.getDocuments()){
        DocumentItem * documentItem = new DocumentItem(document);
        this->appendRow(documentItem);
    }
}
