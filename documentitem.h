#ifndef DOCUMENTITEM_H
#define DOCUMENTITEM_H
#include<QStandardItem>
#include "mongodriverutils.h"

class DocumentItem:public QStandardItem
{
public:
    DocumentItem(CollectionDocument document);
    CollectionDocument getDocument();
private:
    CollectionDocument _document;
};

#endif // DOCUMENTITEM_H
