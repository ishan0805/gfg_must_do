class Solution
{
public:
    void inorder(Node *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, ans);
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }
        inorder(root->right, ans);
    }
    vector<int> boundary(Node *root)
    {
        Node *r;
        vector<int> ans;
        if (root != nullptr)
        {
            ans.push_back(root->data);
            r = root->left;
        }

        while (r != nullptr && (r->left != nullptr || r->right != nullptr))
        {
            ans.push_back(r->data);
            if (r->left != nullptr)
            {
                r = r->left;
            }
            else
            {
                r = r->right;
            }
        }
        if (root->right != nullptr || root->left != nullptr)
        {
            inorder(root, ans);
        }
        root = root->right;
        stack<int> st;
        while (root != nullptr && (root->right != nullptr || root->left != nullptr))
        {
            st.push(root->data);
            if (root->right != nullptr)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundary(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends