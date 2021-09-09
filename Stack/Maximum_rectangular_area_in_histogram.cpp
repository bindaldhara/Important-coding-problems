#include<iostream>
#include<stack>
using namespace std;
int rectangle(int a[],int n){
    int ans=0,i=0;
    stack<int> st;
    while(i<n)
{
 while(!st.empty() && a[st.top()]>a[i]){
     int t=st.top();
     int h=a[t];
     st.pop();
     if(st.empty())
     ans=max(ans,h*i);
     else{
         int len=i-st.top()-1;
         ans=max(ans,len*h);
     }
 }
 st.push(i);
 i++;
}
return ans;
}
int main() {
    int a[]={6,2,5,4,5,1,6};
    int n=7;
   cout<< rectangle(a, n);
}
