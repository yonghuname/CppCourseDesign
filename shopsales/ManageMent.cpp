#include "ManageMent.h"
#include <Windows.h>
#include<fstream>
#include<iostream>
#include <conio.h> //按键控制
#include<sstream>
#include<cstring>

using namespace std;

//ExMessage Window::m_msg;

ManageMent::ManageMent()
{
	setlinecolor(RED);
		readgoodsFile("../goods.txt");
		readbuyerFile("../buyer.txt");
		::loadimage(&m_bk, "../11.jpg", Window::width(), Window::height()); //背景图片

		::settextstyle(26,0,"楷体");

		menu_btns.push_back(new Button("查看商品"));
		menu_btns.push_back(new Button("添加商品")); 
		menu_btns.push_back(new Button("删除商品"));
		menu_btns.push_back(new Button("查找商品"));

		menu_btns.push_back(new Button("查看用户"));
		menu_btns.push_back(new Button("添加用户"));
		menu_btns.push_back(new Button("删除用户"));
		menu_btns.push_back(new Button("查找用户"));

		menu_btns.push_back(new Button("进行结算"));
		menu_btns.push_back(new Button("退出且保存")); //添加按钮
	
		for (int i = 0; i < menu_btns.size(); i++) {
			menu_btns[i]->setFixedsize(250, 50);
			menu_btns[i]->setHoverColor(RED);//鼠标移入会变亮
			int bx = (Window :: width() - menu_btns[i]->width()) / 2;
			int vspace= (Window:: height() - menu_btns.size() * menu_btns[i]->height()) / 2;

			int by = i * menu_btns[i]->height()+vspace;
			menu_btns[i]->move(bx, by);
			std::cout << "drawbutton";

		}
		//初始化表格
		/*
	 	m_showTable = new Table;
		m_showTable->setRowCount(16);
		 m_showTable->setHeader(m_header);
		m_showTable->move(100,100);
		*/
			/*for (auto& val : booklist) {
				m_showTable->insertData(val.formatInfo());
		}*/
}

int  ManageMent::menu(){
	//return 2;

	//Window::flushDraw();
	//for (auto btn : menu_btns)
	//{
	//	btn->show();
	//}
	
	 for (int i = 0; i < menu_btns.size(); i++) {
		
		 menu_btns[i]->show();
		
		 menu_btns[i]->enentloop(m_msg); 
		if (menu_btns[i]->isclicked()) {
			drawBK(); // 重新绘制背景
			return i;
		}
		} 
	 Window::flushDraw();
	//}
	
	
return Menu;
	
}

void ManageMent::run()
{
	op =Menu;		
	Window::beginDraw(); //这些都是让图片不闪烁
		//这个函数用于开始批量绘图。执行后，任何绘图操作都将暂时不输出到绘图窗口上，直到执行 FlushBatchDraw 或 EndBatchDraw 才将之前的绘图输出。
		drawBK();
	
	while (1) 
	{
		drawBK();
		if (Window::hasMsg()) { //信息获取 
			m_msg= Window::getMsg();
			switch (m_msg.message) {
			case WM_KEYDOWN: //按键按下
				if (m_msg.vkcode = VK_ESCAPE) 
				{
					op = Menu;
				}
				break;
			default: //鼠标操作
					break;
			}

		}

		switch (op) { //选择跳转 
		case ManageMent::Menu:
			op = menu();
			//cout << "123";
			
			break;
		case ManageMent::ShowAll1:
			
			displayall1(); 
			

			break;
		case ManageMent::Insert1:
			insert1();
			break;
		case ManageMent::Erase1:
			erase1();
			break;
		case ManageMent::Paymoney:
			paymoney();
			break;
		case ManageMent::Find1:
			find1();
			break;
		case ManageMent::ShowAll2:
			displayall2();
			break;
		case ManageMent::Insert2:
			insert2();
			break;
		case ManageMent::Erase2:
			erase2();
			break;
		case ManageMent::Find2:
			find2();
			break;
		default:
			savegoodsFile("..\\goods1.txt");

			savebuyerFile("..\\buyer1.txt"); //坑爹的转义字符 \b 
			exit(2126223);
			break;
		}
		Window::flushDraw(); 
		Window::clear();
	}
	Window::endDraw(); 
}

void ManageMent::displayall1()
{
	 //显示全部 
	Table a(16, 5);
	a.setHeader(goodshead);

	a.show();
	a.insertData(goodslist);
	Window::flushDraw();
}


void ManageMent::insert1()
{ //实现输入框 ，然后添加到booklist 
	outtextxy(0, 0, "insert");
	Table a(16, 5);
	a.setHeader(goodshead);
	a.show();


	char title[50] = "添加";
	outtextxy((Window::width() - textwidth(title)) / 2, 0, title);

	char str[128] = { 0 };
	string s2 , s1= "以id 名字 分类 价格 库存方式的价格输入，请以 按0或者不输入数据返回主界面";
	InputBox(str, 128, nullptr, s1.c_str(), s2.c_str()); // 弹出输入框，获取用户输入的文本
	s2 = str; // 更新文本内容
	if (s2 == "0" || s2 == "")
	{
		op = Menu;
		return;
	}
	std::istringstream iss(s2);
	Goods b;
	iss >> b.goodsid >> b.goodsname >> b.catalog >> b.price >> b.contain;
	goodslist.push_back(b); 
	a.insertGoods(b);


}

void ManageMent::erase1()
{	//实现遍历 ，然后删除掉对应位置
	
	Table a(16, 5);
	a.setHeader(goodshead);

	a.show();
	char title[50] = "删除";
	outtextxy((Window::width() - textwidth(title)) / 2, 0, title);

	char str[128] = { 0 };
	string s1, s2 = "请输入你要删除的id 按0或者不输入数据返回主界面 ";
	InputBox(str, 128, nullptr, s2.c_str(), s1.c_str()); // 弹出输入框，获取用户输入的文本
	s2 = str; // 更新文本内容
	if (s2 == "0" || s2 == "")
	{
		op = Menu;
		return;
	}
	Sleep(100);
	int textw = ::textwidth(s2.c_str());
	//LineEdit le;
	//le.popInputBox()
	int number = stoi(s2.c_str());
	for (auto it = goodslist.begin(); it != goodslist.end(); ) {
		if (it->goodsid == number) {
			// 删除符合条件的元素
			//std::cout << ;
			a.insertGoods(*it);
			it = goodslist.erase(it);
		}
		else {
			// 继续下一个元素
			++it;
		}
	}

}

	

void ManageMent::find1()
{		//	实现遍历  但是不做操作
	
	Table a(16, 5);
	a.setHeader(goodshead);

	a.show();


	char title[50] = "查找";
	outtextxy((Window::width() - textwidth(title)) / 2, 0, title);

	char str[128] = { 0 };
	string s1, s2 = "请输入你要查找的id 按0或者不输入数据返回主界面 ";
	InputBox(str, 128, nullptr, s2.c_str(), s1.c_str()); // 弹出输入框，获取用户输入的文本
	s2 = str; // 更新文本内容
	if (s2 == "0" || s2 == "")
	{
		op = Menu;
		return;
	}
	Sleep(100);
	int textw = ::textwidth(s2.c_str());
	//LineEdit le;
	//le.popInputBox()
	int number = stoi(s2.c_str());
	for (auto b : goodslist) {
		//std::cout << b.bookid;
		if (b.goodsid == number)
			a.insertGoods(b);
	
	}

}
void ManageMent::paymoney()
{
	Table a(16, 5);
	char title[50] = "结算";
	outtextxy((Window::width() - textwidth(title)) / 2, 0, title);

	a.setHeader(goodshead);
	//a.show();
	char str[128] = { 0 };
	string s2, s1 = "输入要购买的商品id ,购买的用户id ";
	InputBox(str, 128, nullptr, s1.c_str(), s2.c_str()); // 弹出输入框，获取用户输入的文本

	s2 = str; // 更新文本内容
	if (s2 == "0" || s2 == "")
	{
		op = Menu;
		return;
	}Sleep(100);
	std::istringstream iss(s2);
	int bid, mid;//书id 人id 数量
	iss >> bid >> mid;
	auto it1 = goodslist.begin();
	for (auto it = goodslist.begin(); it != goodslist.end(); ) {
		if (it->goodsid == bid) {
			// 删除符合条件的元素
			//std::cout << ;
			it1 = it;
			break;
		}
		else {
			// 继续下一个元素
			++it;
		}
	}


	auto it2 =  list.begin();
	for (auto it =  list.begin(); it !=  list.end(); ) {
		if (it->buyerid == mid) {
			// 删除符合条件的元素
			//std::cout << ;
			it2 = it;
			break;
		}
		else {
			// 继续下一个元素
			++it;
		}
	}
	it2->pay += it1->price;
	int result1 = MessageBox(GetHWnd(), "支付 ？ ", "确认", MB_YESNO | MB_ICONQUESTION);
	if (result1 == IDYES) {
		if (it2->pay * it2->discount <= it2->card_contain)
		{	
			
			it2->card_contain -= (it2->pay)* (it2->discount);
			it1->contain -= 1;
			it2->pay = 0;
			char title[50] = "支付成功 返回主界面";
			outtextxy((Window::width() - textwidth(title)) / 2, 0, title);
			//输出支付成功  返回主界面

			op = Menu;
			return;
		}
		else {
			//输出支付失败 
			char title[50] = "支付成功 返回主界面";
			outtextxy((Window::width() - textwidth(title)) / 2, 0, title);
			return;
			//返回主界面
		}

	}
	else {
		op = Menu;
		return;
	}

}


void ManageMent::displayall2()
{ //同上  感觉可以直接用 
	Table a(16, 5);
	a.setHeader2(buyerhead);

	a.show();
	a.insertData2(list);
	Window::flushDraw();
}

void ManageMent::insert2()
{
	
	Table a(16, 5);
	a.setHeader2(buyerhead);
	a.show();
	//实现输入框 ，然后添加到booklist 



	char title[50] = "添加";
	outtextxy((Window::width() - textwidth(title)) / 2, 0, title);

	char str[128] = { 0 };
	string s2, s1 = "以名字 id 支付数 折扣率 余额的价格输入，请以 按0或者不输入数据返回主界面";
	InputBox(str, 128, nullptr, s1.c_str(), s2.c_str()); // 弹出输入框，获取用户输入的文本
	s2 = str; // 更新文本内容
	if (s2 == "0" || s2 == "")
	{
		op = Menu;
		return;
	}
	std::istringstream iss(s2);
	membercard b;
	 iss >> b.name >> b.buyerid >> b.pay >> b.discount >> b.card_contain;
	 list.push_back(b);
	a.insertbuyer(b);
}

void ManageMent::erase2()
{

	Table a(16, 5);
	a.setHeader2(buyerhead);

	a.show();


	char title[50] = "删除";
	outtextxy((Window::width() - textwidth(title)) / 2, 0, title);

	char str[128] = { 0 };
	string s1, s2 = "请输入你要删除的id 按0或者不输入数据返回主界面 ";
	InputBox(str, 128, nullptr, s2.c_str(), s1.c_str()); // 弹出输入框，获取用户输入的文本
	s2 = str; // 更新文本内容
	if (s2 == "0" || s2 == "")
	{
		op = Menu;
		return;
	}
	Sleep(100);
	int textw = ::textwidth(s2.c_str());
	//LineEdit le;
	//le.popInputBox()
	int number = stoi(s2.c_str());
	for (auto it = list.begin(); it != list.end(); ) {
		if (it->buyerid == number) {
			// 删除符合条件的元素
			//std::cout << ;
			a.insertbuyer(*it);
			it =  list.erase(it);
		}
		else {
			// 继续下一个元素
			++it;
		}
	}
}
void ManageMent::find2()
{	
	Table a(16, 5);
	a.setHeader2(buyerhead);

	a.show();


	char title[50] = "查找";
	outtextxy((Window::width() - textwidth(title)) / 2, 0, title);

	char str[128] = { 0 };
	string s1, s2 = "请输入你要查找的id 按0或者不输入数据返回主界面 ";
	InputBox(str, 128, nullptr, s2.c_str(), s1.c_str()); // 弹出输入框，获取用户输入的文本
	s2 = str; // 更新文本内容
	if (s2 == "0" || s2 == "")
	{
		op = Menu;
		return;
	}
	Sleep(100);
	int textw = ::textwidth(s2.c_str());
	//LineEdit le;
	//le.popInputBox()
	int number = stoi(s2.c_str());
	for (auto b : list) {
		//std::cout << b.bookid;
		if (b.buyerid == number)
			a.insertbuyer(b);

	}
}





void ManageMent::drawBK()
{
	::putimage(0, 0, &m_bk);
}
//格式化读取方法  by 文件
void ManageMent::readgoodsFile(const std::string& fileName) {
	fstream read(fileName, ios::in);
	if (!read.is_open()) {
		cout << "没读出" << endl;
		return; //防止没读出 
	}
	char buf[1024] = { 0 };
	read.getline(buf, 1024);

	goodshead = buf;
	goodshead = goodshead + "\n";
	std::cout << goodshead <<endl;
	while (!read.eof()) {
		char data[1024] = { 0 };
		//跳过空行
		

		read.getline(data, 1024);
		stringstream ss(data);
		Goods b1;
		ss >> b1.goodsid>>b1.goodsname>>b1.catalog>>b1.price>>b1.contain; //读入 存到vector
		goodslist.push_back(b1);
		cout << b1.goodsid << b1.goodsname << b1.catalog << b1.price << b1.contain<<endl;
	}
	read.close();
}
void  ManageMent::savegoodsFile(const std::string& fileName) { 
	fstream write0(fileName, ios::out | ios::trunc);
	if (!write0.is_open()) {
		cerr <<  "file open error1" << endl;
		return;
	} //打开失败

	write0.write(goodshead.c_str(), goodshead.size());
	for (auto&b0 : goodslist) {
		std::string s1 = b0.formatInfo();
		write0.write(s1.c_str(), s1.size());
	}
}

void  ManageMent::savebuyerFile(const std::string& fileName) {
	fstream write1(fileName, ios::out | ios::trunc);
	if (!write1.is_open()) {
		cerr <<  "file open error2" << endl;
		return;
	}

	write1.write(buyerhead.c_str(), buyerhead.size());
	for (auto& b0 :list) {
		std::string s1 = b0.formatInfo();
		write1.write(s1.c_str(), s1.size());
	}
}

void  ManageMent::readbuyerFile(const std::string& fileName) {
	fstream read1(fileName, ios::in);
	if (!read1.is_open()) {
		cout << "没读出" << endl;
		return; //防止没读出 
	}
	char buf[1024] = { 0 };
	read1.getline(buf, 1024);

	buyerhead = buf;
	buyerhead = buyerhead+"\n";
	cout << buyerhead << endl;
//备注  debug ：文件不要多无用 空行
	while (!read1.eof()) {
		

		char data[1024] = { 0 };
		read1.getline(data, 1024); //读行
	
		stringstream ss(data);
		membercard b1;
		ss >> b1.name >> b1.buyerid >> b1.pay >> b1.discount >> b1.card_contain;
		list.push_back(b1);
		cout << b1.name << b1.buyerid << b1.pay << b1.discount << b1.card_contain<< endl;
		cout << data<<endl;


	}
}
//书号	书名		作者		价格	库存容量
//名字	ID	账单需支付	会员折扣率	卡内余额

