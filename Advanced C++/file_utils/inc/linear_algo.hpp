#ifndef LINIAR_ALGO_HPP
#define LINIAR_ALGO_HPP
#include "utils.hpp"
#include <vector>
#include <cstddef>

namespace cpp
{

template<typename T>
void createChaos(std::vector<T>& a_vector, size_t n);

template<typename T>
//Require: +.
double sum(std::vector<T> const& a_vector);

template<typename T>
//Require: ==.
void oddsOut(std::vector<T>& a_vector);

template<typename T>
//Require: Comparator <.
std::pair<size_t, size_t> extremes(std::vector<T> const& a_vector);

template<typename T>
//Require: Comparator <.
std::pair<size_t, size_t> extremes2(std::vector<T> const& a_vector);

template<typename T>
size_t CommontStrange(std::vector<T> const& a_first, std::vector<T> const& a_second,  std::vector<T> const& a_third);

template<typename T>
//Require: <.
size_t firstDuplicate(std::vector<T> const& a_vector);

template<typename T>
//Require: <.
size_t findFirstUnique(std::vector<T> const& a_vector);


} //cpp namespace

#include "./inl/linear_algo.hxx"

#endif /*#ifndefLINIAR_ALGOT_H122*/