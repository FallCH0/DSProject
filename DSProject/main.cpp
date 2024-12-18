#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include<QString>
#include"arrayWGraph.h"
#include<QDebug>
#pragma execution_character_set("utf-8") //防止路径有中文
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "DSProject_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    //连接数据库并初始化
    MainWindow w;
    w.DrawVertexs(w.arr->vs_inf);
    edge<int> *newEdge=new edge<int>(8,4,5);
    w.show();
    w.update();

    return a.exec();
}
