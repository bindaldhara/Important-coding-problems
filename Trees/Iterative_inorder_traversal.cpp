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

void inorderIterative(Node* root)
{
    stack<Node*> st;
    Node* curr = root;
    while (!st.empty() || curr != NULL)
    {
        // if the current node exists, push it into the stack
        // and move to its left child
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, remove an element from the stack,
            // print it, and finally set the current node to its right child
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
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
 
    inorderIterative(root);
    return 0;
}

