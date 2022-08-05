#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i < n; i++)
    {
        nums1.push_back(0);
    }

    int n1_p = m - 1;
    int n2_p = n - 1;
    int insrt = m + n - 1;

    while (n2_p >= 0 && n1_p >= 0)
    {
        if ((nums1[n1_p] > nums2[n2_p]))
            nums1[insrt--] = nums1[n1_p--];
        else
            nums1[insrt--] = nums2[n2_p--];
    }

    while (n2_p >= 0)
        nums1[insrt--] = nums2[n2_p--];
    while (n1_p >= 0)
        nums1[insrt--] = nums1[n1_p--];

    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int m, n, ele;
        cin >> m >> n;

        vector<int> nums1;

        for (int i = 0; i < m; i++)
        {
            cin >> ele;
            nums1.push_back(ele);
        }

        vector<int> nums2;

        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            nums2.push_back(ele);
        }

        merge(nums1, m, nums2, n);
    }
    return 0;
}