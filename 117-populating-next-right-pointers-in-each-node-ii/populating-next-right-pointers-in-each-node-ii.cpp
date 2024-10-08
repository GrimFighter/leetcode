/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{

    private:
        void connectNode(Node *left, Node *right)
        {
            if (left == nullptr || right == nullptr) return;
            left->next = right;

            connectNode(left->left, left->right);
            connectNode(right->left, right->right);
            connectNode(left->right, right->left);
        }
    public:
        Node* connect(Node *root)
        {
            Node *node = root;

            while (node)
            {
                Node *dummy = new Node(0);

                for (Node *needle = dummy; node; node = node->next)
                {
                    if (node->left != nullptr)
                    {
                        needle->next = node->left;
                        needle = needle->next;
                    }
                    if (node->right != nullptr)
                    {
                        needle->next = node->right;
                        needle = needle->next;
                    }
                }

                node = dummy->next;
            }
            return root;
        }
};