#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int val)
    {
        data=val;
        left=NULL;
      right=NULL;
    }
};

void preorderIterative(Node* root)
{
    if (root == NULL)
    return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty())
    {
        // pop a node from the stack and print it
        Node* curr = st.top();
        st.pop();
 
        cout << curr->data << " ";
 
        // push the right child of the popped node into the stack
        if (curr->right) {
            st.push(curr->right);
        }
 
        // push the left child of the popped node into the stack
        if (curr->left) {
            st.push(curr->left);
        }
 
        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}
 
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    preorderIterative(root);
 
    return 0;
}
