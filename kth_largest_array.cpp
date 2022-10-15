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

    int k;
    cin >> k;

    priority_queue<int, vector<int>, greater<int>> minh;

    for (auto i : arr)
    {
        minh.push(i);
        if (minh.size() > k)
            minh.pop();
    }

    while (minh.size() > 0)
    {
        cout << minh.top() << endl;
        minh.pop();
    }
    return 0;
}