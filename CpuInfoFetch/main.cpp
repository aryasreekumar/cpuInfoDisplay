#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFile>
#include <QQmlComponent>
#include <QDebug>
#include <QIODevice>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    //Openfile
    QString fileName = "/proc/cpuinfo";
    QFile cpuInfoFile(fileName);

    if (!cpuInfoFile.open(QIODevice::ReadOnly))
    {
        printf("Failed to open cpuInfo file");
        return -1;
    }
    //Read contents
    QString cpuInfoContent = cpuInfoFile.readAll();
    //Close file
    cpuInfoFile.close();

    printf("Output is %s", cpuInfoContent.toStdString().c_str());

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

#if 0
    /*-- Commented --*/
    QQmlComponent component(&engine, "qrc:/main.qml");
    QObject *object = component.create();
    QVariant cpuInfodata(cpuInfoContent);
    QObject *objectToChange = object->findChild<QObject*>("cpuInfo");
    if(objectToChange)
        objectToChange->setProperty("text",cpuInfodata);

#endif
    /*This part of the code has been referenced from: https://github.com/tralfaz/merchw/tree/master/method2 */

    //rootObjects fun will get the first level children from QML
    QList<QObject *> firstLevel = engine.rootObjects();
    qDebug("First level length:");
    qDebug()<<firstLevel.length();

    QObject* firstlevelElement = firstLevel[0];

    QObject* cpuInfoItem = firstlevelElement->findChild<QObject *>("cpuInfo");
    if (cpuInfoItem)
        cpuInfoItem->setProperty("text",cpuInfoContent);


    return app.exec();
}

