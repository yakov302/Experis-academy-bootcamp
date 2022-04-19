namespace bf 
{

template<typename Word>
WorkingMemory<Word>::WorkingMemory(size_t a_capacity)
: m_memory(a_capacity)
, m_index(a_capacity / 2)
{  

}
    
template<typename Word>
void WorkingMemory<Word>::forward()
{
    ++m_index;
}

template<typename Word>
void WorkingMemory<Word>::backword()
{
    --m_index;
}

template<typename Word>
Word WorkingMemory<Word>::read() const 
{
    return m_memory[m_index];
}

template<typename Word>
void WorkingMemory<Word>::write(Word a_value)
{
    m_memory[m_index] = a_value;
}

template<typename Word>
void WorkingMemory<Word>::debug() const 
{
    for(auto w : m_memory)
    std::cout << w << ' ';
    std::cout << '\n';
}


}//namespace bf 