class Solution
{
public:
    int minDepth(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lt = minDepth(root->left);
        int rt = minDepth(root->right);
        if (lt == 0 || rt == 0)
        {
            return max(lt, rt) + 1;
        }
        return min(lt, rt) + 1;
    }
};
