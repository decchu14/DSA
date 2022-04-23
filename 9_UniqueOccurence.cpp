#include <bits/stdc++.h>
using namespace std;

bool occurence(int arr[], int n)
{
    vector<int> emptyarr(101, 0);
    int occ = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            occ++;
        }
        else
        {
            if (emptyarr[occ] == 0)
            {
                emptyarr[occ] = 1;
                occ = 1;
            }
            else
                return false;
        }
    }
    if (emptyarr[occ] == 1)
        return false;
    return true;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    if (occurence(arr, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}