#include<bits/stdc++.h>
using namespace std;
 
class  Node{
    public:
    int data;

   Node* next;
    Node(int val){
     data=val;
     next=NULL;
    }
};

   int getNthFromLast( Node *head, int n)
{
    //using two pointers
     Node *currNode = head , *nthNode = head;
    
    //traversing first n elements with first pointer.
    while(n!=0)
        {
            if(currNode==NULL)
                return -1;
            currNode = currNode->next;
            n--;
        }
    
    while(currNode!=NULL)   
        {
            nthNode = nthNode->next;
            currNode = currNode->next;
        }
    
    //returning the data of nth node from end.
    if(nthNode!=NULL)
        return nthNode->data;
    else
        return -1;
        
}
 void insert(Node* &head,int val)
{
    Node*n=new Node(val);
    if(head==NULL){
   head=n;
   return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
     temp->next=n;
}
 void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
  
  Node* head = NULL;
  insert(head, 10);
  insert(head, 20);
  insert(head, 30);
  insert(head, 40);
  insert(head, 50);
  display(head);
  cout<<"Nth node from end is: ";
  cout<<getNthFromLast(head,2)<<endl;
  return 0;
}
