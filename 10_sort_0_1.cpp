#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int start = 0;
        int end = n - 1;
        int temp = 0;
        while (start < end)
        {
            if (arr[start] > arr[end])
            {
                temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
            else if (arr[start] < arr[end])
            {
                start++;
                end--;
            }
            else if (arr[start] == arr[end])
            {
                if (arr[start] == 0)
                    start++;
                else
                    end--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}