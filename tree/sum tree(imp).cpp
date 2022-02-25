class Solution
{

public:
    int assistSumTree(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return root->data;
        }

        int lt = assistSumTree(root->left);
        int rt = assistSumTree(root->right);
        if (lt == -1 || rt == -1 || (lt + rt != root->data))
        {
            return -1;
        }
        return root->data + lt + rt;
    }
    bool isSumTree(Node *root)
    {
        if (assistSumTree(root) == -1)
        {
            return false;
        }
        return true;
    }
};