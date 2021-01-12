#include "mongodriver.h"
#include<iostream>
MongoDriver * MongoDriver::instance = NULL;

MongoDriver * MongoDriver::driverInstence()
{
    return MongoDriver::instance ;
}

MongoDriver *MongoDriver::driverInstence(ConnectionUri  uri)
{
     ConnectionException exception;
    if(MongoDriver::instance != NULL){
        ConnectionException exception ;
        exception.reason = PRESET;
        exception.uri = uri;
        throw exception;
    }
    else{

        try {
            return new MongoDriver(uri);

        } catch (const std::exception& xcp) {
            ConnectionException exception;
            exception.uri = uri;
            exception.reason = DOWNSERVER;
            throw exception;
        }
    }

}

QMap<QString, DataBase> MongoDriver::getDataBases()
{
    QMap<QString, DataBase> data_bases;
    mongocxx::cursor cursor = this->client.list_databases();

    for(mongocxx::cursor::iterator iterator = cursor.begin() ;iterator != cursor.end();iterator++){

        const bsoncxx::document::view *view = iterator.operator->();
        //qDebug()<<"data"<<QString::fromStdString(bsoncxx::to_json(*view));
        std::string db_name = view->operator[]("name").get_utf8().value.data();
        bool is_empty = view->operator[]("empty").get_bool().value;
        float size_on_disk = view->operator[]("sizeOnDisk").get_double().value;
        //qDebug() <<"DB NAME : "<< QString::fromStdString(db_name) << " IsEmty : " << is_empty << "Size on Disk : " << size_on_disk;
        DataBase data_base;
        data_base.setIsEmty(is_empty);
        data_base.setName(QString::fromStdString(db_name));
        data_base.setSizeOnDisk(size_on_disk);
        data_base.setJsonFormat(QString::fromStdString(bsoncxx::to_json(*view)));
        data_bases.insert(data_base.getName(),data_base);
    }

    return data_bases;
}

void MongoDriver::getDataBaseCollections(DataBase database)
{
    mongocxx::database driver_database = this->client.database(database.getName().toStdString());
    mongocxx::cursor collections = driver_database.list_collections();
    for(mongocxx::cursor::iterator iterator = collections.begin(); iterator != collections.end();iterator++){
        qDebug()<<"collection : " << QString::fromStdString(bsoncxx::to_json(*(iterator.operator->())));
    }

}

MongoDriver::MongoDriver(ConnectionUri uri){
    this->client = mongocxx::client{mongocxx::uri{uri.toStdString()}};
    MongoDriver::instance = this;
}
