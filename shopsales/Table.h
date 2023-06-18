#include"Configure.h"
#include "Basicwidget.h"
#include<vector>
#include "Goods.h"
#include "buyer.h"
class Table :public Basicwidget
{	public:


	 Table(int row, int col);
	void setRowCount(int row); //设置表的 行数量
	void setColCount(int col);// 设计列表
	void setHeader(const std ::string & header);  //设置段首行  book类
	void insertData (std::vector<Goods>& booklist1); //插入数据 book类
	Table();
	void setHeader2(const std::string& header);//插入 buyer类 段头
	void insertData2(std::vector<membercard>& booklist1);//插入 buyer类 数据 

	void show();
	int m_rows; //行列数 
	int m_cols;
	int m_gridH, m_gridW;//高度，宽度 

	void drawTableGrid();  //画表
	void drawTableData();//画数据 但是没用 全用insertdata了 ，
	std:: string m_header;  //表格 首信息
	std::vector <std::string> m_datas; // 数据集合 

	void  insertGoods(Goods& b); // 录入数据 
	void  insertbuyer(membercard& b); //录入数据 
};
