#include "image-decorator.h"
namespace hpdf{
namespace data {
class ImageDecorator::Implementation{
public:
    Implementation(ImageDecorator* _imageDecorator
                   )
        : imageDecorator(_imageDecorator)
    {
        renderThread=new QThread(imageDecorator);


        pdfImageWorker=new PdfImageWorker();
        pdfImageWorker->moveToThread(renderThread);
        renderThread->start();

        QObject::connect(renderThread, &QThread::finished, pdfImageWorker, &QObject::deleteLater);

        pdfPageRenderer=new QPdfPageRenderer(imageDecorator);
        doc=new QPdfDocument(imageDecorator);
        QObject::connect(pdfPageRenderer,&QPdfPageRenderer::pageRendered,pdfImageWorker,&PdfImageWorker::pageRenderedFinish,Qt::ConnectionType::BlockingQueuedConnection);

        pdfImage=new QImage();
    }

    ~Implementation(){
        renderThread->quit();
        renderThread->wait();
    }
    ImageDecorator* imageDecorator{nullptr};
    QImage *pdfImage{nullptr};

    PdfImageWorker *pdfImageWorker{nullptr};

    QPdfPageRenderer *pdfPageRenderer{nullptr};
    QPdfDocument *doc{nullptr};

    QString b64str;
    QThread *renderThread{nullptr};
};


ImageDecorator::ImageDecorator(Entity *parentEntity
                               ,const QString& key
                               ,const QString& label
                               )
    : DataDecorator{parentEntity,key,label}
{
    implementation.reset(new Implementation(this));

}

ImageDecorator::~ImageDecorator() {};


ImageDecorator& ImageDecorator::setValue(const QString& pdfFilePath){
    QUrl docLocation(pdfFilePath);
    QPdfDocument::Error e=implementation->doc->load(docLocation.toLocalFile());
    //    qDebug()<<"Pdf Load Error:"<<e;
    //    qDebug()<<"pdfFilePath:"<<pdfFilePath;
    implementation->pdfPageRenderer->setDocument(implementation->doc);

    QEventLoop loop;
    loop.connect(implementation->pdfImageWorker,SIGNAL(resultReady()),SLOT(quit()));

    implementation->pdfPageRenderer->requestPage(0,QSize(100,100));
    loop.exec();
    implementation->b64str=implementation->pdfImageWorker->ImageBase64Value();
    return *this;
}



const QString& ImageDecorator::value() const{
    return implementation->pdfImageWorker->ImageBase64Value();
}

const QImage& ImageDecorator::imageValue() const{
    return *implementation->pdfImage;
}

QJsonValue ImageDecorator::jsonValue() const {
    return QJsonValue::fromVariant(QVariant(implementation->pdfImageWorker->ImageBase64Value()));

}
void ImageDecorator::update(const QJsonObject &_jsonObject) {
    if(_jsonObject.contains(key())){
        QByteArray arr_base64 = _jsonObject.value(key()).toString().toLatin1();

        implementation->pdfImage->loadFromData(QByteArray::fromBase64(arr_base64));
    }
}



}
}

