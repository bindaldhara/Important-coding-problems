#include<bits/stdc++.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;

    }
};
 int search(int inorder[],int start,int end,int curr){
     for(int i=start;i<=end;i++){
         if(inorder[i]==curr)
         return i;
     }
     return -1;
 }
Node* build(int inorder[],int postorder[],int start,int end){
    static int idx=4;
    if(start>end)
    return NULL;
    int curr=postorder[idx];
    idx--;
    Node* node=new Node(curr);
    if(start>end)
    return node;
    int pos=search(inorder,start,end,curr);
    node->right=build(inorder,postorder,pos+1,end);
    node->left=build(inorder,postorder,start,pos-1);
    return node;
}
void inorderprint(Node* root){
    if(root==NULL)
    return;
    inorderprint(root->left);
    std::cout<<root->data<<" ";
    inorderprint(root->right);
}

int main(){
    int inorder[]={4,2,1,5,3};
    int postorder[]={4,2,5,3,1};
    Node * root=build(inorder,postorder,0,4);
    inorderprint(root);
    return 0;
}
