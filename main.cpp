#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
 

struct Item
{
     std::string name;
     std::string category;
     int quantity;
     float price;
     Item(std::string n, std::string cat, int qty, float pr) : name(n), category(cat), quantity(qty), price(pr) {}
};
using It = Item;
class invoice
{

     std::string customer_name;
     std::vector<It> items;

public:
     void set_name(const std::string &custname)
     {
          customer_name = custname;
     }

     void additem(It &item)
     {
          items.push_back(item);
     }

     void invoiceprint()
     {

          std::cout << std::setfill('*') << std::setw(40) << "" << std::endl;
          std::cout << std::setfill(' ');
          std::cout << "*   INVOICE                 *\n";
          std::cout << std::setfill('*') << std::setw(40) << "" << std::endl;
          std::cout << std::setfill(' ');
          std::cout << "Customer name : " << customer_name << "\n\n";

          std::cout << std::setfill('-') << std::setw(68) << "" << std::endl;
          std::cout << std::setfill(' ');
          std::cout << std::left << std::setw(20) << "Item"
                    << std::setw(15) << "Category"
                    << std::right << std::setw(10) << "Qty"
                    << std::setw(10) << "Price"
                    << std::setw(12) << "Total" << std::endl;
          std::cout << std::setfill('-') << std::setw(68) << "" << std::endl;
          std::cout << std::setfill(' ');

          double subtotal = 0.0;
          double gsttotal = 0.0;
          std::cout << std::fixed << std::setprecision(2);

          for (const auto &item : items)
          {
               double itemtotal = item.quantity * item.price;
               subtotal += itemtotal;
               double gstrate = 0.18;
               if (item.category == "Luxury" || item.category == "luxury")
               {
                    double gstrate = 0.28;
               }
               gsttotal = itemtotal * gstrate;

               std::cout << std::left << std::setw(20) << item.name
                         << std::setw(15) << item.category
                         << std::right << std::setw(10) << item.quantity
                         << std::setw(10) << item.price
                         << std::setw(12) << itemtotal << std::endl;
          }
          std::cout << std::setfill('-') << std::setw(68) << "" << std::endl;
          std::cout << std::setfill(' ');
          std::cout << std::left << std::setw(50) << "Sub-Total :- " << std::right << std::setw(10) << subtotal << std::endl;
          std::cout << std::left << std::setw(50) << "Total GST:- " << std::right << std::setw(10) << gsttotal << std::endl;
          std::cout << std::setfill('-') << std::setw(68) << "" << std::endl;
          std::cout << std::setfill(' ');
          std::cout << std::left << std::setw(50) << "GRAND TOTAL:" << std::right << std::setw(10) << subtotal + gsttotal << std::endl;
           std::cout << std::setfill('-') << std::setw(68) << "" << std::endl;
          std::cout << std::setfill(' ');
       
          std::cout << "\nThank you for coming !";
     }
};

int main()
{
     invoice obj;
     std::string iname, category;
     std::string cname;
     float pr;
     int qty;

     std::cout << "Enter the name of the  customer : " << std::endl;
     std::getline(std::cin,cname);
     obj.set_name(cname);

     char choice;
     do
     {
          std::cout << "Enter item name : ";
           std::getline(std::cin,iname);
          std::cout << "Enter quantity : ";
          std::cin >> qty;
          std::cout << "Enter the price per item : Rs ";
          std::cin >> pr;
          std::cout << "Enter the category : (Luxury or Standard) ";
          std::cin >> category;
          Item obji(iname, category, qty, pr);
          obj.additem(obji);
          std::cout << "Want to add another item ? (y/n) ";
          std::cin >> choice;
          std::cin.ignore(); /* will get rid of newline character  */
     } while (choice == 'y' || choice == 'Y');
     obj.invoiceprint();
     return 0;
}