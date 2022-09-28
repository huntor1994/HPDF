#ifndef RECENTLYOPENEDFILESEARCH_H
#define RECENTLYOPENEDFILESEARCH_H

#include <QObject>
#include <QScopedPointer>
#include <QtQml/QQmlListProperty>
#include <hpdf-lib_global.h>
#include <data/entity.h>
#include <models/recently-opened-file.h>
#include <controllers/database-controller.h>
using namespace hpdf::data;
using namespace hpdf::models;
using namespace hpdf::controllers;
namespace hpdf {
namespace models {
class HPDFLIBSHARED_EXPORT RecentlyOpenedFileSearch : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<hpdf::models::RecentlyOpenedFile> ui_readResults READ readResults NOTIFY searchResultsChanged)
public:
    explicit RecentlyOpenedFileSearch(QObject *parent = nullptr,DatabaseController* databaseController = nullptr);
    ~RecentlyOpenedFileSearch()override;
    QQmlListProperty<models::RecentlyOpenedFile> readResults();
    const QList<models::RecentlyOpenedFile*>& OpenedFiles();
public slots:
    void search();
signals:
    void searchResultsChanged();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};
}}
#endif // RECENTLYOPENEDFILESEARCH_H
