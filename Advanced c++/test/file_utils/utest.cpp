#include "mu_test.h"
#include "linear_algo.hpp"
#include "file_utils.hpp"
#include "utils.hpp"
#include "ball.hpp"
#include <vector>
#include <map>

BEGIN_TEST(freq_letter)
   
    using namespace std;
	using namespace cpp;

    map<char, int> letterMap;
	ifstream file("./book.txt");
    letterFrequency(letterMap ,file);

	printf("----------------------\n");
    for (std::map<char, int>::iterator it = letterMap.begin(); it != letterMap.end(); ++it) 
    {
		printf("  %-2c | ", it-> first);
 		printf(" %-6d times  |\n", it->second);
 		printf("----------------------\n");
    }
    ASSERT_PASS();

END_TEST


BEGIN_TEST(freq_word)
   
    using namespace std;
	using namespace cpp;

    map<std::string, size_t> wordMap;
    ifstream file("./book.txt");
    wordFrequency(wordMap, file);

	printf("-------------------\n");
    for (std::map<std::string, size_t>::iterator it = wordMap.begin(); it != wordMap.end(); ++it) 
    {
		std::cout << it->first <<"   ";
		std::cout << it->second <<" \n";
 	//	printf(" %-5ld times |\n", it->second);
 		printf("-------------------\n");
    }
    ASSERT_PASS();

END_TEST


BEGIN_TEST(topNWords_test)
   
	using namespace cpp;
	using namespace std;

	size_t const N = 10;
	map<std::string, size_t> wordMap;
    ifstream file("./book.txt");
    wordFrequency(wordMap, file);

	std::vector<std::pair<std::string, size_t> > result;
	result = topNWords(wordMap, N);

	for(size_t i = 0; i < N; i++)
	{
		std::cout  << result[i].first << " " << result[i].second << "\n";
	}
    ASSERT_PASS();

END_TEST

BEGIN_SUITE(TEST)

	TEST(freq_word)
	TEST(freq_letter)
	TEST(topNWords_test)

END_SUITE
