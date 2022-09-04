#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        arr[i] = i;
    }
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j = j + i)
        {
            if (j % i == 0)
                arr[j] = i;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == i)
            cout << arr[i] << " ";
    }

    return 0;
}