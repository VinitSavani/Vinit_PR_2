#include <iostream>
using namespace std;

class Train 
{
public:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;

    void inputTrainDetails() 
	{
        cout << endl << "Enter Train Number: ";
        cin >> trainNumber;
        cout << "Enter Train Name: ";
        cin >> trainName;
        cout << "Enter Source: ";
        cin >> source;
        cout << "Enter Destination: ";
        cin >> destination;
        cout << "Enter Train Time: ";
        cin >> trainTime;
        cout << endl ;
    }

    void displayTrainDetails() 
	{
        cout << endl << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
        cout << "-----------------------------------------" << endl ;
    }

    int searchTrain(int searchNumber) {
        return (trainNumber == searchNumber) ? 1 : 0;
    }
};

int main() 
{
    int N,i;
    
    cout << endl << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/" << endl;
    cout << "Train Record input and serch program " << endl ;
    cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/" << endl;
    
    cout << endl << "Enter the number of train records: ";
    cin >> N;

    if (N < 3) {
        cout << "Minimum 3 train records are required." << endl;
        return 0;
    }

    Train trains[N];

    for (i = 0; i < N; ++i) {
        cout << "Enter details for Train " << i + 1 << ":" << endl;
        trains[i].inputTrainDetails();
    }

    int searchNumber;
    cout << "Enter Train Number to search: ";
    cin >> searchNumber;

    int foundIndex = -1;
    for (i = 0; i < N; ++i) {
        if (trains[i].searchTrain(searchNumber)) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) 
    {
        cout << "Train details for Train Number " << searchNumber << ":" << endl;
        trains[foundIndex].displayTrainDetails();
    } else 
    {
        cout << "Train with Train Number " << searchNumber << " not found." << endl;
    }

    return 0;
}
