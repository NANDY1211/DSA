#include <iostream>

void left_rotate_by_one_element(int arr[],int size)
{
    int temp = arr[0];
    for(int i = 1;i<size;i++)
    {
        arr[i-1] = arr[i];
    }
    arr[size-1] = temp;
}

void print_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        std::cout<<arr[i]<<",";
    }
}

int main()
{
    int arr[6] = {6,6,7,8,3,2};
    left_rotate_by_one_element(arr,6);
    std::cout<<"After rotating left \n";
    print_array(arr,6);
    return 0;
}