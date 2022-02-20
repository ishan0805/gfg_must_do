/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        queue<Node *> q;
        if (root != nullptr)
        {
            q.push(root);
        }
        vector<int> ans;
        int f = 0;
        while (!q.empty())
        {
            int s = q.size();
            vector<int> v;
            while (s--)
            {
                auto root = q.front();

                q.pop();
                if (root->left != nullptr)
                {
                    q.push(root->left);
                }
                if (root->right != nullptr)
                {
                    q.push(root->right);
                }
                v.push_back(root->data);
            }
            if (f)
                reverse(v.begin(), v.end());
            ans.insert(ans.end(), v.begin(), v.end());
            f ^= 1;
        }
        return ans;
    }
};