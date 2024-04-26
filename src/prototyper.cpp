#include "prototyper.h"
#include <QString>
#include <QStandardPaths>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTextStream>
#include <QIODevice>
#include <QQmlEngine>
#include <QDir>
#include <QDateTime>
#include <stdio.h>
#include <stdlib.h>

int Prototyper::FILECOUNTERPREVIEW=0;

Prototyper::Prototyper(QObject *parent) : QObject(parent)
{
}

QString Prototyper::returnFileCounter()
{
    return QString::number(Prototyper::FILECOUNTERPREVIEW);
}

void Prototyper::createWorkFiles()
{
    //создание если не существует папки QML прототипов в папке Документы пользователя
    QString path_Documents=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/QML прототипы/";
    QDir dir_Documents(path_Documents);
    if (!dir_Documents.exists()) { dir_Documents.mkpath("."); }

    //удаляем файл с выводом qDebug и/или создаем пустой новый
    QFile filedebugrm(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/logqtdebug.txt");
     if (filedebugrm.exists()) {filedebugrm.remove(); QFile filedeb(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/logqtdebug.txt"); filedeb.open(QIODevice::ReadWrite); filedeb.close();} else {QFile filedeb(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/logqtdebug.txt"); filedeb.open(QIODevice::ReadWrite); filedeb.close();}

    //очищаем папку кешированных qml-страниц
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/cache/";
    QDir dircache(path);
    dircache.removeRecursively();

         QFile errorlogfile(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/error_log.txt");
         if (!errorlogfile.exists()) {errorlogfile.open(QIODevice::ReadWrite | QIODevice::Text);errorlogfile.close();} else { errorlogfile.close();}
         QDir dir(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/cache");
         if (!dir.exists()) {dir.mkpath(".");}
}

QString Prototyper::pathDocuments()
{
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
}

 QString Prototyper::pathAppLocalFolder()
 {
     return QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
 }

void Prototyper::saveComponentQMLdefaultfolder(QString componentsource, QString filename)
{
    Prototyper::FILECOUNTERPREVIEW++;
    QFile file1(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/QML прототипы/"+filename);
    QFile file2(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/cache/component_preview_"+ QString::number(Prototyper::FILECOUNTERPREVIEW)+".qml");

    QString part1=" import QtQuick 2.6 \n import Sailfish.Silica 1.0 \n\n\n Page { \n objectName: \"componentPage\" \n allowedOrientations: Orientation.All \n\n\n SilicaFlickable { \n objectName: \"flickable\" \n anchors.fill: parent \n contentHeight: layout.height + Theme.paddingLarge \n width:parent.width \n height:parent.height \n\n\n Column { \n id: layout \n anchors.verticalCenter: parent.verticalCenter \n anchors.horizontalCenter: parent.horizontalCenter \n objectName: \"layout\" \n width: parent.width \n\n" ;

    QString partm=" PullDownMenu { \n MenuItem { \n text: qsTr(\"Назад в редактор\") \n onClicked: pageStack.push(Qt.resolvedUrl(\"QMLEditPage.qml\")) \n } \n } \n";
    QString partmtest=" PullDownMenu { \n MenuItem { \n text: qsTr(\"Назад в редактор\") \n onClicked: pageStack.navigateBack() \n } \n } \n";

    QString part2="\n } \n } \n } \n";

    try {
      if (!file1.open(QIODevice::WriteOnly | QIODevice::Text)) {
          qDebug()<<"Ошибка открытия файла "+QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/QML прототипы/"+filename;
          file1.close();
           }
      else {
      QTextStream out1(&file1);
      out1 << componentsource;
      out1.flush();
      file1.close();
       }

      if (!file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
          qDebug()<<"Ошибка открытия файла "+QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/cache/component_preview_"+ QString::number(Prototyper::FILECOUNTERPREVIEW)+".qml"; file2.close();
           }
      else {
      QTextStream out2(&file2);
      out2 << part1+partmtest+componentsource+part2;
      file2.close();
       }

    }  catch (const char* error_message) {
        qDebug()<<error_message;
        QFile errorlogfile(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/error_log.txt");
        QTextStream outerror(&errorlogfile);
        if (errorlogfile.open(QIODevice::Append)) {
           outerror << error_message;
           outerror.flush();
           errorlogfile.close();
        }
        else {
        errorlogfile.close();
        }

    }


}

void Prototyper::saveComponentQML(QString componentsource, QString filename)
{
    Prototyper::FILECOUNTERPREVIEW++;
    QFile file1(filename);
    QFile file2(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/cache/component_preview_"+ QString::number(Prototyper::FILECOUNTERPREVIEW)+".qml");

    QString part1=" import QtQuick 2.6 \n import Sailfish.Silica 1.0 \n\n\n Page { \n objectName: \"componentPage\" \n allowedOrientations: Orientation.All \n\n\n SilicaFlickable { \n objectName: \"flickable\" \n anchors.fill: parent \n contentHeight: layout.height + Theme.paddingLarge \n width:parent.width \n height:parent.height \n\n\n Column { \n id: layout \n anchors.verticalCenter: parent.verticalCenter \n anchors.horizontalCenter: parent.horizontalCenter \n objectName: \"layout\" \n width: parent.width \n\n" ;

    QString partm=" PullDownMenu { \n MenuItem { \n text: qsTr(\"Назад в редактор\") \n onClicked: pageStack.push(Qt.resolvedUrl(\"QMLEditPage.qml\")) \n } \n } \n";
    QString partmtest=" PullDownMenu { \n MenuItem { \n text: qsTr(\"Назад в редактор\") \n onClicked: pageStack.navigateBack() \n } \n } \n";

    QString part2="\n } \n } \n } \n";

    try {
      if (!file1.open(QIODevice::WriteOnly | QIODevice::Text)) {
          qDebug()<<"Ошибка открытия файла "+QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/QML прототипы/"+filename;
          file1.close();
           }
      else {
      QTextStream out1(&file1);
      out1 << componentsource;
      out1.flush();
      file1.close();
       }

      if (!file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
          qDebug()<<"Ошибка открытия файла "+QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/cache/component_preview_"+ QString::number(Prototyper::FILECOUNTERPREVIEW)+".qml"; file2.close();
           }
      else {
      QTextStream out2(&file2);
      out2 << part1+partmtest+componentsource+part2;
      file2.close();
       }

    }  catch (const char* error_message) {
        qDebug()<<error_message;
        QFile errorlogfile(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/error_log.txt");
        QTextStream outerror(&errorlogfile);
        if (errorlogfile.open(QIODevice::Append)) {
           outerror << error_message;
           outerror.flush();
           errorlogfile.close();
        }
        else {
        errorlogfile.close();
        }

    }


}


void Prototyper::savePageQMLdefaultfolder(QString componentsource, QString filename)
{
    Prototyper::FILECOUNTERPREVIEW++;
    QFile file1(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/QML прототипы/"+filename);
    QFile file2(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/cache/page_preview_"+ QString::number(Prototyper::FILECOUNTERPREVIEW)+".qml");

    try {


        if (!file1.open(QIODevice::WriteOnly | QIODevice::Text)) {
          qDebug()<<"Ошибка открытия файла "+QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/QML прототипы/"+filename;
          file1.close(); }
      else {
          QTextStream out1(&file1);
          out1 << componentsource;
          out1.flush();
          file1.close();
       }

      if (!file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
          qDebug()<<"Ошибка открытия файла "+QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/cache/page_preview_"+ QString::number(Prototyper::FILECOUNTERPREVIEW)+".qml";
          file2.close(); }
      else {
      QTextStream out2(&file2);
      out2 << componentsource;
      out2.flush();
      file2.close();
       }

    }  catch (const char* error_message) {
        qDebug()<<error_message;
        QFile errorlogfile(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/error_log.txt");
        QTextStream outerror(&errorlogfile);
        if (errorlogfile.open(QIODevice::Append)) {
           outerror << error_message;
           outerror.flush();
           errorlogfile.close();
        }
        else {
        errorlogfile.close();
        }
    }


}

void Prototyper::savePageQML(QString componentsource, QString filename)
{
    Prototyper::FILECOUNTERPREVIEW++;
    QFile file1(filename);
    QFile file2(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/cache/page_preview_"+ QString::number(Prototyper::FILECOUNTERPREVIEW)+".qml");

    try {


        if (!file1.open(QIODevice::WriteOnly | QIODevice::Text)) {
          qDebug()<<"Ошибка открытия файла "+QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/QML прототипы/"+filename;
          file1.close(); }
      else {
          QTextStream out1(&file1);
          out1 << componentsource;
          out1.flush();
          file1.close();
       }

      if (!file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
          qDebug()<<"Ошибка открытия файла "+QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/cache/page_preview_"+ QString::number(Prototyper::FILECOUNTERPREVIEW)+".qml";
          file2.close(); }
      else {
      QTextStream out2(&file2);
      out2 << componentsource;
      out2.flush();
      file2.close();
       }

    }  catch (const char* error_message) {
        qDebug()<<error_message;
        QFile errorlogfile(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/error_log.txt");
        QTextStream outerror(&errorlogfile);
        if (errorlogfile.open(QIODevice::Append)) {
           outerror << error_message;
           outerror.flush();
           errorlogfile.close();
        }
        else {
        errorlogfile.close();
        }
    }


}


QString Prototyper::loadQMLsourceFile(QString filepath)
{
    QFile filesource(filepath);
    if (filesource.exists()) {
    filesource.open(QIODevice::ReadOnly);
    QTextStream streamfile(&filesource);
    QString outfile = streamfile.readAll();
    return outfile;
    filesource.close();
    }
    else {
        QString error="Ошибка открытия файла: "+filepath;
        qDebug() << error;
        return error;
    }
}

void Prototyper::copySources()
{
    try {
        if(QFile(APP_SOURCES_OUTPUT).exists())
        {
            QFile::remove(APP_SOURCES_OUTPUT);
            QFile::copy(APP_SOURCES,APP_SOURCES_OUTPUT);
            qDebug() << "Файл исходных кодов приложения скопирован в папку Documents пользователя";
        }
        else
        {
            QFile::copy(APP_SOURCES,APP_SOURCES_OUTPUT);
            qDebug() << "Файл исходных кодов приложения скопирован в папку Documents пользователя";
        }

    }  catch (const char* errormessage) {
        qDebug() << errormessage;
    }
}


QString Prototyper::addTextTextAreaCursorPosition(int position, QString text, QString string) // добавляет подстроку в нужное место строки (где курсор)
{
    return text.insert(position,string);
}


QString Prototyper::qDebugOutputfromLogfile()
{
    QFile filedebug(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/logqtdebug.txt");

    if (filedebug.exists()) {
    filedebug.open(QIODevice::ReadOnly);
    QTextStream streamfile(&filedebug);
    QString outfile = streamfile.readAll();
    return outfile;
    filedebug.close();
}
    else return "Ошибка открытия файла: "+QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"/logqtdebug.txt";
}

