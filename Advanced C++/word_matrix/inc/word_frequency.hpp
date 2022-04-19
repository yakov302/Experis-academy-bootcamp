#include <fstream>
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>

namespace arrowword
{

using stringVector = std::vector<std::string>;
using resultLUT = std::unordered_map<std::string, size_t>;

class WordFrequency
{
public:
    WordFrequency(stringVector& a_lines, std::ifstream& a_words);
    void generateWordFrequency(resultLUT& a_wordsLUT);

private:
    void wordsLoop(resultLUT& a_wordsLUT, std::string& a_line);
    void calculateFrequency(resultLUT& a_wordsLUT, std::string& a_line, std::string& a_word);

private:
    stringVector& m_lines;
    stringVector m_words;
};


}//arrowword namespace