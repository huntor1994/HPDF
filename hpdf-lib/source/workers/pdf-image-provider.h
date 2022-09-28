#ifndef PDFIMAGEPROVIDER_H
#define PDFIMAGEPROVIDER_H

#include <QObject>
#include <QQuickImageProvider>
#include <controllers/database-controller.h>
#include <models/recently-opened-file-search.h>
#include <hpdf-lib_global.h>
#include <QScopedPointer>
namespace hpdf {
namespace workers {
class  PdfImageProvider : public  QQuickImageProvider
{
    //Q_OBJECT
public:
    explicit PdfImageProvider(controllers::DatabaseController* database=nullptr
            ,RecentlyOpenedFileSearch* recentlyOpenedFileSearch=nullptr);
    QImage requestImage(const QString &id, QSize *size, const QSize& requestedSize)override;

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}
}

#endif // PDFIMAGEPROVIDER_H
