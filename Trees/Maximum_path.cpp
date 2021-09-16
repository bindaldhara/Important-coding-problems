#include<bits/stdc++.h>
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
int maxpath(Node *root,int &ans){
 if(root==NULL)
 return 0;
 int left=maxpath(root->left,ans);
 int right=maxpath(root->right,ans);
 int nodemax=max(max(root->data,root->data+root->right+root->left), max(root->data+root->right,root->data+root->left));
 ans=max(ans,nodemax);
 int singlepath=max(root->data,max(root->right+root->data,root->left+root->data));
 return singlepath;

}
int max(Node* root){
    int ans=INT_MIN;
    maxpath(root,ans);
    return ans;
}
