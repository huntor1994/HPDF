#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QWindow>
#include <Windows.h>

#include <controllers/master-controller.h>
#include <controllers/command-controller.h>
#include <models/recently-opened-file.h>
#include <models/recently-opened-file-search.h>
#include <workers/pdf-image-provider.h>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);

    qmlRegisterType<hpdf::controllers::CommandController>("HPDF",1,0,"CommandController");
    qmlRegisterType<hpdf::controllers::MasterController>("HPDF",1,0,"MasterController");
    hpdf::controllers::MasterController masterController(nullptr);

    qmlRegisterType<hpdf::models::RecentlyOpenedFile>("HPDF",1,0,"RecentlyOpenedFile");
    qmlRegisterType<hpdf::models::RecentlyOpenedFileSearch>("HPDF",1,0,"RecentlyOpenedFileSearch");
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("masterController", &masterController);
    engine.addImportPath("qrc:/");
    engine.addImageProvider(QLatin1String("RecentlyOpenedFiles"), masterController.pdfImageProvider());

    const QUrl url(QStringLiteral("qrc:/views/MasterView.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
