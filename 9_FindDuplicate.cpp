#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int arr[n];
    int arr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr_sum = arr_sum + arr[i];
    }

    int m = n - 1;
    int nsum = (m * (m + 1)) / 2;

    cout << arr_sum - nsum << endl;

    return 0;
}