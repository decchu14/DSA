#include <bits/stdc++.h>
using namespace std;
#define ll long long

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int temp, j = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0 && nums[j] == 0)
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
        else if (nums[j] > 0)
            j++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
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
        int n, ele;
        cin >> n;

        vector<int> nums;

        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            nums.push_back(ele);
        }

        moveZeroes(nums);
    }
    return 0;
}