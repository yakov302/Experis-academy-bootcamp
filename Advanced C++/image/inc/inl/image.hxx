#ifndef  IMAEGE_HXX
#define  IMAEGE_HXX

#include <string>
#include <fstream>
#include <unordered_map>
#include <math.h>

namespace cpp
{

template<typename T>
Image<T>::Image(size_t a_x, size_t a_y, std::string a_format, int a_colorScale)
: m_x(a_x)
, m_y (a_y)
, m_format(a_format)
, m_colorScale(a_colorScale)
, m_pixels(new T[a_x*a_y])
{

}

template<typename T>
Image<T>::Image(Image const& a_source)
: m_x(a_source.m_x)
, m_y (a_source.m_y)
, m_format(a_source.m_format)
, m_colorScale(a_source.m_colorScale)
, m_pixels(new T[m_x*m_y])
{
    std::copy(a_source.m_pixels, a_source.m_pixels + (m_x*m_y), m_pixels);
}

template<typename T>
Image<T>::Image(Image&& a_source)
: m_x(a_source.m_x)
, m_y (a_source.m_y)
, m_format(a_source.m_format)
, m_colorScale(a_source.m_colorScale)
, m_pixels(a_source.m_pixels)
{
    a_source.m_pixels = nullptr;
    a_source.m_x = 0;
}

template<typename T>
Image<T>& Image<T>::operator=(Image<T> const& a_source)
{
    if(*this == a_source){return *this;}
    Image<T> temp(a_source);
    swap(temp);
    return *this;
}

template<typename T>
Image<T>& Image<T>::operator=(Image<T>&& a_source)
{
    if(*this == a_source){return *this;}
    Image<T> temp(a_source);
    swap(temp);
    return *this;
}

template<typename T>
Image<T>::~Image()
{
    delete[] m_pixels;
} 

template<typename T>
T Image<T>::getPixel(size_t a_x, size_t a_y)const
{
    if(a_x >= m_x || a_y >= m_y)
    {
        std::cout << "Error: Point outside the image range" << "\n";
        return m_pixels[m_x*m_y];
    }
    return m_pixels[a_x*m_x + a_y];
}

template<typename T>
void Image<T>::setPixel(size_t a_x, size_t a_y, T a_pixel)
{
    if(a_x >= m_x || a_y >= m_y)
    {
        std::cout << "Error: Point outside the image range" << "\n";
        return;
    }
    if(a_pixel > m_colorScale)
    {
        m_pixels[a_x*m_x + a_y] = m_colorScale;
        return;
    }
    if(a_pixel < 0)
    {
        m_pixels[a_x*m_x + a_y] = 0;
        return;
    }
    m_pixels[a_x*m_x + a_y] = a_pixel;
}

template<typename T>
void Image<T>::swap(Image<T>& a_source)
{
    std::swap(a_source.m_x, this->m_x);
    std::swap(a_source.m_y, this->m_y);
    std::swap(a_source.m_format, this->m_format);
    std::swap(a_source.m_colorScale, this->m_colorScale);
    std::swap(a_source.m_pixels, this->m_pixels);
}

template<typename T>
size_t Image<T>::x()const
{
    return m_x;
}

template<typename T>
size_t Image<T>::y()const
{
    return m_y;
}

template<typename T>
T Image<T>::scale()const
{
    return m_colorScale;
}

template<typename T>
std::string Image<T>::format()const
{
    return m_format;
}

template<typename T>
bool Image<T>::operator==(Image const& a_source)
{
    return m_pixels == a_source.m_pixels;
}

template<typename T>  
Image<T> read (std::ifstream& a_image)
{
    std::string format;
    size_t x;
    size_t y;
    T colorScale;
    a_image >> format >> x >> y >> colorScale;
    Image<T> image(x, y,format, colorScale);

    x = 0;
    T pixel;
    while(a_image >> pixel)
    {
        image.setPixel(x, 0, pixel);
        for(size_t i = 1; i < y; ++i)
        {
            a_image >> pixel;
            image.setPixel(x, i,pixel);
        }
        ++x;
    }
    return image;
}

template<typename T>  
void save (Image<T> a_image,  std::ofstream& a_file)
{
    a_file << a_image.format() << "\n";
    a_file << a_image.x() << " " << a_image.y() << "\n";
    a_file << a_image.scale() << "\n";

    for(size_t i = 0 ; i < a_image.x(); ++i)
    {
        for(size_t j = 0 ; j < a_image.y(); ++j)
        {
            a_file << a_image.getPixel(i, j) << " ";
        }
        a_file << "\n";
    }
}

template<typename T>  
Image<T> brighten (Image<T> a_image, int a_factor)
{
    const size_t x = a_image.x();
    const size_t y = a_image.y();
    for(size_t i = 0 ; i < x; ++i)
    {
        for(size_t j = 0 ; j < y; ++j)
        {
            T pixel = a_image.getPixel(i, j);
            pixel += a_factor;
            a_image.setPixel(i, j, pixel);
        }
    }
    return a_image;
}

template<typename T> 
Image<T> changeColorScale(Image<T> a_image, T a_scale)
{
    Image<T> image(a_image.x(), a_image.y(), a_image.format(), a_scale);

    size_t x = a_image.x();
    size_t y = a_image.y();
    for(size_t i = 0 ; i < x; ++i)
    {
        for(size_t j = 0 ; j < y; ++j)
        {
            T pixel = a_image.getPixel(i, j);
            float p = pixel/(float)a_image.scale();
            T fixPixel = p*a_scale;
            image.setPixel(i, j, fixPixel);
        }
    }

    return image;
}

template<typename T> 
Image<T> pixelate(Image<T> a_image)
{
    Image<T> image(a_image.x(), a_image.y(), a_image.format(), a_image.scale());

    size_t x = a_image.x();
    size_t y = a_image.y();
    for(size_t i = 0 ; i < x - 1; i += 2)
    {
        for(size_t j = 0 ; j < y - 1; j += 2)
        {
            T p1 = a_image.getPixel(i, j);
            T p2 = a_image.getPixel(i + 1, j);
            T p3 = a_image.getPixel(i, j + 1);
            T p4 = a_image.getPixel(i + 1, j + 1);
            T ava = (p1 + p2 + p3 + p4)/4;

            image.setPixel(i, j, ava);
            image.setPixel(i + 1, j, ava);
            image.setPixel(i, j + 1, ava);
            image.setPixel(i + 1, j + 1, ava);
        }
    }

    return image;
}


}// namespace cpp

#endif // IMAEGE.HXX
