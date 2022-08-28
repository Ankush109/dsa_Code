// using two stacks  approach
// we need to push the root of the tree in stack 1 and then check if it has right or left the push o=it into the stack 2
// pop the element in the top of thestack and push in stack 2
vector<int> postorder;
if (root == NULL)
    return postorder;
stack<TreeNode *> st1, st2;

st1.push_back(root);

while (!st.empty())
{
    root = st1.top();
    st1.pop();
    s2.push(root);
    if (root->left != NULL)
    {
        st1.push(root->left);
    }
    if (root->right != NULL)
    {
        st1.push(root->right);
    }
}
while (!st2.empty())
{
    postorder.push_back(st2.top());
    st2.pop();
}
return postorder;