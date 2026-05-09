#include <iostream>

void print_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        std::cout<<arr[i]<<",";
    }
}

void reverse(int arr[],int start,int end)
{
    int temp;
    while(start<=end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void right_rotate_by_d_elements(int arr[],int size,int d)
{
    d%=size;
    reverse(arr,size-d,size-1); //Reverse the elements from size-d to last element
    reverse(arr,0,size-d-1); //Reverse the elements from 0 to d elements 
    reverse(arr,0,size-1); //Now reverse all the element then the rotation will happen
    print_array(arr,6);
}



int main()
{
    int arr[6] = {1,2,3,4,5,6};
    right_rotate_by_d_elements(arr,6,2);
    return 0;
}