#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QTextEdit>
#include <QDockWidget>
#include <QMessageBox>
#include <QString>
#include <QFile>

#include <cstdlib>
#include <iostream>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;


//===================函数声明======================================//
void      clear();                              //初始化缓存
void      getlength();                          //获取字符串长度
void      search();                             //匹配最长字符
void      output();                            //输出
void      initial_state_1();                      //六个输入状态转移函数
void      initial_state_2();
void      initial_state_3();
void      initial_state_4();
void      initial_state_5();
void      initial_state_6();
void      RUN();								//运行函数


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*
    //move(100,100)//窗口初始位置移动
    //QPushButton b;
    b.setParent(this);
    b.setText("开始检索解析");
    b.resize(200,25);
    b.move(100,100);

    //connect(&b,&QPushButton::pressed,this,&MainWindow::close);

    connect(&b,&QPushButton::pressed,
            [=]() mutable
             {
                qDebug() << "2333";
             }
            );

    //自定义槽---------------------------------------------------


    //菜单,工具,状态栏
    //菜单栏---------------------------------------------------------------------------------------
    QMenuBar *mBar =menuBar();
        //添加菜单
    QMenu *pFile = mBar->addMenu("开始");
        //添加菜单项
    QAction *pRun = pFile->addAction("运行");

    connect(pRun,&QAction::triggered,
            [=]()
            {

            }

            );
      pFile->addSeparator();//添加分割线
      QAction *pFinish = pFile->addAction("结束");
      connect(pFinish,&QAction::triggered,this,&MainWindow::close);
   //菜单栏结束---------------------------------------------------------------------------------------

    //工具栏（快捷方式）---------------- -----------------------------------------------------------------
      QToolBar *toolbar = addToolBar("toolBar");

            //工具栏添加快捷键
      toolbar->addAction(pRun);

      //QPushButton *b3 =new QPushButton(this);
      //添加小控件


    //工具栏（快捷方式）结束---------------- -------------------------------------------------------------

    //核心控件---------------- ----------------------------------------------------------------------
      QTextEdit *textedit =new QTextEdit(this);
      setCentralWidget(textedit);




    //核心控件结束---------------- ----------------------------------------------------------------------

      //浮动窗口---------------- ----------------------------------------------------------------------
      //QDockWidget *dock = new QDockWidget(this);
      //addDockWidget(Qt::RightDockWidgetArea,2);





       //浮动窗口结束---------------- ----------------------------------------------------------------------

      //关于窗口---------------- ----------------------------------------------------------------------
      QAction *pAbout = pFile->addAction("关于程序");

      connect(pAbout,&QAction::triggered,
              [=]()
              {
                QMessageBox::about(this,"关于程序","采用贪心算法实现教材 P.62 表 3.5 的 DFA，从输入串中匹配最长的子串。输出所有识别出的符号串及其词形");
              }

              );


      //关于窗口结束---------------- ----------------------------------------------------------------------
    */
    //关于窗口---------------- ----------------------------------------------------------------------
    ui->setupUi(this);
    //ui->actionAbout
            connect(ui->actionAbout,&QAction::triggered,
                    [=]()
                    {
                      QMessageBox::about(this,"关于程序",
                       "采用贪心算法实现教材 P.62 表 3.5 的 DFA，从输入串中匹配最长的子串。输出所有识别出的符号串及其词形\n\n\t作者：袁啸山\n\tVer:1.0");
                    }

                    );
     //关于窗口结束---------------- -------------------------------------------------------------------

     //说明窗口---------------- ----------------------------------------------------------------------
            ui->setupUi(this);
            //ui->actionAbout
                    connect(ui->actionillustrate,&QAction::triggered,
                            [=]()
                            {
                              QMessageBox::about(this,"使用说明",
                               "请输入一串ab字符并以'#'号结束,程序将输出匹配最长字符串和对应类型");
                            }

                            );
      //说明于窗口结束---------------- ---------------------------------------------------------------
/*//说明窗口--------------------------------------------------------------------------------------
                           ui->setupUi(this);
                           //ui->actionAbout
                                   connect(ui->actionIntroduction,&QAction::triggered,
                                           [=]()
                                           {
                                             QMessageBox::about(this,"程序介绍",
                                              "c[]记录字符串,使用贪心算法匹配每个符合DFA的字符串，并用T1,T2记录起始位置,T3记录每段的匹配类型");
                                           }

                                           );
//说明于窗口结束---------------- -------------------------------------------------------------------*/



     connect(ui->actionFINISH,&QAction::triggered,this,&MainWindow::close);//终结窗口

     connect(ui->actionRUN,&QAction::triggered,this,&MainWindow::RUN);//运行窗口

     //读取样式表

     QFile qssFile("source.qss");//资源文件":/css.qss"
     qssFile.open(QFile::ReadOnly);
     if(qssFile.isOpen())
     {
         QString qss = QLatin1String(qssFile.readAll());
         qApp->setStyleSheet(qss);
         qssFile.close();
     }



     //QTextEdit* iEdit  = new QTextEdit();
     //iEdit->setStyleSheet("background-image:url(:/new/prefix1/QJ6166776010.jpg)");
     //background:url(:/new/prefix1/QJ6166776010.jpg);

     //this->setStyleSheet("background-image:url(:/new/prefix1/madeira-4279303.jpg);");
     //this->setStyleSheet("background-image:url(:/new/prefix1/QJ6166776010.jpg);");
     this->setStyleSheet("background-image:url(:/new/prefix1/madeira-4279303_1920.jpg);");

     //QPalette paa = ui->textEdit->palette();
     //paa.setColor(QPalette::Base,QColor(255, 255, 255));
     ui->textEdit->setStyleSheet("QTextEdit{background:white}");
     ui->textEdit_2->setStyleSheet("QTextEdit{background:white}");

}

//===================全局变量======================================//
char      c[100];                               //预定缓存空间存放字符串
int       i = 0, j = 0, lenth = 0, p = 1;               //获取字符串信息
int       T1[100], T2[100];                      //识别出的字符起始标志与结束标志
string    T3[100];                              //存储获取的字符串相应的词形
string    state[3] = { "a", "a*bb*", "abb" };          //词形
stringstream temp;                                 //输出转换中间字符流变量
stringstream temp2;
string  strtemp;                                        //输出转换中间字符变量
QString   qstr2;                                        //最终输出流
//QChar     *b=new Qchar[100];
                                                       //===================模拟初始化缓存空间============================//
void  clear()
{
    for (int q = 0; q < 100; q++)
    {
        c[q] = '\n';
        T1[q] = 101;
        T2[q] = 101;
    }

}
//====================获取字符串的长度============================//
void  getlength()
{
    for (int q = 0; q < 100; q++)
        if (c[q] != '#')
            lenth = lenth + 1;
        else
        {
            //lenth = lenth - 1;
            return;
        }
}
//==================六个输入状态转移函数=========================//
//------------------------状态一---------------------------------//
void   initial_state_1()
{
    if (c[i] == '#')
    {
        T2[j]--;
        return;


    }
    if (c[i] == 'a')        //状态1遇到a转换
    {
        T1[j] = i;
        T2[j] = i;
        ++i;
        T3[j] = state[0];       //先设为a识别,后续状态可能改动也可能不改动
        initial_state_2();      //识别a后进入状态2
    }
    else
    {
        T1[j] = i;
        T2[j] = i;
        ++i;
        T3[j] = state[1];
        initial_state_3();
    }
}
//-------------------------状态二---------------------------------//
void   initial_state_2()
{
       if ( c[i] == '#' )
     {
         return;
     }
       if ( c[i] == 'a' )
       {
           ++i;
           T2[j] = i;
           T3[j] = state[0];
           if ( c[i] == '#' )
             for ( i = i-2; i < lenth; i++ )
             {
                  T1[j] = i;
                  T2[j] = i;
                  T3[j] = state[0];
                  j++;
             }
             initial_state_4();
       }
       else
       {

                            //-5-
          ++i;
          T2[j] = i;
          T3[j] = state[1];
          initial_state_5();
     }
}
//---------------------------状态三--------------------------------//
void   initial_state_3()
{
     if ( c[i] == '#' )
     {
         T2[j]--;
         return;
     }
     if  (c[i] == 'a' )     //不符合文法,切割并设定终态
     {
         T2[j] = i - 1;
         T3[j] = state[1];
         j++;
     }
     else                   //识别b时循环于状态3
     {
         ++i;
         T2[j] = i;
         initial_state_3();
     }
}
//------------------状态四-------------------------------//
void   initial_state_4()
{
    if (c[i] == '#')
    {
        T2[j]--;
        return;
    }
    if (c[i] == 'a')
    {
        ++i;
        T2[j] = i;
        p++;
        if (c[i] == '#')
        {
            for (i = i - p - 1; i < lenth; i++)


            {
                T1[j] = i;
                T2[j] = i;
                T3[j] = state[0];
                j++;
            }
        }
        initial_state_4();

    }
    else
    {
        p = 1;
        ++i;
        T2[j] = i;
        T3[j] = state[1];
        initial_state_3();
    }
}
//-------------------状态五-------------------------------//
void   initial_state_5()
{
    if (c[i] == '#')
    {
        T2[j]--;
        return;
    }
    if (c[i] == 'a')
    {
        T2[j] = i - 1;
        T3[j] = state[1];
        j++;
    }
    else
    {
        i++;
        T2[j] = i;
        T3[j] = state[2];
        initial_state_6();
    }
}


//----------------------状态六-------------------------------//
void   initial_state_6()
{
    if (c[i] == '#')
    {
        T2[j]--;
        return;
    }
    if (c[i] == 'a')
    {
        T2[j] = i - 1;
        T3[j] = state[2];
        j++;
    }
    else
    {
        i++;
        T2[j] = i;
        T3[j] = state[1];
        initial_state_3();
    }
}
//====================匹配函数==============================//
void   search()
{
    while (i<lenth)
    {
        initial_state_1();
    }
}
//==================输出函数================================//
/*
void   output()
{

    for (int k = 0; (T1[k] != 101 && T2[k] != 101); k++)
    {

        //QString qstr2;
        for (int q = T1[k]; q <= T2[k]; q++)


           {


            temp<<c[q]<<"\n";
            //strtemp=temp.str();
            //qstr2=QString::fromStdString(strtemp);
            //ui->textEdit_2->append(qstr2);
            //temp.str().clear();                     //调用后清空并初始化
            //temp.str("");
            //strtemp ="";
            //qstr2="";



            //qDebug()<< c[q];
            //cout << c[q];
            }
        //if(T1[k] >= 101 || T2[k] >= 101)
            //break;

        //temp2<< "\t" << T3[k] <<"\n";
        //temp2<< "\t" << T3[k] <<"\n";
        //strtemp=temp2.str();
        //QString qstr2=QString::fromStdString(strtemp);
        //ui->textEdit_2->insertPlainText(qstr2);//append(qstr2);
        //temp2.str().clear();                   //调用后清空并初始化
        //temp2.str("");
        //strtemp ="";
        //qstr2="";

        //temp2<< "\t" << T3[k] <<"\n";
        //strtemp=temp2.str();
        //QString qstr2=QString::fromStdString(T3[k]);
        //ui->textEdit_2->insertPlainText(qstr2);//append(qstr2);
        //temp2.str().clear();                   //调用后清空并初始化
        //temp2.str("");
        //strtemp ="";
        //qstr2="";
        //qDebug()<< "   ";
        //qDebug("%s",qPrintable(T3[k]));
        //qDebug()<<endl;
        //cout << "   " << T3[k] << endl;
    }
    return;
}
*/
void   output()
{
    for (int k = 0; ((T1[k] != 101) && (T2[k] != 101)); k++)
    {
        for (int q = T1[k]; q <= T2[k]; q++)
            temp<<c[q];

        temp<< "\t" << T3[k] <<"\n";

    }
}
//----------------------程序运行函数---------------------------
void   MainWindow::RUN()
{
    clear();                           //运行结束，清空模拟缓存


    //读取字符串-------------------------------------------
    QString str = ui->textEdit->toPlainText();
    QByteArray ba=str.toLatin1();
    char *b;
    b=ba.data();
    c[100]={0};
    strncpy(c,b,100);
    //cin.get(&c[0], 100, '\n');            //读取字符串
    //读取字符串结束---------------------------------------------
    getlength();                   //获取输入字符串的长度，便于检测

    /**********************************************
    qDebug()<<"读取内容：";
    for(int i=0;i<lenth+1;i++)
    {
        qDebug()<<c[i];
    }
    qDebug()<<endl;
    **********************************************/

    temp<<"您输入的字符串长度为:\n";
    //ui->textEdit_2->append("您输入的字符串长度为:");
    //cout << "您输入的字符串长度为:" << endl;


    temp<< lenth<<"\n";
    //strtemp=temp.str();
    //qstr2=QString::fromStdString(strtemp);
    //ui->textEdit_2->append(qstr2);
    //temp.str().clear();                     //调用后清空并初始化
    //temp.str("");
    //strtemp ="";
    //qstr2="";
    //ui->textEdit_2->setText("您输入的字符串长度为:\n");
    //cout << lenth << endl;               //显示字符串长度


    //emit //信号量调用？（已放弃）




    search();                         //贪心匹配最长字符串


    temp<<("所识别的所有最大匹配字符串及其词形如下:\n");
    //cout << "所识别的所有最大匹配字符串及其词形如下:" << endl;


    output();                          //对识别出的字符串统一输出

    //输出转换开始----------------------------------------------------------------------------------------------------------
    strtemp=temp.str();
    qstr2=QString::fromStdString(strtemp);
    //ui->textEdit_2->append(qstr2);
    temp.str().clear();                     //调用后清空并初始化
    temp.str("");
    strtemp ="";
    //输出转换结束-----------------------------------------------------------------------------------------------------------
    ui->textEdit_2->append(qstr2);//输出

    clear();                           //运行结束，清空模拟缓存
    //system("PAUSE");
}

MainWindow::~MainWindow()
{
    delete ui;
}
