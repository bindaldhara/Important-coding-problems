#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data; 
    int hd; 
    Node *left, *right; 
    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};

void bottomView(Node *root)
{
    if (root == NULL)
        return;
    int hd = 0;
    map<int, int> mp;
    queue<Node *> q;
    root->hd = hd;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();   
        hd = temp->hd;
        mp[hd] = temp->data;
        if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
        cout << it->second << " ";
}


int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    
    bottomView(root);
    return 0;
}
