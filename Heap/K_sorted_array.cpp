#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sortKSortedArray(vector<int> &a, int k){
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (int i = 0; i <= k; i++) {
        pq.push(a[i]);
    }
    int index = 0;
    //  for remaining elements in the array
    for (int i = k + 1; i < a.size(); i++) {
        a[index++] = pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    while (!pq.empty()){
        a[index++] = pq.top();
        pq.pop();
    }
}
 
int main()
{
    vector<int>a = { 6,5,3,2,8,10,9};
    int k = 3;
    sortKSortedArray(a, k);
    for (int it: a) 
        cout << it << " ";
    return 0;
}
