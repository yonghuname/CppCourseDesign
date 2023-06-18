	#pragma once
	#include<string>
	#
	class Goods

	{
	public:
		double price;
		std::string goodsname;
		std::string catalog;
		//std::string press;//出版社
		int goodsid;
		int contain;//库存容量

		void display();
		 int   getgoodsid();
		 std::string   getgoodsname();
		 std::string   getcatlog();
		int getcontain();
		double getprice(); 
		 //std::string   getpress();
		Goods(double price1,  std::string   name1,  std::string   catalog1, int goodsid1, int contain1);
		Goods();
		std::string formatInfo();

	};