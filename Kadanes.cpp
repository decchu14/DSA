#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll max_sum = INT_MIN;
    ll current_sum = 0;
    for (ll i = 0; i < n; i++)
    {
        current_sum += arr[i];
        max_sum = max(max_sum, current_sum);
        if (current_sum < 0)
            current_sum = 0;
    }
    cout << max_sum << endl;
    return 0;
}