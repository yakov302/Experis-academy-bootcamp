#pragma once

#include <functional>

#include "working_memory.hpp"
#include "bf_code.hpp"
#include "bf_instructions.hpp"

namespace bf 
{

template<typename Word, typename Instruction> 
class BrainFuckMachine{
public:
    BrainFuckMachine(WorkingMemory<Word>& a_memory, 
                    CodeSegment<Instruction>& a_code, 
                    InstructionSet<Instruction, Word> & a_opCodTable);
    void run();

private:
    void execute(Instruction a_opcode);

private:
    WorkingMemory<Word>& m_memory;
    CodeSegment<Instruction>& m_code;
    InstructionSet<Instruction, Word> & m_opCodeTable;
};


}//namespace bf 

#include "./inl/bf_machine.hxx"