#pragma once

#include <vector>
#include <istream>
#include <unordered_map>

#include "working_memory.hpp"

namespace bf
{

template<typename Instruction, typename Word>
class InstructionSet
{
public:
    InstructionSet();

    using Lambda = std::function<void(WorkingMemory<Word>&,  CodeSegment<Instruction>&)>;
    auto get(Instruction code) ;
    
private:
    std::unordered_map<Instruction, Lambda> m_opCodeTable;
    Lambda m_nop = [](WorkingMemory<Word>& memory, CodeSegment<Instruction>& code){ };
};


}//namespace bf

#include "./inl/bf_instructions.hxx"
