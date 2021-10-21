#include<iostream>
using namespace std;

void merge(int A[], int l, int m, int r) {
   int i, j, k, n1, n2;
   //size of left and right sub-arrays
   n1 = m-l+1; n2 = r-m;
   int left[n1], right[n2];
   //fill left and right sub-arrays
   for(i = 0; i<n1; i++)
      left[i] = A[l+i];
   for(j= 0; j<n2; j++)
      right[j] = A[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < n1 && j<n2) {
      if(left[i] <= right[j]) {
         A[k] = left[i];
         i++;
         k++;
      }else{
       A[k] = right[j];
         j++;
         k++;
      }
      
   }
   while(i<n1) {       //extra element in left array
      A[k] = left[i];
      i++; k++;
   }
   while(j<n2) {     //extra element in right array
      A[k] = right[j];
      j++; k++;
   }
}
void mergeSort(int A[], int l, int r) {

   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(A, l, m);
      mergeSort(A, m+1, r);
      merge(A, l, m, r);
   }
}
int main() {
   int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
  
  for(int i=0;i<n;i++){
mergeSort(A, 0, n-1); 
cout<<A[i]<<" ";
  }
       return 0;
   
}
