#include <iostream>

void remove_duplicates(int arr[],int size)
{
    int i=0; //Initial pointer
    for(int j = 1; j < size ;j++) //Another pointer to traverse through
    {
        if(arr[i] != arr[j]) //if not equals
        {
            i++; //move the pointer 
            arr[i] = arr[j]; //Replace the diff element
        }
    }
}
int main()
{
    int arr[5] = {1,1,2,2,3};

    std::cout<<"After removing duplicates \n";
    remove_duplicates(arr,5);
    for(int i = 0; i < 5; i++)
    {
        std::cout<<arr[i]<<",";
    }
    return 0;
}