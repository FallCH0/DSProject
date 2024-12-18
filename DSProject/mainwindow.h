#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QVBoxLayout>
#include <QMainWindow>
#include<QIntValidator>
#include<QMessageBox>
#include<QTabWidget>
#include<arrayWGraph.h>
#include<QPainter>
#include<QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
public:
    arrayWGraph<int> *arr;
    QWidget *dp;
    edge<int> *linshibian;
    int drawcode;
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void DrawVertex(int x,int y,string name,int id);
    void DrawVertexs(vector<NodeInfo> vertexs);
    void DrawEdge(edge<int>* Edge);
    ~MainWindow();


private slots:
    void addvpushClick();

};
#endif // MAINWINDOW_H
