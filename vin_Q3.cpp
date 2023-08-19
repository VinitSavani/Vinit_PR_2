#include <iostream>
#include <cstdlib>
using namespace std;

class Person {
public:
    string name;
    long accountNumber;
    string phoneNumber;
    string email;
};

class Bank {
private:
    Person loggedInUser;
    double accountBalance = 200000;
public:
    void clearScreen() {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }

    void displayIntroScreen() {
        clearScreen();
        cout << "**********************************************" << endl;
        cout << "*        Welcome to the Bank System          *" << endl;
        cout << "*           Press any key to continue        *" << endl;
        cout << "**********************************************" << endl;
        cin.get();
        cin.ignore();
    }

    char displayLoginScreen() {
        clearScreen();
        cout << "**********************************************" << endl;
        cout << "*         Login as Admin or Staff            *" << endl;
        cout << "**********************************************" << endl;
        cout << "*    A. Login as Admin                       *" << endl;
        cout << "*    S. Login as Staff                       *" << endl;
        cout << "**********************************************" << endl;
        char choice;
        cin >> choice;
        return choice;
    }

    void displayAdminLoginScreen() {
        clearScreen();
        cout << "**********************************************" << endl;
        cout << "*         Admin Login                        *" << endl;
        cout << "**********************************************" << endl;
    }

    void displayStaffLoginScreen() {
        clearScreen();
        cout << "**********************************************" << endl;
        cout << "*         Staff Login                        *" << endl;
        cout << "**********************************************" << endl;
    }

    void loginAsStaff() {
        displayStaffLoginScreen();
        cout << "Enter name: ";
        cin >> loggedInUser.name;
        cout << "Enter account number: ";
        cin >> loggedInUser.accountNumber;
        cout << "Enter phone number: ";
        cin >> loggedInUser.phoneNumber;
        cout << "Enter email: ";
        cin >> loggedInUser.email;
    }

    void loginAsAdmin() {
        displayAdminLoginScreen();
        cout << "Enter name: ";
        cin >> loggedInUser.name;
        cout << "Enter account number: ";
        cin >> loggedInUser.accountNumber;
        cout << "Enter phone number: ";
        cin >> loggedInUser.phoneNumber;
        cout << "Enter email: ";
        cin >> loggedInUser.email;
    }

    void displayUserInfo() {
        cout << "Name: " << loggedInUser.name << endl;
        cout << "Account Number: " << loggedInUser.accountNumber << endl;
        cout << "Phone Number: " << loggedInUser.phoneNumber << endl;
        cout << "Email: " << loggedInUser.email << endl;
    }

    void displayOptions() {
        clearScreen();
        cout << "**********************************************" << endl;
        cout << "*                 Options                    *" << endl;
        cout << "**********************************************" << endl;
        cout << "*    1. Deposit Money                        *" << endl;
        cout << "*    2. Transfer Money                       *" << endl;
        cout << "*    3. Withdraw Money                       *" << endl;
        cout << "*    0. Exit                                 *" << endl;
        cout << "**********************************************" << endl;
        cout << "Current Balance: " << accountBalance << endl;
    }

    void performDeposit() {
        clearScreen();
        cout << "**********************************************" << endl;
        cout << "*            Deposit Money                   *" << endl;
        cout << "**********************************************" << endl;
        cout << "Current Balance: " << accountBalance << endl;
        cout << "Enter the amount to deposit: ";
        double amount;
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount." << endl;
        } else {
            accountBalance += amount;
            cout << "Deposit successful. Current balance: " << accountBalance << endl;
        }
    }

    void performTransfer() {
        clearScreen();
        cout << "**********************************************" << endl;
        cout << "*           Transfer Money                   *" << endl;
        cout << "**********************************************" << endl;
        cout << "Current Balance: " << accountBalance << endl;
        cout << "Enter the amount to transfer: ";
        double amount;
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount." << endl;
        } else if (amount > accountBalance) {
            cout << "Insufficient funds." << endl;
        } else {
            accountBalance -= amount;
            cout << "Transfer successful. Current balance: " << accountBalance << endl;
        }
    }

    void performWithdraw() {
        clearScreen();
        cout << "**********************************************" << endl;
        cout << "*           Withdraw Money                   *" << endl;
        cout << "**********************************************" << endl;
        cout << "Current Balance: " << accountBalance << endl;
        cout << "Enter the amount to withdraw: ";
        double amount;
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount." << endl;
        } else if (amount > accountBalance) {
            cout << "Insufficient funds." << endl;
        } else {
            accountBalance -= amount;
            cout << "Withdrawal successful. Current balance: " << accountBalance << endl;
        }
    }
};

int main() {
    Bank bank;

    bank.displayIntroScreen();
    
    char loginChoice;
    while (true) {
        bank.clearScreen();
        loginChoice = bank.displayLoginScreen();
        if (loginChoice == 'S' || loginChoice == 's') {
            bank.displayStaffLoginScreen();
            bank.loginAsStaff();
            break;
        } else if (loginChoice == 'A' || loginChoice == 'a') {
            bank.displayAdminLoginScreen();
            bank.loginAsAdmin();
            break;
        }
    }

    bank.clearScreen();
    
    cout << "User Information:" << endl;
    bank.displayUserInfo();

    while (true) {
        bank.clearScreen();
        bank.displayOptions();
        
        int option;
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                bank.performDeposit();
                break;
            case 2:
                bank.performTransfer();
                break;
            case 3:
                bank.performWithdraw();
                break;
            case 0:
                cout << "Exiting the Bank System." << endl;
                return 0;
            default:
                cout << "Invalid option." << endl;
        }

        cout << "Press any key to continue...";
        cin.get();
        cin.ignore();
    }

    return 0;
}
