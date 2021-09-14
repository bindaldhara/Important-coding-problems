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

int height(Node* root){
    if(root==NULL)
    return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return std::max(lh,rh)+1;
}

/* int diameter(Node* root){
    if(root==NULL)     TC=O(n square)
    return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    int currd=lh+rh+1;
    int ld=diameter(root->left);
    int rd=diameter(root->right);
    return std::max(currd,std::max(ld,rd));
} */

int diameter(Node* root,int *height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ld=diameter(root->left,&lh);
    int rd=diameter(root->right,&rh);
    int currd=lh+rh+1;
    *height=std::max(rh,lh)+1;
    return std::max(currd,std::max(ld,rd));
}
int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    int hei=0;
    std::cout<<"Height: "<<height(root)<<std::endl;
    std::cout<<"Diameter: "<<diameter(root,&hei)<<std::endl;
    return 0;
 }
