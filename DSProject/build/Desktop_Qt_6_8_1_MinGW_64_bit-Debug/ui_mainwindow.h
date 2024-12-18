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
#include <QtWidgets/QComboBox>
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
    QComboBox *eravsel;
    QLabel *label_4;
    QPushButton *pusherav_sel;
    QLabel *label_5;
    QLineEdit *eravser;
    QPushButton *pusherav_ser;
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
        eravsel = new QComboBox(erav);
        eravsel->setObjectName("eravsel");
        eravsel->setGeometry(QRect(50, 50, 171, 22));
        label_4 = new QLabel(erav);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 15, 61, 21));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pusherav_sel = new QPushButton(erav);
        pusherav_sel->setObjectName("pusherav_sel");
        pusherav_sel->setGeometry(QRect(80, 90, 101, 31));
        label_5 = new QLabel(erav);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(80, 140, 101, 31));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        eravser = new QLineEdit(erav);
        eravser->setObjectName("eravser");
        eravser->setGeometry(QRect(50, 190, 171, 31));
        pusherav_ser = new QPushButton(erav);
        pusherav_ser->setObjectName("pusherav_ser");
        pusherav_ser->setGeometry(QRect(90, 250, 91, 31));
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
        editx->setCurrentIndex(0);
        addv->setCurrentIndex(1);
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
        label_4->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\347\202\271", nullptr));
        pusherav_sel->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\210\226\346\237\245\346\211\276\347\202\271", nullptr));
        eravser->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\347\202\271\347\232\204\346\226\207\345\255\227\344\277\241\346\201\257", nullptr));
        pusherav_ser->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
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
