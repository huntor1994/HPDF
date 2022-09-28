#ifndef DATETIMEDECORATOR_H
#define DATETIMEDECORATOR_H

#include <QObject>
#include <QJsonObject>
#include <QJsonValue>
#include <QScopedPointer>
#include <QString>
#include <QDateTime>
#include <QLocale>
#include <hpdf-lib_global.h>
#include <data/data-decorator.h>

namespace hpdf{
namespace data{

class HPDFLIBSHARED_EXPORT DateTimeDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(QDateTime ui_value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString ui_iso8601String READ toIso8601String NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyDateString READ toPrettyDateString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyTimeString READ toPrettyTimeString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyString READ toPrettyString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_simpleString READ toSimpleString NOTIFY valueChanged)

public:
    explicit DateTimeDecorator(Entity *parentEntity = nullptr
            ,const QString& key="SomeItemKey"
            ,const QString& label=""
            ,const QDateTime& value=QDateTime());
    ~DateTimeDecorator() override;

    DateTimeDecorator& setValue(const QDateTime& value);
    const QDateTime& value() const;
    const QString toIso8601String() const;
    const QString toPrettyDateString() const;
    const QString toPrettyTimeString() const;
    const QString toPrettyString() const;
    const QString toSimpleString() const;

    QJsonValue jsonValue() const override;
    void update(const QJsonObject &jsonObject) override;

signals:
    void valueChanged();
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
    QLocale locale = QLocale::English;//set the local enviroment to english
};
}}
#endif // DATETIMEDECORATOR_H
