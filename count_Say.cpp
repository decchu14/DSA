class Solution
{
public:
    string lookandsay(int n)
    {
        if (n == 1)
            return "1";
        if (n == 2)
            return "11";

        string str = "11";
        for (int i = 3; i <= n; i++)
        {

            string ans = "";
            str = str + "$";
            int str_ln = str.length();
            int count = 1;
            for (int j = 1; j < str_ln; j++)
            {
                if (str[j - 1] == str[j])
                {
                    count++;
                }
                else
                {
                    string s = to_string(count);
                    ans = ans + s;
                    ans = ans + str[j - 1];
                    count = 1;
                }
            }
            str = ans;
        }
        return str;
    }
};