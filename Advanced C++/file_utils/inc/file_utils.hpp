#ifndef FILE_UTILS_H
#define FILE_UTILS_H
#include <cstddef>
#include <map>
#include <fstream> 
#include <vector>

namespace cpp
{

struct comparBySecond
{
    bool operator()(std::pair<std::string, size_t> &a, std::pair<std::string, size_t> &b)
    {
        return a.second > b.second;
    }
};

int* randomIntArray(size_t n);

void letterFrequency(std::map<char, int> &a_map, std::ifstream& a_file);

void wordFrequency(std::map<std::string, size_t> &map, std::ifstream& a_file);

std::vector<std::pair<std::string, size_t> > topNWords(std::map<std::string, size_t >& a_map, size_t a_numOfTop);


}// cpp namespace

#endif /*#ifndefFILE_UTILS_H*/