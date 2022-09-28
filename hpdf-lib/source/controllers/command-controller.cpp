#include "command-controller.h"
namespace hpdf {
namespace controllers {
class CommandController::Implementation{
public:
    Implementation(CommandController *_commandController
                   ,DatabaseController* _databaseController
                   ,models::RecentlyOpenedFile* _openedFile
                   ,RecentlyOpenedFileSearch* _recentlyOpenedFileSearch)
        :commandController(_commandController)
        ,databaseController(_databaseController)
        ,openedFile(_openedFile)
        ,recentlyOpenedFileSearch(_recentlyOpenedFileSearch)
    {
        Command* openFilesSaveCommand=new Command(commandController,QChar(0xf0c7),"Save");
        QObject::connect(openFilesSaveCommand
                         ,&Command::executed
                         ,commandController
                         ,&CommandController::onOpenFilesSaveExecuted);
        workAreaViewCommands.append(openFilesSaveCommand);
        Command* openFilesReadExecuted=new Command(commandController,QChar(0xf0c7),"Read");
        QObject::connect(openFilesReadExecuted
                         ,&Command::executed
                         ,commandController
                         ,&CommandController::onOpenFilesReadExecuted);

        workAreaViewCommands.append(openFilesReadExecuted);
    }
    CommandController *commandController{nullptr};
    DatabaseController* databaseController{nullptr};
    models::RecentlyOpenedFile* openedFile{nullptr};
    QList<hpdf::framework::Command*> workAreaViewCommands{};
    RecentlyOpenedFileSearch* recentlyOpenedFileSearch{nullptr};
};


CommandController::CommandController(QObject* _parent
                                     , DatabaseController* databaseController
                                     ,models::RecentlyOpenedFile* openedFile
                                     ,RecentlyOpenedFileSearch* recentlyOpenedFileSearch)
    : QObject(_parent)
{
    implementation.reset(new Implementation(this,databaseController,openedFile,recentlyOpenedFileSearch));
}
CommandController::~CommandController(){}

QQmlListProperty<hpdf::framework::Command> CommandController::ui_workAreaViewCommands(){
    return QQmlListProperty<hpdf::framework::Command>(this,&implementation->workAreaViewCommands);
}

void CommandController::onOpenFilesSaveExecuted(){
    qDebug() << "You executed the OpenFileSave command!";
    implementation->databaseController->createRow(
                implementation->openedFile->key()
                ,implementation->openedFile->id()
                ,implementation->openedFile->toJson()
                ,*implementation->openedFile->closeTime);
    implementation->recentlyOpenedFileSearch->search();
}

void CommandController::onOpenFilesReadExecuted(){
    qDebug() << "You executed the OpenFilesRead command!";
    implementation->recentlyOpenedFileSearch->search();
}

void CommandController::onOpenFilesDeleteExecuted(){
    qDebug() << "You executed the OpenFileDelete command!";
}




}
}
