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

    priority_queue<int> maxh;

    for (auto i : arr)
    {
        maxh.push(i);
        if (maxh.size() > k)
            maxh.pop();
    }

    cout << maxh.top() << endl;

    return 0;
}