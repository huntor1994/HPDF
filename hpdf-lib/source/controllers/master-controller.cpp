#include "master-controller.h"
namespace hpdf {
namespace controllers {
class MasterController::Implementation
{
public:
    Implementation(MasterController* _masterController):
        masterController(_masterController){

        databaseController=new DatabaseController(masterController);
        newOpenedFile=new models::RecentlyOpenedFile(masterController);

        recentlyOpenedFileSearch=new models::RecentlyOpenedFileSearch(masterController,databaseController);
        commandController=new CommandController(masterController,databaseController,newOpenedFile,recentlyOpenedFileSearch);
        pdfImageProvider=new workers::PdfImageProvider(databaseController,recentlyOpenedFileSearch);


    }
    MasterController* masterController{nullptr};
    CommandController* commandController{nullptr};
    DatabaseController* databaseController{nullptr};
    models::RecentlyOpenedFile* newOpenedFile{nullptr};
    workers::PdfImageProvider* pdfImageProvider{nullptr};
    models::RecentlyOpenedFileSearch* recentlyOpenedFileSearch{nullptr};
};
MasterController::MasterController(QObject *parent)
    : QObject{parent}
{
    implementation.reset(new Implementation(this));
}

MasterController::~MasterController()
{


}
CommandController* MasterController::commandController(){
    return implementation->commandController;

}

DatabaseController* MasterController::databaseController(){
    return implementation->databaseController;
}

models::RecentlyOpenedFile* MasterController::newOpenedFile(){
    return implementation->newOpenedFile;
}

workers::PdfImageProvider* MasterController::pdfImageProvider(){
    return implementation->pdfImageProvider;
}

models::RecentlyOpenedFileSearch* MasterController::recentlyOpenedFileSearch(){
    return implementation->recentlyOpenedFileSearch;
}


}}
