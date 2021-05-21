class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        //code here
        vector<int> v;
        stack<Node *> s;
        Node *cursor = root;

        bool done = false;

        while (!done)
        {
            if (cursor != NULL)
            {
                s.push(cursor);        //place pointer to node on the stack
                                       //before traversing the node's left subtree
                cursor = cursor->left; //traverse the left subtree
            }
            else //backtrack from the empty subtree and
                 //visit the node at the top of the stack;
                 //however, if the stack is empty, you are
                 //done
            {
                if (!s.empty())
                {
                    cursor = s.top();
                    s.pop();
                    v.push_back(cursor->data);
                    cursor = cursor->right;
                }
                else
                    done = true;
            }
        }

        return v;
    }
};