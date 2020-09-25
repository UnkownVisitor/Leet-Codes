#include <algorithm>
#include <vector>

using std::distance;
using std::find;
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
public:
    TreeNode *buildTree(vector<int> inorder, vector<int> postorder)
    {
        if (inorder.empty())
            return NULL;
        TreeNode *Node = new TreeNode(postorder.back());
        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), Node->val);
        Node->left = buildTree(
            vector<int>(inorder.begin(), iter),
            vector<int>(postorder.begin(), postorder.begin() + distance(inorder.begin(), iter)));
        Node->right = buildTree(
            vector<int>(iter + 1, inorder.end()),
            vector<int>(postorder.begin() + distance(inorder.begin(), iter), postorder.end() - 1));
        return Node;
    }
};