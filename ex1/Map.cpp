#include <map>
#include <vector>

using std::map;
using std::pair;
using std::vector;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        map<int, int> table;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); i++)
        {
            iter = table.find(target - nums.at(i));
            if (iter == table.end())
            {
                table.insert(pair<int, int>(nums.at(i), i));
            }
            else
            {
                ans.push_back(iter->second);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};