#pragma once

namespace bf
{

template<typename Instruction, typename Word>
InstructionSet<Instruction, Word>::InstructionSet()
: m_opCodeTable{16}
{
    m_opCodeTable['+'] = [](WorkingMemory<Word>& memory, CodeSegment<Instruction>& code){
        auto w = memory.read();
        ++w;
        memory.write(w);
    };

    m_opCodeTable.insert( std::make_pair('-',  [](WorkingMemory<Word>& memory, CodeSegment<Instruction>& code){
        auto w = memory.read();
        --w;
        memory.write(w);
    }));

    m_opCodeTable['>'] = [](WorkingMemory<Word>& memory, CodeSegment<Instruction>& code){
        memory.forward();
    };

    m_opCodeTable['.'] = [](WorkingMemory<Word>& memory, CodeSegment<Instruction>& code){
        std::cout <<  static_cast<char>(memory.read());
    };

    m_opCodeTable[','] = [this]( WorkingMemory<Word>& memory, CodeSegment<Instruction>& code){
        auto w = memory.read();
        std::cin >> w;
        memory.write(w);
    };

    m_opCodeTable['<'] = [](WorkingMemory<Word>& memory, CodeSegment<Instruction>& code){
        memory.backword();
    };

    m_opCodeTable['!'] = [](WorkingMemory<Word>& memory, CodeSegment<Instruction>& code){
        memory.write(-memory.read());
    };

    m_opCodeTable['['] = [](WorkingMemory<Word>& memory, CodeSegment<Instruction>& code){
        code.setStatrLoop();
        if(memory.read() == 0)
        {
            code.setProgramCounter(code.getEndLoop() + 1);
        }
    };

    m_opCodeTable[']'] = [](WorkingMemory<Word>& memory, CodeSegment<Instruction>& code){
        code.setEndLoop();
        if(memory.read() != 0)
        {
            code.setProgramCounter(code.getStatrLoop());
        }
    };

    m_opCodeTable['2'] = [](WorkingMemory<Word>& memory, CodeSegment<Instruction>& code){
        memory.write(2*memory.read());
    };    
}

template<typename Instruction, typename Word>
auto InstructionSet<Instruction, Word>::get(Instruction code) 
{
    auto it = m_opCodeTable.find(code);
    if(it == m_opCodeTable.end() ){
        return m_nop;
    }
    return it->second;
}


}//namespace bf

