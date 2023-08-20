// id = 123
// psaa = 321

#include <iostream>
using namespace std;

class Item {
public:
    int itemNumber;
    char itemName[50];
    int quantity;
    double price;
    double discountPercentage;
    double discountedPrice;
    double finalPrice;

    void calculateDiscountedPrice() {
        discountedPrice =(((price * quantity) * discountPercentage) / 100);
    }

    void calculateFinalPrice()
	{
        finalPrice = (price * quantity) - discountedPrice;
    }
};

int main() 
{
    int userId, password , i;
    
    cout << endl << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl ;
    cout << "              Supermarket Billing System" << endl ;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl ;
    
    cout << endl << "Enter User ID: ";
    cin >> userId;
    cout << "Enter Password: ";
    cin >> password;

    if (userId != 123 || password != 321) {
        cout << "Invalid User ID or Password. Exiting...";
        return 0;
    }

    int itemCount;
    cout << endl << endl << "Enter the number of items: ";
    cin >> itemCount;

    Item items[itemCount];

    for (i = 0; i < itemCount; ++i) {
        cout << endl << "Enter details for Item " << i + 1 << ":" << endl;
        cout << "Item Number: ";
        cin >> items[i].itemNumber;
        cout << "Item Name: ";
        cin.ignore();
        cin.getline(items[i].itemName, 50);
        cout << "Quantity: ";
        cin >> items[i].quantity;
        cout << "Price: ";
        cin >> items[i].price;
        cout << "Discount Percentage: ";
        cin >> items[i].discountPercentage;

        items[i].calculateDiscountedPrice();
        items[i].calculateFinalPrice();
    }

    
    cout << endl << "Final Bill :-" << endl ;
    cout << "---------------------------------------------------------------------------------------------------------" << endl ;
    cout << "Item No." << "    Item Name" << "        Quantity"
         << "     Price" << "       Discount (%)" << "    Discounted Price" << "    Final Price\n";
    cout << "---------------------------------------------------------------------------------------------------------" << endl ;

    for (i = 0; i < itemCount; ++i) {
        cout << items[i].itemNumber << "            " << items[i].itemName << "                " << items[i].quantity
             << "           " << items[i].price << "            " << items[i].discountPercentage << "                " << items[i].discountedPrice
             << "                 " << items[i].finalPrice << endl;
    }

    cout << "----------------------------------------------------------------------------------------------------------" << endl ;

    return 0;
}
