#include"Window.h"
#include "ManageMent.h"
#include<iostream>
#include<Windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);//中文正常显示 
    std::cout.imbue(std::locale("en_US.UTF-8"));

    Window w(800, 600, EX_SHOWCONSOLE);
    w.setWindowTitle("图书购买管理系统");
    ManageMent m;
    m.run();
    return w.exec();
}