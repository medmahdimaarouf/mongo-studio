#ifndef MONGODRIVERUTILS_H
#define MONGODRIVERUTILS_H
#include<QString>
#include<QtDebug>

class CollectionDocument{
public:
    CollectionDocument(){}
    CollectionDocument(QString id){this->id = id;}
    QString getId(){return this->id;}
    void addValue(QString key,QVariant value){this->data.insert(key,value);}
    void setJsonFormat(QString json){this->jsonFormat = json;}
    QString getJsonFormat(){return jsonFormat;}
private:
    QString id;
    QMap<QString,QVariant> data;
    QString jsonFormat ;
};


class DataBaseCollection{
public:
    void setName(QString name){this->name = name;}
    QString getName() {return this->name;}
    void setType(QString type){this->type = type;}
    QString getType(){return this->type;}
    void setJsonFormat(QString json){this->jsonFormat = json;}
    QString getJsonFormat(){return this->jsonFormat;}
    void addDocument(CollectionDocument document){this->documents.insert(document.getId(),document);}
    QList<CollectionDocument> getDocuments(){return this->documents.values();}
private:
    QString name;
    QString type;
    QString jsonFormat;
    QMap<QString,CollectionDocument> documents;
};

class DataBase{
    public:
    void setName(QString name){this->name = name;}
    void setSizeOnDisk(double sizeOnDisk){this->sizeOnDisk = sizeOnDisk;}
    void setIsEmty(bool isEmpty){this->_isEmpty = isEmpty;}
    void setJsonFormat(QString jsonData){this->jsonData = jsonData;}
    QString getName(){return this->name;}
    bool isEmpty(){return this->_isEmpty;}
    double getSizeOnDisk(){return this->sizeOnDisk;}
    QString toJson(){return this->jsonData;}
    void addCollection(DataBaseCollection collection){this->collections.insert(collection.getName(),collection);}
    DataBaseCollection getCollection(QString collectionName){return this->collections.value(collectionName);}
    QList<QString> getCollectionsNames(){return this->collections.keys();}
    QList<DataBaseCollection> getCollections (){return this->collections.values();}

    QString toString(){
        QString string_collections = "";
        for(DataBaseCollection c : getCollections()){
            string_collections += c.getJsonFormat() + ",";
        }
        string_collections.remove(string_collections.length() - 1,1);

        return  "{\"databaseinfo\":" + jsonData + ",\"collections\":[" + string_collections + "]},";
    }

private:
    QString name;
    bool _isEmpty;
    double sizeOnDisk;
    QString jsonData;
    QMap<QString,DataBaseCollection> collections;
};

class ConnectionUri{
public:
    ConnectionUri(){}
    ConnectionUri(QString protocol,QString host,unsigned int port) {
        setHost(host);
        setPort(port);
        setProtocol(protocol);
    }
    inline int getPort()const{return this->port;}
    inline QString getHost()const{return this->host;}
    inline QString getProtocol()const {return this->protocol;}

    inline void setPort(unsigned int &port){this->port = port?port:27072;}
    inline void setHost(QString &host){ this->host = host != NULL?host:"localhost";}
    inline void setProtocol(QString &protocol){this->protocol = protocol != NULL? protocol:QString("mongo");}

    virtual  QString  toString(){return this->protocol + "://" + this->host + ":" + QString::number(this->port);}
    virtual  std::string  toStdString(){return this->toString().toStdString();}
private:
    int port;
    QString host;
    QString protocol;
};


enum ConnectionExceptionReason {DOWNSERVER,PRESET};
struct ConnectionException{
    ConnectionExceptionReason reason;
    ConnectionUri uri;
};

#endif // MONGODRIVERUTILS_H
