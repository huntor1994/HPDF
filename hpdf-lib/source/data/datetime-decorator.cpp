#include "datetime-decorator.h"

#include <QVariant>
namespace hpdf {
namespace data {
class DateTimeDecorator::Implementation{
public:
    Implementation(DateTimeDecorator* _datetimeDecorator, const QDateTime&
                   _value)
        : datetimeDecorator(_datetimeDecorator)
        , value(_value)
    {
    }
    DateTimeDecorator* datetimeDecorator{nullptr};
    QDateTime value;
};

DateTimeDecorator::DateTimeDecorator(Entity *parentEntity
                                 ,const QString& key
                                 ,const QString& label
                                 ,const QDateTime& value) : DataDecorator(parentEntity,key,label)
{
    implementation.reset(new Implementation(this,value));
}

DateTimeDecorator::~DateTimeDecorator(){

}

DateTimeDecorator& DateTimeDecorator::setValue(const QDateTime& value){
    if(implementation->value!=value){
         implementation->value=value;
         emit valueChanged();
    }
    return *this;
}
const QDateTime& DateTimeDecorator::value() const{
    return implementation->value;
}

const QString DateTimeDecorator::toIso8601String() const{
    if(implementation->value.isNull()){
        return "";
    }else{
        return implementation->value.toString(Qt::ISODate);
    }
}
const QString DateTimeDecorator::toPrettyDateString() const{
    if(implementation->value.isNull()){
        return "Not set";
    }else{
        return locale.toString(implementation->value,"d MMM yyyy");
    }
}
const QString DateTimeDecorator::toPrettyTimeString() const{
    if(implementation->value.isNull()){
        return "Not set";
    }else{
        return locale.toString(implementation->value,"hh:mm ap");
    }
}
const QString DateTimeDecorator::toPrettyString() const{
    if(implementation->value.isNull()){
        return "Not set";
    }else{
        return locale.toString(implementation->value,"ddd d MMM yyyy @ HH:mm:ss");
    }
}
const QString DateTimeDecorator::toSimpleString() const{
    if(implementation->value.isNull()){
        return "Not set";
    }else{
        return locale.toString(implementation->value,"MM-dd HH:mm");
    }
}

QJsonValue DateTimeDecorator::jsonValue() const {
    return QJsonValue::fromVariant(QVariant(implementation->value.toString(Qt::ISODate)));

}
void DateTimeDecorator::update(const QJsonObject &_jsonObject) {
    if(_jsonObject.contains(key())){
        auto valueAsString=_jsonObject.value(key()).toString();
        auto valueAsDate=QDateTime::fromString(valueAsString,Qt::ISODate);
        setValue(valueAsDate);
    }else{
        setValue(QDateTime());
    }
}
}
}
