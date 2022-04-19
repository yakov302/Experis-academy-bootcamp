#include "word_matrix.hpp"

int main (int argc, char* argv[])
{
    std::ifstream matrixFile(argv[1]);
    std::ifstream wordsFile(argv[2]);
    std::ofstream resultFile(argv[3]);
    std::string directions = argv[4];

    arrowword::WordMatrix a(matrixFile, wordsFile, directions, resultFile);
    a.generateResult();
}

/*   
cmd:
    make
   ./main ../files/matrix.txt ../files/words.txt ../files/result.txt rludyxtz
*/
