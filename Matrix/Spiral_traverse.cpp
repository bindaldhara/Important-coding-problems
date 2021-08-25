#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3
 
void spiralPrint(int m, int n, int a[R][C])
{
    int row = 0, col = 0;
 
    /* row - starting row index
        m - ending row index
        col - starting column index
        n - ending column index
    
    */
 
    while (row < m && col < n) {
        /* Print the first row from
               the remaining rows */
        for (int i = col; i < n; ++i) {
            cout << a[row][i] << " ";
        }
        row++;
 
        /* Print the last column
         from the remaining columns */
        for (int i = row; i < m; ++i) {
            cout << a[i][n - 1] << " ";
        }
        n--;
 
        /* Print the last row from
                the remaining rows */
        if (row < m) {
            for (int i = n - 1; i >= col; --i) {
                cout << a[m - 1][i] << " ";
            }
            m--;
        }
 
        /* Print the first column from
                   the remaining columns */
        if (col < n) {
            for (int i = m - 1; i >= row; --i) {
                cout << a[i][col] << " ";
            }
            col++;
        }
    }
}
 

int main()
{
    int A[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>A[i][j];
        }
    }
    spiralPrint(R, C, A);
    return 0;
}
