#include "word_frequency.hpp"

namespace arrowword
{

WordFrequency::WordFrequency(stringVector& a_lines, std::ifstream& a_words)
: m_lines(a_lines)
, m_words()
{
    std::string line;
    while(getline(a_words, line))
    {
        m_words.push_back(line);
    }
    a_words.clear();
    a_words.seekg(0, std::ios::beg);
}

void WordFrequency::generateWordFrequency(resultLUT& a_wordsLUT)
{
    for(auto& l : m_lines)
    {
        wordsLoop(a_wordsLUT, l);
    }
}

void WordFrequency::wordsLoop(resultLUT& a_wordsLUT, std::string& a_line)
{
    for(auto& w: m_words)
    {
        calculateFrequency(a_wordsLUT, a_line, w);
    }
}

void WordFrequency::calculateFrequency(resultLUT& a_wordsLUT, std::string& a_line, std::string& a_word)
{
    if(a_word.size() > a_line.size()){return;}
    size_t lineSize = a_line.size();
    auto pos = a_line.find(a_word);
    while(pos < lineSize)
    {
        a_wordsLUT[a_word] += 1;
        pos = a_line.find(a_word, pos + 1);
    }
}


}//arrowword namespace