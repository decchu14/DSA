#include <bits/stdc++.h>
using namespace std;
#define ll long long

void rotate(vector<int> &nums, int k)
{
    vector<int> temp;

    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % nums.size()] = nums[i];
    }
    nums = temp;
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
    int k;
    cin >> k;
    rotate(nums, k);

    return 0;
}