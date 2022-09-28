#include "recently-opened-file-search.h"
namespace hpdf {
namespace models {
class RecentlyOpenedFileSearch::Implementation
{
public:
    Implementation(RecentlyOpenedFileSearch* _recentlyOpenedFileSearch, DatabaseController*_databaseController):
        recentlyOpenedFileSearch(_recentlyOpenedFileSearch)
      , databaseController(_databaseController){

    }
    RecentlyOpenedFileSearch* recentlyOpenedFileSearch{nullptr};
    DatabaseController* databaseController{nullptr};
    QList<models::RecentlyOpenedFile*> openedFiles{};
};
RecentlyOpenedFileSearch::RecentlyOpenedFileSearch(QObject *parent,DatabaseController* databaseController)
    : QObject{parent}
{
    implementation.reset(new Implementation(this,databaseController));
}
RecentlyOpenedFileSearch::~RecentlyOpenedFileSearch()
{

}
QQmlListProperty<models::RecentlyOpenedFile> RecentlyOpenedFileSearch::readResults(){
    return QQmlListProperty<models::RecentlyOpenedFile>(this,&implementation->openedFiles);
}

const QList<models::RecentlyOpenedFile*>& RecentlyOpenedFileSearch::OpenedFiles(){
    return implementation->openedFiles;
}
void RecentlyOpenedFileSearch::search(){

    auto resultsArray=implementation->databaseController->readRows("RecentlyOpenedFiles");
    implementation->openedFiles.clear();
    for(const QJsonValue jsonValue : resultsArray) {
        implementation->openedFiles.append(new RecentlyOpenedFile(this,jsonValue.toObject()));
    }
    qDebug()<<"searchResultsChanged signal emit!";
    searchResultsChanged();
}

}}
