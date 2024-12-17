#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include<QtSql>
#include<QString>
#include"arrayWGraph.h"
#include<QDebug>
#pragma execution_character_set("utf-8") //路径有中文
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
    string map_name="test";
    QSqlDatabase db;
    db=QSqlDatabase::addDatabase("QSQLITE");
    string path="./"+map_name+".db";
    QString Qpath=QString::fromStdString(path);
    db.setDatabaseName("C:/Users/16219/Desktop/testdb/identifier.db");
    QSqlQuery sql_query(db); //sql语句对象与具体的db对象关联
    sql_query.exec("select COUNT(*) from NodeInfodb");
    int n_num;
    while (sql_query.next()) //逐行检索
    {
        n_num=sql_query.value(0).toInt();
    }
    arrayWGraph<int> *arr=new arrayWGraph<int>();
    QString select_all_nodeinfo="select * from NodeInfodb";//查询表NodeInfodb所有内容
    sql_query.exec(select_all_nodeinfo);//执行命令
    while (sql_query.next()) //逐行检索
    {
        int id=sql_query.value(0).toInt();
        QString name=sql_query.value(1).toString();
        int x=sql_query.value(2).toInt();
        int y=sql_query.value(3).toInt();
        NodeInfo newNode(id,name.toStdString(),x,y);
        arr->addVertex(newNode);
    }

    QString select_all_edge="select * from Edgedb";//查询表NodeInfodb所有内容
    sql_query.exec(select_all_edge);//执行命令
    while (sql_query.next()) //逐行检索
    {
        int v1_id=sql_query.value(0).toInt();
        int v2_id=sql_query.value(1).toInt();
        int w=sql_query.value(2).toInt();
        edge<int> *newEdge=new edge<int>(v1_id,v2_id,w);
        if(!arr->existsEdge(v1_id,v2_id)){
        arr->insertEdge(newEdge);
        }
    }




    MainWindow w;
    w.show();
    return a.exec();
}
