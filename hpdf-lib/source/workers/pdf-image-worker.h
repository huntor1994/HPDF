#ifndef PDFIMAGEWORKER_H
#define PDFIMAGEWORKER_H

#include <QObject>
#include <QPdfDocument>
#include <QPdfPageRenderer>
#include <QPdfDocumentRenderOptions>
#include <QScopedPointer>
#include <QBuffer>
#include <QUrl>
namespace hpdf {
namespace workers
{
class PdfImageWorker : public QObject
{
    Q_OBJECT
public:
    explicit PdfImageWorker(QObject *parent = nullptr);

    const QString& ImageBase64Value() const;
signals:
    void resultReady();
public slots:
    void pageRenderedFinish(int pageNumber, QSize imageSize, const QImage &image,
                                            QPdfDocumentRenderOptions options, quint64 requestId);
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;

};

}
}


#endif // PDFIMAGEWORKER_H

