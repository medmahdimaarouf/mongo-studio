#ifndef MONGODRIVERUTILS_H
#define MONGODRIVERUTILS_H
#include<QString>
#include<QtDebug>
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
private:
    QString name;
    bool _isEmpty;
    double sizeOnDisk;
    QString jsonData;
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
