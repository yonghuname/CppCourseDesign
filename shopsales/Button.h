#pragma once
#include"BasicWidget.h"
#include"Configure.h" //要处理文本
class Button : public Basicwidget
{
public:  
    Button(const std::string& text, int x = 0, int y = 0, int w = 100, int h = 30);
      void show();

      bool isin();
      bool isclicked();

      void enentloop(const ExMessage& msg); //事件循环
      void setBackgroundColor(COLORREF c);  //基本背景色 
      void setHoverColor(COLORREF c);//鼠标移动到 背景按钮 会变色，表示移动



protected:
    std::string m_text;
    ExMessage m_msg;
    COLORREF cur_c;
    COLORREF normal_c =RGB(232,232,236);//实现 鼠标移动过去鼠标会变红 这是正常颜色 
    COLORREF hover_c;//覆盖色
};



