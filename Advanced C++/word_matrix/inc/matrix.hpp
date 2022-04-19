#ifndef MATRIX_HPP
#define MATRIX_HPP

#include<string>
#include <cstring>


template<typename T>  
class Matrix
{
public:
    Matrix(size_t a_x = 1, size_t a_y = 1);
    Matrix(Matrix const& a_source) = delete;
    Matrix& operator=(Matrix const& a_source) = delete;
    ~Matrix();
   
    T get(size_t a_x, size_t a_y) const;
    void set(size_t a_x, size_t a_y, T a_value);
    size_t getXindex()const;
    size_t getYindex()const;

private:
    T** m_matrix;
    size_t m_x;
    size_t m_y;
};

template<typename T>  
bool isExists(Matrix<T> const& a_matrix, T a_value);

#include "matrix.hxx"

#endif //MATRIX.HPP