#include <iostream>
#include <climits>

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

void move_zeros_to_right(int arr[],int size)
{
    int j = -1;

    // Loop into the array and find the first occurence of 0 . then set the j index as 0 element index
    for(int i = 0 ; i < size-1 ; i++)
    {
        if(arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    //Compare 0 and non-zero and swap continuosly through the array
    for(int i = j+1 ; i <= size-1 ; i++)
    {
        if(arr[i] != 0)
        {
            std::swap(arr[i],arr[j]);
            j++;
        }
    }

    print_array(arr,6);

}



int main()
{
    int arr[6] = {0,0,0,4,5,6};
    move_zeros_to_right(arr,6);
    
    return 0;
}