#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QPdfDocument>
#include <QtQml/QQmlListProperty>
#include <hpdf-lib_global.h>
#include <controllers/command-controller.h>
#include <controllers/database-controller.h>
#include <models/recently-opened-file.h>
#include <workers/pdf-image-provider.h>

using namespace hpdf::models;
using namespace hpdf::workers;

namespace hpdf {
namespace controllers {
class HPDFLIBSHARED_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(hpdf::controllers::CommandController* ui_commandController READ commandController CONSTANT)
    Q_PROPERTY(hpdf::models::RecentlyOpenedFile* newOpenedFile READ newOpenedFile CONSTANT)
    Q_PROPERTY(hpdf::controllers::DatabaseController * ui_databaseController READ databaseController CONSTANT)
    Q_PROPERTY(hpdf::workers::PdfImageProvider * ui_pdfImageProvider READ pdfImageProvider CONSTANT)
    Q_PROPERTY(hpdf::models::RecentlyOpenedFileSearch * ui_recentlyOpenedFileSearch READ recentlyOpenedFileSearch CONSTANT)

public:
    explicit MasterController(QObject *parent = nullptr);
    ~MasterController() override;
    CommandController* commandController();
    DatabaseController* databaseController();
    models::RecentlyOpenedFile* newOpenedFile();
    workers::PdfImageProvider* pdfImageProvider();
    RecentlyOpenedFileSearch* recentlyOpenedFileSearch();
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};
}
}


#endif // MASTERCONTROLLER_H
