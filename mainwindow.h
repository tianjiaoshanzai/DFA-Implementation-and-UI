#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>


#include <iostream>
#include <string>
#include <assert.h>
#include <stdio.h>
using namespace std;



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    Ui::MainWindow *ui;
    //QPushButton b;
public slots:
//===================函数声明======================================//
//void      clear();                              //初始化缓存
//void      getlength();                          //获取字符串长度
//void      search();                             //匹配最长字符
//void      output();                            //输出
/*void      initial_state_1();                      //六个输入状态转移函数
void      initial_state_2();
void      initial_state_3();
void      initial_state_4();
void      initial_state_5();
void      initial_state_6();*/
void      RUN();								//运行函数


};

//===================函数声明======================================//
void      clear();                              //初始化缓存
void      getlength();                          //获取字符串长度
void      search();                             //匹配最长字符
void      initial_state_1();                      //六个输入状态转移函数
void      initial_state_2();
void      initial_state_3();
void      initial_state_4();
void      initial_state_5();
void      initial_state_6();
void      output();

#endif // MAINWINDOW_H
