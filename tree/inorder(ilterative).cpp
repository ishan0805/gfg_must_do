class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        stack<Node *> st;
        vector<int> ans;

        auto r = root;
        while (r != nullptr || (!st.empty()))
        {

            while (r != nullptr)
            {
                st.push(r);
                r = r->left;
            }
            r = st.top();
            ans.push_back(r->data);

            st.pop();

            r = r->right;
        }
        return ans;
    }
};