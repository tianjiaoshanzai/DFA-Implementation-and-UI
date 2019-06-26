#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainWindow w;
    w.setWindowTitle("贪心算法实现的DFA");//标题
    w.resize(1500,850);
    //w.show();

    /*
    QPushButton b;
    b.setText("开始检索解析");//按钮内容
    b.setParent(&w);
    b.resize(200,25);
    b.move(10,10);
    //b.show();
    */
    //QPainter p(this);


    w.show();

     //ui->textEdit_2->setPlainText("您输入的字符串长度为:");



    return a.exec();
}
