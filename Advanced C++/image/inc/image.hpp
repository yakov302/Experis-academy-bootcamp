#ifndef IMAEGE_HPP
#define  IMAEGE_HPP

#include <string>
#include <cstring>

namespace cpp
{

template<typename T>  
class Image
{
public:
    Image(size_t a_x = 1, size_t a_y = 1, std::string a_format = "P2", int a_colorScale = 255);
    Image(Image const& a_source);
    Image(Image&& a_source);
    Image& operator=(Image const& a_source);
    Image<T>& operator=(Image<T>&& a_source);
    ~Image();
   
    T getPixel(size_t a_x, size_t a_y) const;
    void setPixel(size_t a_x, size_t a_y, T a_value);
    void swap(Image<T>& a_source);

    size_t x()const;
    size_t y()const;
    T scale()const;
    std::string format()const;

    bool operator==(Image const& a_source);

private:
    size_t m_x;
    size_t m_y;
    std::string m_format;
    T m_colorScale;
    T* m_pixels;
};

template<typename T>  
Image<T> read (std::ifstream& a_image);

template<typename T>  
void save (Image<T> a_image, std::ofstream& a_file);

template<typename T>  
Image<T> brighten (Image<T> a_image, int a_factor);

template<typename T> 
Image<T> changeColorScale(Image<T> a_image, T a_scale);

template<typename T> 
Image<T> pixelate(Image<T> a_image);


} // namespace cpp

#include "./inl/image.hxx"

#endif // IMAEGE.HPP