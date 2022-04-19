
#ifndef MATRIX_HXX
#define MATRIX_HXX

template<typename T>
Matrix<T>::Matrix(size_t a_x, size_t a_y)
: m_x(a_x)
, m_y (a_y)
{
    m_matrix = new T*[a_x];
    for(size_t i = 0; i < a_x; ++i)
    {
        m_matrix[i] = new T[a_y];
    }
}

template<typename T>
 Matrix<T>::~Matrix()
{
    for(size_t i = 0; i < m_x; ++i)
    {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
} 

template<typename T>
T Matrix<T>::get(size_t a_x, size_t a_y)const
{
    if(a_x >= m_x || a_y >= m_y)
    {
        std::cout << "Error: Point outside the matrix range" << "\n";
        return m_matrix[m_x - 1][m_y - 1];;
    }
    return m_matrix[a_x][a_y];
}

template<typename T>
size_t Matrix<T>::getXindex()const
{
    return m_x;
}

template<typename T>
size_t Matrix<T>::getYindex()const
{
    return m_y;
}

template<typename T>
void Matrix<T>::set(size_t a_x, size_t a_y, T a_value)
{
    if(a_x >= m_x || a_y >= m_y)
    {
        std::cout << "Error: Point outside the matrix range" << "\n";
        return;
    }
    m_matrix[a_x][a_y] = a_value;
}

template<typename T>
bool isExists(Matrix<T> const& a_matrix, T a_value)
{
    T const indexX = a_matrix.getXindex();
    T i;
    for(i = 0 ; i < indexX; ++i)
    {
            T const indexY = a_matrix.getXindex();
            for(T j = 0 ; j < indexY; ++j)
            {
                if(a_matrix.get(i, j) == a_value)
                {
                    return true;
                }
                if(a_matrix.get(i, j) > a_value)
                {
                    break;
                }
            }
    }
    return false;
}

#endif //MATRIX.HXX
