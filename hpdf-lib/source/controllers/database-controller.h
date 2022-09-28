#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QObject>
#include <QScopedPointer>
#include <hpdf-lib_global.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QtSql/QSqlError>
#include <data/datetime-decorator.h>
namespace hpdf {
namespace controllers {
class HPDFLIBSHARED_EXPORT DatabaseController : public QObject
{
    Q_OBJECT
public:

    explicit DatabaseController(QObject *parent = nullptr);
    ~DatabaseController() override;

    bool createRow(const QString& tableName, const QString& id, const QJsonObject& jsonObject,data::DateTimeDecorator&) const ;
    bool deleteRow(const QString& tableName, const QString& id) const ;
    QJsonArray find(const QString& tableName, const QString& searchText) const ;
    QJsonObject readRow(const QString& tableName, const QString& id) const ;
    bool updateRow(const QString& tableName, const QString& id, const QJsonObject& jsonObject) const ;
    QJsonArray readRows(const QString& tableName)const;
signals:

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;

};
}}
#endif // DATABASECONTROLLER_H
