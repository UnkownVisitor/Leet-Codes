#include <algorithm>
#include <stack>
#include <vector>

using std::reverse;
using std::stack;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> stk;
        TreeNode *node = root;

        while (node || !stk.empty())
        {
            if (node)
            {
                ans.emplace_back(node->val);
                stk.emplace(node);
                node = node->right;
            }
            else
            {
                node = stk.top();
                stk.pop();
                node = node->left;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};