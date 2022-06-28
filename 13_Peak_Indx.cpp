#include <bits/stdc++.h>
using namespace std;
#define ll long long

int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int mid;

    mid = low + (high - low) / 2;
    while (low < high)
    {

        if (arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }

        mid = low + (high - low) / 2;
    }
    return mid;
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

    int ans = peakIndexInMountainArray(arr);

    cout << ans << endl;
    return 0;
}