#include "LINKEDIT.h"
#include"Window.h"
#include<conio.h>
void LineEdit::show()
{
    //Basicwidget::show(); // 调用基类的show方法，绘制基本控件框架

    setfillcolor(RGB(232, 232, 236)); // 设置填充颜色为浅灰色
    fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h); // 填充矩形框

    if (!m_hideCursor)  //光标 
    {
        // 绘制闪烁的小竖线作为光标
        setlinecolor(RED); // 设置光标颜色为红色
        line(m_x + textw + 2, m_y + 2, m_x + textw + 2, m_y + m_h - 2); // 绘制光标
    }// 输出文字到输入框
    outtextxy(m_x, m_y + (m_h - textheight(m_text.c_str())) / 2, m_text.c_str());
    if (m_isPopUp)
    {
        m_pretext = m_text;
        popInputBox(); // 弹出输入框
        m_isPopUp = false;
    }
}
void LineEdit::eventLoop(const ExMessage& msg)
{
    if (msg.x > m_x && msg.x < m_x + m_w && msg.y > m_y && msg.y < m_y + m_h
        && msg.message == WM_LBUTTONDOWN)
    {
        m_isPopUp = true; // 点击输入框区域，设置标志位以弹出输入框
    }
}

void LineEdit::popInputBox()
{
    char str[128] = { 0 };
    InputBox(str, 128, nullptr, m_title.c_str(), m_text.c_str()); // 弹出输入框，获取用户输入的文本
    m_text = str; // 更新文本内容
    textw = ::textwidth(m_text.c_str()); // 计算文本宽度
}
void LineEdit::setInputBoxTitle(const std::string& title)
{
    m_title = title; // 设置输入框的标题
}
void LineEdit::setText(const std::string& text)
{
    m_text = text; // 设置文本内容
    textw = ::textwidth(m_text.c_str()); // 计算文本宽度
}
std::string LineEdit::text()
{
    return m_text; // 返回当前的文本内容
}
void LineEdit::clear()
{
    m_text.clear(); // 清空文本内容
    textw = 0; // 重置文本宽度
}
void LineEdit::setCursorHide(bool isHide)
{
    m_hideCursor = isHide; // 设置光标隐藏状态
}
bool LineEdit::textChanged()
{
    if (m_pretext == m_text)
    {
        return false; // 文本内容没有改变
    }

    m_pretext = m_text; // 更新前一次文本内容
    return true; // 文本内容改变了
}
