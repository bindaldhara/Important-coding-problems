#include <bits/stdc++.h>
using namespace std;
 
int findWater(int arr[], int n)
{
    
    int left[n];
    int right[n];
    int water = 0;
 
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
 
    
    // amount of water will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
 
    return water;
}
int main()
{
    int N;
    cout<<"Enter the size of array: ";
    cin>>N;
     int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    } 
   
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum water that can be accumulated is "
         << findWater(arr, n);
    return 0;
}