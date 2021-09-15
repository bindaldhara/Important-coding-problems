#include <bits/stdc++.h>
using namespace std;
 
struct PetrolPumpData
{
  int petrol;
  int distance;
};

int StartPointOfTour(struct PetrolPumpData array[], int n)
{
    int start_point = 0;
    int end_point =  1;
    int curr_petrol = array[start_point].petrol - array[start_point].distance;
    while (end_point != start_point || curr_petrol < 0)
    {
        while (curr_petrol < 0 && start_point != end_point)
        {
            curr_petrol = curr_petrol - (array[start_point].petrol - array[start_point].distance);
            start_point = (start_point + 1)%n;
         
            if (start_point == 0)
               return -1;
        
        curr_petrol = curr_petrol + array[end_point].petrol - array[end_point].distance;
        end_point = (end_point + 1)%n;
    }
    return start_point;
}

int main()
{
    struct PetrolPumpData input_array[] = { {4, 6}, {6, 3}, {6, 7} };
    int size = sizeof(input_array)/sizeof(input_array[0]);
    int result = StartPointOfTour(input_array,size);
    if(result == -1)
    {
        cout<<"No Tour"<<endl;
    }
    else
    {
        cout<<"Start point is: "<<result<<endl;
    }
    return 0;
}
