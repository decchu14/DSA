#include <bits/stdc++.h>
using namespace std;
#define ll long long

int fact_sum(int n)
{
    int prod = 1;
    int prod_sum = 0;
    while (n > 0)
    {

        for (int i = n; i > 0; i--)
        {
            prod = prod * i;
        }

        prod_sum = prod_sum + prod;
        prod = 1;
        n--;
    }
    return prod_sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << fact_sum(n) << endl;

    return 0;
}