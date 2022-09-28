#include "int-decorator.h"
#include <QVariant>

namespace hpdf {
namespace data {
class IntDecorator::Implementation{
public:
    Implementation(IntDecorator* _intDecorator, const int&
                   _value)
        : intDecorator(_intDecorator)
        , value(_value)
    {
    }
    IntDecorator* intDecorator{nullptr};
    int value;
};

IntDecorator::IntDecorator(Entity *parentEntity
                                 ,const QString& key
                                 ,const QString& label
                                 ,const int& value) : DataDecorator(parentEntity,key,label)
{
    implementation.reset(new Implementation(this,value));
}

IntDecorator::~IntDecorator(){

}

IntDecorator& IntDecorator::setValue(const int& value){
    if(implementation->value!=value){
         implementation->value=value;
         emit valueChanged();
    }
    return *this;
}
int IntDecorator::value() const{
    return implementation->value;
}

QJsonValue IntDecorator::jsonValue() const {
    return QJsonValue::fromVariant(QVariant(implementation->value));

}
void IntDecorator::update(const QJsonObject &_jsonObject) {
    if(_jsonObject.contains(key())){
        setValue(_jsonObject.value(key()).toInt());
    }else{
        setValue(0);
    }
}
}
}
