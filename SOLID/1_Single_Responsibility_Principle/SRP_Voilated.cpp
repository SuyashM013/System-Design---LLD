#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    string name;
    double price;

    Product(string _name, double _price) : name(_name), price(_price) {}
};


//voilating SRP, because it has more than one responsibility
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

    void printInvoice(){
        cout << "Invoice:" << endl;
        for (auto p : products)
        {
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total: $" << calculateTotal() << endl;
    } 

    void saveToDB(){
        cout << "Saving to DB" << endl;
    }
};

int main()
{
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 1000.0));
    cart->addProduct(new Product("Mobile", 500.0));

    cart->printInvoice();
    cart->saveToDB();
    cout << cart->calculateTotal();
    cout << endl;
    return 0;
}