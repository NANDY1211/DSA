#include <iostream>
#define SIZE 5

void selectionSortAsc(int arr[],int size)
{
    for(int i = 0;i<size-1;i++)
    {
        int min = i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        std::swap(arr[i],arr[min]);
    }
}

void selectionSortDesc(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int max = i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]>arr[max])
            {
                max = j;
            }
        }
        std::swap(arr[i],arr[max]);
    }
}

void bubbleSortAsc(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        bool swapped = false;
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                std::swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void bubbleSortDesc(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        bool swapped = false;
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                std::swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void insertionSortAsc(int arr[], int size)
{
    for(int i = 1; i < size; i++)  // start from second element
    {
        int j = i;
        while(j > 0 && arr[j] < arr[j-1])
        {
            std::swap(arr[j], arr[j-1]);
            j--;  // move left
        }
    }
}


void printArr(int arr[],int size)
{
    std::cout<<"After sorting\n";
    for(int it=0;it<size;it++)
    {
        std::cout<<arr[it]<<",";
    }
    std::cout<<"\n";
}


int main()
{
    int arr[SIZE] = {5,4,3,2,1};


    //bubble sort in ascending order
    bubbleSortAsc(arr,SIZE);
    //after sort
    printArr(arr,SIZE);

    //Bubble sort in descending order
    bubbleSortDesc(arr,SIZE);
    //after sort
    printArr(arr,SIZE);


    //Insertion sort
    insertionSortAsc(arr,SIZE);
    //after sort
    printArr(arr,SIZE);
    return 0;


}