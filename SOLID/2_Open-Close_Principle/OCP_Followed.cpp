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

class shopingCartDB
{
    ShoppingCart *cart;

public:
    virtual void save(ShoppingCart *cart) = 0;
};

class shopingCartSQLDB : public shopingCartDB
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving to SQL DB, with total price ->"<< cart->calculateTotal() << endl;
    }
};

class shopingCartMongoDB : public shopingCartDB
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving to MongoDB, with total price ->"<< cart->calculateTotal()  << endl;
    }
};

class shopingCartFileDB : public shopingCartDB
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving to File DB , with total price ->"<< cart->calculateTotal()    << endl;
    }
};

int main()
{

    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 1000.0));
    cart->addProduct(new Product("Mobile", 500.0));

    ShoppingCart* cart2 = new ShoppingCart();

    cart2->addProduct(new Product("TV", 233333));


    ShopingCartPrinter printer(cart);
    printer.printInvoice();


    shopingCartDB* db = new shopingCartMongoDB();
    shopingCartDB* db2 = new shopingCartSQLDB();
    shopingCartDB* db3 = new shopingCartFileDB();

    db->save(cart);
    db2->save(cart);
    
    db3->save(cart2);


    cout << endl;
    return 0;
}