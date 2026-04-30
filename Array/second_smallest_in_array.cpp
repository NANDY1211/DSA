#include <iostream>
#include <climits>


int sSmallest(int arr[],int size)
{
    int smallest = arr[0]; //Assuming first element as smallest
    int sSmallest = INT_MIN; //Assuming min element as second smallest

    for(int i = 1; i < size;i++) //Itearting over the first element
    {
        if(arr[i] < smallest) //if adjacent element is smaller than present smallest
        {
            sSmallest = smallest; //then the smallest become the second smallest
            smallest = arr[i]; // and adjacent element become the smallest
        }
        else if(arr[i] > smallest and arr[i] < sSmallest) //If initially we got smallest element then second smallest can be calculated with adjacent element
        {
            sSmallest = arr[i]; //adjacent element as second smallest
        }
    }
    return sSmallest;
}
int main()
{
    int arr[5] = {6,6,3,2,2};

    std::cout<<"Second Smallest element in an array "<<sSmallest(arr,5)<<std::endl;


    return 0;
}