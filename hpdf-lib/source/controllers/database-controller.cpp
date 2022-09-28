#include "database-controller.h"
namespace hpdf {
namespace controllers {
class DatabaseController::Implementation
{
public:
    Implementation(DatabaseController* _databaseController)
        :databaseController(_databaseController){
        if(initialise()){
            qDebug()<<"Database created using Sqlite version: "+sqliteVersion();

            if(createTables()){
                qDebug()<<"Database tables created";
            }else{
                qDebug()<<"ERROR: Unable to create database tables";
            }
        }else{
            qDebug()<<"ERROR: Unable to open database";
        }

    }
    DatabaseController* databaseController{nullptr};
    QSqlDatabase database;
private:
    bool initialise(){
        database=QSqlDatabase::addDatabase("QSQLITE","hpdf");
        database.setDatabaseName("hpdf.sqlite");
        return database.open();
    }

    bool createTables(){
        QString tableName="RecentlyOpenedFiles";
        //qDebug()<<"tableName:"<<tableName;
        return createJsonTable(tableName);
    }

    bool createJsonTable(const QString& tableName)const{
        QSqlQuery query(database);
        QString sqlStatement =  "CREATE TABLE IF NOT EXISTS " + tableName + " (id text primary key, json text not null, date text not null)";
        if(!query.prepare(sqlStatement)) return false;
        return query.exec();
    }

    QString sqliteVersion() const{
        QSqlQuery query(database);
        query.exec("SELECT sqlite_version()");
        if(query.next())return query.value(0).toString();
        return QString::number(-1);
    }
};
DatabaseController::DatabaseController(QObject *parent)
    : QObject{parent}
{
    implementation.reset(new Implementation(this));
}

DatabaseController::~DatabaseController(){

}

bool DatabaseController::createRow(const QString& tableName, const QString& id, const QJsonObject& jsonObject,data::DateTimeDecorator& date) const {
    if(tableName.isEmpty()) return false;
    if(id.isEmpty()) return false;
    if(jsonObject.isEmpty()) return false;

    QSqlQuery query(implementation->database);

    QString sqlStatement = "INSERT OR REPLACE INTO " + tableName + " (id, json, date) VALUES (:id, :json, :date)";

    if(!query.prepare(sqlStatement)) {
        qDebug()<<"Database Error:"<<query.lastError();
        return false;
    }

    query.bindValue(":id",QVariant(id));
    query.bindValue(":json",QVariant(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact)));
    query.bindValue(":date",QVariant(date.toIso8601String()));
    if(!query.exec()) {
        qDebug()<<"Database Error:"<<query.lastError();
        return false;
    }
    sqlStatement= "SELECT COUNT(json) FROM "+tableName;
    if(!query.prepare(sqlStatement)) {
        qDebug()<<"Database Get Count Prepare Error:"<<query.lastError();
        return false;
    }
    if(!query.exec()) {
        qDebug()<<"Database Get Count Exec Error:"<<query.lastError();
        return false;
    }
    query.first();
    int count = query.value(0).toInt();
    if(count>11){
        sqlStatement= "DELETE FROM "+tableName+" WHERE Id = (SELECT Id FROM "+tableName+" ORDER BY date ASC LIMIT 1)";
    }
    if(!query.prepare(sqlStatement)) {
        qDebug()<<"Database Delete Prepare Error:"<<query.lastError();
        return false;
    }
    if(!query.exec()) {
        qDebug()<<"Database Delete Exec Error:"<<query.lastError();
        return false;
    }
    return query.numRowsAffected()>0;
}

bool DatabaseController::deleteRow(const QString& tableName, const QString& id) const {
    if (tableName.isEmpty()) return false;
    if (id.isEmpty()) return false;
    QSqlQuery query(implementation->database);
    QString sqlStatement = "DELETE FROM " + tableName + " WHERE id=:id";
    if (!query.prepare(sqlStatement)) return false;
    query.bindValue(":id", QVariant(id));
    if(!query.exec()) {
        qDebug()<<query.lastError();
        return false;
    }
    return query.numRowsAffected() > 0;

}

QJsonArray DatabaseController::find(const QString& tableName, const QString& searchText) const{
    if (tableName.isEmpty()) return {};
    if (searchText.isEmpty()) return {};
    QSqlQuery query(implementation->database);
    QString sqlStatement = "SELECT json FROM " + tableName + " where lower(json) like :searchText";
    if (!query.prepare(sqlStatement)) return {};
    query.bindValue(":searchText", QVariant("%" + searchText.toLower() + "%"));
    if (!query.exec()) return {};
    QJsonArray returnValue;
    while ( query.next() ) {
        auto json = query.value(0).toByteArray();
        auto jsonDocument = QJsonDocument::fromJson(json);
        if (jsonDocument.isObject()) {
            returnValue.append(jsonDocument.object());
        }
    }
    return returnValue;

}

QJsonObject DatabaseController::readRow(const QString& tableName, const QString& id) const {
    if (tableName.isEmpty()) return {};
    if (id.isEmpty()) return {};
    QSqlQuery query(implementation->database);
    QString sqlStatement = "SELECT json FROM " + tableName + " WHERE id=:id";
    if (!query.prepare(sqlStatement)) return {};
    query.bindValue(":id", QVariant(id));
    if (!query.exec()) return {};
    if (!query.first()) return {};
    auto json = query.value(0).toByteArray();
    auto jsonDocument = QJsonDocument::fromJson(json);
    if (!jsonDocument.isObject()) return {};
    return jsonDocument.object();
}

QJsonArray DatabaseController::readRows(const QString& tableName) const{
    if (tableName.isEmpty()) return{};
    QSqlQuery query(implementation->database);

    QString sqlStatement = "SELECT json FROM " + tableName + " ORDER BY date DESC";

    if (!query.prepare(sqlStatement))
    {
        qDebug()<<query.lastError();
        return{};
    }
    if (!query.prepare(sqlStatement)) return {};
    if (!query.exec()) return {};
    QJsonArray returnValue;
    while ( query.next() ) {
        auto json = query.value(0).toByteArray();
        auto jsonDocument = QJsonDocument::fromJson(json);
        if (jsonDocument.isObject()) {
            returnValue.append(jsonDocument.object());
        }
    }
    return returnValue;

}

bool DatabaseController::updateRow(const QString& tableName, const QString& id, const QJsonObject& jsonObject) const {
    if (tableName.isEmpty()) return false;
    if (id.isEmpty()) return false;
    if (jsonObject.isEmpty()) return false;

    QSqlQuery query(implementation->database);

    QString sqlStatement = "UPDATE " + tableName + " SET json=:json WHERE id=:id";

    if (!query.prepare(sqlStatement))
    {
        qDebug()<<query.lastError();
        return false;
    }

    query.bindValue(":id", QVariant(id));
    query.bindValue(":json", QVariant(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact)));

    if(!query.exec()) return false;

    return query.numRowsAffected() > 0;
}



}
}

