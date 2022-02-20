class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    int findDiameter(Node *root, int &diameter)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lt_height = findDiameter(root->left, diameter);
        int rt_height = findDiameter(root->right, diameter);
        int temp_diameter = lt_height + rt_height + 1;
        diameter = max(diameter, temp_diameter);
        return max(lt_height, rt_height) + 1;
    }
    int diameter(Node *root)
    {
        int ans = 0;
        findDiameter(root, ans);
        return ans;
    }
};
