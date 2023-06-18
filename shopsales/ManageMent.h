#include "Window.h"
#include<vector>
#include"Button.h"
#include "Goods.h"
#include"buyer.h"
#include"Table.h"
#include"LINKEDIT.h"
class ManageMent //管理类 
{
	enum Operator
	{
		ShowAll1,
		Insert1,
		Erase1,
		Find1,
		ShowAll2,
		Insert2,
		Erase2,
		Find2,
		Paymoney,
	
		Exit,
		Menu,
	};
public:
	int op;
	ManageMent();
	int menu();
	void run();

	//显示所有
	void displayall1();
	//添加
	void insert1();
	//删除
	void erase1(); 
	//查找
	void find1();
	//显示所有
	void displayall2();
	//添加
	void insert2();
	//删除
	void erase2();
	//查找
	void find2();
	// 
	//付钱
	void paymoney();



	void drawBK();//背景
	void enentloop(); //事件循环

	//读文件
	void readgoodsFile(const std::string& fileName); //读取book数据文件
	void savegoodsFile(const std::string& fileName);//存book数据文件
	void readbuyerFile(const std::string& fileName); //同上，可望文生义。
	void savebuyerFile(const std::string& fileName);

private:
	IMAGE  m_bk; //背景图 引入 
	ExMessage m_msg; //信息 
	std::vector<Button*>  menu_btns;//菜单按钮

public:	
	std::string goodshead;//首行段头
	std::vector<Goods> goodslist; //用vector 存书的集合 

	std::string buyerhead;//首行
	std::vector<membercard>  list;//同上个list 集合 存 用户 
	// 查明学生表格
	Table* m_showTable; // 调用
	void  enevtLoop(); //持续存在   调试时用过 

public://删除学生页面
	LineEdit* delEdit;
	 Button* delBtn;
	Table* delTable;
};
