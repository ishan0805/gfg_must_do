class Solution
{

public:
    Node *assistBuilt(int in[], int pre[], int st, int en, int &curr)
    {
        if (st > en)
        {
            return nullptr;
        }
        Node *root = new Node(pre[curr++]);

        int mid = 0;
        for (int i = st; i <= en; i++)
        {
            if (root->data == in[i])
            {
                mid = i;
                break;
            }
        }
        root->left = assistBuilt(in, pre, st, mid - 1, curr);
        root->right = assistBuilt(in, pre, mid + 1, en, curr);
        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        int curr = 0;
        return assistBuilt(in, pre, 0, n - 1, curr);
    }
};