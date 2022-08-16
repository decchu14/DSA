#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (nums[i] > nums[(i + 1) % n])
            count++;
        if (count == 2)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ele;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }

    if (check(nums))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}