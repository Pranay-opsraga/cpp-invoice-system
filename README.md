#  C++ Invoicing System 🧾

I built this project to apply my C++ knowledge to a real-world problem. It's a console application that helps small businesses in India generate invoices, and I challenged myself to implement features like   GST system (18% and 28%) to make it more realistic. By doing this project my understanding of OOP and file handling have solidfied.



## 📸 Screenshot


<img width="985" height="370" alt="Screenshot 2025-08-05 at 10 22 08 PM" src="https://github.com/user-attachments/assets/6ea12400-059f-45e1-91bf-ada5b0f0162e" />

## Key Learnings

- **Mastering Console I/O:** I learned how to handle the tricky `std::cin` and `std::getline` bug using `cin.ignore()`, a common problem in C++.
- **Professional Formatting:** This project was great practice for using the `<iomanip>` library to create perfectly aligned, table-formatted text output.
- **The DRY Principle:** I learned the importance of the "Don't Repeat Yourself" principle by using `stringstream` to build the invoice output once and then sending it to both the console and a file.

## ✨ Features

- Generate professional, table-formatted invoices.
- Add multiple items with quantity and price.
- **Tiered GST Calculation:** Applies 18% for "Standard" items and 28% for "Luxury" items.
- Saves each invoice to a unique, timestamped `.txt` file for record-keeping.
- User-friendly command-line interface.

## 🛠️ Tech Stack

- **Language:** C++
- **Core Libraries:** `<iostream>`, `<vector>`, `<string>`, `<iomanip>`, `<fstream>`, `<chrono>`

## 🚀 How to Run

1. Clone the repository:

 git clone https://github.com/Pranay-opsraga/cpp-invoice-system.git
 
2. Navigate to the directory:
 
   cd cpp-invoice-system
   
3. Compile the program :
 g++ main.cpp -o invoice

4. Run the executable :
 ./invoice

## 🗒️ Note 
- This my second cpp project. Uploading first project soon.....

## 🔗 LinkedIn 

  
-  Here, My linkedin account
  
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/pranay-sharma-a198a8250/)
   
   
