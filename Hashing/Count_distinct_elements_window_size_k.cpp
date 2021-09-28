
#include <iostream>
#include <unordered_map>
using namespace std;
 
void countDistinct(int arr[], int k, int n){
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < k; i++) {
        if (m[arr[i]] == 0) {
            count++;
        }
        m[arr[i]] += 1;
    }
    cout <<count << endl;
    for (int i = k; i < n; i++) {
        if (m[arr[i - k]] == 1) {
            count--;
        }
      
        m[arr[i - k]] -= 1;
        if (m[arr[i]] == 0) {
            count++;
        }
        m[arr[i]] += 1;
        cout << count << endl;
    }
}
 
int main()
{
    int arr[] = { 1, 2, 4,4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    countDistinct(arr, k, size);
 
    return 0;
}
