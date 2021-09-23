#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int  kth(int arr[],int n,int k){
priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) 
        {
            //if size of priority queue becomes equal to k and top 
            //element is smaller than arr[i], we pop the front 
            //element and push arr[i] in priority queue.
            if (pq.size() == k && pq.top() < arr[i]) 
            { 
                pq.pop();
                pq.push(arr[i]);
            } 
            //else we just push arr[i] in priority queue.
            else if (pq.size() < k)
                pq.push(arr[i]);
        }
        //returning the top element of priority queue.
        return pq.top();
}
int main()
{
    int arr[] = {4,3,7,6,5};
    int k = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Kth largest element is:"<<kth(arr,n,k);
    return 0;
}
