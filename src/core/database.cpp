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
                           "p_id SERIAL PRIMARY KEY, "
                           "product VARCHAR(255)   NOT NULL,"
                           "price REAL             NOT NULL,"
                           "volume INT             NOT NULL,"
                           "for_recipe INT         NOT NULL"
                       " )"
                   )){
        qDebug() << "DataBase: error of create products";
        qDebug() << query.lastError().text();
        return false;
    }
    query.clear();
    if(!query.exec( "CREATE TABLE warehouse ("
                           "p_id INT REFERENCES products(p_id),"
                           "count INT NOT NULL,"
                           "CONSTRAINT pk PRIMARY KEY(p_id)"
                       " )"
                   )){
        qDebug() << "DataBase: error of create warehouse";
        qDebug() << query.lastError().text();
        return false;
    }
    query.clear();
    if(!query.exec( "CREATE TABLE types_recipes ("
                           "t_id  SERIAL PRIMARY KEY,"
                           "type  VARCHAR(50) NOT NULL"
                       " )"
                   )){
        qDebug() << "DataBase: error of create types";
        qDebug() << query.lastError().text();
        return false;
    }
    query.clear();
    if(!query.exec( "CREATE TABLE recipes ("
                           "r_id    SERIAL PRIMARY KEY,"
                           "recipe  VARCHAR(255) NOT NULL,"
                           "t_id    INT REFERENCES types_recipes(t_id),"
                           "p_id    INT REFERENCES products(p_id),"
                           "count   INT NOT NULL"
                       " )"
                   )){
        qDebug() << "DataBase: error of create recipes";
        qDebug() << query.lastError().text();
        return false;
    }
    qDebug() << "Created";
    return true;

}
