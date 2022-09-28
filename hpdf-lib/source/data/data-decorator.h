#ifndef DATADECORATOR_H
#define DATADECORATOR_H

#include <QObject>
#include<QJsonObject>
#include<QJsonValue>
#include<QScopedPointer>

#include <hpdf-lib_global.h>

namespace hpdf {
namespace data {

class Entity;

class HPDFLIBSHARED_EXPORT DataDecorator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_label READ label CONSTANT)
public:
    explicit DataDecorator(Entity *parent = nullptr
            ,const QString& key="SomeItemKey"
            ,const QString& label="");
    virtual ~DataDecorator() override;

    const QString& key() const;
    const QString& label() const;
    Entity *parentEntity();

    virtual QJsonValue jsonValue() const=0;
    virtual void update(const QJsonObject& jsonObject)=0;

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};
}
}


#endif // DATADECORATOR_H
