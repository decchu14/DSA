#include <bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int n, int m)
{
    int mx = max(n, m);
    int mn = min(n, m);

    if (mn == 0)
        return mx;

    return gcd(mn, mx % mn);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int ans = gcd(n, m);
    cout << ans;

    return 0;
}