#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    pair<int, int> ans;

    int low = 0;
    int high = n - 1;
    int mid;
    int first = -1;
    int last = -1;

    // search for first occurence
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (k == arr[mid])
        {
            high = mid - 1;
            first = mid;
        }
        else if (k > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    low = 0;
    high = n - 1;

    // search for last occurence
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (k == arr[mid])
        {
            low = mid + 1;
            last = mid;
        }
        else if (k > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    ans = {first, last};

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr;
        int ele;
        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            arr.push_back(ele);
        }

        pair<int, int> ans = firstAndLastPosition(arr, n, k);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}