#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node * nextRight;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void connect(Node *root)
    {
if(root==NULL)
        return;
       // empty queue 
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
         // size is to denote no. of nodes at current level
           int size=q.size();
         // to keep track of previous node
           Node* prev=NULL;
           while(size--){
               Node* temp=q.front();
               q.pop();
              
               if(temp->left)
                q.push(temp->left);
              
               if(temp->right)
                q.push(temp->right);
               
               if(prev!=NULL)
                prev->nextRight=temp;
               prev=temp;
           }
           prev->nextRight=NULL;
       }
    }
  
    int main() {
      /* Constructed binary tree is
             10
            /  \
          20    30
         / \
        40  60
        */

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    connect(root);

    cout << "Right of " << root->data << " is "
         << (root->nextRight ? root->nextRight->data : -1) << endl;
    cout << "Right of " << root->left->data << " is "
         << (root->left->nextRight ? root->left->nextRight->data : -1) << endl;
    cout << "Right of " << root->right->data << " is "
         << (root->right->nextRight ? root->right->nextRight->data : -1) << endl;
    cout << "Right of " << root->left->left->data << " is "
         << (root->left->left->nextRight ? root->left->left->nextRight->data : -1) << endl;
    cout << "Right of " << root->left->right->data << " is "
         << (root->left->right->nextRight ? root->left->right->nextRight->data : -1) << endl;
    return 0;
}
