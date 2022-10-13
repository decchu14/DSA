#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        minh.push({it->second, it->first});
    }

    while (minh.size() > 0)
    {
        for (int i = 0; i < minh.top().first; i++)
        {
            cout << minh.top().second << " ";
        }
        minh.pop();
    }

    return 0;
}