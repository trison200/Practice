bool isPalindromeHelper(const string &str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    if (!isalnum(str[start]))
    {
        return isPalindromeHelper(str, start + 1, end);
    }
    if (!isalnum(str[end]))
    {
        return isPalindromeHelper(str, start, end - 1);
    }
    if (tolower(str[start]) != tolower(str[end]))
    {
        return false;
    }
    return isPalindromeHelper(str, start + 1, end - 1);
}

bool isPalindrome(string str)
{
    return isPalindromeHelper(str, 0, str.length() - 1);
}

int findGCD(int a, int b)
{
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}
