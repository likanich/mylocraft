#include "database.hpp"
#include <QDebug>

Database::Database(QObject *parent) : QObject(parent)
{

}

Database::~Database()
{
    closeDataBase();
}

void Database::connectToDataBase()
{
    qDebug() << "Here";
    if(this->openDataBase()){
        if (!db.tables().contains("products")) {
            qDebug() << "connect to database";
            this->restoreDataBase();
        }
        qDebug() << db.tables();
    } else {
        qDebug() << "Failed to connect the database";
    }
}

bool Database::openDataBase()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("192.168.8.100");
    db.setDatabaseName("mylo");
    db.setUserName("mylo_user");
    db.setPassword("rjnbr");
    return db.open();
}

bool Database::restoreDataBase()
{
    if(!this->createTable()){
        return false;
    } else {
        return true;
    }
    return false;
}

void Database::closeDataBase()
{
    db.close();
}

bool Database::createTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE products ("
                           "id SERIAL PRIMARY KEY, "
                           "product VARCHAR(255)   NOT NULL,"
                           "price REAL             NOT NULL,"
                           "volume INT             NOT NULL,"
                           "for_recipe INT                NOT NULL"
                       " )"
                   )){
        qDebug() << "DataBase: error of create products";
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "Created";
        return true;
    }
    return false;
}
