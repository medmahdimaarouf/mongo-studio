#include "mongodriver.h"
#include<iostream>

QMap<QString, DataBase> MongoConnection::getDataBases()
{
    QMap<QString, DataBase> data_bases;
    mongocxx::cursor cursor = this->client.list_databases();
    for(mongocxx::cursor::iterator iterator = cursor.begin() ;iterator != cursor.end();iterator++){
        DataBase data_base = fetchDataBase(iterator.operator->());
        data_bases.insert(data_base.getName(),data_base);
    }

    return data_bases;
}

DataBase MongoConnection::fetchDataBase(const bsoncxx::document::view *view)
{
    DataBase data_base;
    data_base.setIsEmty(view->operator[]("empty").get_bool().value);
    data_base.setName(view->operator[]("name").get_utf8().value.data());
    data_base.setSizeOnDisk(view->operator[]("sizeOnDisk").get_double().value);
    data_base.setJsonFormat(QString::fromStdString(bsoncxx::to_json(*view)));

    mongocxx::database driver_database = this->client.database(data_base.getName().toStdString());

    mongocxx::cursor collections = driver_database.list_collections();
    for(mongocxx::cursor::iterator iterator = collections.begin(); iterator != collections.end();iterator++){
        const bsoncxx::document::view *view = iterator.operator->();
        DataBaseCollection collection = fetchCollection(driver_database,view);
        data_base.addCollection(collection);
    }
    return data_base;
}

DataBaseCollection MongoConnection::fetchCollection(mongocxx::database database, const bsoncxx::document::view *view)
{
    DataBaseCollection collection;
    mongocxx::collection driver_collection = database.collection(view->operator[]("name").get_utf8().value.data());
    collection.setJsonFormat(QString::fromStdString(bsoncxx::to_json(*view)));
    collection.setName(view->operator[]("name").get_utf8().value.data());
    collection.setType(view->operator[]("type").get_utf8().value.data());
    mongocxx::cursor cursor = driver_collection.find({});

    for(mongocxx::cursor::iterator iterator = cursor.begin();iterator != cursor.end();iterator++){
        CollectionDocument document = fetchDocument(driver_collection,iterator.operator->());
        collection.addDocument(document);
    }
    return collection;
}

CollectionDocument MongoConnection::fetchDocument(mongocxx::collection collection,const bsoncxx::document::view *view)
{
    QString json = bsoncxx::to_json(*view).data();
    bsoncxx::document::element elment_id = view->operator[]("_id");
    QString docId = "uid:binary";
    if(elment_id.type() == bsoncxx::type::k_utf8){
        docId = elment_id.get_utf8().value.data();
        view->operator[]("id");
    }else
    if(elment_id.type() == bsoncxx::type::k_oid){
        docId =QString::fromStdString(elment_id.get_oid().value.to_string());
    }

    CollectionDocument document(docId) ;
    document.setJsonFormat(json);
    qDebug()<<document.getJsonFormat();

    for(bsoncxx::document::view::iterator iterator = view->begin();iterator != view->end();iterator++){
        QString key = iterator->key().data();
        //qDebug()<<"key"<<key;
        bsoncxx::document::element element = iterator->operator[](iterator->key().data());
        if(element) QVariant variant = fetchElement(element);
    }

    return document;
}

QVariant MongoConnection::fetchElement(const bsoncxx::document::element element)
{
    QString type = "";
    if(element.type() == bsoncxx::type::k_array) type = "array";
    if(element.type() == bsoncxx::type::k_binary) type = "k_binary";
    if(element.type() == bsoncxx::type::k_bool) type = "k_bool";
    if(element.type() == bsoncxx::type::k_code) type = "k_code";
    if(element.type() == bsoncxx::type::k_codewscope) type = "k_codewscope";
    if(element.type() == bsoncxx::type::k_date) type = "k_date";
    if(element.type() == bsoncxx::type::k_dbpointer) type = "k_dbpointer";
    if(element.type() == bsoncxx::type::k_decimal128) type = "k_dbpointer";
    if(element.type() == bsoncxx::type::k_document) type = "k_document";
    if(element.type() == bsoncxx::type::k_double) type = "k_double";
    if(element.type() == bsoncxx::type::k_int32) type = "k_int32";
    if(element.type() == bsoncxx::type::k_int64) type = "k_int64";
    if(element.type() == bsoncxx::type::k_maxkey) type = "k_maxkey";
    if(element.type() == bsoncxx::type::k_minkey) type = "k_minkey";
    if(element.type() == bsoncxx::type::k_null) type = "k_null";
    if(element.type() == bsoncxx::type::k_oid) type = "k_oid";
    if(element.type() == bsoncxx::type::k_regex) type = "k_regex";
    if(element.type() == bsoncxx::type::k_symbol) type = "k_symbol";
    if(element.type() == bsoncxx::type::k_timestamp) type = "k_undefined";
    if(element.type() == bsoncxx::type::k_undefined) type = "k_timestamp";
    if(element.type() == bsoncxx::type::k_utf8) type = "k_utf8";
    qDebug()<<"type : "<< type ;
    return QVariant();

}


MongoConnection::MongoConnection(ConnectionUri uri){
    this->uri = uri;
    this->client = mongocxx::client{mongocxx::uri{uri.toStdString()}};
}

