#include <iostream>  
using namespace std;  
    
int partition (int a[], int start, int end){  //Lomuto Partition  
    int pivot = a[end]; //  last element as pivot 
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  {   
        if (a[j] < pivot)  {  
            i++; 
            int t = a[i];  
            a[i] = a[j];  //swapping a[i] and a[j]
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];   // swapping a[i+1] and a[end]
    a[end] = t;  
    return (i + 1);  
}  
  

void quick(int a[], int start, int end) {  
    if (start < end)  {  
        int p = partition(a, start, end);  //p is the partitioning index  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  
  
int main()  {  
    int a[] = { 23, 8, 28, 13, 18, 26 };  
    int n = sizeof(a) / sizeof(a[0]);  
     for(int i=0;i<n;i++){
       quick(a, 0, n - 1);  
       cout<<a[i]<<" ";
     }
    return 0;  
}  
