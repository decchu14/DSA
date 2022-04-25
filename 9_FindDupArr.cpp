#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();
    vector<int> empty(n + 1, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (empty[nums[i]] == 1)
            ans.push_back(nums[i]);
        else
            empty[nums[i]] = 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }

    vector<int> ans;
    ans = findDuplicates(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}