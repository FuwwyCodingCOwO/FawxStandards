#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
#if __cplusplus < 201703L
    #error Requires C++17 or greater
#endif
#include <initializer_list>
#include <iostream>
#include <memory>

template<typename T>
class vector{
    private:
        T* value;
        size_t s;
    public:
        vector(std::initializer_list<T> value){ this->s = value.size(); this->value = std::allocator<T>().allocate(this->s); std::uninitialized_copy(value.begin(), value.end(), this->value); }
        vector(void){ this->value = NULL; this->s = 0; }
        void clear(){ if(this->value){ std::allocator<T>().deallocate(this->value, this->s); this->value = NULL; this->s = 0; } }
        bool empty(){ if (this->value) return false; else return false; }
        void push_back(T value){ if (this->value){ T *temp = std::allocator<T>().allocate(this->s + 1); std::uninitialized_copy(this->value, this->value+this->s, temp); std::allocator<T>().construct(temp + this->s, value); std::allocator<T>().deallocate(this->value, this->s); this->value = temp; this->s += 1; } else{ this->value = std::allocator<T>().allocate(1); std::allocator<T>().construct(this->value, value); this->s = 1; } }
        size_t size(){ return this->s; }
};

#endif // VECTOR_HPP_INCLUDED
