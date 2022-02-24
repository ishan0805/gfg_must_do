class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        stack<Node *> st;
        vector<int> ans;

        while (root != NULL || (!st.empty()))
        {
            while (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            if (root->right == nullptr)
            {
                st.pop();
                ans.push_back(root->data);
                auto temp = st.top();
                // Imp check if current is the right child of the elemnt in the stack
                // if so then you should remove the stack element

                while (!st.empty() && root == temp->right)
                {
                    ans.push_back(temp->data);
                    root = temp;
                    st.pop();
                    if (!st.empty())
                        temp = st.top();
                    else
                        temp->right = NULL;
                }
                root = temp->right;
            }
            else
            {
                root = root->right;
            }
        }
        return ans;
    }
};