#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data,hd;
    struct Node*left;
    struct Node* right;
     Node(int val){
         data=val;
         left=NULL;
         right=NULL;
     }
};

void topview(Node* root){
    if (root == NULL)
        return;
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);

    while (q.size()) {
        hd = root->hd;
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
 
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }
    }
    int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    topview(root);
    return 0;
    }
