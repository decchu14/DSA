#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(vector<int> time, int n, int m, ll mid)
{
    int count = 1;
    int chapSum = 0;

    for (int i = 0; i < m; i++)
    {
        if (chapSum + time[i] <= mid)
        {
            chapSum = chapSum + time[i];
        }
        else
        {
            count++;
            if (count > n || time[i] > mid)
                return false;

            chapSum = time[i];
        }
    }
    return true;
}

ll ayushGivesNinjatest(int n, int m, vector<int> time)
{
    ll ans = -1;

    ll sum = 0;

    for (int i = 0; i < m; i++)
    {
        sum = sum + time[i];
    }
    ll start = 0;
    ll end = sum;
    ll mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (isPossible(time, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;

        mid = start + (end - start) / 2;
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
        int n, m;
        cin >> n >> m;

        vector<int> m_arr;
        int ele;
        for (int i = 0; i < m; i++)
        {

            cin >> ele;
            m_arr.push_back(ele);
        }
        cout << "hello";
        cout << ayushGivesNinjatest(n, m, m_arr) << endl;
    }
    cout << "hello";
    return 0;
}