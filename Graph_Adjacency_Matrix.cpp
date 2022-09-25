#include <iostream>
using namespace std;

int main()
{
    int n, m, src, dest;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    cout << "1. Directed Graph" << endl;
    cout << "2. Undirected Graph" << endl;
    cout << "3. Exit" << endl;
    int ch;

    while (1)
    {
        cout << "Enter your choice : ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter the total edges : ";
            cin >> m;
            for (int i = 0; i < m; i++)
            {
                cin >> src >> dest;
                arr[src - 1][dest - 1] = 1;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if (ch == 2)
        {
            cout << "Enter the total edges : ";
            cin >> m;
            for (int i = 0; i < m; i++)
            {
                cin >> src >> dest;
                arr[src - 1][dest - 1] = 1;
                arr[dest - 1][src - 1] = 1;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if (ch == 3)
        {
            break;
        }
        else
            cout << "Invalid Option, Try Again" << endl;
    }
    return 0;
}