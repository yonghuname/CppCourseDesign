#pragma once
#include "Configure.h"

class Window
{public:
	Window(int w, int h, int flag);
	int exec();
	void setWindowTitle(const std::string & title);
	static int width();//返回宽度
	static int height();   //返回高度
	static void clear(); //防止因为刷新帧率都太高 
	static void beginDraw(); //缓冲类，让刷新变慢点 这三个都是调用batchdraw  来更新刷新频率
	static void flushDraw(); //缓冲类，让刷新变慢点 这三个都是调用batchdraw  来更新刷新频率
	static void endDraw();//缓冲类，让刷新变慢点 这三个都是调用batchdraw  来更新刷新频率 让他不要一直闪
	//全部静态 因为就一个窗口 ，只需要调用就心理 

	//判断有没有消息  按键操作和鼠标操作 
	inline static bool hasMsg() { return ::peekmessage(&m_msg, EX_MOUSE | EX_KEY); }
	inline static const ExMessage& getMsg() { return m_msg; }

private:
	HWND m_handle;//窗口句柄
	inline static ExMessage m_msg; //消息类 ， 来自于easyx库

};

