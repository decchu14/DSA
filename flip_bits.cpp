#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int count = 0;
    while (a > 0 || b > 0)
    {
        if ((a & 1) != (b & 1))
            count++;

        a = a >> 1;
        b = b >> 1;
    }
    cout << count << endl;

    return 0;
}