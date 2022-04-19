
#include <vector>
#include <fstream>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include "fill_container.hpp"
#include "word_frequency.hpp"

namespace arrowword
{

using containerLUT =  std::unordered_map<std::string, std::vector<std::string>>;
using resultLUT = std::unordered_map<std::string, size_t>;

class WordMatrix
{
public:
    WordMatrix(std::ifstream& a_matrixFile, std::ifstream& a_wordsFile, std::string& a_directions, std::ofstream& a_resultFile);
    void generateResult();

private:
    std::string removeDuplicates(std::string& a_directions);

private:
    resultLUT m_result;
    std::string& m_directions;
    std::ifstream& m_wordsFile;
    std::ofstream& m_resultFile;
    std::ifstream& m_matrixFile;
    FillContainer m_fillContainer;
    containerLUT m_linesByDirection;
};
        

}//arrowword namespace