#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sqrt_int(int n)
{
    int low = 0, high = n;
    long long int mid = low + (high - low) / 2, result = -1;

    while (low <= high)
    {
        long long int square = mid * mid;

        if (square == n)
            return mid;

        if (square < n)
        {
            result = mid;
            low = mid + 1;
        }

        else
            high = mid - 1;

        mid = low + (high - low) / 2;
    }
    return result;
}

double sqrt_float(int n, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = tempSol; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // cout << "Enter the number" << endl;
    cin >> n;

    int tempSol = sqrt_int(n);
    cout << sqrt_float(n, 3, tempSol) << endl;

    return 0;
}