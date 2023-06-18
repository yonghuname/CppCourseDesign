#pragma once
#include"BasicWidget.h"
#include"Configure.h"
//#include<thread>
//#pragma comment(lib,"Imm32.lib")
#
class LineEdit :public Basicwidget
{
public:
	LineEdit(int x = 0, int y = 0, int w = 100, int h = 30);
	void show();

	void eventLoop(const ExMessage& msg);

	//�������������
	void popInputBox();
	void setInputBoxTitle(const std::string& title);
	void setText(const std::string& text);
	std::string text();
	void clear();
	void setCursorHide(bool isHide);
	//�ı��Ƿ�ı���
	bool textChanged();
private:
	std::string m_pretext;	//��һ�ε�����
	std::string m_text;		//�б༭���е�����
	int textw;

	std::string m_title;	//�б༭������������
	bool m_hideCursor = false;		//�Ƿ���ʾ���
	bool m_isPopUp;	//�Ƿ񵯳�
};


