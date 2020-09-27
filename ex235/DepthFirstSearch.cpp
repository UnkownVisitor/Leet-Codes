#include <bits/stdc++.h>

using std::find;
using std::swap;
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
    vector<TreeNode *> m, n, path;
    int flag;
    void dfs(TreeNode *current, TreeNode *p, TreeNode *q)
    {
        if (current == NULL || flag == 2)
            return;
        path.push_back(current);
        if (current == p)
        {
            m = path;
            flag++;
        }
        if (current == q)
        {
            n = path;
            flag++;
        }
        dfs(current->left, p, q);
        dfs(current->right, p, q);
        path.pop_back();
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = NULL;
        vector<TreeNode *>::reverse_iterator tmp;

        flag = 0;

        dfs(root, p, q);

        for (vector<TreeNode *>::reverse_iterator iter = m.rbegin(); iter != m.rend(); iter++)
        {
            tmp = find(n.rbegin(), n.rend(), *iter);
            if (tmp != n.rend())
            {
                ans = *tmp;
                break;
            }
        }

        return ans;
    }
};
