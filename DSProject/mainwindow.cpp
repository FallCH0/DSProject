#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    arr=new arrayWGraph<int>();
    ui->setupUi(this);
    dp=ui->DrawPlace;
    drawcode=0;
    dp->setStyleSheet("background-color:white");
    QIntValidator *validator = new QIntValidator(1, 9999, this);
    ui->addv_x->setValidator(validator);
    ui->addv_y->setValidator(validator);

    QTabWidget *opr = ui->Opreate;  // 通过 ui 获取 SubWindow（假设已在 .ui 文件中添加了子窗口）

    // 获取子窗口中的按钮（通过名称获取）
    QPushButton *addvp = opr->findChild<QPushButton *>("pushaddv"); // 使用 Qt Designer 中的对象名称
    connect(addvp, &QPushButton::clicked, this, &MainWindow::addvpushClick);

    QPushButton *eravp_sel = opr->findChild<QPushButton *>("pusherav_sel"); // 使用 Qt Designer 中的对象名称
    connect(eravp_sel, &QPushButton::clicked, this, &MainWindow::on_pusherav_sel_clicked);

    string map_name="test";
    QSqlDatabase db;
    db=QSqlDatabase::addDatabase("QSQLITE");
    string path="./"+map_name+".db";
    QString Qpath=QString::fromStdString(path);
    db.setDatabaseName("C:/Users/16219/Desktop/dbtest/dbtest.db");
    QSqlQuery sql_query(db); //sql语句对象与具体的db对象关联
    db.open();
    QString select_all_nodeinfo="select * from NodeInfodb";//查询表NodeInfodb所有内容
    sql_query.exec(select_all_nodeinfo);//执行命令

    while (sql_query.next()) //逐行检索
    {
        int id=sql_query.value(0).toInt()-1;
        QString name=sql_query.value(1).toString();
        int x=sql_query.value(2).toInt();
        int y=sql_query.value(3).toInt();
        NodeInfo newNode(id,name.toStdString(),x,y);
        arr->addVertex(newNode);
        ui->eravsel->addItem(name);
    }
    QString select_all_edge="select * from Edgedb";//查询表NodeInfodb所有内容
    sql_query.exec(select_all_edge);//执行命令
    while (sql_query.next()) //逐行检索
    {
        int v1_id=sql_query.value(0).toInt()-1;
        int v2_id=sql_query.value(1).toInt()-1;
        int wx=sql_query.value(2).toInt();
        edge<int> *newEdge=new edge<int>(v1_id,v2_id,wx);
        arr->insertEdge(newEdge);
        linshibian=newEdge;
        drawcode=1;
        update();
    }


}
void MainWindow::DrawVertex(int x,int y,string name,int id){
    QPushButton *b=new QPushButton();
    b->setParent(dp);
    b->setFixedSize(10,10);
    b->move(x,y);
    b->setStyleSheet("QPushButton {border-radius:50px;background-color:blue;}");
    b->show();
    QString bname=QString("but_%1").arg(id);
    b->setObjectName(bname);
    b->setToolTip(QString::fromStdString(name));

}
void MainWindow::DrawVertexs(vector<NodeInfo> vertexs){
    for(auto i:vertexs){
        DrawVertex(i.x,i.y,i.name,i.node_id);
    }
}
void MainWindow::DrawEdge(edge<int>* Edge){
        if (!dp) {
            qDebug() << "Invalid QWidget passed!";
            return;
        }

        // 获取边的相关数据
        int W = Edge->get_w();
        int v1_id = Edge->get_v1();
        int v2_id = Edge->get_v2();
        int v1_index = arr->getIndex(v1_id);
        int v2_index = arr->getIndex(v2_id);
        int v1x = arr->vs_inf[v1_index].x;
        int v1y = arr->vs_inf[v1_index].y;
        int v2x = arr->vs_inf[v2_index].x;
        int v2y = arr->vs_inf[v2_index].y;

        // 创建 QPainter 对象并初始化
        QPainter painter(dp);
        if (!painter.isActive()) {
            qDebug() << "Failed to activate QPainter!";
            return;
        }

        // 设置画笔
        QPen pen;
        pen.setColor(Qt::black);  // 设定颜色
        pen.setWidth(2);         // 设定线宽
        painter.setPen(pen);

        // 绘制线条
        painter.drawLine(v1x, v1y, v2x, v2y);

        // 触发控件重绘
        dp->update();  // 触发重新绘制
        drawcode=0;

}

void MainWindow::paintEvent(QPaintEvent *event)
{

    if(drawcode==1){
        DrawEdge(linshibian);
        drawcode=0;
        if (!dp) {
            qDebug() << "Invalid QWidget passed!";
            return;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addvpushClick()
{
    if (ui->addv_name->text().isEmpty()||ui->addv_x->text().isEmpty()||ui->addv_y->text().isEmpty()) {
        // 弹出警告框提示用户
        QMessageBox::warning(nullptr, "警告", "信息未完整填写！", QMessageBox::Ok);
    } else {
        int x=ui->addv_x->text().toInt();
        int y=ui->addv_y->text().toInt();
        string name=ui->addv_name->text().toStdString();
        int id=arr->giveid();
        QMessageBox::information(nullptr, "成功", "增加点成功！", QMessageBox::Ok);
        ui->addv_name->setText("");
        ui->addv_x->setText("");
        ui->addv_y->setText("");
        NodeInfo *newnode=new NodeInfo(id,name,x,y);
        arr->addVertex(*newnode);
        DrawVertex(x,y,name,id);
    }
}


void MainWindow::on_pusherav_sel_clicked()
{

}

