#include <bits/stdc++.h>
using namespace std;
#define ll long long

void bubbleSort(vector<int> &arr, int n)
{
    // Write your code here.
    int temp;
    bool swapped = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr;
        int ele;
        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            arr.push_back(ele);
        }

        bubbleSort(arr, n);
    }

    return 0;
}