#pragma once

#include <vector>

namespace bf 
{

template<typename Word>
class WorkingMemory
{
public:
    explicit WorkingMemory(size_t a_capacity = 1024);
    
    void forward();
    void backword();

    Word read() const;
    void write(Word a_value);

    void debug() const;
private:
    std::vector<Word> m_memory;
    size_t m_index;
};


}//namespace bf 

#include "./inl/working_memory.hxx"