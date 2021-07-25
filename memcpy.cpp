#include <iostream>

void* memcopy(void* dst, const void* src, size_t size)
{
    if(dst == nullptr || src == nullptr)
    {
        return nullptr;
    }

    if((src < dst) && (char*)src + size > (char*)dst)
    {
        char* psrc = (char*)src + size - 1;
        char* pdst = (char*)dst + size - 1;
        while(size--)
        {
            *pdst-- = *psrc--;
        }
    }
    else
    {
        char* psrc = (char*)src;
        char* pdst = (char*)dst;
        while(size--)
        {
            *pdst++ = *psrc++;
        }
    }
    return dst;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    memcopy(arr+5, arr, sizeof(int)*10);
    for(auto member : arr)
        std::cout << member << " ";
    std::cout << std::endl;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    memcopy(arr1, arr1+5, sizeof(int)*10);
    for(auto member : arr1)
        std::cout << member << " ";
    std::cout << std::endl;
}
