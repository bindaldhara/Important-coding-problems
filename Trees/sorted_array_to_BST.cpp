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
Node* sorted(int arr[],int start,int end){
    if(start>end)
    return NULL;
    int mid=(start+end)/2;
    Node* root=new Node(arr[mid]);
    root->left=sorted(arr,start,mid-1);
    root->right=sorted(arr,mid+1,end);
    return root;
}
void printpreorder(Node* root){
     if(root==NULL)
     return;
     cout<<root->data<<" ";
     printpreorder(root->left);
     printpreorder(root->right);
 }
 int main(){
     int arr[]={10,20,30,40,50};
     Node* root=sorted(arr,0,4);
     printpreorder(root);
     return 0;
 }
