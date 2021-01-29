#include "documentview.h"
#include "ui_documentview.h"

DocumentView::DocumentView(DocumentItem * docitem, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DocumentView)
{
    ui->setupUi(this);
    this->docitem = docitem;
    qDebug()<<"json"<<docitem->getDocument().getJsonFormat();
    this->ui->jsondoc->setPlainText(docitem->getDocument().getJsonFormat());
}

DocumentView::~DocumentView()
{
    delete ui;
}
