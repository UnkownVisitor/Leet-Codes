#include <vector>

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
private:
    vector<int> ans;
    void dfs(TreeNode *node)
    {
        if (node == NULL)
            return;
        dfs(node->left);
        dfs(node->right);
        ans.emplace_back(node->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};