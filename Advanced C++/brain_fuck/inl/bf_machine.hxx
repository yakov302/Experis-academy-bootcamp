#pragma once

#include "../bf_instructions.hpp"

namespace bf 
{

template<typename Word, typename Instruction> 
BrainFuckMachine<Word, Instruction>::BrainFuckMachine(WorkingMemory<Word>& a_memory, 
                                                      CodeSegment<Instruction>& a_code,
                                                      InstructionSet<Instruction, Word> & a_opCodTable)
: m_memory{a_memory}
, m_code{a_code}
, m_opCodeTable{a_opCodTable}
{        

}

template<typename Word, typename Instruction> 
void BrainFuckMachine<Word, Instruction>::run()
{
    while( m_code.isNotEnd()){
        auto opcode = m_code.getCommand();        
        execute(opcode);
    }
}

template<typename Word, typename Instruction> 
void BrainFuckMachine<Word, Instruction>::execute(Instruction a_opcode)
{
    m_opCodeTable.get(a_opcode)(m_memory, m_code);
}


}//namespace bf 


