#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->DrawPlace->setStyleSheet("background-color:white");
}
void MainWindow::DrawVertex(int x,int y,string name,int id){
    QPushButton *b=new QPushButton();
    b->setParent(ui->DrawPlace);
    b->setFixedSize(200,200);
    b->move(x,y);
    b->setStyleSheet("QPushButton#objBtn{border-radius:50px;background-color:blue;}");
    QString bname=QString("but_%1").arg(id);
    b->setObjectName(bname);
    b->setToolTip(QString::fromStdString(name));

}
void MainWindow::DrawVertexs(vector<NodeInfo> vertexs){
    for(auto i:vertexs){
        DrawVertex(i.x,i.y,i.name,i.node_id);
    }
}








MainWindow::~MainWindow()
{
    delete ui;
}
