#include "word_matrix.hpp"

namespace arrowword
{

WordMatrix::WordMatrix(std::ifstream& a_matrixFile, std::ifstream& a_wordsFile, std::string& a_directions, std::ofstream& a_resultFile)
: m_result()
, m_directions(a_directions)
, m_wordsFile(a_wordsFile)
, m_resultFile(a_resultFile)
, m_matrixFile(a_matrixFile)
, m_fillContainer(m_matrixFile, m_linesByDirection)
, m_linesByDirection(8)
{
    m_directions = removeDuplicates(a_directions);
    size_t numOfDirections = m_directions.size();
    for(size_t i = 0; i < numOfDirections; ++i)
    {
        std::string direction;
        direction = m_directions[i];
        m_fillContainer.fillByDirection(direction)(m_linesByDirection);
    }
}

std::string WordMatrix::removeDuplicates(std::string& a_directions)
{
    std::unordered_set<char> unique{a_directions.begin(), a_directions.end()};
    return std::string{unique.begin(), unique.end()};
}

void WordMatrix::generateResult()
{
    size_t numOfDirection = m_directions.size();
    for(size_t i = 0; i < numOfDirection; ++i) 
    {
        std::string direction;
        direction = m_directions[i];
        WordFrequency w(m_linesByDirection[direction], m_wordsFile);
        w.generateWordFrequency(m_result);
    }

    for(auto& e : m_result) 
    {
        m_resultFile << e.first << ": " << e.second << "\n";
    }
}


}//arrowword namespace