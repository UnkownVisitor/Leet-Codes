#include <stddef.h>

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
private:
    Node *previous, *nextrow;

    void link(Node *node)
    {
        if (nextrow == NULL)
            nextrow = node;
        if (previous)
            previous->next = node;
        previous = node;
    }

public:
    Node *connect(Node *root)
    {
        Node *current = root;
        previous = NULL, nextrow = NULL;

        while (current)
        {
            if (current->left)
                link(current->left);
            if (current->right)
                link(current->right);

            if (current->next == NULL)
            {
                current = nextrow;
                previous = nextrow = NULL;
            }
            else
            {
                current = current->next;
            }
        }
        return root;
    }
};