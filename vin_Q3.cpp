#include <iostream>
#include <cstdlib>
using namespace std;

class Person 
{
public:
    string name;
    long accountNumber;
    string phoneNumber;
    string email;
};

class Bank 
{
private:
    Person loggedInUser;
    double accountBalance = 200000;
public:
    void clearScreen() 
	{
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }

    void displayIntroScreen() 
	{
        clearScreen();
        cout << endl << endl << endl ;
        cout << "                         -: BANK MANAGEMENT SYSTEM :-               " << endl;
        cout << "          ----------------------------------------------------------" << endl << endl ;
        cout << "                         -: Design & Programed By :-               " << endl;
        cout << "          ----------------------------------------------------------" << endl ;
        cout << "                               VINIT S SAVANI                     " << endl << endl << endl ;
        cout << "          ----------------------------------------------------------" << endl;
        cout << "                     Press Any key N Enter To Continue.........." << endl;
        cin.get();
    }

    char displayLoginScreen() 
	{
        clearScreen();
        cout << endl << endl << endl ;
        cout << "          **********************************************" << endl;
        cout << "          *               Welcome TO SBI               *" << endl;
        cout << "          **********************************************" << endl << endl << endl;
        cout << "          **********************************************" << endl;
        cout << "          *        Press A To Login as Admin           *" << endl;
        cout << "          *        Press S To Login as Staff           *" << endl;
        cout << "          **********************************************" << endl;
        
        char choice;
        
        cin >> choice;
        return choice;
    }

    void displayAdminLoginScreen() 
	{
        clearScreen();
        cout << "          **********************************************" << endl;
        cout << "          *               Admin Login                  *" << endl;
        cout << "          **********************************************" << endl;
    }

    void displayStaffLoginScreen() 
	{
        clearScreen();
        cout << "          **********************************************" << endl;
        cout << "          *              Staff Login                   *" << endl;
        cout << "          **********************************************" << endl;
    }

    void loginAsStaff() 
	{
        displayStaffLoginScreen();
        cout << "          Enter name: ";
        cin >> loggedInUser.name;
        cout << "          Enter account number: ";
        cin >> loggedInUser.accountNumber;
        cout << "          Enter phone number: ";
        cin >> loggedInUser.phoneNumber;
        cout << "          Enter email: ";
        cin >> loggedInUser.email;
    }

    void loginAsAdmin() 
	{
        displayAdminLoginScreen();
        cout << "          Enter name: ";
        cin >> loggedInUser.name;
        cout << "          Enter account number: ";
        cin >> loggedInUser.accountNumber;
        cout << "          Enter phone number: ";
        cin >> loggedInUser.phoneNumber;
        cout << "          Enter email: ";
        cin >> loggedInUser.email;
    }

    void displayUserInfo() 
	{
        cout << endl << "          Name: " << this->loggedInUser.name << endl;
        cout << "          Account Number: " << this->loggedInUser.accountNumber << endl;
        cout << "          Phone Number: " << this->loggedInUser.phoneNumber << endl;
        cout << "          Email: " << this->loggedInUser.email << endl << endl << endl ;
    }

    void displayOptions() 
	{
        cout << "          **********************************************" << endl;
        cout << "          *                 Options                    *" << endl;
        cout << "          **********************************************" << endl;
        cout << "          *    1. Deposit Money                        *" << endl;
        cout << "          *    2. Transfer Money                       *" << endl;
        cout << "          *    3. Withdraw Money                       *" << endl;
        cout << "          *    0. Exit                                 *" << endl;
        cout << "          **********************************************" << endl << endl ;
        cout << "               Current Balance: " << accountBalance << endl;
    }

    void performDeposit() 
	{
        clearScreen();
        cout << endl << endl << endl ;
        cout << "          **********************************************" << endl;
        cout << "          *            Deposit Money                   *" << endl;
        cout << "          **********************************************" << endl << endl ;
        cout << "          Current Balance: " << accountBalance << endl;
        cout << endl << "          Enter the amount to deposit: ";
        double amount;
        cin >> amount;
        if (amount <= 0) 
		{
            cout << "          Invalid amount." << endl;
        } else 
		{
            accountBalance += amount;
            cout << endl << "          Deposit successful.  " << endl << endl ;
            cout << "          Current balance: " << accountBalance << endl << endl;
        }
    }

    void performTransfer() {
        clearScreen();
        cout << endl << endl << endl ;
        cout << "          **********************************************" << endl;
        cout << "          *           Transfer Money                   *" << endl;
        cout << "          **********************************************" << endl << endl ;
        cout << "          Current Balance: " << accountBalance << endl;
        cout << "          Enter the amount to transfer: ";
        double amount;
        cin >> amount;
        if (amount <= 0)
		{
            cout << "          Invalid amount." << endl;
        } else if (amount > accountBalance) 
		{
            cout << "          Insufficient funds." << endl;
        } else 
		{
            accountBalance -= amount;
            cout << endl << "          Transfer successful." << endl << endl;
            cout << "          Current balance: " << accountBalance << endl << endl;
        }
    }

    void performWithdraw() 
	{
        clearScreen();
        cout << endl << endl << endl ;
        cout << "          **********************************************" << endl;
        cout << "          *           Withdraw Money                   *" << endl;
        cout << "          **********************************************" << endl << endl ;
        cout << "          Current Balance: " << accountBalance << endl;
        cout << "          Enter the amount to withdraw: ";
        double amount;
        cin >> amount;
        if (amount <= 0) 
		{
            cout << "          Invalid amount." << endl;
        } else if (amount > accountBalance) 
		{
            cout << "          Insufficient funds." << endl;
        } else 
		{
            accountBalance -= amount;
            cout << endl << "          Withdrawal successful."<< endl << endl;
            cout << "          Current balance: " << accountBalance << endl << endl;
        }
    }
};

int main() 
{
    Bank bank;

    bank.displayIntroScreen();
    
    char loginChoice;
    
    while (true) 
	{
        bank.clearScreen();
        loginChoice = bank.displayLoginScreen();
        if (loginChoice == 'S' || loginChoice == 's') 
		{
            bank.displayStaffLoginScreen();
            bank.loginAsStaff();
            break;
        } else if (loginChoice == 'A' || loginChoice == 'a') 
		{
            bank.displayAdminLoginScreen();
            bank.loginAsAdmin();
            break;
        }
    }

    while (true) 
	{
        bank.clearScreen();
        cout << endl << endl << "          User Information:" << endl;
        bank.displayUserInfo();
        bank.displayOptions();
        
        int option;
        cout << endl << endl << "                Select an option: ";
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
                cout << "          Exiting the Bank System." << endl;
                return 0;
            default:
                cout << "          Invalid option." << endl;
        }

        cout << "          Press any key to continue......";
        cin.get();
        cin.ignore();
    }

    return 0;
}
