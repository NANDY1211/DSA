#include <iostream>


bool is_array_sorted(int arr[],int size)
{
    for(int i = 1;i < size ;i++)
    {
        if(arr[i-1] > arr[i]) //if the previous element is greater than next element then it is not in sorted order
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int arr[5] = {1,2,3,4,5};

    std::cout<<"Is array sorted "<<std::boolalpha<<is_array_sorted(arr,5)<<std::endl;

    return 0;
}