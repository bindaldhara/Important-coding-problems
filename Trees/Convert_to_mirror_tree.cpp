#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void preorder(Node* root)
{
    if (root == NULL) {
        return;
    }
 
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

bool convertToMirror(Node* root){
    if (root == NULL) 
        return true;
    convertToMirror(root->left);
    convertToMirror(root->right);
    swap(root->left, root->right);
}
 
int main()
{
    /* Construct the following tree
              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    convertToMirror(root);
    preorder(root);
    return 0;
}
