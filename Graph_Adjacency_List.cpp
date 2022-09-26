#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int ch, n, m, s, d;
    cout << "1. Directed" << endl;
    cout << "2. Undirected" << endl;
    cout << "Exit" << endl;

    while (1)
    {
        cout << "Enter the Number of Nodes : ";
        cin >> n;
        vector<int> arr[n];
        cout << "Enter your choice : ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter the number of edges : ";
            cin >> m;

            for (int i = 0; i < m; i++)
            {
                cin >> s >> d;
                arr[d].push_back(s);
                arr[s].push_back(d);
            }

            for (int i = 0; i < n; ++i)
            {
                cout << "Adjacency list of Vertex " << i << " ";
                for (auto x : arr[i])
                {
                    cout << "->" << x;
                }
                cout << endl;
            }
        }
        else if (ch == 2)
        {
            cout << "Enter the number of edges";
            cin >> m;
        }
        else if (ch == 3)
        {
            break;
        }
        else
            cout << "Invalid Choice, Try Again" << endl;
    }

    return 0;
}