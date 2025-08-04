#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <sstream>

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
     std::string RealtimeDate()
     {
          auto now = std::chrono::system_clock::now();
          auto in_time_t = std::chrono::system_clock::to_time_t(now);
          std::stringstream ss;

          ss << std::put_time(std::localtime(&in_time_t), "%d-%b-%Y");
          return ss.str();
     }

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
          std::stringstream output;
          output << std::setfill('*') << std::setw(40) << "" << std::endl;
          output << std::setfill(' ');
          output << "*   INVOICE                 *\n";
          output << std::setfill('*') << std::setw(40) << "" << std::endl;
          output << std::setfill(' ');
          output << "Customer name : " << customer_name << "\n";
          output << "Date :- " << RealtimeDate() << "\n\n";

          output << std::setfill('-') << std::setw(68) << "" << std::endl;
          output << std::setfill(' ');
          output << std::left << std::setw(20) << "Item"
                 << std::setw(15) << "Category"
                 << std::right << std::setw(10) << "Qty"
                 << std::setw(10) << "Price"
                 << std::setw(12) << "Total" << std::endl;
          output << std::setfill('-') << std::setw(68) << "" << std::endl;
          output << std::setfill(' ');

          double subtotal = 0.0;
          double gsttotal = 0.0;
          output << std::fixed << std::setprecision(2);

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

               output << std::left << std::setw(20) << item.name
                      << std::setw(15) << item.category
                      << std::right << std::setw(10) << item.quantity
                      << std::setw(10) << item.price
                      << std::setw(12) << itemtotal << std::endl;
          }
          output << std::setfill('-') << std::setw(68) << "" << std::endl;
          output << std::setfill(' ');
          output << std::left << std::setw(50) << "Sub-Total :- " << std::right << std::setw(10) << subtotal << std::endl;
          output << std::left << std::setw(50) << "Total GST:- " << std::right << std::setw(10) << gsttotal << std::endl;
          output << std::setfill('-') << std::setw(68) << "" << std::endl;
          output << std::setfill(' ');
          output << std::left << std::setw(50) << "GRAND TOTAL:" << std::right << std::setw(10) << subtotal + gsttotal << std::endl;
          output << std::setfill('-') << std::setw(68) << "" << std::endl;
          output << std::setfill(' ');

          output << "\nThank you for coming !\n";
          std::cout << output.str();
          std::string filename = customer_name + "_" + RealtimeDate() + ".txt";
          std::ofstream write(filename);

          if (write.is_open())
          {
               write << output.str();
               write.close();
               std::cout << " File is saved ! " << std::endl;
          }
          else
          {
               std::cout << " ERROR: File is not  saved !" << std::endl;
          }
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
     std::getline(std::cin, cname);
     obj.set_name(cname);

     char choice;
     do
     {
          std::cout << "Enter item name : ";
          std::getline(std::cin, iname);
          std::cout << "Enter quantity : ";
          std::cin >> qty;
          std::cout << "Enter the price per item : Rs ";
          std::cin >> pr;
          std::cout << "Enter the category : ( 'Luxury' or  'Standard) ";
          std::cin >> category;
          Item obji(iname, category, qty, pr);
          obj.additem(obji);
          std::cout << "Want to add another item ? (y/n) ";
          std::cin >> choice;
          std::cin.ignore(); 
     } while (choice == 'y' || choice == 'Y');
     obj.invoiceprint();
     return 0;
}