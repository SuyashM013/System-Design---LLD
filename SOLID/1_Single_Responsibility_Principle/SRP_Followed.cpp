#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    string name;
    double price;

    Product(string _name, double _price) : name(_name), price(_price) {}
};

// voilating SRP, because it has more than one responsibility
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

    void printInvoice()
    {
        cout << "Invoice:" << endl;
        for (auto p : products)
        {
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total: $" << calculateTotal() << endl;
    }

    void saveToDB()
    {
        cout << "Saving to DB" << endl;
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

class shopingCartDB
{
    ShoppingCart *cart;

public:
    shopingCartDB(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void saveToDB()
    {
        cout << "Saving to DB" << endl;
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
    db.saveToDB();

    cout << endl;
    ShoppingCart *cart2 = new ShoppingCart();

    cart2->addProduct(new Product("Laptop", 12344.5));
    ShopingCartPrinter printer2(cart2);
    printer2.printInvoice();

    cout << endl;
    return 0;
}