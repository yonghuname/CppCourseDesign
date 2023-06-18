#include "BasicWidget.h"

Basicwidget::Basicwidget(int x, int y, int w, int h):m_x(x),m_y(y),m_w(w),m_h(h)
{

}

int Basicwidget::width()
{
    return m_w;
}

int Basicwidget::height()
{
    return m_h;
}

void Basicwidget::setFixedsize(int w, int h)
{
    this->m_w = w;
    this->m_h = h;
}

int Basicwidget::x()
{
    return m_x;
}

int Basicwidget::y()
{

    return m_y;
}

void Basicwidget::move(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

