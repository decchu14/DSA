#include <bits/stdc++.h>
using namespace std;
#define ll long long

void selectionSort(vector<int> &arr, int n)
{

    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        int mindx = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[mindx])
            {
                mindx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[mindx];
        arr[mindx] = temp;
    }
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

        vector<int> arr;
        int ele;
        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            arr.push_back(ele);
        }

        selectionSort(arr, n);
    }

    return 0;
}