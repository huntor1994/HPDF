#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QScopedPointer>
#include <map>
#include <data/data-decorator.h>
#include <hpdf-lib_global.h>
//#include <data/entity-collection.h>
#include <QJsonArray>
//#include <controllers/i-database-controller.h>
#include <QUuid>
#include <data/string-decorator.h>
namespace hpdf {
namespace data {
class HPDFLIBSHARED_EXPORT Entity : public QObject
{
    Q_OBJECT

public:
    Entity(QObject *parent = nullptr
            ,const QString& key="SomeEntityKey");

    Entity(QObject* parent
            ,const QString& key
            ,const QJsonObject& jsonObject);
    virtual ~Entity();
    const QString& id() const;
    const QString& key() const;
    void update(const QJsonObject& jsonObject);
    QJsonObject toJson() const;
signals:
    void childEntitiesChanged();
    void dataDecoratorsChanged();
    void childCollectionsChanged(const QString& collectionKey);
protected:
    void setPrimaryKey(StringDecorator* primaryKey);
    Entity* addChild(Entity* childEntity,const QString& key);
    DataDecorator* addDataItem(DataDecorator* dataDecorator);
    //EntityCollectionBase* addChildCollection(EntityCollectionBase* entityCollection);
protected:
    class Implementation;
    QScopedPointer<Implementation> implementation;

};
}
}


#endif // ENTITY_H
