#include "pdf-image-worker.h"
namespace hpdf {
namespace workers
{
class PdfImageWorker::Implementation{
public:
    Implementation(QObject* _parent){

    }
    PdfImageWorker* pdfImageWorker{nullptr};

    QString b64str;
};

PdfImageWorker::PdfImageWorker(QObject *parent)
    : QObject{parent}
{
    implementation.reset(new Implementation(this));
}



void PdfImageWorker::pageRenderedFinish(int pageNumber, QSize imageSize, const QImage &image,
                                        QPdfDocumentRenderOptions options, quint64 requestId)
{
    QByteArray ba;
    QBuffer buf(&ba);
    buf.open(QIODevice::WriteOnly);
    image.save(&buf, "png");
    QByteArray ba2 = ba.toBase64();
    implementation->b64str = QString::fromLatin1(ba2);

    emit resultReady();
}

const QString& PdfImageWorker::ImageBase64Value() const{
    return implementation->b64str;
}
}}
