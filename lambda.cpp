#include <iostream>
#include <algorithm>

int main()
{
    int arr[] = { 4, 2, 5, 2, 9, 0};
    std::sort(arr, arr+sizeof(arr)/sizeof(arr[0]), [=](int x, int y)->bool { return x < y; });
    for(auto num : arr)
        std::cout << num << std::endl;
    exit(0);
}
