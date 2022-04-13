#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <queue> 
#include <fstream> 
#include <string>
#include <cassert>
#include "file_utils.hpp"
#include "utils.hpp"

namespace cpp
{

namespace details_impl
{

static void fromMapToPriorityQ(std::map<std::string, size_t >& a_map, std::priority_queue<std::pair<std::string, size_t>,std::vector<std::pair<std::string, size_t> >, comparBySecond >& a_queue, size_t a_max)
{
    using namespace std;

    for(map<string, size_t >::iterator it = a_map.begin(); it != a_map.end(); ++it)
    {
        pair<std::string, size_t> pair(it->first, it->second);

        if(a_queue.size() < a_max)
        {
            a_queue.push(pair);
        }

        else
        {
            if(a_queue.top().second < pair.second)
            {
                a_queue.pop();
                a_queue.push(pair);
            }
        }
    }
}


} //details_impl namespace

void letterFrequency(std::map<char, int>& a_map, std::ifstream& a_file)
{
    char letter;
    while (a_file >> letter) 
    {
       if (isalpha(letter) && a_file.good())
       {
            ++a_map[tolower(letter)];
       }
    }
}

std::string fixWord(std::string word)
{
    int const size = word.size();
	word[0] = tolower(word[0]);

	for(int i = 0; i < size; i++)
	{
	    if(!isalpha(word[i]))
	    {
	        word.resize(i);
            break;
	    }
	}
    return word;
}

void wordFrequency(std::map<std::string, size_t>& a_map, std::ifstream &a_file)
{
    using namespace std;
    string word;

	while(a_file >> word)
	{	
        if(a_file.good())
        {
            ++a_map[fixWord(word)];
        }
	}
}

std::vector<std::pair<std::string, size_t> > topNWords(std::map<std::string, size_t >& a_map, size_t a_numOfTop)
{
    using namespace std;

    priority_queue<pair<string, size_t>, vector<pair<string, size_t> >, comparBySecond > queue;
    details_impl::fromMapToPriorityQ(a_map, queue, a_numOfTop);

    std::vector<std::pair<std::string, size_t> > Top;
    Top.reserve(a_numOfTop);
    
    for(size_t i = 0; i < a_numOfTop; ++i)
    {
        Top.push_back(queue.top());
        queue.pop();
    }

    return Top;
}


}// cpp namespace