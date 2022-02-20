/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.
    int ok(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lt_height = ok(root->left);
        int rt_height = ok(root->right);
        if (lt_height == -1 || rt_height == -1)
        {
            return -1;
        }
        if (abs(lt_height - rt_height) > 1)
        {
            return -1;
        }
        return max(lt_height, rt_height) + 1;
    }
    bool isBalanced(Node *root)
    {
        if (ok(root) == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
