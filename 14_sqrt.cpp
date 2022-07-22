#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long int binarysearch(int n)
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

int mySqrt(int x)
{
    return binarysearch(x);
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
        cout << mySqrt(n) << endl;
    }

    return 0;
}