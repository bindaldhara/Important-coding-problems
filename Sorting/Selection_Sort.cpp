#include <iostream>

using namespace std;
 
 
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void SelectionSort(int A[], int n){
    for (int i=0; i<n-1; i++){
      int min_ind=i;
      for(int j=i+1;j<n;j++){
          if(A[j]<A[min_ind])
          min_ind=j;
          swap(A[min_ind],A[i]);
      }

      }
}
 
int main() {
 
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n;i++){
     SelectionSort(A,n);
      cout<< A[i]<<" ";
    }
    return 0;
}
