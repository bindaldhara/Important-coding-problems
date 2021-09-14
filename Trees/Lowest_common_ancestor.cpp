#include<bits/stdc++.h>
#include<vector>
struct Node{
    int data;
    struct Node*left;
    struct Node* right;
     Node(int val){
         data=val;
         left=NULL;
         right=NULL;
     }
};

Node* lca2(Node* root,int n1,int n2){
    if(root==NULL)
    return NULL;
    if(root->data==n1 || root->data==n2)
    return root;
    Node* leftlca=lca2(root->left,n1,n2);
    Node* rightlca=lca2(root->right,n1,n2);
    if(leftlca && rightlca)
    return root;
    if(leftlca!=NULL)
    return leftlca;
    else
    return rightlca;
}

int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right= new Node(3);
    root->left->left=new Node(4);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    root->right->left->left=new Node(7);

    int n1=7;
    int n2=6;
    Node *LCA=lca2(root,n1,n2);
    if(LCA==NULL)
    std::cout<<"LCA doesnt exist\n";
    else
    std::cout<<LCA->data;
    return 0;
}
