#include <iostream>
#include <string.h>

int main()
{
    int arr[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    memcpy(arr+6, arr, sizeof(int)*12);
    std::cout << sizeof(arr) / sizeof(int) << std::endl;
    for(auto member : arr)
    {
        std::cout << member << " ";
    }
    std::cout << std::endl;

    int arr1[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    memcpy(arr1, arr1+5, sizeof(int)*10);
    for(auto member : arr1)
    {
        std::cout << member << " ";
    }
    std::cout << std::endl;
}
