#ifndef IMAGEDECORATOR_H
#define IMAGEDECORATOR_H

#include <QObject>
#include <QJsonObject>
#include <QJsonValue>
#include <QScopedPointer>
#include <QImage>
#include <QBuffer>
#include <hpdf-lib_global.h>
#include <data/data-decorator.h>
#include <QPdfDocument>
#include <QPdfPageRenderer>
#include <QPdfDocumentRenderOptions>
#include <QThread>
#include <QEventLoop>
#include <workers/pdf-image-worker.h>
using namespace hpdf::workers;
namespace hpdf{
namespace data {
class ImageDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(QString ui_value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit ImageDecorator(Entity *parentEntity = nullptr
            ,const QString& key="SomeItemKey"
            ,const QString& label="");
    ~ImageDecorator() override;
    ImageDecorator& setValue(const QString& pdfFilePath);
    const QString& value() const;
    const QImage& imageValue() const;
    QJsonValue jsonValue() const override;
    void update(const QJsonObject &jsonObject) override;

signals:
    void valueChanged();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};
}}
#endif // IMAGEDECORATOR_H
