#include <algorithm>
#include <unordered_map>
#include <vector>

using std::max;
using std::pair;
using std::unordered_map;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    int count;
    unordered_map<int, int> map;
    unordered_map<int, int>::iterator iter;
    void dfs(TreeNode *Node)
    {
        if (!Node)
        {
            return;
        }
        dfs(Node->left);
        iter = map.find(Node->val);
        if (iter == map.end())
        {
            map.insert(pair<int, int>(Node->val, 1));
            count = max(count, 1);
        }
        else
        {
            iter->second++;
            count = max(count, iter->second);
        }
        dfs(Node->right);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> ans;
        dfs(root);
        for (iter = map.begin(); iter != map.end(); iter++)
        {
            if (iter->second == count)
            {
                ans.push_back(iter->first);
            }
        }
        return ans;
    }
};