class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int max = 0;
        int start = 0;
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (res.find(s[i]) != string::npos)
            {
                i = res.find(s[i]) + start + 1;
                start = i;
                res = "";
            }
            res += s[i];
            if (res.length() > max)
            {
                max = res.length();
            }
        }
        return max;
    }
};