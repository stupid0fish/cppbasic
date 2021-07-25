#include <iostream>
#include <cassert>

size_t COUNT[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};

union bitbumber
{
    uint8_t u8[4];
    uint32_t u32;
};

size_t countbybit(uint8_t number)
{
    size_t count = 0;
    while(number)
    {
        count += number & 0x01;
        number >>= 1;
    }
    return count;
}


size_t countbyone(uint8_t number)
{
    size_t count = 0;
    while(number)
    {
        number &= number - 1;
        ++count;
    }
    return count;
}

size_t countbyindex(uint8_t index)
{
    return COUNT[index];
}

size_t countforuint32(uint32_t number)
{
    bitbumber bn;
    bn.u32 = number;
    /*
    std::cout << countbyone(bn.u8[0]) << countbyindex(bn.u8[0]) << std::endl;
    std::cout << countbyone(bn.u8[1]) << countbyindex(bn.u8[1]) << std::endl;
    std::cout << countbyone(bn.u8[2]) << countbyindex(bn.u8[2]) << std::endl;
    std::cout << countbyone(bn.u8[3]) << countbyindex(bn.u8[3]) << std::endl;
    */
    assert(countbyindex(bn.u8[0]) == countbyone(bn.u8[0]));
    assert(countbyindex(bn.u8[1]) == countbyone(bn.u8[1]));
    assert(countbyindex(bn.u8[2]) == countbyone(bn.u8[2]));
    assert(countbyindex(bn.u8[3]) == countbyone(bn.u8[3]));

    return countbyindex(bn.u8[0]) + countbyindex(bn.u8[1]) + countbyindex(bn.u8[2]) + countbyindex(bn.u8[3]);
}

size_t counttochange(uint32_t left, uint32_t right)
{
    uint32_t number = left ^ right;
    return countforuint32(number);
}

int main()
{
    int maxu8 = 255;
    for(int i = 0; i <= maxu8; ++i)
    {
        assert(countbybit(i) == countbyone(i));
        std::cout << countbyone(i) << ", ";
    }
    std::cout << std::endl;

    for(uint32_t i = 255; i <= 1024; ++i)
    {
        //countforuint32(i);
        std::cout << countforuint32(i) << " ";
    }
    std::cout << std::endl;

    exit(0);
}


