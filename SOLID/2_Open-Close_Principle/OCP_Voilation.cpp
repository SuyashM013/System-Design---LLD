#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    string name;
    double price;

    Product(string _name, double _price) : name(_name), price(_price) {}
};


class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProduct(Product *p)
    {
        products.push_back(p);
    }

    const vector<Product *> &getProducts() const
    {
        return products;
    }

    double calculateTotal()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }

};

class ShopingCartPrinter
{
    ShoppingCart *cart;

public:
    ShopingCartPrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void printInvoice()
    {
        cout << "Invoice:" << endl;
        for (auto p : cart->getProducts())
        {
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total: $" << cart->calculateTotal() << endl;
    }
};


// voilating SRP, because it has more than one responsibility + OCP, new database yh koi bh functinality add krne ke lie same class modify krna padega

class shopingCartDB
{
    ShoppingCart *cart;

public:
    shopingCartDB(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void saveToSQLDB()
    {
        cout << "Saving to SQL DB" << endl;
    }

    void saveToMongoDB(){
        cout << "Saving to MongoDB" << endl;

    }

    void SaveToFile(){
        cout << "Saving to File DB" << endl;
    }
};


int main()
{

    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 1000.0));
    cart->addProduct(new Product("Mobile", 500.0));

    ShopingCartPrinter printer(cart);
    printer.printInvoice();

    shopingCartDB db(cart);
    db.saveToSQLDB();



    cout << endl;
    return 0;
}