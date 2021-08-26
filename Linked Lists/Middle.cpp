#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
    data=val;
    next=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node*n=new node(val);
    if(head==NULL)//no element
    {
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
    temp=temp->next;
    }
    temp->next=n;
}
void middle(node* head){
    if(head==NULL)
    return;
    node* slow=head;
    node* fast=head;
    while(fast!=NULL &&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<" ";
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}

int main()
{
    node* head=NULL;
    insertAtTail(head,20);
    insertAtTail(head,21);
    insertAtTail(head,22);
    insertAtTail(head,23);
    insertAtTail(head,24);
    display(head);
    cout<<"Middle element: ";
    middle(head);
    return 0;
}
