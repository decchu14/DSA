#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ele;
        cin >> n >> m;
        vector<int> arr1;
        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            arr1.push_back(ele);
        }

        vector<int> arr2;
        for (int i = 0; i < m; i++)
        {
            cin >> ele;
            arr2.push_back(ele);
        }

        vector<int> ans = findArrayIntersection(arr1, n, arr2, m);

        if (ans.size() > 0)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}