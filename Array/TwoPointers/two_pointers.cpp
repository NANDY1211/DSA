#include <iostream>
#include <vector>
#include <climits>



std::pair<int,int> twoSumSorted(const std::vector<int>& arr,int target)
{
    int left = 0;
    int right = (int)(arr.size()-1);


    while(left < right)
    {
        if(arr[left] + arr[right] == target)
        {
            return std::make_pair(arr[left],arr[right]);
        }
        else if(arr[left] < target)
        {
            left++;
        }
        else
        {
            right++;
        }
    }

    return std::make_pair(-1,-1);

}


struct Container
{
    int area_;
    int height_;
    int width_;
};


Container maxArea(const std::vector<int>& arr)
{
    int left = 0;
    int right = (int)(arr.size()-1);
    int first = INT_MIN;
    int second = INT_MIN;

    int maxWater = INT_MIN;

    while(left < right)
    {
        int l = std::min(arr[left],arr[right]);
        int width = right - left;

        int area = width * l;

        std::cout<<"Height "<<l<<" Width "<<width<<" Area "<<area<<std::endl;
        
        if(area > maxWater)
        {
            maxWater = area;
            first = l;
            second = width;
        }

        if(arr[left] < arr[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return {.area_ = maxWater , .height_ = first , .width_ = second};
}

std::vector<int> removeDuplicates(std::vector<int>& arr)
{

    if(arr.empty()) return arr;
    int slow = 0;

    for(int fast = slow+1;fast < arr.size();++fast)
    {
        if(arr[slow] != arr[fast])
        {
            ++slow;
            arr[slow] = arr[fast];
        }
    }

    arr.erase(arr.begin()+(slow+1),arr.end());
    return arr;

}


std::vector<int> moveZeros(std::vector<int>& arr)
{
    int zero = 0;

    for(int i = 0; i<arr.size();i++)
    {
        if(arr[i] == 0)
        {
            zero = i;
            break;
        }
    }
    

    for(int nonZero = 1 ; nonZero < arr.size();++nonZero)
    {
        if(arr[nonZero] != arr[zero])
        {
            std::swap(arr[zero],arr[nonZero]);
            ++zero;
        }
    }

    return arr;
}

int main()
{


    std::vector<int> arr = {1,8,6,2,5,4,8,3,7};

    auto result = twoSumSorted(arr,11);
    std::cout<<"Target 11"<<" Pairs "<<result.first<<" "<<result.second<<std::endl;

    auto resultContainer = maxArea(arr);
    std::cout<<"Max water found is "<<resultContainer.area_<<" legth "<<resultContainer.height_<<" Width "<<resultContainer.width_<<std::endl;

    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    auto distinctArr = removeDuplicates(nums);

    std::cout<<"After removing duplicates \n ";

    for(int num : distinctArr)
    {
        std::cout<<num<<",";
    }


    std::vector<int> arr2 = {1,0,0,3,12};

    auto sorted = moveZeros(arr2);

    std::cout<<"\n After moving zeros \n";

    for(int num : sorted)
    {
        std::cout<<num<<",";
    }

    return 0;
}