#include "documentitem.h"

DocumentItem::DocumentItem(CollectionDocument document):QStandardItem(document.getId())
{
    this->setEditable(false);
    this->setCheckable(false);
    this->setIcon(QIcon(":/icons/icons/document.ico"));
    this->_document = document;
}

CollectionDocument DocumentItem::getDocument()
{
    return this->_document;
}
