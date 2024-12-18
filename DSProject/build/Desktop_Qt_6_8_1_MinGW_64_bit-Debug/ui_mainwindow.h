/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *DrawPlace;
    QTabWidget *Opreate;
    QWidget *calculate;
    QTabWidget *calculatex;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *edit;
    QTabWidget *editx;
    QWidget *vertex;
    QTabWidget *addv;
    QWidget *addv1;
    QLineEdit *addv_name;
    QLineEdit *addv_x;
    QLineEdit *addv_y;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushaddv;
    QWidget *erav;
    QWidget *editv;
    QWidget *edge;
    QTabWidget *tabWidget_2;
    QWidget *adde;
    QWidget *erae;
    QWidget *edite;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        DrawPlace = new QWidget(centralwidget);
        DrawPlace->setObjectName("DrawPlace");
        DrawPlace->setGeometry(QRect(30, 30, 431, 531));
        DrawPlace->setAutoFillBackground(false);
        Opreate = new QTabWidget(centralwidget);
        Opreate->setObjectName("Opreate");
        Opreate->setGeometry(QRect(500, 20, 271, 541));
        calculate = new QWidget();
        calculate->setObjectName("calculate");
        calculatex = new QTabWidget(calculate);
        calculatex->setObjectName("calculatex");
        calculatex->setGeometry(QRect(0, 0, 271, 521));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        calculatex->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        calculatex->addTab(tab_4, QString());
        Opreate->addTab(calculate, QString());
        edit = new QWidget();
        edit->setObjectName("edit");
        editx = new QTabWidget(edit);
        editx->setObjectName("editx");
        editx->setGeometry(QRect(0, 0, 271, 521));
        vertex = new QWidget();
        vertex->setObjectName("vertex");
        addv = new QTabWidget(vertex);
        addv->setObjectName("addv");
        addv->setGeometry(QRect(0, 0, 271, 501));
        addv1 = new QWidget();
        addv1->setObjectName("addv1");
        addv_name = new QLineEdit(addv1);
        addv_name->setObjectName("addv_name");
        addv_name->setGeometry(QRect(50, 80, 161, 31));
        addv_name->setMaxLength(30);
        addv_x = new QLineEdit(addv1);
        addv_x->setObjectName("addv_x");
        addv_x->setGeometry(QRect(50, 180, 71, 31));
        addv_y = new QLineEdit(addv1);
        addv_y->setObjectName("addv_y");
        addv_y->setGeometry(QRect(140, 180, 71, 31));
        label = new QLabel(addv1);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 30, 131, 31));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(addv1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 140, 51, 21));
        label_3 = new QLabel(addv1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 130, 40, 41));
        pushaddv = new QPushButton(addv1);
        pushaddv->setObjectName("pushaddv");
        pushaddv->setGeometry(QRect(70, 250, 121, 31));
        addv->addTab(addv1, QString());
        erav = new QWidget();
        erav->setObjectName("erav");
        addv->addTab(erav, QString());
        editv = new QWidget();
        editv->setObjectName("editv");
        addv->addTab(editv, QString());
        editx->addTab(vertex, QString());
        edge = new QWidget();
        edge->setObjectName("edge");
        tabWidget_2 = new QTabWidget(edge);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 0, 271, 501));
        adde = new QWidget();
        adde->setObjectName("adde");
        tabWidget_2->addTab(adde, QString());
        erae = new QWidget();
        erae->setObjectName("erae");
        tabWidget_2->addTab(erae, QString());
        edite = new QWidget();
        edite->setObjectName("edite");
        tabWidget_2->addTab(edite, QString());
        editx->addTab(edge, QString());
        Opreate->addTab(edit, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Opreate->setCurrentIndex(1);
        calculatex->setCurrentIndex(1);
        editx->setCurrentIndex(1);
        addv->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        calculatex->setTabText(calculatex->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        calculatex->setTabText(calculatex->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        Opreate->setTabText(Opreate->indexOf(calculate), QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227", nullptr));
        addv_name->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\226\207\345\255\227\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\202\271\347\232\204\346\226\207\345\255\227\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        pushaddv->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        addv->setTabText(addv->indexOf(addv1), QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\202\271", nullptr));
        addv->setTabText(addv->indexOf(erav), QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\347\202\271", nullptr));
        addv->setTabText(addv->indexOf(editv), QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\347\202\271\347\232\204\344\277\241\346\201\257", nullptr));
        editx->setTabText(editx->indexOf(vertex), QCoreApplication::translate("MainWindow", "\347\202\271", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(adde), QCoreApplication::translate("MainWindow", "\345\242\236\345\212\240\350\276\271", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(erae), QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\276\271", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(edite), QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\350\276\271\347\232\204\346\235\203\345\200\274", nullptr));
        editx->setTabText(editx->indexOf(edge), QCoreApplication::translate("MainWindow", "\350\276\271", nullptr));
        Opreate->setTabText(Opreate->indexOf(edit), QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
