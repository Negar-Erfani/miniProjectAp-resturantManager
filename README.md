Restaurant Order Management System
Overview
The Restaurant Order Management System is a C++ application designed to manage restaurant orders efficiently using AVL Tree and Linked List data structures. The system enables users to add, delete, modify, and review orders, as well as manage a categorized menu (food, appetizers, drinks). Orders are stored persistently in order information.txt, and menu items are saved in separate text files (food.txt, apetizer.txt, drink.txt). The AVL Tree ensures efficient order retrieval and balanced operations.
Features

Order Management:
Add new orders with customer details (name, student ID) and items.
Delete specific items from an order (if more than one item exists).
Replace items in an order with new ones from the menu.
Update order status (e.g., "Processing", "Delivered", "Canceled").
Review all orders stored in the system.


Menu Management:
Supports categorized menu items (food, appetizers, drinks).
Allows adding new menu items via text files or user input during initialization.
Validates order items against the menu.


Data Persistence:
Orders are saved to order information.txt.
Menu items are stored in food.txt, apetizer.txt, and drink.txt.


Efficient Data Structures:
Uses an AVL Tree for balanced storage and retrieval of orders.
Uses Linked Lists to store menu items and order items.



Technologies Used

Programming Language: C++
Data Structures:
AVL Tree (for order storage and retrieval)
Linked List (for menu items and order items)


File I/O: Reads/writes data to text files for persistence
Standard Libraries: <iostream>, <vector>, <string>, <fstream>, <map>, <sstream>, <algorithm>

Project Structure
├── AVL.h                 # AVL Tree class definition
├── AVL.cpp               # AVL Tree implementation (insert, remove, search, rotations)
├── linkedlist.h          # Linked List class definition for menu and order items
├── listOfOrders.h        # Class definition for managing list of orders
├── listOfOrders.cpp      # Implementation of order management (add, delete, replace, status change)
├── Menu.h                # Menu class definition
├── Menu.cpp              # Menu implementation (add items, check menu)
├── MenuItem.h            # MenuItem class definition
├── MenuItem.cpp          # MenuItem implementation (load/add menu items)
├── Order.h               # Order struct definition
├── Order.cpp             # Order implementation (order creation, status change)
├── main.cpp              # Main program logic and user interface
├── order information.txt # Stores order data (e.g., order number, customer info, items)
├── food.txt              # Stores food menu items
├── apetizer.txt          # Stores appetizer menu items (e.g., salad, soup)
├── drink.txt             # Stores drink menu items

Menu Files
The menu is divided into three categories, each stored in a separate text file. If a file doesn't exist, the program prompts the user to create it by entering items (type end to finish). Below is an example of the apetizer.txt file:
salad
soup


food.txt: Contains main course items (e.g., sandwich, pizza).
apetizer.txt: Contains appetizer items (e.g., salad, soup).
drink.txt: Contains drink items (e.g., water, juice).

Each file lists one item per line. The program loads these items into linked lists for validation during order placement.
Prerequisites

C++ Compiler: Ensure you have a C++ compiler (e.g., g++) installed.
Git: Required for cloning the repository.
Operating System: The code includes Windows-specific console encoding (system("chcp 65001")) for UTF-8 support. For non-Windows systems, you may need to modify or remove this line.
Text Files: The program expects the following files in the project directory:
order information.txt (for orders)
food.txt, apetizer.txt, drink.txt (for menu items, created automatically if they don't exist)



Installation and Setup

Clone the Repository:git clone https://github.com/Negar-Erfani/restaurant-order-system.git
cd restaurant-order-system


Compile the Code:
Use a C++ compiler like g++ to compile the program:g++ -o restaurant main.cpp AVL.cpp listOfOrders.cpp Menu.cpp MenuItem.cpp Order.cpp




Run the Program:
Execute the compiled binary:./restaurant





Usage

Run the Program:
Start the program, and it will load the menu and existing orders from order information.txt.


Available Commands:
getOrder: Add a new order by entering customer name, student ID (8 digits), and items (type end to finish).
delete: Remove an item from an existing order by specifying the order number and item.
add: Add a new item to an existing order.
chandeStatus: Update the status of an order (e.g., "Delivered" or "Canceling").
review: Display all orders from the file.
Any other input will exit the program.


Menu Management:
If food.txt, apetizer.txt, or drink.txt do not exist, the program prompts you to create them by entering items (type end to finish).


Order Validation:
Items must exist in the menu to be added to an order.
Student IDs must be 8 digits.
Orders cannot be deleted if they have only one item.



Example
Sample Input/Output
your wish is my command:
getOrder
please enter customer's name:
Ali
please enter customer's studentID:
12345678
please enter customer's order. write end when you are done:
salad
soup
end
your wish is my command:
review
1 Negar 40328853 sandwich Processing
2 Omaij 12345678 soup Processing
3 Ali 12345678 salad soup Processing

Sample order information.txt
1 Negar 40328853 sandwich Processing
2 Omaij 12345678 soup Processing
5 Mina 40328853 water Processing

Notes

Error Handling: The program validates inputs (e.g., student ID, menu items) and provides appropriate error messages.
File Management: Orders are rewritten to order information.txt after every modification to ensure persistence.
Platform-Specific Code: The system("chcp 65001") command is Windows-specific for UTF-8 encoding. For cross-platform compatibility, consider removing or replacing it.
Limitations:
The program does not support concurrent users.
Menu items are loaded from files at startup and cannot be modified dynamically during execution.



Contributing
We welcome contributions to improve the project! To contribute:

Fork the repository.
Create a new branch for your feature or bug fix:git checkout -b feature/<your-feature-name>


Commit your changes:git commit -m "Add <your-feature-description>"


Push to your branch:git push origin feature/<your-feature-name>


Open a pull request with a detailed description of your changes.

License
This project is licensed under the MIT License. See the LICENSE file for details.
Contact
For questions or suggestions, feel free to open an issue on GitHub or contact the maintainer at negarer1384@gmail.com
