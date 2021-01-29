#ifndef MONGODRIVER_H
#define MONGODRIVER_H
#include<mongodriverutils.h>
#include<QString>
#include<QDebug>
#include <cstdlib>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/stdx/string_view.hpp>
#include <mongocxx/exception/exception.hpp>

#include<mongocxx/cursor.hpp>
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;
using bsoncxx::stdx::string_view;
using mongocxx::collection;
using mongocxx::validation_criteria;

class MongoConnection
{

public:
    MongoConnection(ConnectionUri uri);
    QMap<QString,DataBase> getDataBases();
    QString getJson(){
        QMap<QString,DataBase> databses =  this->getDataBases();
        QString sdebug = "";

        if(!databses.isEmpty()){
           for(DataBase db :this->getDataBases()){
               sdebug += db.toString();
           }
           sdebug = "[" + sdebug.remove(sdebug.length() -1,1) + "]";
        }
        return sdebug;
    }

    ConnectionUri getUri()const{return uri;}

    DataBase fetchDataBase(const bsoncxx::document::view *view);
    DataBaseCollection fetchCollection(mongocxx::database database,const bsoncxx::document::view *view);
    CollectionDocument fetchDocument(mongocxx::collection collection, const bsoncxx::document::view *view);
    QVariant fetchElement(const bsoncxx::document::element element);
private:
    mongocxx::client client;
    ConnectionUri uri;
//slots:
};

#endif // MONGODRIVER_H
