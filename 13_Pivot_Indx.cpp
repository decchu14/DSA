#include <bits/stdc++.h>
using namespace std;
#define ll long long

int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    if (n % 2 == 1)
        return -1;
    int low = 0;
    int high = n - 1;
    int left_sum = 0;
    int right_sum = 0;

    while (low <= high)
    {
        // cout << low << " " << high << " " << left_sum << " " << right_sum << endl;
        if (low == high && left_sum == right_sum)
            return low;
        else if (left_sum <= right_sum)
        {
            left_sum = left_sum + nums[low];
            low++;
        }
        else if (left_sum > right_sum)
        {
            right_sum = right_sum + nums[high];
            high--;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums;
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }

    int ans = pivotIndex(nums);
    cout << ans << endl;

    return 0;
}