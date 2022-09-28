#include "recently-opened-file.h"
namespace hpdf {
namespace models {
RecentlyOpenedFile::RecentlyOpenedFile(QObject *parent)
    : Entity(parent,"RecentlyOpenedFiles")
{
    closeTime= static_cast<DateTimeDecorator*>(addDataItem(new DateTimeDecorator(this, "closeTime", "CloseTime")));
    filePath = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this, "filePath", "FilePath")));
    pageCount= static_cast<IntDecorator*>(addDataItem(new IntDecorator(this, "pageCount", "PageCount")));
    closePage= static_cast<IntDecorator*>(addDataItem(new IntDecorator(this, "closePage", "ClosePage")));
    coverImage= static_cast<ImageDecorator*>(addDataItem(new ImageDecorator(this, "coverImage", "CoverImage")));
    setPrimaryKey(filePath);
}

RecentlyOpenedFile::RecentlyOpenedFile(QObject* parent,const QJsonObject& json)
    :Entity(parent){
    closeTime= static_cast<DateTimeDecorator*>(addDataItem(new DateTimeDecorator(this, "closeTime", "CloseTime")));
    filePath = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this, "filePath", "FilePath")));
    pageCount= static_cast<IntDecorator*>(addDataItem(new IntDecorator(this, "pageCount", "PageCount")));
    closePage= static_cast<IntDecorator*>(addDataItem(new IntDecorator(this, "closePage", "ClosePage")));
    coverImage= static_cast<ImageDecorator*>(addDataItem(new ImageDecorator(this, "coverImage", "CoverImage")));
    update(json);
}

RecentlyOpenedFile::~RecentlyOpenedFile()
{


}

}}
