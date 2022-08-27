// in recursion we used callback stack to implement inorder traversal in tree
// but if we want to solve this qs without recursion then we need to do it by making our own stack called
// auxillary stack

#include <iostream>
#include <stack>

using namespace std;
vector<int> inorderiterative_traversal(Treenode *root)
{
    stack<Treenode *> st;
    Treenode *node = root;

    vector<int> ans;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
                return;

            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
        return ans;
    }
}
int main()
{
    return 0;
}