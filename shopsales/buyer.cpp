    #include "buyer.h"
    #include<string>
    #include<iostream>
    #include<sstream>
    using namespace std; 
     std::string membercard::getname()
    {
         return name;
    }
    int membercard::gerbuyerid()
    {
        return buyerid;
    }
    double membercard::getshouldpay()
    {
        return pay;
    }
    void membercard::getcardpay()
    {
    
        if (card_contain >= getshouldpay())
        {
            card_contain -=getshouldpay();
            //在图像上输出卡的余额。表示支付成功
            }
        else {
            //在图像上表示输出钱不够 转而使用现金支付

        }
    
    }
    void membercard::change_card_contain()
    {
        double newmoney ;
        std:: cin >> newmoney;
        // 从gui获得新钱数量
        card_contain = newmoney;
    }
    std::string  membercard::formatInfo() {
        std::stringstream ss;
        ss<<  name << "\t" << buyerid << "\t" << pay << "\t" << discount << "\t" << card_contain << endl;
        return ss.str();
    }  