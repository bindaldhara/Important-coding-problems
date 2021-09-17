#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(int arr[], int n){
    
    int i,maxCur=arr[0];
    int totalsum=arr[0];
    for(i=1;i<n;i++)
    {
        maxCur=max(arr[i],arr[i]+maxCur);
        if(maxCur>totalsum)
        {
            totalsum=maxCur;
        }
    }
    return totalsum;
    
}

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
