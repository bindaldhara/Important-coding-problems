#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n], index;
        for (index = 0; index < n; index++)
            cin >> arr[index];
        int low = 0, mid = 0, high = n - 1, temp;
        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                temp = arr[mid];
                arr[mid] = arr[low];
                arr[low] = temp;
                low++;
                mid++;
            }
            else if (arr[mid] == 2)
            {
                temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
            }
            else
                mid++;
        }
        for (index = 0; index < n; index++)
            cout << arr[index] << " ";
        cout << "\n";
    }
    return 0;
}
