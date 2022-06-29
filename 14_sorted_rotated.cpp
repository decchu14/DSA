#include <bits/stdc++.h>
using namespace std;
#define ll long long

int getPivot(vector<int> arr, int n)
{
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;

    while (low < high)
    {
        if (arr[mid] >= arr[0])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }

        mid = low + (high - low) / 2;
    }
    return low;
}

int binarySearch(vector<int> arr, int low, int high, int k)
{
    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (k == arr[mid])
            return mid;

        if (k > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        mid = low + (high - low) / 2;
    }
    return -1;
}

int findPosition(vector<int> &arr, int n, int k)
{
    int pivot = getPivot(arr, n);

    if (k >= arr[pivot] && k <= arr[n - 1])
    {
        // binary search on second line
        return binarySearch(arr, pivot, n - 1, k);
    }
    else
    {
        // binary search on first line
        return binarySearch(arr, 0, pivot - 1, k);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr;
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }

    int k;
    cin >> k;

    int ans = findPosition(arr, n, k);

    cout << ans << endl;

    return 0;
}