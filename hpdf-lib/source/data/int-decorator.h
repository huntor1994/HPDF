#ifndef INTDECORATOR_H
#define INTDECORATOR_H

#include <hpdf-lib_global.h>
#include <data/data-decorator.h>

namespace hpdf{
namespace data{

class HPDFLIBSHARED_EXPORT IntDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit IntDecorator(Entity *parentEntity = nullptr
            ,const QString& key="SomeItemKey"
            ,const QString& label=""
            ,const int& value=0);
    ~IntDecorator() override;

    IntDecorator& setValue(const int& value);
    int value() const;

    QJsonValue jsonValue() const override;
    void update(const QJsonObject &jsonObject) override;

signals:
    void valueChanged();
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};
}}
#endif // INTDECORATOR_H
