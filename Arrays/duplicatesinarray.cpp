class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> vect1;

        for (int i = 0; i < nums.size(); i++)
        {
            int count = 1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    count++;
                }
            }
            if (count == 2)
            {
                vect1.push_back(nums[i]);
            }
        }
        return vect1;
    }
};