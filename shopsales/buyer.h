#pragma once
#include<string>	

using namespace std;


class membercard {
private:

public:
	double discount;//折扣率 
	double card_contain;//卡内余额
	double pay;
	std::string   name;
	int buyerid;

	double getshouldpay();
	void getcardpay();
	void change_card_contain();

	std::string   getname();
	int gerbuyerid();
	std::string formatInfo();
};