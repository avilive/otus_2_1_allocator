#include <iostream>
#include <customContainer.h>
#include <limitedAllocator.h>
#include <vector>
#include <map>

inline int fact(const int& n)
{
    if (n == 0)
        return 0;
    else
        return n + fact(n - 1);
}

int main(int, char* []) 
    {

    {
        //1.MAP 
        auto m1 = std::map<int, int>{};
       
        for (int i = 0; i < 10; i++) 
            m1.insert(std::pair<int, int>(i, fact(i)));
 
   
        std::cout << "Map print: " << std::endl;
       for (auto it = m1.begin(); it != m1.end(); it++)
            std::cout << it->first << ' ' << it->second << std::endl;
    }

    //map with custom allocators that allows only 10 elements
    {
        auto m = std::map<int, int, std::less<int>,
            limitedAllocator<std::pair<const int, int>>>{};
        for (int i = 0; i < 10; i++)
            m.insert(std::pair<int, int>(i, fact(i)));

        std::cout << "Map with allocator  print: " << std::endl;
        for (auto it = m.begin(); it != m.end(); it++)
            std::cout << it->first << ' ' << it->second << std::endl;


    }
   //custom container
   {
    std::cout << "Custom vector  with allocator  print: " << std::endl;
    auto vec = customContainer<int, std::allocator<int>>{};
    vec.Reserve(10);
    for (int i =0 ;i<10;i++)
        vec.PushBack(fact(i));
    for (int i=0; i<10;i++)
        std::cout << vec.at(i) << std::endl;
   }

    return 0;
}
