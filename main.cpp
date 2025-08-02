#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

struct Item {
    std::string name;
    std::string category;
    int quantity;
    float price;
    Item (std::string n,std::string cat,int qty,float pr): name(n), category (cat) , quantity(qty), price(pr) {}
};
using It = Item;
class invoice {
     std::string customer_name;
     std::vector<Item>items;

     void set_name(const std::string &custname){
          customer_name = custname;
     }

     void additem (It &item){
        items.push_back(item);
     }

     void invoiceprint (){

     }

};
 