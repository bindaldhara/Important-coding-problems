GFG Question Link:https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse_list(Node* head)
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next;
        
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        
    }
    
   
    bool is_identical(Node* n1, Node* n2)
    {
        for( ; n1 && n2 ; n1=n1->next, n2=n2->next )
            if( n1->data != n2->data )
                return 0;
        return 1;
    }
    bool isPalindrome(Node *head)
    {
        int size=0;
        Node* ptr;
       
        for( ptr=head ; ptr ; ptr=ptr->next )
            size++;
            
        
        if(size<2) return 1;
        
        ptr = head;
        int mid_pt = (size-1)/2;
     
        while(mid_pt--)
            ptr = ptr->next;
            
        Node* head2 = ptr->next;
        ptr->next = NULL;
     
        head2 = reverse_list(head2);
        
     
        bool ret = is_identical(head, head2);
        

        head2 = reverse_list(head2);
        ptr->next = head2;
        
        return ret;
    }
};

int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}
