#include <iostream>
using namespace std;

int main()
{
    int amt;
    cout << "enter amount : ";
    cin >> amt;
    int notes = 0;
    int ch = -1;

    while (ch)
    {
        cout << "Enter your choice of note (100 or 50 or 2 or 1) or q to quit: ";
        cin >> ch;

        switch (ch)
        {
        case 100:
            notes = amt / 100;
            cout << notes << endl;
            break;
        case 50:
            notes = amt / 50;
            cout << notes << endl;
            break;
        case 2:
            notes = amt / 2;
            cout << notes << endl;
            break;

        case 1:
            notes = amt / 1;
            cout << notes << endl;
            break;
        case 0:
            break;
        default:
            cout << "Invalid option" << endl;
        }
    }
    return 0;
}
