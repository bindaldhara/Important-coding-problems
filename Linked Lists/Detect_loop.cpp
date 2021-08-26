#include<iostream>
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

   
}void makecycle(node* &head,int pos){
    node*temp=head;
    node* start;
    int count =1;
    while(temp->next!=NULL){
        if(count==pos)
        start=temp;
        temp=temp->next;
        count++;
    }
    temp->next=start;
}

bool detect(node* &head){
    node*fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        return true;
    }
    return false;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}
int main(){
    node*head=NULL;
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    makecycle(head,3);
    cout<<"Existence of loop: ";
    cout<<detect(head)<<endl;
    
    return 0;
    
}
