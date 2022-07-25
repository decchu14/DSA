#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(vector<int> boards, int k, int n, int mid)
{
    int k_count = 1;
    int boardSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (boardSum + boards[i] <= mid)
        {
            boardSum = boardSum + boards[i];
        }
        else
        {
            k_count++;
            if (k_count > k)
                return false;
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int sum = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        sum = sum + boards[i];
    }
    int start = 0;
    int end = sum;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {

        if (isPossible(boards, k, n, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> n_arr;
        int ele;
        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            n_arr.push_back(ele);
        }
        cout << findLargestMinDistance(n_arr, k) << endl;
    }

    return 0;
}