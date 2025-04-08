// exercise: consecutiveOnes

bool consecutiveOnes(vector<int> &nums)
{
    bool end = false;
    bool found = false;
    if (nums.empty())
    {
        return true;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            if (end)
            {
                return false;
            }
            found = true;
        }
        else if (found)
        {
            end = true;
        }
    }
    return true;
}