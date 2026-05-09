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

void left_rotate_by_d_elements(int arr[],int size,int d)
{
    d%=size;
    reverse(arr,0,d-1); //Reverse the elements upto the d element
    reverse(arr,d,size-1); //Reverse the elements from d to end elements 
    reverse(arr,0,size-1); //Now reverse all the element then the rotation will happen
    print_array(arr,6);
}



int main()
{
    int arr[6] = {1,2,3,4,5,6};
    left_rotate_by_d_elements(arr,6,3);
    return 0;
}