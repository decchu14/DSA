string restoreString(string s, vector<int> &indices)
{
    string ans;
    int n = s.length();
    string str[n];
    for (int i = 0; i < n; i++)
    {
        str[indices[i]] = s[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans = ans + str[i];
    }

    return ans;
}