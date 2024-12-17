#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<arrayWGraph.h>
#include<QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void DrawVertex(int x,int y,string name,int id);
    void DrawVertexs(vector<NodeInfo> vertexs);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
