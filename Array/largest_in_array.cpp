#include <iostream>


int largest(int arr[],int size)
{
    int largest = arr[0]; //Assuming first element as largest
    for(int i = 1;i < size;i++) //Iterate from the second element
    {
        if(arr[i] > largest) //Check with the adjacent element 
        {
            largest = arr[i];
        }
    }
    return largest;
}
int main()
{

    int arr[5] = {4,5,32,2,1};
    std::cout<<"Largest element in an array is "<<largest(arr,5);
    return 0;
}