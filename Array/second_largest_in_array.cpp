#include <iostream>
#include <climits>


int sLargest(int arr[],int size)
{
    int largest = arr[0]; //Assuming first element as largest
    int sLargest = INT_MIN; //Assuming min element as second Largest

    for(int i = 1; i < size;i++) //Itearting over the first element
    {
        if(arr[i] > largest) //if adjacent element is greater than present largest
        {
            sLargest = largest; //then the largest become the second largest
            largest = arr[i]; // and adjacent element become the largest
        }
        else if(arr[i] < largest and arr[i] > sLargest) //If initially we got largest element then second largest can be calculated with adjacent element
        {
            sLargest = arr[i]; //adjacent element as second largest
        }
    }
    return sLargest;
}
int main()
{
    int arr[5] = {6,6,3,2,2};

    std::cout<<"Second largest element in an array "<<sLargest(arr,5)<<std::endl;


    return 0;
}