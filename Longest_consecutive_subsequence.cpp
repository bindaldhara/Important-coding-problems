#include <bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;
          // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
         //possible sequence checking
    for (int i = 0; i < n; i++) //possible sequence checking
    {
        if (S.find(arr[i] - 1) == S.end())
        {

            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
 
        
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
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
    int n = sizeof arr / sizeof arr[0];
    cout << "Length of the Longest contiguous subsequence "
            "is "
         << findLongestConseqSubseq(arr, n);
    return 0;
}