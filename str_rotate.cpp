bool areRotations(string s1, string s2)
{
    // Your code here
    int s1_len = s1.length();
    int s2_len = s2.length();
    string temp = s1 + s1;
    int p = temp.find(s2);
    if (s1_len == s2_len)
    {
        if (p != -1)
            return true;
    }
    return false;
}