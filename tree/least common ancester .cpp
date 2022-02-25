class Solution
{
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    bool findLCA(Node *root, int n1, int n2, Node *&ans)
    {
        if (root == nullptr)
        {
            return false;
        }
        bool lt = findLCA(root->left, n1, n2, ans);
        bool rt = findLCA(root->right, n1, n2, ans);

        if (root->data == n1 || root->data == n2)
        {
            if (lt || rt)
            {
                ans = root;
            }
            return true;
        }
        else if (lt && rt && ans == nullptr)
        {
            ans = root;
        }
        return lt || rt;
    }
    Node *lca(Node *root, int n1, int n2)
    {
        Node *ans = nullptr;
        findLCA(root, n1, n2, ans);
        if (ans == nullptr)
        {
            return new Node(-1);
        }
        return ans;
    }
};