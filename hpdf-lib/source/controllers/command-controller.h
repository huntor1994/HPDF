#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QObject>
#include <hpdf-lib_global.h>
#include <controllers/database-controller.h>
#include <models/recently-opened-file.h>
#include <models/recently-opened-file-search.h>
#include <framework/command.h>
#include <QtQml/QQmlListProperty>
using namespace hpdf::framework;
namespace hpdf {
namespace controllers {
class HPDFLIBSHARED_EXPORT CommandController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<hpdf::framework::Command>
               ui_workAreaViewCommands READ
               ui_workAreaViewCommands
               CONSTANT)
public:
    explicit CommandController(QObject* _parent = nullptr
            , DatabaseController* databaseController = nullptr
            ,models::RecentlyOpenedFile* openedFile= nullptr
            ,RecentlyOpenedFileSearch* recentlyOpenedFileSearch=nullptr);
    ~CommandController()override;

     QQmlListProperty<framework::Command> ui_workAreaViewCommands();
public slots:
    void onOpenFilesSaveExecuted();
    void onOpenFilesReadExecuted();
    void onOpenFilesDeleteExecuted();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}
}

#endif // COMMANDCONTROLLER_H
