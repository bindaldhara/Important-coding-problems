#include <bits/stdc++.h>
using namespace std;

// Function to find next gap.
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int* arr1, int* arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap); 
         gap > 0; gap = nextGap(gap)) 
    {
        // comparison of elements in arr1.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);

        // comparison of elements in both the arrays.
        for (j = gap > n ? gap - n : 0; 
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);

        if (j < m) {
            // comparison elements in arr2.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}


int main()
{
    int N,M;
    cout<<"Enter size of array 1: ";
    cin>>N;
     cout<<"Enter size of array 2: ";
    cin>>M;
    int a1[N],a2[M];
    for(int i=0;i<N;i++)
    cin>>a1[i];
    for(int i=0;i<M;i++)
    cin>>a2[i];

    int n = sizeof(a1) / sizeof(int);
    int m = sizeof(a2) / sizeof(int);
    merge(a1, a2, n, m);
    printf("First Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a1[i]);
    printf("\nSecond Array: ");
    for (int i = 0; i < m; i++)
        printf("%d ", a2[i]);
    printf("\n");
    return 0;
}