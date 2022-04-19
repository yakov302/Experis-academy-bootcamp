#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>

#include "matrix.hpp"

namespace arrowword
{

using containerLUT =  std::unordered_map<std::string, std::vector<std::string>>;
using Lambda = std::function<void(containerLUT&)>;
using functionsLUT = std::unordered_map<std::string, Lambda>;
using matrixPtr = std::unique_ptr<Matrix<std::string>>;
using matrixCoordinates = std::pair<size_t, size_t>;

class FillContainer
{
public:
    FillContainer(std::ifstream& a_matrix, containerLUT& a_linesByDirection);
    Lambda fillByDirection(std::string a_direction);

private:
    void BuildFunctionsLUT();
    void BuildMatrix(std::ifstream& a_matrix);
    void fillMatrix(std::ifstream& a_matrix);
    matrixCoordinates matrixSize(std::ifstream& a_matrix);

private:
    size_t m_x;
    size_t m_y; 
    matrixPtr m_matrix;
    functionsLUT m_functions; 
    Lambda m_fill = [](containerLUT& a_linesByDirection){ };
  
};

}//arrowword namespace