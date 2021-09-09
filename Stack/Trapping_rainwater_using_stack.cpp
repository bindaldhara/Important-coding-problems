#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
 
 int trapping(vector<int>arr)
 {
   stack<int>st;
   int ans=0;
   for(int i=0;i<arr.size();i++)
   {
       while(!st.empty() && arr[st.top()]<arr[i]){
       int curr=st.top();
       st.pop();
       if(st.empty())
       break;
       int len=i-st.top()-1;
       ans+=min(arr[st.top()],arr[i]-arr[curr])*len;
       }
       st.push(i);
   }
   return ans;
 }
 int main()
 {
     vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
     cout<<trapping(arr);
     return 0;
 }
