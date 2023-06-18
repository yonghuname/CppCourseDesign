#include "Goods.h"
#include<string>
#include<sstream>
using namespace std;
int Goods::getgoodsid()
{
    return goodsid;
}

string Goods::getgoodsname()
{
    return goodsname;
}

string Goods::getcatlog()
{
    return catalog;
}

int Goods::getcontain()
{
    return contain;
}

double Goods::getprice()
{
    return price;
}
 

Goods::Goods(double price1, string bookname1, string catalog1, int goodsid1, int contain1)
{
	price = price1;
	goodsname = bookname1;
	catalog = catalog1;
	//press = press1;
	goodsid = goodsid1;
	contain = contain1;
}
Goods::Goods() {};
std::string Goods::formatInfo() {
	std::stringstream ss;
	ss <<  goodsid <<"\t" << goodsname<<"\t\t" << catalog << "\t" << price << "\t" << contain << endl;
	return ss.str();
}
//id	书名		作者	价格	库存
//