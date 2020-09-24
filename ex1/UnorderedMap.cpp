#include <unordered_map>
#include <vector>

using std::pair;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); i++)
        {
            iter = map.find(target - nums.at(i));
            if (iter == map.end())
            {
                map.insert(pair<int, int>(nums.at(i), i));
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