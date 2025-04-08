string repeatString(const string &str, int count)
{
    if (count <= 0)
        return "";
    if (count == 1)
        return str;
    return str + repeatString(str, count - 1);
}

string expand(string s, string::size_type &index)
{
    if (index >= s.length())
        return "";

    if (isdigit(s[index]))
    {
        int count = s[index] - '0';
        index++;
        if (s[index] == '(')
        {
            index++;
            string subResult = expand(s, index);
            return repeatString(subResult, count) + expand(s, index);
        }
    }
    else if (s[index] == ')')
    {
        index++;
        return "";
    }
    else
    {
        char c = s[index];
        index++;
        return string(1, c) + expand(s, index);
    }

    return "";
}

string expand(string s)
{
    string::size_type index = 0;
    return expand(s, index);
}
