#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
public:
    int id;
    string name;
    double price;

    Product(int id = 0, string name = "", double price = 0.0)
        : id(id), name(name), price(price) {}
};

class Catalog {
public:
    vector<Product> products;

    void load() {
        products.push_back(Product(1, "Apple", 0.5));
        products.push_back(Product(2, "Bread", 1.5));
        products.push_back(Product(3, "Milk", 2.0));
        products.push_back(Product(4, "Chocolate", 1.0));
    }

    Product* find(int id) {
        for (auto& p : products)
            if (p.id == id) return &p;
        return nullptr;
    }
};

class Cart {
public:
    vector<Product> items;
    vector<int> qty;

    void add(Product* p, int q) {
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i].id == p->id) { qty[i] += q; return; }
        }
        items.push_back(*p);
        qty.push_back(q);
    }

    double subtotal() {
        double s = 0.0;
        for (size_t i = 0; i < items.size(); i++)
            s += items[i].price * qty[i];
        return s;
    }
};

class Checkout {
public:
    Cart cart;
    double taxRate = 0.07;

    double discount(double subtotal) {
        if (subtotal > 10.0) return subtotal * 0.9;
        return subtotal;
    }

    void printReceipt() {
        cout << "---- Receipt ----\n";
        for (size_t i = 0; i < cart.items.size(); i++) {
            cout << cart.items[i].name << " x" << cart.qty[i]
                 << " @ " << cart.items[i].price
                 << " = " << (cart.items[i].price * cart.qty[i]) << "\n";
        }
        double subtotal = cart.subtotal();
        double afterDiscount = discount(subtotal);
        double tax = afterDiscount * taxRate;
        double total = afterDiscount + tax;
        cout << "Subtotal: " << subtotal << "\n";
        cout << "Discounted: " << afterDiscount << "\n";
        cout << "Tax: " << tax << "\n";
        cout << "Total: " << total << "\n";
    }
};

int main() {
    Catalog catalog;
    catalog.load();

    Checkout checkout;
    checkout.cart.add(catalog.find(1), 4);
    checkout.cart.add(catalog.find(2), 1);
    checkout.cart.add(catalog.find(4), 3);
    checkout.printReceipt();

    return 0;
}
