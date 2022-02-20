// Structure of the node of the tree is as struct Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Solution
{
public:
    bool check(Node *left, Node *right)
    {
        if (left == nullptr || right == nullptr)
            return left == right;

        return check(left->left, right->right) && check(left->right, right->left) && left->data == right->data;
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node *root)
    {
        return root == nullptr || check(root->left, root->right);
    }
};