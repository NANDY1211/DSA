#include <iostream>
#include <vector>
#include <climits>


void search(const std::vector<int>& arr,int key)
{
    for(int num : arr)
    {
        if(num == key)
        {
            std::cout<<"Element "<<key<<" found\n";
            return;
        }
    }

    std::cout<<"Element not found\n";
}

void largest(const std::vector<int>& arr)
{
    int largest = INT_MIN;
    for(int num : arr)
    {
        if(num > largest)
            largest = num;
    }

    std::cout<<"Largest Element in an array is "<<largest<<std::endl;
}


void smallest(const std::vector<int>& arr)
{
    int smallest = INT_MAX;

    for(int num : arr)
    {
        if(num < smallest)
            smallest = num;
    }

    std::cout<<"Smallest in the array is "<<smallest<<std::endl;
}


void secondLargest(const std::vector<int>& arr)
{
    int first = INT_MIN;
    int second = INT_MIN;


    for(int num : arr)
    {
        if(num > first)
        {
            second = first;
            first = num;
        }
        else if(num > second && num!= first)
        {
            second = num;
        }
    }

    std::cout<<"Second largest element in array is "<<second<<std::endl;
}


void secondSmallest(const std::vector<int>& arr)
{
    int first = INT_MAX;
    int second = INT_MAX;


    for(int num : arr)
    {
        if(num < first)
        {
            second = first;
            first = num;
        }
        else if(num < second && num != first)
        {
            second = num;
        }
    }

    std::cout<<"Second smallest element in an array is "<<second<<std::endl;
}



int main()
{
    std::vector<int> arr = {-1,-4,-3,-10,1,2};

    smallest(arr);
    largest(arr);

    secondLargest(arr);
    secondSmallest(arr);

    
    return 0;
}