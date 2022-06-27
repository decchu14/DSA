#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sort012(int *arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    int temp;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            temp = arr[high];
            arr[high] = arr[mid];
            arr[mid] = temp;
            high--;
        }
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
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort012(arr, n);
    }
    return 0;
}