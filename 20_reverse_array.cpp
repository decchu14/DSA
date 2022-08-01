#include <bits/stdc++.h>
using namespace std;
#define ll long long

void reverseArray(vector<int> &arr, int n, int m)
{
    // Write your code here.
    int start = m + 1;
    int end = n - 1;

    int temp;

    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
        int n, m;
        cin >> n >> m;

        vector<int> arr;
        int ele;
        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            arr.push_back(ele);
        }

        reverseArray(arr, n, m);
    }
    return 0;
}