#include "Button.h"

Button::Button(const std::string& text, int x, int y, int w, int h) : m_text(text), Basicwidget(x, y, w, h)
{
}

void Button::show()
{
	setfillcolor(cur_c);
	//设置颜色，绘制按钮 圆角矩形
		::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);
		settextcolor(BLACK);
		//设置文字居中 
		int tx = m_x + (m_w - textwidth(m_text.c_str())) / 2; 
		int ty = m_y + (m_h - textheight(m_text.c_str())) / 2;

		::outtextxy(tx, ty, m_text.c_str());

	

}	
//判断 鼠标到了 按钮里面没有 
bool Button::isin() {
	if (m_msg.x >= m_x && m_msg.x < m_x + m_w && m_msg.y >= m_y && m_msg.y <= m_y + m_h)
	{
		return true;

	}
	return false;
}
//点击确认
bool Button::isclicked() {
	if (isin()) {
		if (m_msg.message == WM_LBUTTONDOWN) {
			return true;
		}
	
	}
	return false;


}
//  颜色处理 
void Button:: enentloop(const ExMessage& msg) {
	 m_msg = msg;

	 if (!isin()) {//鼠标不再按钮里面  
		 cur_c = normal_c;
	 }
	 else {
		 cur_c = hover_c; //覆盖颜色
	 }
}

void Button::setBackgroundColor(COLORREF c) {
	normal_c = c;
}
//修改颜色
void Button::setHoverColor(COLORREF c) {
	hover_c = c;
}
