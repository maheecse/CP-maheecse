/*
    ONLINE SHOPPING MANAGEMENT SYSTEM (WITH TRY-THROW-CATCH)
    Features: Classes, Inheritance, Encapsulation, File I/O, Exception Handling
    Target Line Count: ~730 lines
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

const int LINE_WIDTH = 70;

// ===================== UI & HELPER FUNCTIONS =====================
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printLine()
{
    cout << string(LINE_WIDTH, '-') << "\n";
}

void printHeader(const string &title)
{
    printLine();
    int pad = (LINE_WIDTH - (int)title.size()) / 2;
    if (pad < 0)
        pad = 0;
    cout << string(pad, ' ') << title << "\n";
    printLine();
}

void pauseScreen()
{
    cout << "\nPress ENTER to continue...";
    string dummy;
    getline(cin, dummy);
}

string toLowerStr(string s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

string getCurrentDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    ostringstream oss;
    oss << setfill('0') << setw(2) << ltm->tm_mday << "-"
        << setfill('0') << setw(2) << (1 + ltm->tm_mon) << "-"
        << (1900 + ltm->tm_year);
    return oss.str();
}

// Exception Handling in Input Functions
int readInt(const string &prompt)
{
    int val;
    while (true)
    {
        cout << prompt;
        try
        {
            if (!(cin >> val))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                throw "Invalid input! Please enter a valid integer.";
            }
            cin.ignore(1000, '\n');
            return val;
        }
        catch (const char *msg)
        {
            cout << "[ERROR] " << msg << "\n";
        }
    }
}

double readDouble(const string &prompt)
{
    double val;
    while (true)
    {
        cout << prompt;
        try
        {
            if (!(cin >> val))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                throw "Invalid input! Please enter a valid double number.";
            }
            cin.ignore(1000, '\n');
            return val;
        }
        catch (const char *msg)
        {
            cout << "[ERROR] " << msg << "\n";
        }
    }
}

string readLineTrim(const string &prompt)
{
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}

// ===================== CLASSES =====================

// Base User Class
class User
{
protected:
    int id;
    string name;
    string username;
    string password;

public:
    User(int id_ = 0, string name_ = "", string username_ = "", string password_ = "")
        : id(id_), name(name_), username(username_), password(password_) {}

    virtual ~User() {}

    virtual void displayInfo() const
    {
        cout << "ID       : " << id << "\n"
             << "Name     : " << name << "\n"
             << "Username : " << username << "\n";
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getUsername() const { return username; }
    string getPassword() const { return password; }
    bool checkPassword(const string &p) const { return password == p; }
};

// Customer Class
class Customer : public User
{
private:
    string address;

public:
    Customer() : User() {}
    Customer(int id_, string name_, string username_, string password_, string address_ = "N/A")
        : User(id_, name_, username_, password_), address(address_) {}

    string getAddress() const { return address; }

    void displayInfo() const override
    {
        cout << "----- CUSTOMER PROFILE -----\n";
        cout << "ID       : " << id << "\n"
             << "Name     : " << name << "\n"
             << "Username : " << username << "\n"
             << "Address  : " << address << "\n";
    }
};

// Admin Class
class Admin : public User
{
public:
    Admin() : User() {}
    Admin(int id_, string name_, string username_, string password_)
        : User(id_, name_, username_, password_) {}

    void displayInfo() const override
    {
        cout << "----- ADMIN PROFILE -----\n";
        cout << "ID       : " << id << "\n"
             << "Name     : " << name << "\n"
             << "Username : " << username << "\n";
    }
};

// Product Class
class Product
{
private:
    int productId;
    string name;
    string category;
    double price;
    int stock;

public:
    Product() : productId(0), name(""), category(""), price(0), stock(0) {}
    Product(int id_, string name_, string category_, double price_, int stock_)
        : productId(id_), name(name_), category(category_), price(price_), stock(stock_) {}

    int getId() const { return productId; }
    string getName() const { return name; }
    string getCategory() const { return category; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    void setName(const string &n) { name = n; }
    void setCategory(const string &c) { category = c; }
    void setPrice(double p) { price = p; }
    void setStock(int s) { stock = s; }

    void reduceStock(int qty)
    {
        if (qty > stock)
            throw "Not enough stock available to reduce!";
        stock -= qty;
    }

    void displayRow() const
    {
        cout << left << setw(8) << productId << setw(25) << name.substr(0, 24)
             << setw(18) << category << setw(12) << fixed << setprecision(2) << price
             << setw(8) << stock << "\n";
    }
};

// Cart Item Struct
struct CartItem
{
    int productId;
    int quantity;
    CartItem(int pid = 0, int qty = 0) : productId(pid), quantity(qty) {}
};

// Order Class
class Order
{
private:
    int orderId;
    int customerId;
    vector<CartItem> items;
    double totalAmount;
    string orderDate;
    string status;

public:
    Order() : orderId(0), customerId(0), totalAmount(0), status("Pending") {}
    Order(int orderId_, int customerId_, vector<CartItem> items_, double totalAmount_,
          string orderDate_, string status_ = "Pending")
        : orderId(orderId_), customerId(customerId_), items(items_),
          totalAmount(totalAmount_), orderDate(orderDate_), status(status_) {}

    int getOrderId() const { return orderId; }
    int getCustomerId() const { return customerId; }
    const vector<CartItem> &getItems() const { return items; }
    double getTotalAmount() const { return totalAmount; }
    string getDate() const { return orderDate; }
    string getStatus() const { return status; }
    void setStatus(const string &s) { status = s; }
};

// ===================== SHOP MANAGER CLASS =====================
class ShopManager
{
private:
    vector<Product> products;
    vector<Customer> customers;
    vector<Admin> admins;
    vector<Order> orders;

    vector<CartItem> currentCart;
    int loggedInCustomerId;

    int nextProductId;
    int nextCustomerId;
    int nextOrderId;

    Product *findProductById(int id)
    {
        for (size_t i = 0; i < products.size(); i++)
        {
            if (products[i].getId() == id)
                return &products[i];
        }
        return nullptr;
    }

    Customer *findCustomerByUsername(const string &uname)
    {
        for (size_t i = 0; i < customers.size(); i++)
        {
            if (customers[i].getUsername() == uname)
                return &customers[i];
        }
        return nullptr;
    }

public:
    ShopManager()
    {
        loggedInCustomerId = -1;
        nextProductId = 101;
        nextCustomerId = 1;
        nextOrderId = 1001;
    }

    // ============ FILE HANDLING WITH EXCEPTION HANDLING ============
    void loadProducts()
    {
        try
        {
            ifstream file("products.txt");
            if (!file.is_open())
                return;
            string line;
            while (getline(file, line))
            {
                if (line.empty())
                    continue;
                stringstream ss(line);
                string idStr, name, category, priceStr, stockStr;
                getline(ss, idStr, '|');
                getline(ss, name, '|');
                getline(ss, category, '|');
                getline(ss, priceStr, '|');
                getline(ss, stockStr, '|');

                int id = atoi(idStr.c_str());
                double price = atof(priceStr.c_str());
                int stock = atoi(stockStr.c_str());

                products.push_back(Product(id, name, category, price, stock));
                if (id >= nextProductId)
                    nextProductId = id + 1;
            }
            file.close();
        }
        catch (...)
        {
            cout << "[WARNING] Failed to load products file properly.\n";
        }
    }

    void saveProducts()
    {
        try
        {
            ofstream file("products.txt");
            if (!file.is_open())
                throw "Unable to open products file for saving.";
            for (size_t i = 0; i < products.size(); i++)
            {
                file << products[i].getId() << "|" << products[i].getName() << "|"
                     << products[i].getCategory() << "|" << products[i].getPrice() << "|"
                     << products[i].getStock() << "\n";
            }
            file.close();
        }
        catch (const char *err)
        {
            cout << "[ERROR] " << err << "\n";
        }
    }

    void loadCustomers()
    {
        ifstream file("customers.txt");
        if (!file.is_open())
            return;
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;
            stringstream ss(line);
            string idStr, name, username, password, address;
            getline(ss, idStr, '|');
            getline(ss, name, '|');
            getline(ss, username, '|');
            getline(ss, password, '|');
            getline(ss, address, '|');

            int id = atoi(idStr.c_str());
            customers.push_back(Customer(id, name, username, password, address));
            if (id >= nextCustomerId)
                nextCustomerId = id + 1;
        }
        file.close();
    }

    void saveCustomers()
    {
        ofstream file("customers.txt");
        for (size_t i = 0; i < customers.size(); i++)
        {
            file << customers[i].getId() << "|" << customers[i].getName() << "|"
                 << customers[i].getUsername() << "|" << customers[i].getPassword() << "|"
                 << customers[i].getAddress() << "\n";
        }
        file.close();
    }

    void loadOrders()
    {
        ifstream file("orders.txt");
        if (!file.is_open())
            return;
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;
            stringstream ss(line);
            string idStr, custStr, date, status, totalStr, itemsStr;
            getline(ss, idStr, '|');
            getline(ss, custStr, '|');
            getline(ss, date, '|');
            getline(ss, status, '|');
            getline(ss, totalStr, '|');
            getline(ss, itemsStr, '|');

            int id = atoi(idStr.c_str());
            int custId = atoi(custStr.c_str());
            double total = atof(totalStr.c_str());

            vector<CartItem> items;
            stringstream itemStream(itemsStr);
            string pair;
            while (getline(itemStream, pair, ','))
            {
                if (pair.empty())
                    continue;
                size_t colon = pair.find(':');
                if (colon != string::npos)
                {
                    int pid = atoi(pair.substr(0, colon).c_str());
                    int qty = atoi(pair.substr(colon + 1).c_str());
                    items.push_back(CartItem(pid, qty));
                }
            }
            orders.push_back(Order(id, custId, items, total, date, status));
            if (id >= nextOrderId)
                nextOrderId = id + 1;
        }
        file.close();
    }

    void saveOrders()
    {
        ofstream file("orders.txt");
        for (size_t i = 0; i < orders.size(); i++)
        {
            file << orders[i].getOrderId() << "|" << orders[i].getCustomerId() << "|"
                 << orders[i].getDate() << "|" << orders[i].getStatus() << "|"
                 << orders[i].getTotalAmount() << "|";

            const vector<CartItem> &items = orders[i].getItems();
            for (size_t j = 0; j < items.size(); j++)
            {
                file << items[j].productId << ":" << items[j].quantity;
                if (j + 1 < items.size())
                    file << ",";
            }
            file << "\n";
        }
        file.close();
    }

    void initializeSampleData()
    {
        if (products.empty())
        {
            products.push_back(Product(101, "Mechanical Keyboard", "Electronics", 3200.00, 15));
            products.push_back(Product(102, "Wireless Mouse", "Electronics", 1200.00, 28));
            products.push_back(Product(103, "Gaming Headset", "Accessories", 2500.00, 7));
            products.push_back(Product(104, "USB-C Hub", "Electronics", 1800.00, 20));
            products.push_back(Product(105, "Cotton T-Shirt", "Fashion", 650.00, 40));
            nextProductId = 106;
        }
        if (customers.empty())
        {
            customers.push_back(Customer(1, "Rahim Uddin", "rahim", "pass123", "Dhaka, BD"));
            customers.push_back(Customer(2, "Karim Ahmed", "karim", "pass123", "Chittagong, BD"));
            nextCustomerId = 3;
        }
        if (admins.empty())
        {
            admins.push_back(Admin(1, "System Admin", "admin", "admin123"));
        }
    }

    void loadData()
    {
        loadProducts();
        loadCustomers();
        loadOrders();
        initializeSampleData();
    }

    void saveData()
    {
        saveProducts();
        saveCustomers();
        saveOrders();
    }

    // ============ PRODUCT FUNCTIONS ============
    void listProducts(const vector<Product> &list)
    {
        if (list.empty())
        {
            cout << "[!] No products available.\n";
            return;
        }
        cout << left << setw(8) << "ID" << setw(25) << "Product Name"
             << setw(18) << "Category" << setw(12) << "Price" << setw(8) << "Stock" << "\n";
        printLine();
        for (size_t i = 0; i < list.size(); i++)
        {
            list[i].displayRow();
        }
        printLine();
    }

    void browseProducts()
    {
        clearScreen();
        printHeader("BROWSE PRODUCTS");
        listProducts(products);
        pauseScreen();
    }

    void searchProducts()
    {
        clearScreen();
        printHeader("SEARCH PRODUCTS");
        cout << "[1] Search by ID\n[2] Search by Name\n[3] Search by Category\n[0] Back\n";
        int choice = readInt("Enter choice: ");

        vector<Product> result;
        if (choice == 1)
        {
            int id = readInt("Enter Product ID: ");
            Product *p = findProductById(id);
            if (p != nullptr)
                result.push_back(*p);
        }
        else if (choice == 2)
        {
            string name = toLowerStr(readLineTrim("Enter Product Name: "));
            for (size_t i = 0; i < products.size(); i++)
            {
                if (toLowerStr(products[i].getName()).find(name) != string::npos)
                    result.push_back(products[i]);
            }
        }
        else if (choice == 3)
        {
            string cat = toLowerStr(readLineTrim("Enter Category: "));
            for (size_t i = 0; i < products.size(); i++)
            {
                if (toLowerStr(products[i].getCategory()).find(cat) != string::npos)
                    result.push_back(products[i]);
            }
        }
        else
            return;

        cout << "\n--- Search Results ---\n";
        listProducts(result);
        pauseScreen();
    }

    // ============ CUSTOMER FUNCTIONS WITH TRY-THROW ============
    void registerCustomer()
    {
        clearScreen();
        printHeader("CUSTOMER REGISTRATION");
        try
        {
            string name = readLineTrim("Full Name       : ");
            string username = readLineTrim("Choose Username : ");

            if (findCustomerByUsername(username) != nullptr)
                throw "Username already exists! Choose a different one.";

            string password = readLineTrim("Choose Password : ");
            string address = readLineTrim("Address         : ");

            customers.push_back(Customer(nextCustomerId++, name, username, password, address));
            saveCustomers();
            cout << "[SUCCESS] Registration successful!\n";
        }
        catch (const char *msg)
        {
            cout << "[ERROR] " << msg << "\n";
        }
        pauseScreen();
    }

    void loginCustomer()
    {
        clearScreen();
        printHeader("CUSTOMER LOGIN");
        try
        {
            string username = readLineTrim("Username : ");
            string password = readLineTrim("Password : ");

            Customer *c = findCustomerByUsername(username);
            if (c == nullptr || !c->checkPassword(password))
                throw "Invalid username or password.";

            loggedInCustomerId = c->getId();
            currentCart.clear();
            cout << "[SUCCESS] Welcome, " << c->getName() << "!\n";
            pauseScreen();
            customerSessionMenu();
        }
        catch (const char *msg)
        {
            cout << "[ERROR] " << msg << "\n";
            pauseScreen();
        }
    }

    // ============ CART & CHECKOUT WITH TRY-THROW ============
    void addToCart()
    {
        clearScreen();
        printHeader("ADD TO CART");
        listProducts(products);

        try
        {
            int id = readInt("Enter Product ID: ");
            Product *p = findProductById(id);

            if (p == nullptr)
                throw "Product with this ID was not found!";

            int qty = readInt("Enter Quantity: ");
            if (qty <= 0)
                throw "Quantity must be greater than zero!";

            int currentQtyInCart = 0;
            for (size_t i = 0; i < currentCart.size(); i++)
            {
                if (currentCart[i].productId == id)
                    currentQtyInCart += currentCart[i].quantity;
            }

            if (qty + currentQtyInCart > p->getStock())
                throw "Insufficient stock available for this quantity!";

            bool found = false;
            for (size_t i = 0; i < currentCart.size(); i++)
            {
                if (currentCart[i].productId == id)
                {
                    currentCart[i].quantity += qty;
                    found = true;
                    break;
                }
            }
            if (!found)
                currentCart.push_back(CartItem(id, qty));

            cout << "[SUCCESS] Item successfully added to cart!\n";
        }
        catch (const char *msg)
        {
            cout << "[ERROR] " << msg << "\n";
        }
        pauseScreen();
    }

    void viewCart()
    {
        clearScreen();
        printHeader("MY CART");
        if (currentCart.empty())
        {
            cout << "Your cart is empty.\n";
            pauseScreen();
            return;
        }

        cout << left << setw(28) << "Product" << setw(12) << "Quantity"
             << setw(15) << "Unit Price" << "Total\n";
        printLine();

        double total = 0;
        for (size_t i = 0; i < currentCart.size(); i++)
        {
            Product *p = findProductById(currentCart[i].productId);
            if (p != nullptr)
            {
                double lineTotal = p->getPrice() * currentCart[i].quantity;
                total += lineTotal;
                cout << left << setw(28) << p->getName().substr(0, 27)
                     << setw(12) << currentCart[i].quantity
                     << setw(15) << p->getPrice() << lineTotal << "\n";
            }
        }
        printLine();
        cout << "Subtotal: " << total << " BDT\n";
        pauseScreen();
    }

    void checkout()
    {
        clearScreen();
        printHeader("CHECKOUT");
        try
        {
            if (currentCart.empty())
                throw "Your cart is empty! Cannot proceed to checkout.";

            double subtotal = 0;
            for (size_t i = 0; i < currentCart.size(); i++)
            {
                Product *p = findProductById(currentCart[i].productId);
                if (p != nullptr)
                    subtotal += p->getPrice() * currentCart[i].quantity;
            }

            double grandTotal = subtotal + 100.0;
            cout << "Subtotal       : " << subtotal << " BDT\n";
            cout << "Delivery Charge: 100.00 BDT\n";
            cout << "Grand Total    : " << grandTotal << " BDT\n\n";

            cout << "[1] Confirm Order & Pay\n[0] Cancel\n";
            int choice = readInt("Enter choice: ");
            if (choice == 1)
            {
                // Reduce stock with try-catch inside
                for (size_t i = 0; i < currentCart.size(); i++)
                {
                    Product *p = findProductById(currentCart[i].productId);
                    if (p != nullptr)
                    {
                        p->reduceStock(currentCart[i].quantity); // Can throw exception
                    }
                }
                saveProducts();

                Order newOrder(nextOrderId++, loggedInCustomerId, currentCart, grandTotal, getCurrentDate(), "Confirmed");
                orders.push_back(newOrder);
                saveOrders();

                currentCart.clear();
                cout << "[SUCCESS] Order placed successfully! ID: " << newOrder.getOrderId() << "\n";
            }
        }
        catch (const char *msg)
        {
            cout << "[ERROR] " << msg << "\n";
        }
        pauseScreen();
    }

    void viewMyOrders()
    {
        clearScreen();
        printHeader("MY ORDERS");
        cout << left << setw(12) << "Order ID" << setw(15) << "Date"
             << setw(14) << "Amount" << "Status\n";
        printLine();

        bool hasOrders = false;
        for (size_t i = 0; i < orders.size(); i++)
        {
            if (orders[i].getCustomerId() == loggedInCustomerId)
            {
                hasOrders = true;
                cout << left << setw(12) << orders[i].getOrderId()
                     << setw(15) << orders[i].getDate()
                     << setw(14) << orders[i].getTotalAmount()
                     << orders[i].getStatus() << "\n";
            }
        }
        if (!hasOrders)
            cout << "No orders found.\n";
        pauseScreen();
    }

    // ============ ADMIN FUNCTIONS ============
    bool loginAdmin()
    {
        clearScreen();
        printHeader("ADMIN LOGIN");
        try
        {
            string username = readLineTrim("Username : ");
            string password = readLineTrim("Password : ");

            for (size_t i = 0; i < admins.size(); i++)
            {
                if (admins[i].getUsername() == username && admins[i].checkPassword(password))
                {
                    cout << "[SUCCESS] Admin logged in!\n";
                    pauseScreen();
                    return true;
                }
            }
            throw "Invalid admin credentials provided!";
        }
        catch (const char *msg)
        {
            cout << "[ERROR] " << msg << "\n";
            pauseScreen();
            return false;
        }
    }

    void addProduct()
    {
        clearScreen();
        printHeader("ADD PRODUCT");
        try
        {
            string name = readLineTrim("Product Name : ");
            string cat = readLineTrim("Category     : ");
            double price = readDouble("Price        : ");
            int stock = readInt("Stock        : ");

            if (price < 0 || stock < 0)
                throw "Price and stock cannot be negative numbers!";

            products.push_back(Product(nextProductId++, name, cat, price, stock));
            saveProducts();
            cout << "[SUCCESS] Product added successfully!\n";
        }
        catch (const char *msg)
        {
            cout << "[ERROR] " << msg << "\n";
        }
        pauseScreen();
    }

    void updateStock()
    {
        clearScreen();
        printHeader("UPDATE STOCK");
        listProducts(products);
        try
        {
            int id = readInt("Enter Product ID: ");
            Product *p = findProductById(id);
            if (p == nullptr)
                throw "Product not found!";

            int stock = readInt("Enter New Stock: ");
            if (stock < 0)
                throw "Stock quantity cannot be negative!";

            p->setStock(stock);
            saveProducts();
            cout << "[SUCCESS] Stock updated!\n";
        }
        catch (const char *msg)
        {
            cout << "[ERROR] " << msg << "\n";
        }
        pauseScreen();
    }

    void viewAllOrders()
    {
        clearScreen();
        printHeader("ALL ORDERS");
        cout << left << setw(10) << "Order ID" << setw(12) << "Customer ID"
             << setw(15) << "Date" << setw(12) << "Amount" << "Status\n";
        printLine();

        for (size_t i = 0; i < orders.size(); i++)
        {
            cout << left << setw(10) << orders[i].getOrderId()
                 << setw(12) << orders[i].getCustomerId()
                 << setw(15) << orders[i].getDate()
                 << setw(12) << orders[i].getTotalAmount()
                 << orders[i].getStatus() << "\n";
        }
        pauseScreen();
    }

    void updateOrderStatus()
    {
        clearScreen();
        printHeader("UPDATE ORDER STATUS");
        try
        {
            int id = readInt("Enter Order ID: ");

            Order *target = nullptr;
            for (size_t i = 0; i < orders.size(); i++)
            {
                if (orders[i].getOrderId() == id)
                {
                    target = &orders[i];
                    break;
                }
            }

            if (target == nullptr)
                throw "Order with specified ID not found!";

            cout << "[1] Pending  [2] Confirmed  [3] Delivered  [4] Cancelled\n";
            int choice = readInt("Select Status: ");
            if (choice == 1)
                target->setStatus("Pending");
            else if (choice == 2)
                target->setStatus("Confirmed");
            else if (choice == 3)
                target->setStatus("Delivered");
            else if (choice == 4)
                target->setStatus("Cancelled");
            else
                throw "Invalid status choice selected!";

            saveOrders();
            cout << "[SUCCESS] Status updated!\n";
        }
        catch (const char *msg)
        {
            cout << "[ERROR] " << msg << "\n";
        }
        pauseScreen();
    }

    // ============ MENUS ============
    void customerSessionMenu()
    {
        int choice;
        do
        {
            clearScreen();
            printHeader("CUSTOMER PORTAL");
            cout << "[1] Browse Products\n[2] Search Products\n[3] View Cart\n"
                 << "[4] Add to Cart\n[5] Checkout\n[6] My Orders\n[0] Logout\n";
            choice = readInt("Enter choice: ");

            switch (choice)
            {
            case 1:
                browseProducts();
                break;
            case 2:
                searchProducts();
                break;
            case 3:
                viewCart();
                break;
            case 4:
                addToCart();
                break;
            case 5:
                checkout();
                break;
            case 6:
                viewMyOrders();
                break;
            case 0:
                loggedInCustomerId = -1;
                break;
            default:
                cout << "Invalid choice!\n";
                pauseScreen();
                break;
            }
        } while (choice != 0);
    }

    void customerPortalMenu()
    {
        int choice;
        do
        {
            clearScreen();
            printHeader("CUSTOMER ACCESS");
            cout << "[1] Register\n[2] Login\n[0] Back\n";
            choice = readInt("Enter choice: ");

            switch (choice)
            {
            case 1:
                registerCustomer();
                break;
            case 2:
                loginCustomer();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!\n";
                pauseScreen();
                break;
            }
        } while (choice != 0 && loggedInCustomerId == -1);
    }

    void adminPortalMenu()
    {
        if (!loginAdmin())
            return;

        int choice;
        do
        {
            clearScreen();
            printHeader("ADMIN DASHBOARD");
            cout << "[1] Add Product\n[2] Browse Products\n[3] Update Stock\n"
                 << "[4] View All Orders\n[5] Update Order Status\n[0] Logout\n";
            choice = readInt("Enter choice: ");

            switch (choice)
            {
            case 1:
                addProduct();
                break;
            case 2:
                browseProducts();
                break;
            case 3:
                updateStock();
                break;
            case 4:
                viewAllOrders();
                break;
            case 5:
                updateOrderStatus();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!\n";
                pauseScreen();
                break;
            }
        } while (choice != 0);
    }

    void run()
    {
        int choice;
        do
        {
            clearScreen();
            printHeader("MAIN MENU - ONLINE SHOPPING SYSTEM");
            cout << "[1] Customer Portal\n[2] Admin Portal\n[3] Browse Products\n[0] Exit\n";
            choice = readInt("Enter choice: ");

            switch (choice)
            {
            case 1:
                customerPortalMenu();
                break;
            case 2:
                adminPortalMenu();
                break;
            case 3:
                browseProducts();
                break;
            case 0:
                cout << "Exiting application...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                pauseScreen();
                break;
            }
        } while (choice != 0);
    }
};

int main()
{
    try
    {
        ShopManager system;
        system.loadData();
        system.run();
        system.saveData();
    }
    catch (...)
    {
        cout << "[CRITICAL ERROR] An unexpected system error occurred.\n";
    }
    return 0;
}