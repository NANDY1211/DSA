#include <iostream>


int smallest(int arr[],int size)
{
    int smallest = arr[0]; //Assuming first element as smallest
    for(int i = 1;i < size;i++) //Iterate from the second element
    {
        if(arr[i] < smallest) //Check with the adjacent element 
        {
            smallest = arr[i];
        }
    }
    return smallest;
}
int main()
{

    int arr[5] = {4,5,32,2,-1};
    std::cout<<"Smallest element in an array is "<<smallest(arr,5);
    return 0;
}