#include <iostream>  
using namespace std;  
    
int partition (int a[], int start, int end){  //Hoare's Partition  
    int pivot = a[start]; //  first element as pivot 
    int i = (start - 1); 
    int j= end+1; 
  
    while(true){
        do{
            i++;
        } while(a[i]<pivot);
        do{
            j--;
        } while(a[j]>pivot);
        if(i>=j)
        return j;
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}  
  
void quick(int a[], int start, int end) {  
    if (start < end)  {  
        int p = partition(a, start, end);  //p is the partitioning index  
        quick(a, start,p);  
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
