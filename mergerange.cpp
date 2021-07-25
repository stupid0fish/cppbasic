#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int32_t>> merge(std::vector<std::vector<int32_t>>& intervals)
{
    std::vector<std::vector<int32_t>> result;
    size_t size = intervals.size();
    for(auto vec : intervals)
    {
        for(auto num : vec)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    std::sort(intervals.begin(), intervals.end(), [](std::vector<int32_t>left, std::vector<int32_t> right)
            {
                return left[0] < right[0];
            }
            );
    for(auto vec : intervals)
    {
        for(auto num : vec)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    bool needleft = true;
    int32_t left, right;
    for(size_t i = 0; i < size-1; ++i)
    {
       if(needleft)
       {
           left = intervals[i][0];
           right = intervals[i][1];
           needleft = false;
       }
       if(right < intervals[i+1][0])
       {
           right = std::max(right, intervals[i][1]);
           result.push_back({left, right});
           needleft = true;
       }
       else
       {
           right = std::max(right, intervals[i+1][1]);
       }
    }
    if(needleft)
        result.push_back(intervals[size-1]);
    else
    {
        right = std::max(intervals[size-1][1], right);
        result.push_back({left, right});
    }
    for(auto vec : result)
    {
        for(auto num : vec)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return result;
}

int main()
{
    std::vector<std::vector<int32_t>> data = {{74,78},{61,63},{46,50},{51,54},{50,50},{60,64},{39,42},{25,27},{91,95},{14,16},{85,85},{5,7},{45,46},{45,49},{66,66},{73,73},{25,26},{25,26},{45,48},{67,67},{63,65},{82,84},{90,92},{47,49},{3,4},{1,5},{64,66},{73,77},{90,94},{20,21},{84,87},{48,49},{80,80},{85,85},{53,55},{21,23},{31,34},{71,75},{62,65},{8,9},{32,33},{7,8},{20,22},{57,57},{51,53},{18,21},{71,75},{49,50},{44,45},{28,31},{38,42},{15,17},{4,7},{48,52},{9,10},{37,38},{69,70},{89,89},{28,29},{52,52},{75,76},{20,21},{90,94},{49,53},{56,59},{84,85},{79,83},{20,21},{90,93},{55,59},{76,80},{40,41},{40,41},{36,39},{79,82},{0,4},{11,11},{1,4},{42,44},{40,40},{32,36},{48,50},{76,77},{0,1},{89,91},{65,68},{51,53},{64,67},{90,92},{11,15},{92,96},{23,24},{36,37},{9,9},{79,80},{80,83},{26,27},{75,79},{2,4},{20,23},{34,36},{61,63},{46,48},{80,81},{29,33},{57,59},{60,60},{78,79},{57,61},{79,82},{41,42},{51,55},{92,96},{73,74},{6,6},{90,93},{34,35},{30,30},{81,84},{68,68},{7,7},{84,86},{57,61},{15,16},{54,58},{54,56},{6,9},{66,66}};
    merge(data);
    std::vector<std::vector<int32_t>> data1 = {{1,3},{2,6},{8,10},{15,18}};
    merge(data1);
    std::vector<std::vector<int32_t>> data2 = {{1,4}, {4, 6}};
    merge(data2);
    std::vector<std::vector<int32_t>> data3 = {{1,9}, {4, 6}};
    merge(data3);
    std::vector<std::vector<int32_t>> data4 = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    merge(data4);
    exit(0);
}
