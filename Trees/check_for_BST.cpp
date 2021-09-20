#include<bits/stdc++.h>
using namespace std;
 struct Node{
     int data;
     Node* left,*right;
     Node(int val){
         data=val;
         right=NULL;
         left=NULL;
     }
 };
bool check(Node* root,Node* max=NULL,Node*min=NULL){
    if(root==NULL)
    return true;
    if(min!=NULL && root->data<=min->data)
    return false;
    if(max!=NULL && root->data>=max->data)
    return false;
    bool leftvalid=check(root->left,max,root);
    bool rightvalid=check(root->right,max,root);
    return (rightvalid&&leftvalid);
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    if(check(root)==false)
    cout<<"Invalid"<<endl;
    else
    cout<<"Valid";
    return 0;

}
