#include <iostream>
#include <random>
#include <vector>
#include <time.h>

std::vector<int32_t> buildVec(size_t size, uint32_t basenumber, uint32_t uplimit)
{
    std::vector<int32_t> result(size);
    srand(time(0));
    for(size_t i = 0; i < size; ++i)
    {
        result[i] = rand() % uplimit - basenumber;
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return result;
}

int32_t findFirstIndex(const std::vector<int32_t>& numvec)
{
    size_t size = numvec.size();
    if(size == 0)
    {
        return 0;
    }
    std::vector<int32_t> ltor(size, 0);
    std::vector<int32_t> rtol(size, 0);
    for(size_t i = 1; i < size; ++i)
    {
        ltor[i] = ltor[i-1] + numvec[i-1];
        rtol[size-i-1] = rtol[size-i] + numvec[size-i];
    }
    for(size_t i = 0; i < size; ++i)
    {
        std::cout << ltor[i] << " ";
    }
    std::cout << std::endl;

    for(size_t i = 0; i < size; ++i)
    {
        std::cout << rtol[i] << " ";
    }
    std::cout << std::endl;

    for(size_t i = 0; i < size; ++i)
    {
        if(ltor[i] == rtol[i])
            return i;
    }
    return -1;
}

int main()
{
    std::vector<int32_t> vec = buildVec(20, 30, 50);
    std::cout << findFirstIndex(vec) << std::endl;
    exit(0);
}


