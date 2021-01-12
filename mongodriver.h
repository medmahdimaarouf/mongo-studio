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

class MongoDriver
{
public:
    static MongoDriver *driverInstence();
    static MongoDriver *driverInstence(ConnectionUri uri);

    QMap<QString,DataBase> getDataBases();
    void getDataBaseCollections(DataBase database);
private:
    MongoDriver(ConnectionUri uri);
    static MongoDriver *instance ;
    mongocxx::client client;
};

#endif // MONGODRIVER_H
