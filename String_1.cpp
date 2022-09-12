int f(int arr[], int low, int high, int n, int x)
{

    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return f(arr, (mid + 1), high, n, x);
        else

            return f(arr, low, (mid - 1), n, x);
    }
    return -1;
}

int l(int arr[], int low, int high, int n, int x)
{

    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return l(arr, low, mid - 1, n, x);
        else
            return l(arr, mid + 1, high, n, x);
    }
    return -1;
}
vector<int> find(int arr[], int n, int x)
{
    // code here
    vector<int> ans;
    int first = f(arr, 0, n - 1, n, x);
    int last = l(arr, 0, n - 1, n, x);
    ans.push_back(first);
    ans.push_back(last);

    return ans;
}