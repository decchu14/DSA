#include <bits/stdc++.h>
using namespace std;
#define ll long long

int fact(int val)
{
    if (val == 0 || val == 1)
        return 1;

    return val * fact(val - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r;
    cin >> n >> r;

    cout << fact(n) / ((fact(n - r)) * fact(r));

    return 0;
}