#ifndef PROTOTYPER_H
#define PROTOTYPER_H

#include <QObject>
#include <QString>
#include <QStandardPaths>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTextStream>
#include <QIODevice>
#include <QQmlEngine>
#include <QDateTime>

#define APP_SOURCES "/usr/share/ru.mastercond.QmlPrototyper/qml/pages/sources/sources-QmlPrototyper-0.4.zip"
#define APP_SOURCES_OUTPUT QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/sources-QmlPrototyper-0.4.zip"

class Prototyper: public QObject
{
    Q_OBJECT

public:
    explicit Prototyper(QObject *parent = 0);
    static int FILECOUNTERPREVIEW;

public slots:
    QString returnFileCounter(); //возвращает значение глобальной переменной для перехода к qml-файлу
    void createWorkFiles(); //создать в папке приложения AppLocalDataLocation пустые файлы error_log.txt, component_preview.qml, page_preview.qml
    QString pathDocuments(); //возвращает путь до папки Документы для использования пути в QML
    QString pathAppLocalFolder(); //возвращает путь до папки  кэша приложения для использования пути в QML
    void saveComponentQMLdefaultfolder(QString componentsource, QString filename); //сохранияет правленный файл в папке Документы/QML прототипы/ и перезаписывает component_preview_XXXX.qml в папке приложения для его последующего просмотра
    void savePageQMLdefaultfolder(QString componentsource, QString filename); //сохранияет правленный файл в папке Документы/QML прототипы/ и перезаписывает component_page_XXXX.qml в папке приложения для его последующего просмотра
    void saveComponentQML(QString componentsource, QString filename); //сохранияет правленный файл в папке и перезаписывает component_preview_XXXX.qml в папке приложения для его последующего просмотра
    void savePageQML(QString componentsource, QString filename); //сохранияет правленный файл в папке и перезаписывает component_page_XXXX.qml в папке приложения для его последующего просмотра
    QString loadQMLsourceFile(QString filepath); //возвращает содержимое QML файла в виде строки для отображения в TextArea
    void copySources(); //скопировать файл исходных кодов приложения в папку Документы

    QString addTextTextAreaCursorPosition(int position, QString text, QString string); // добавляет подстроку string в нужное место строки text (где курсор) - для дополнения QML кода шаблонами

    QString qDebugOutputfromLogfile(); //открывает лог-файл, созданный в main.cpp и возвращает его содержимое строкой для отображения в консоли приложения

};

#endif // PROTOTYPER_H
