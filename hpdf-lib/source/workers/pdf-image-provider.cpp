#include "pdf-image-provider.h"
namespace hpdf {
namespace workers {
class PdfImageProvider::Implementation
{
public:
    Implementation(controllers::DatabaseController* _databaseController
                   ,RecentlyOpenedFileSearch* _recentlyOpenedFileSearch)
        :databaseController(_databaseController)
         ,recentlyOpenedFileSearch(_recentlyOpenedFileSearch)
    {


    }
    controllers::DatabaseController* databaseController{nullptr};
    RecentlyOpenedFileSearch* recentlyOpenedFileSearch{nullptr};
};

PdfImageProvider::PdfImageProvider(controllers::DatabaseController* database,RecentlyOpenedFileSearch* recentlyOpenedFileSearch)
    : QQuickImageProvider{QQuickImageProvider::ImageType::Image}
{
    implementation.reset(new Implementation(database,recentlyOpenedFileSearch));
}

QImage PdfImageProvider::requestImage(const QString &id, QSize *size, const QSize& requestedSize){
       // qDebug()<<"request Image id:"<<id;
        //implementation->recentlyOpenedFileSearch->OpenedFiles()[id.toInt()]->coverImage->imageValue().save("default save.png");
    return implementation->recentlyOpenedFileSearch->OpenedFiles()[id.toInt()]->coverImage->imageValue();
}
}
}
