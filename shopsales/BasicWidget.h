#pragma once
class Basicwidget {
public:
	Basicwidget(int x, int y, int w, int h);
	int width();
	int height();
	void setFixedsize(int w, int h); //设置组件的大小
	int x();
	int y();
	void move(int x, int y);//设置 这些组件的起始点位置 位置 
	virtual void show() = 0; //画到gui窗口的函数
protected:
	int m_x; //坐标
	int m_y;
	int m_w;//宽高
	int m_h;
};