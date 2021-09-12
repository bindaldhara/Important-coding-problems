#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int>q1;
    queue<int>q2;
    int n;

public:
Stack(){
     n=0; 
}
void push(int x){
    q2.push(x);
    n++;
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
   queue <int>temp=q1;
   q1=q2;
   q2=temp;
}

void pop(){
    q1.pop();
    n--;
}
int top(){
    return q1.front();
}
int size(){
return n;
}
};
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    cout<<st.top();
    return 0;
}
