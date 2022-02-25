class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        unordered_map<int, vector<int>> m;
        int first = 0, last = 0, curr = 0;
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                auto p = q.front();
                q.pop();
                auto r = p.first;
                int l = p.second;
                m[l].push_back(r->data);
                if (r->left != nullptr)
                {
                    first = min(first, l - 1);
                    q.push({r->left, l - 1});
                }
                if (r->right != nullptr)
                {
                    last = max(last, l + 1);
                    q.push({r->right, l + 1});
                }
            }
        }
        vector<int> ans;
        for (int i = first; i <= last; i++)
        {
            for (auto ele : m[i])
            {
                ans.push_back(ele);
            }
        }
        return ans;
    }
};