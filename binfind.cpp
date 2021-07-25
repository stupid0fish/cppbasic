#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

std::vector<int32_t> buildVec(size_t size, uint32_t basenumber, uint32_t uplimit)
{
   srand(time(0));
   std::vector<int32_t> result(size);
   for(size_t i = 0; i < size; ++i)
   {
       result[i] = rand() % uplimit - basenumber;
   }
   sort(result.begin(), result.end());
   for(size_t i = 0; i < size; ++i)
       std::cout << i << "[" << result[i] << "] ";
   std::cout << std::endl;
   return result;
}


int32_t findIndex(const std::vector<int32_t>& nums, const int32_t target)
{
    int32_t size = nums.size();
    int32_t left = 0;
    int32_t right = size-1;
    int32_t index = 0;
    std::cout << target << std::endl; 
    while(left <= right)
    {
        index = left + ((right - left) >> 1);
        if(target == nums[index])
            return index;
        else if(target < nums[index])
        {
            right = index - 1;
        }
        else
        {
            left = index + 1;
        }
    }
    std::cout << left << "--" << right << std::endl;
    return left;
}

int main()
{
    std::vector<int32_t> nums = buildVec(100, 1024, 2048);
    std::cout << findIndex(nums, 1024) << std::endl;
    std::cout << findIndex(nums, -1024) << std::endl;
    std::cout << findIndex(nums, 409) << std::endl;
    exit(0);
}
