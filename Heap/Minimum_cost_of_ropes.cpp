#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
 
int MinCost(vector<int> &arr){
   //min heap
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

    int res = 0;
    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
 
        int y = pq.top();
        pq.pop();

        int sum = x + y;
        pq.push(sum);
        res += sum;
    }
    return res;
}

int main(){
    vector<int> arr = { 4,3,2,6 };
    cout << "The minimum cost is " <<MinCost(arr);
    return 0;
}
