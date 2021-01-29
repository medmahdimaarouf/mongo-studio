#ifndef DOCUMENTVIEW_H
#define DOCUMENTVIEW_H

#include <QWidget>
#include<collectionitem.h>
namespace Ui {
class DocumentView;
}

class DocumentView : public QWidget
{
    Q_OBJECT

public:
    explicit DocumentView(DocumentItem *docitem = NULL,QWidget * parent = NULL);
    ~DocumentView();
    QString getName(){return this->docitem->text();}

private:
    Ui::DocumentView *ui;
    DocumentItem *docitem;
};

#endif // DOCUMENTVIEW_H
