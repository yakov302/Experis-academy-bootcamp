#pragma once

namespace bf
{

template<typename Instruction>
CodeSegment<Instruction>::CodeSegment(std::istream& a_codeStream) 
: m_code{}
, m_programCounter{0}
, m_statrLoop{0}
, m_endLoop{0}
{
    Instruction opcode{};
    while (a_codeStream >> opcode) {
        m_code.push_back(opcode);
    }
    //m_code.push_back(halt);
}

template<typename Instruction>
Instruction CodeSegment<Instruction>::getCommand()
{
    //assert
    return m_code[m_programCounter++];    
}

template<typename Instruction>
auto CodeSegment<Instruction>::size() const -> size_t
{
    return m_code.size();
}

template<typename Instruction>
void CodeSegment<Instruction>::setProgramCounter(size_t a_index)
{
   m_programCounter = a_index;
}

template<typename Instruction>
void CodeSegment<Instruction>::setStatrLoop()
{
    m_statrLoop = m_programCounter;
}

template<typename Instruction>
void CodeSegment<Instruction>::setEndLoop()
{
    m_endLoop = m_programCounter;
}

template<typename Instruction>
size_t CodeSegment<Instruction>::getStatrLoop()
{
    return m_statrLoop;
}

template<typename Instruction>
size_t CodeSegment<Instruction>::getEndLoop()
{
    return m_endLoop;
}

template<typename Instruction>
bool CodeSegment<Instruction>::isNotEnd()
{
    return m_programCounter < m_code.size();
}


}//namespace bf

