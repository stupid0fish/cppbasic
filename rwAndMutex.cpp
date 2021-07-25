#include <iostream>
#include <time.h>
#include <mutex>
#include <shared_mutex>

int main()
{
    std::mutex ml;
    std::shared_mutex sml;
    uint32_t count = 0;
    clock_t start = clock();
    for(uint32_t i; i < 1000000; ++i)
    {
        std::lock_guard<std::mutex> guard(ml);
        ++count;
    }
    clock_t end = clock();
    std::cout << "time: " << end - start << std::endl;
    
    start = clock();
    for(uint32_t i; i < 1000000; ++i)
    {
        std::shared_lock lock(sml);
        ++count;
    }
    end = clock();
    std::cout << "time: " << end - start << std::endl;
    exit(0);
}
