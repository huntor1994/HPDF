#ifndef RECENTLYOPENEDFILE_H
#define RECENTLYOPENEDFILE_H

#include <QObject>
#include <hpdf-lib_global.h>
#include <data/entity.h>
#include <data/string-decorator.h>
#include <data/datetime-decorator.h>
#include <data/int-decorator.h>
#include <data/image-decorator.h>
using namespace hpdf::data;
namespace hpdf {
namespace models {
class HPDFLIBSHARED_EXPORT RecentlyOpenedFile : public data::Entity
{
    Q_OBJECT
    Q_PROPERTY( hpdf::data::DateTimeDecorator* ui_closeTime MEMBER closeTime CONSTANT )
    Q_PROPERTY( hpdf::data::StringDecorator* ui_filePath MEMBER filePath CONSTANT )
    Q_PROPERTY( hpdf::data::IntDecorator* ui_pageCount MEMBER pageCount CONSTANT )
     Q_PROPERTY( hpdf::data::IntDecorator* ui_closePage MEMBER closePage CONSTANT )
    Q_PROPERTY( hpdf::data::ImageDecorator* ui_coverImage MEMBER coverImage CONSTANT )

public:
    explicit RecentlyOpenedFile(QObject *parent = nullptr);
    RecentlyOpenedFile(QObject* parent,const QJsonObject& json);
    ~RecentlyOpenedFile() override;
    DateTimeDecorator* closeTime{nullptr};
    StringDecorator* filePath{nullptr};
    IntDecorator* pageCount{nullptr};
    IntDecorator* closePage{nullptr};
    ImageDecorator* coverImage{nullptr};

};
}
}


#endif // RECENTLYOPENEDFILE_H
