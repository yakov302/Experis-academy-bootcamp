#include "fill_container.hpp"

namespace arrowword
{

FillContainer::FillContainer(std::ifstream& a_matrix, containerLUT& a_linesByDirection)
: m_functions(8)
{
    BuildMatrix(a_matrix);
    BuildFunctionsLUT();  
}

void FillContainer::BuildFunctionsLUT()
{
    m_functions["r"] = [this](containerLUT& a_linesByDirection)
    {
        std::vector<std::string> m_lines;
        for(size_t i = 0; i < m_y; ++i)
        {
            std::string line;
            for(size_t j = 0; j < m_x; ++j)
            {
                line += m_matrix->get(j, i);
            }
            m_lines.push_back(line);
        }
        a_linesByDirection["r"] = m_lines;
    };

    m_functions["l"] = [this](containerLUT& a_linesByDirection)
    {
        std::vector<std::string> m_lines;
        for(size_t i = 0; i < m_y; ++i)
        {
            std::string line;
            for(size_t j = m_x - 1; j >= 0 && j < m_x; --j)
            {
                line += m_matrix->get(j, i);
            }
            m_lines.push_back(line);
        }
        a_linesByDirection["l"] = m_lines;
    };

    m_functions["u"] = [this](containerLUT& a_linesByDirection)
    {
        std::vector<std::string> m_lines;
        for(size_t i = 0; i < m_x; ++i)
        {
            std::string line;
            for(size_t j = 0; j < m_y; ++j)
            {
                line += m_matrix->get(i, j);
            }
            m_lines.push_back(line);
        }      
        a_linesByDirection["u"] = m_lines;
    };

    m_functions["d"] = [this](containerLUT& a_linesByDirection)
    {
        std::vector<std::string> m_lines;
        for(size_t i = 0; i < m_x; ++i)
        {
            std::string line;
            for(size_t j = m_y - 1 ; j >= 0 && j < m_y; --j)
            {
                line += m_matrix->get(i, j);
            }
            m_lines.push_back(line);
        }
        a_linesByDirection["d"] = m_lines;
    };

    m_functions["y"] = [this](containerLUT& a_linesByDirection)
    {
        std::vector<std::string> m_lines;
        for(size_t i = 0; i < m_x; ++i)
        {
            std::string line;
            for(size_t j = 0 ; j < m_y; ++j)
            {
                if(i + j >= m_x){ break;} 
                line += m_matrix->get(i + j , j);
            }
            m_lines.push_back(line);
        }

        for(size_t i = 1; i < m_y; ++i)
        {
            std::string line;
            for(size_t j = 0; j < m_y - i; ++j)
            {
                line += m_matrix->get(j, i + j);
            }
            m_lines.push_back(line);
        }
        a_linesByDirection["y"] = m_lines;
    };

    m_functions["x"] = [this](containerLUT& a_linesByDirection)
    {
        std::vector<std::string> m_lines;
        for(size_t i = m_x - 1; i >= 0 && i < m_x; --i)
        {
            std::string line;
            for(size_t j = 0 ; j < m_y; ++j)
            {
                if(i - j < 0 || i - j >= m_x){ break;}
                line += m_matrix->get(i - j , j);
            }
        m_lines.push_back(line);
        }

        for(size_t i = 0; i < m_y; ++i)
        {
            size_t y = i;
            std::string line;
            for(size_t j = m_x -1 ; y < m_y - 1; --j)
            {
                y += 1;
                line += m_matrix->get(j, y);
            }
            m_lines.push_back(line);
        }
        a_linesByDirection["x"] = m_lines;
    };

    m_functions["t"] = [this](containerLUT& a_linesByDirection)
    {
        std::vector<std::string> m_lines;
        for(size_t i = m_x - 1; i >= 0 && i < m_x; --i)
        {
            std::string line;
            for(size_t j = 0 ; j < m_y; ++j)
            {
                if(i - j < 0 || i - j >= m_x){ break;}
                line += m_matrix->get(i - j , j);
            }
            std::reverse(line.begin(), line.end());
            m_lines.push_back(line);
        }

        for(size_t i = 0; i < m_y; ++i)
        {
            size_t y = i;
            std::string line;
            for(size_t j = m_x -1 ; y < m_y - 1; --j)
            {
                y += 1;
                line += m_matrix->get(j, y);
            }
            std::reverse(line.begin(), line.end());
            m_lines.push_back(line);
        }
        a_linesByDirection["t"] = m_lines;
    };

    m_functions["z"] = [this](containerLUT& a_linesByDirection)
    {
        std::vector<std::string> m_lines;
        for(size_t i = 0; i < m_x; ++i)
        {
            std::string line;
            for(size_t j = 0 ; j < m_y; ++j)
            {
                if(i + j >= m_x){ break;} 
                line += m_matrix->get(i + j , j);
            }
            std::reverse(line.begin(), line.end());
            m_lines.push_back(line);
        }

        for(size_t i = 1; i < m_y; ++i)
        {
            std::string line;
            for(size_t j = 0; j < m_y - i; ++j)
            {
                line += m_matrix->get(j, i + j);
            }
            std::reverse(line.begin(), line.end());
            m_lines.push_back(line);
        }
        a_linesByDirection["z"] = m_lines;
    };  
}

Lambda FillContainer::fillByDirection(std::string a_direction)
{
    auto it = m_functions.find(a_direction);
    if (it == m_functions.end())
    {
        return m_fill;
    }
    return it->second;
}

void FillContainer::BuildMatrix(std::ifstream& a_matrix)
{
    std::pair<size_t, size_t> coordinates = matrixSize(a_matrix);
    m_x = coordinates.first;
    m_y = coordinates.second;
    m_matrix = std::unique_ptr<Matrix<std::string>>(new Matrix<std::string>(m_x, m_y));
    fillMatrix(a_matrix);
}
    
std::pair<size_t, size_t> FillContainer::matrixSize(std::ifstream &a_matrix)
{
    std::pair<size_t, size_t> coordinates;
    std::string line;
    size_t count = 1;

    getline(a_matrix, line);
    coordinates.first = line.size();

    while (getline(a_matrix, line))
    {
        std::reverse(line.begin(), line.end());
        ++count;
    }

    coordinates.second = count;
    return coordinates;
}

void FillContainer::fillMatrix(std::ifstream &a_matrix)
{
    a_matrix.clear();
    a_matrix.seekg(0, std::ios::beg);

    std::string line;
    for (size_t i = 0; i < m_y; ++i)
    {
        getline(a_matrix, line);
        for (size_t j = 0; j < m_x; ++j)
        {
            std::string Letter;
            Letter = line[j];
            m_matrix->set(j, i, Letter);
        }
    }
}


} // arrowword namespace