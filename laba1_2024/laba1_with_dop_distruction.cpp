#include <iostream>
using namespace std;

class cashRegister {
private:
    int cashOnHand;

public:
    cashRegister(int cash = 500) : cashOnHand(cash) {}

    int getCurrentBalance() {
        return cashOnHand;
    }

    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int cost;

public:
    dispenserType() {
        numberOfItems = 50;
        cost = 50;
    }

    dispenserType(int items, int price) {
        numberOfItems = items;
        cost = price;
    }

    int getNoOfItems() {
        return numberOfItems;
    }

    int getCost() {
        return cost;
    }

    void makeSale() {
        if (numberOfItems > 0) {
            numberOfItems--;
        }
    }

 /*   ~dispenserType() {
        cout << "The dispenser Type destructor is called. Freeing up memory and deleting variables." << endl;
    }*/
};

/*class giftDispenser { //дать подарок после 5 покупки
public:
    int numberOfPurchases; // количество покупок
    int giftChoice; // выбор подарка

    giftDispenser(int purchases) : numberOfPurchases(purchases), giftChoice(1) {
        // Конструктор класса
    }

    void chooseGift() {
        cout << "Congratulations! You have made " << numberOfPurchases << " purchases. Please choose your gift: " << giftChoice << endl;
        // Метод для отображения выбора подарка на основе количества покупок и выбранного подарка
    }
};*/

void showSelection() {
    cout << "1. Candy" << endl;
    cout << "2. Chips" << endl;
    cout << "3. Gum" << endl;
    cout << "4. Cookies" << endl;
}

void sellProduct(dispenserType& dispenser, cashRegister& reg) {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        if (dispenser.getNoOfItems() > 0) {
            cout << "Price of Candy: $" << dispenser.getCost() << endl;
            cout << "Insert money: ";
            int money;
            cin >> money;

            if (money >= 10) { // Updated cost for gum
                dispenser.makeSale();
                reg.acceptAmount(dispenser.getCost());

                // Calculate and give change
                int change = money - 30; // Updated cost for Candy 

                if (change > 0) {
                    cout << "Please take your change: $" << change << endl;
                }

                cout << "Thank you for your purchase! Enjoy your Candy." << endl;
            }
            else {
                cout << "Insufficient funds. Money refunded." << endl;
            }
        }
        else {
            cout << "Out of Candy. Please make another selection." << endl;
        }
        break;

    case 2:
        if (dispenser.getNoOfItems() > 0) {
            cout << "Price of Chips: $" << dispenser.getCost() << endl;
            cout << "Insert money: ";
            int money;
            cin >> money;

            if (money >= 80) { // Updated cost for chips
                dispenser.makeSale();
                reg.acceptAmount(dispenser.getCost());

                int change = money - 80;
                if (change > 0) {
                    cout << "Please take your change: $" << change << endl;
                }
                cout << "Thank you for your purchase! Enjoy your Chips." << endl;
            }
            else {
                cout << "Insufficient funds. Money refunded." << endl;
            }
        }
        else {
            cout << "Out of Chips. Please make another selection." << endl;
        }
        break;

    case 3:
        if (dispenser.getNoOfItems() > 0) {
            cout << "Price of Gum: $" << dispenser.getCost() << endl;
            cout << "Insert money: ";
            int money;
            cin >> money;

            if (money >= dispenser.getCost()) {
                dispenser.makeSale();
                reg.acceptAmount(dispenser.getCost());

                int change = money - dispenser.getCost();
                if (change > 0) {
                    cout << "Please take your change: $" << change << endl;
                }

                cout << "Thank you for your purchase! Enjoy your Gum." << endl;
            }
            else {
                cout << "Insufficient funds. Money refunded." << endl;
            }
        }
        else {
            cout << "Out of Gum. Please make another selection." << endl;
        }
        break;

    case 4:
        if (dispenser.getNoOfItems() > 0) {
            cout << "Price of Cookies: $" << dispenser.getCost() << endl;
            cout << "Insert money: ";
            int money;
            cin >> money;

            if (money >= dispenser.getCost()) {
                dispenser.makeSale();
                reg.acceptAmount(dispenser.getCost());

                int change = money - dispenser.getCost();
                if (change > 0) {
                    cout << "Please take your change: $" << change << endl;
                }

                cout << "Thank you for your purchase! Enjoy your Cookies." << endl;
            }
            else {
                cout << "Insufficient funds. Money refunded." << endl;
            }
        }
        else {
            cout << "Out of Cookies. Please make another selection." << endl;
        }
        break;

    default:
        cout << "Invalid choice. Please try again." << endl;
    }
}

int main() {
    cashRegister cashRegisterObj; // Renamed the object to cashRegisterObj
    dispenserType candy(50, 30); // Change the price and quantity as needed
    dispenserType Chips(50, 80);
    dispenserType Gum(50, 10);
    dispenserType Cookies(50, 50);

    showSelection();
    sellProduct(candy, cashRegisterObj); // Pass the cashRegisterObj
  

    return 0;
}

/*I didn't change the price for the products. but in general, the solution is ready. added a destructor structure for the class*/