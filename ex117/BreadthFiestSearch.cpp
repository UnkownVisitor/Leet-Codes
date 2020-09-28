#include <vector>

using std::vector;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        vector<Node *> queue = {root, nullptr};
        int i = 0;

        while ((i != queue.size() - 1) && (queue.at(i) || queue.at(i + 1)))
        {
            if (queue.at(i) == nullptr)
            {
                queue.emplace_back(nullptr);
            }
            else
            {
                queue.at(i)->next = queue.at(i + 1);
                if (queue.at(i)->left)
                    queue.emplace_back(queue.at(i)->left);
                if (queue.at(i)->right)
                    queue.emplace_back(queue.at(i)->right);
            }
            i++;
        }

        return root;
    }
};
