#pragma once

#include <vector>
#include <istream>

namespace bf
{

template<typename Instruction>
class CodeSegment
{
public:
    explicit CodeSegment(std::istream& a_stream);
    Instruction getCommand();

    void setProgramCounter(size_t a_index);
    void setStatrLoop();
    void setEndLoop();

    size_t getStatrLoop();
    size_t getEndLoop();
    
    size_t size() const;
    bool isNotEnd();

private:
    std::vector<Instruction> m_code;
    size_t m_programCounter;
    size_t m_statrLoop;
    size_t m_endLoop;
};


}//namespace bf

#include "./inl/bf_code.hxx"
