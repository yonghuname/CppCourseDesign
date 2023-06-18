#include "Window.h"
//ExMessage Window::m_msg;//要写到 cpp里面来 
Window::Window(int w, int h, int flag) {
	m_handle = ::initgraph(w,h,flag);
	::setbkmode(TRANSPARENT);
}
void Window::setWindowTitle(const std::string& title)
{
	::SetWindowText(m_handle,title.c_str());//就是调用库的函数在类内内部
}

int Window::width()
{
	return ::getwidth();
}

int Window::height()
{
	return ::getheight();
}

void Window::clear()
{
	::cleardevice(); //这些都是把easyx库的写入类内  就是清屏，
}

void Window::beginDraw()
{
	::BeginBatchDraw(); //画图等等相关的
}

void Window::flushDraw()
{
	::FlushBatchDraw();
}

void Window::endDraw()
{
	::EndBatchDraw();
}

int Window::exec(){
	 
	return getchar();
}
