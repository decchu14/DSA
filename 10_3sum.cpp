// -200 12 208
// -84 13 91
// -12 14 18
// 4 6 10
// -33 0 53
// -12 12 20
// 0 8 12
// -187 17 190
// -70 9 81
// 4 7 9
// 4 8 8
// -137 11 146
// -98 14 104
// -62 11 71
// 1 5 14
// -78 12 86
// -140 10 110
// -200 15 165
// -200 18 162
// -200 15 165
// -200 18 162
// -60 12 28

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> findTriplets(vector<int> arr, int n, int k)
{
    set<vector<int>> res;
    vector<vector<int>> vec;
    if (n == 1 || n == 2)
        return vec;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int x, y;
        x = i + 1;
        y = n - 1;
        while (x < y)
        {
            int sum = arr[i] + arr[x] + arr[y];

            if (sum == k)
            {
                vector<int> ans;
                ans.push_back(arr[i]);
                ans.push_back(arr[x]);
                ans.push_back(arr[y]);
                res.insert(ans);
                x++;
                y--;
            }
            else if (sum < k)
                x++;
            else
                y--;
        }
    }

    // for (int i = 0; i < res.size(); i++)
    // {
    //     vect.push_back(res[i]);
    // }

    vector<vector<int>> vect{res.begin(), res.end()};

    return vect;
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

        int k;
        cin >> k;
        vector<vector<int>> res;

        res = findTriplets(arr, n, k);
        if (res.size() > 0)
        {
            for (int i = 0; i < res.size(); i++)
            {
                for (auto it = res[i].begin(); it != res[i].end(); it++)
                    cout << *it << " ";
                cout << endl;
            }
        }
        else
            cout << -1 << endl;
    }

    return 0;
}