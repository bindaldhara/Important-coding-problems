#include <iostream>
using namespace std;

void InsertionSort(int A[], int n){
    for (int i=1; i<n; i++){
        int j = i-1;
        int x = A[i];
        while (j>-1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}
 
int main() {
 
    int A[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1};
    int n=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n;i++){
     InsertionSort(A,n);
      cout<< A[i]<<" ";
    }
    return 0;
}
