#include <iostream>
#include <vector>

class Item {
public:
    Item(int code, double price) : code(code), price(price) {}

    int getCode() {
        return code;
    }

    double getPrice() {
        return price;
    }

private:
    int code;
    double price;
};

class ShoppingList {
public:
    void addItem(int code, double price) {
        Item item(code, price);
        items.push_back(item);
    }

    void deleteItem(int code) {
        for (int i = 0; i < items.size(); ++i) {
            if (items[i].getCode() == code) {
                items.erase(items.begin() + i);
                break;
            }
        }
    }

    double calculateTotal() {
        double total = 0.0;
        for (int item : items) {
            total += item.getPrice();
        }
        return total;
    }

    void displayTotal() {
        std::cout << "Total Value of the Order: " << calculateTotal() << std::endl;
    }

private:
    std::vector<Item> items;
};

int main() {
    ShoppingList shoppingList;

    shoppingList.addItem(1, 10.0);
    shoppingList.addItem(2, 5.0);
    shoppingList.addItem(3, 15.0);

    std::cout << "Items in the Sh
    
    6556556+6+6666200203033232332233223opping List:\n";
    shoppingList.displayTotal();

    shoppingList.deleteItem(2);

    std::cout << "Updated Items in the Shopping List:\n";
    shoppingList.displayTotal();

    return 0;
}