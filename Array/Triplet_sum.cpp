#include <bits/stdc++.h>
using namespace std;

void findTripletSum(int A[], int n, int X)
{
    sort(A, A+n);   
    int i, j, k, count = 0;
    for(i = 0;i<=n-3;i++)   
    {
        j = i+1;
        k = n-1;
        while(j<k)    //two-pointer appraoch is used.
        {
            if(A[i] + A[j] + A[k] < X)  
            {
                j++;
            }
            else if(A[i] + A[j] + A[k] > X)  
            {
                k--;
            }
            else if(A[i] + A[j] + A[k] == X) 
            {
                j++;
                k--;
                count++;
            }
        }
    }
    if(count == 0)
      cout<<"The triplet doesn't exists"<<endl;
    else
      cout<<"The triplet exists"<<endl;
}

int main()
{
    int n, X;
    cout<<"Enter n"<<endl;
    cin>>n;
    cout<<"Enter the sum which you want to find"<<endl;
    cin>>X;
    cout<<"Enter the elements of array"<<endl;
    int A[n];
    for(int i = 0;i<n;i++)
    {
        cin>>A[i];
    }
    findTripletSum(A, n, X);
    return 0;
}
