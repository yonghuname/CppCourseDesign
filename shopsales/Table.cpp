#include"Table.h"
#include"Window.h"
#include "Goods.h"
#include<iostream>
#include "buyer.h"
#include<vector>
Table::Table() : Basicwidget(0, 0, 0, 0), m_rows(0), m_cols(0), m_gridH(0), m_gridW(0) {};
Table::Table(int row, int col) :m_rows(row), m_cols(col), Basicwidget(0, 0, 0, 0) {
}
void Table::setRowCount(int row) {
	m_rows = row;
}
void Table::setColCount(int col) {
	m_cols = col;
}//�����ö�ͷ
void Table::setHeader(const std::string& header) {

	//std::cout <<   header << std::endl;

	 m_cols = std::count(header.begin(), header.end(), '\t')-1;
	//std::cout << m_cols << std::endl;
	 m_header = header;
	 m_gridW = ::textwidth("c++_primer") +10;
	 m_gridH = ::textheight(header.c_str())+10;
	 //std::cout << "m_gridH" << m_gridH << "m_gridW" << m_gridW;
	 int mx = (Window::width() - 5 * m_gridW) / 2;
	  move(mx, 100);

	  std::string s0 = " id", s1 = " name"	,	s2 = " catalog"	,	s3 = " price",		s4=" contain";
	 outtextxy(m_x, m_y, s0.c_str());
	 outtextxy(m_x+ m_gridW  , m_y, s1.c_str());
	 outtextxy(m_x + m_gridW * 2, m_y, s2.c_str());
	 outtextxy(m_x + m_gridW * 3, m_y, s3.c_str());
	 outtextxy(m_x + m_gridW * 4, m_y, s4.c_str());
}
void Table::show()
		
		{
	drawTableGrid();


		}
//����� 

void Table::drawTableGrid() {
	

	setlinecolor(BLACK);//������
	//std::cout << "begin"<<std::endl;
	for (int i = 0; i < m_rows + 1; i++) {
		line(m_x, m_y + i * m_gridH, m_x + m_cols * m_gridW, m_y + i * m_gridH);
		
	}
	//������
	//std::cout << "123";
	for (int i = 0; i < m_cols + 1; i++) {
		line(m_x + i * m_gridW, m_y, m_x + i * m_gridW, m_y + m_rows * m_gridH);
	}
}

void Table::drawTableData() {

}
//���������ã��������� ���Ǵ�vector����������� Ȼ��ֵ����Ӧ������ Ȼ��������ض�λ������ ���� ����
void Table::insertGoods(Goods &b) {
	double p1 = b.price;
	int c1 = b.contain;
	int i1 = b.goodsid;
	std::string s2 = b.catalog;
	std::string s1 =b.goodsname;
	int startX = (m_gridW - ::textwidth("c++_primer")) / 2;
	int startY = (m_gridH - ::textheight(s1.c_str())) / 2 +   m_gridH + m_y;
	std::string s0 = std::to_string(i1);
	std::string s3 = std::to_string(p1);
	std::string s4 = std::to_string(c1);
	outtextxy(startX + 0 * m_gridW + m_x, startY, s0.c_str()); // ���Կ��ܵľ��棬ʹ�� .c_str() �� std::string ת��Ϊ const char*
	outtextxy(startX + 1 * m_gridW + m_x, startY, s1.c_str());
	outtextxy(startX + 2 * m_gridW + m_x, startY, s2.c_str());
	outtextxy(startX + 3 * m_gridW + m_x, startY, s3.c_str());
	outtextxy(startX + 4 * m_gridW + m_x, startY, s4.c_str());

}
//����һ�� ���������һ��������
void Table::insertbuyer(membercard& b) {
	std::string s0 = b.name;//���øı�����
	int  i1 = b.buyerid;
	double p2 = b.pay;
	double d3 = b.discount;
	double m4 = b.card_contain;
	int startX = (m_gridW - ::textwidth("c++_primer")) / 2;
	int startY = (m_gridH - ::textheight(s0.c_str())) / 2 +   m_gridH + m_y;

	std::string s2 = std::to_string(p2);
	std::string s3 = std::to_string(d3);
	std::string s4 = std::to_string(m4);
	std::string s1 = std::to_string(i1);
	//std::cout << s0;
	outtextxy(startX + 0 * m_gridW + m_x, startY, s0.c_str()); // ���Կ��ܵľ��棬ʹ�� .c_str() �� std::string ת��Ϊ const char*
	outtextxy(startX + 1 * m_gridW + m_x, startY, s1.c_str());
	outtextxy(startX + 2 * m_gridW + m_x, startY, s2.c_str());
	outtextxy(startX + 3 * m_gridW + m_x, startY, s3.c_str());
	outtextxy(startX + 4 * m_gridW + m_x, startY, s4.c_str());
}
//���Ƕ��������ݽ��в��� ȫ�� ������ ���������������  
void Table::insertData(std::vector<Goods>& booklist1) {
	int row = static_cast<int>(booklist1.size()); // ���Կ��ܵľ��棬ʹ�� static_cast ������ʽ����ת��
	


	for (int i = 0; i < row; i++) {
		double p1 = booklist1[i].price;
		int c1 = booklist1[i].contain;
		int i1 = booklist1[i].goodsid;
		std::string s2 = booklist1[i].catalog;
		std::string s1 = booklist1[i].goodsname;
		int startX = (m_gridW - ::textwidth("c++_primer") )/ 2;
		int startY = ( m_gridH - ::textheight(s1.c_str()) )/ 2 + (i+1) * m_gridH + m_y;
		
		std::string s0 = std::to_string(i1);
		std::string s3 = std::to_string(p1);
		std::string s4 = std::to_string(c1);
//std::cout << s0;
		outtextxy(startX + 0 * m_gridW +m_x, startY, s0.c_str()); // ���Կ��ܵľ��棬ʹ�� .c_str() �� std::string ת��Ϊ const char*
		outtextxy(startX + 1 * m_gridW + m_x, startY, s1.c_str());
		outtextxy(startX + 2 * m_gridW + m_x, startY, s2.c_str());
		outtextxy(startX + 3 * m_gridW + m_x, startY, s3.c_str());
		outtextxy(startX + 4 * m_gridW + m_x, startY, s4.c_str());
	}
}
//����ͬ�ϣ����ö��󻻸������
void Table::insertData2(std::vector<membercard>& booklist1) {
	int row = static_cast<int>(booklist1.size()); // ���Կ��ܵľ��棬ʹ�� static_cast ������ʽ����ת��



	for (int i = 0; i < row; i++) {
		
		std::string s0 = booklist1[i].name;//���øı�����
		int  i1 = booklist1[i].buyerid;
		double p2= booklist1[i].pay;
		double d3 = booklist1[i].discount;
		double m4 = booklist1[i].card_contain;
		int startX = (m_gridW - ::textwidth("c++_primer")) / 2;
		int startY = (m_gridH - ::textheight(s0.c_str())) / 2 + (i + 1) * m_gridH + m_y;

		std::string s2 = std::to_string(p2);
		std::string s3 = std::to_string(d3);
		std::string s4 = std::to_string(m4);
		std::string s1 = std::to_string(i1);
		//std::cout << s0;
		outtextxy(startX + 0 * m_gridW + m_x, startY, s0.c_str()); // ���Կ��ܵľ��棬ʹ�� .c_str() �� std::string ת��Ϊ const char*
		outtextxy(startX + 1 * m_gridW + m_x, startY, s1.c_str());
		outtextxy(startX + 2 * m_gridW + m_x, startY, s2.c_str());
		outtextxy(startX + 3 * m_gridW + m_x, startY, s3.c_str());
		outtextxy(startX + 4 * m_gridW + m_x, startY, s4.c_str());
	}
}

void Table::setHeader2(const std::string& header) {

	//std::cout <<   header << std::endl;

	m_cols = std::count(header.begin(), header.end(), '\t') +1;
	//std::cout << m_cols << std::endl;
	m_header = header;
	m_gridW = ::textwidth("c++_primer") +10;
	m_gridH = ::textheight(header.c_str()) +10; 
	//std::cout << "m_gridH" << m_gridH << "m_gridW" << m_gridW;
	int mx = (Window::width() - 5 * m_gridW) / 2;
	move(mx, 100);
	//bname	ID	needpay	discount	cardmoney
	std::string s0 = "name", s1 = "ID", s2 = "needpay", s3 = " discount", s4 = " cardmoney";
	outtextxy(m_x, m_y, s0.c_str());
	outtextxy(m_x + m_gridW, m_y, s1.c_str());
	outtextxy(m_x + m_gridW * 2, m_y, s2.c_str());
	outtextxy(m_x + m_gridW * 3, m_y, s3.c_str());
	outtextxy(m_x + m_gridW * 4, m_y, s4.c_str());
}
//����Ҫдһ��set head 3 �����н���  
//�����ʱ��Ҫ�õ� �����鱾id �����鱾�Ĳ���  �����˵����� 