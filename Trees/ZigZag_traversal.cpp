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

void zigzag(Node* root)
{
     if(root==NULL)
     return ;
     stack<Node*>currlevel;
     stack<Node*>nextlevel;
     bool lefttoright=true; // for direction
     currlevel.push(root);
     while(!currlevel.empty())
     {
         Node* temp=currlevel.top();
         currlevel.pop();

         if(temp!=NULL){
             cout<<temp->data<<" ";
         
         if(lefttoright==true){
          if(temp->left!=NULL)
          nextlevel.push(temp->left);
          if(temp->right!=NULL)
          nextlevel.push(temp->right);
         }
         else{
             if(temp->right!=NULL)
             nextlevel.push(temp->right);
             if(temp->left!=NULL)
          nextlevel.push(temp->left);
         }
         }
         if(currlevel.empty()){
             lefttoright=!lefttoright;
             swap(currlevel,nextlevel);
         }
     }
}
int main(){
    Node* root=new Node(12);
    root->left=new Node(9);
    root->right=new Node(15);
    root->left->left=new Node(5);
    root->left->right=new Node(10);
    zigzag(root);
    return 0;
}
