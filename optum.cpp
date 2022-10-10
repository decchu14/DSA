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

    int ans[n];
    ans[0] = 0;
    int ans_i = 1;

    for (int i = 1; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
                count++;
        }
        ans[ans_i] = count;
        ans_i++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}