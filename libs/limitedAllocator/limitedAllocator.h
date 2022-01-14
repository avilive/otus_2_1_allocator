#ifndef __PRETTY_FUNCTION__
#include "pretty.h"
#endif

#include <iostream>
#include <memory>
//#include <limits>

#define USE_PRETTY 1

template<typename T>
class limitedAllocator
{
public:
    using value_type = T;

    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    template<typename U>
    struct rebind {
        using other = limitedAllocator<U>;
    };

    limitedAllocator() = default;

    ~limitedAllocator() = default;
        
    
    template<typename U>
    limitedAllocator(const limitedAllocator<U>&) {

    }

    T *allocate(std::size_t n) {/*
#ifndef USE_PRETTY
        std::cout << "allocate: [n = " << n << "]" << std::endl;
#else
        std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;
#endif*/


        auto p = std::malloc(n * sizeof(T));
        if (!p || ((mAllocations+n)>maxAllocations + 1))
            throw std::bad_alloc();

        mAllocations+=n;
      //  std::cout << "mAllocations = " << mAllocations << std::endl;
        return reinterpret_cast<T *>(p);
    }

    void deallocate(T *p, std::size_t n) {
        /*
#ifndef USE_PRETTY
        std::cout << "deallocate: [n  = " << n << "] " << std::endl;
#else
        std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;
#endif*/
        std::free(p);
    }

    template<typename U, typename ...Args>
    void construct(U *p, Args &&...args) {
/*#ifndef USE_PRETTY
        std::cout << "construct" << std::endl;
#else
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif*/
        new(p) U(std::forward<Args>(args)...);
    };
    
    
    //template<typename U> //???
    void destroy(T *p) {
/*#ifndef USE_PRETTY
        std::cout << "destroy" << std::endl;
#else
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif*/
        p->~T();
    }
private:
    std::size_t  mAllocations=0;
    const std::size_t maxAllocations = 10;
};
