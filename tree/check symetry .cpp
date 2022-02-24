class Solution
{
public:
    bool ok(Node *r1, Node *r2)
    {

        if (r1 == nullptr || r2 == nullptr)
        {

            return r1 == r2;
        }

        return r1->data == r2->data && ok(r1->left, r2->left) && ok(r1->right, r2->right);
    }
    // Function to check if S is a subtree of tree T.
    bool isSubTree(Node *r1, Node *r2)
    {
        if (r2 == nullptr)
        {
            return true;
        }
        if (r1 == nullptr)
        {
            return false;
        }
        if (r1->data == r2->data && ok(r1, r2))
        {
            return true;
        }
        else
        {
            return isSubTree(r1->left, r2) || isSubTree(r1->right, r2);
        }
    }
};