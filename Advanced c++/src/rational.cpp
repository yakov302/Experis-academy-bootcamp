#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include "rational.hpp"
#include "utils.hpp"

namespace numbers{

Rational::Rational(int a_numerator, int a_denominator, bool a_redused)
  :m_numerator(a_numerator)
  ,m_denominator (a_denominator)
  ,m_redused(a_redused)
{
	assert(a_denominator != 0);
	if(a_denominator < 0)
	{
		m_numerator *= (-1);
		m_denominator *= (-1);
	}

	if(a_numerator == 0)
	{
		m_denominator = 1;
		return;
	}

	if(m_redused)
	{
		reduce();
	}
}

void Rational::add(Rational a_rational)
{
	m_numerator = (m_numerator * a_rational.m_denominator) + (m_denominator * a_rational.m_numerator);
    m_denominator = m_denominator * a_rational.m_denominator;
	if(m_redused)
	{
		reduce();
	}
	axioms();
}

void Rational::sub(Rational a_rational)
{
	m_numerator = (m_numerator * a_rational.m_denominator) - (m_denominator * a_rational.m_numerator);
    m_denominator = m_denominator * a_rational.m_denominator;
	if(m_redused)
	{
		reduce();
	}
	axioms();
}

void Rational::mul(Rational a_rational)
{	
	m_numerator = a_rational.m_numerator * m_numerator; 
	m_denominator = a_rational.m_denominator * m_denominator;
	if(m_redused)
	{
		reduce();
	}
	axioms();
}

void Rational::div(Rational a_rational)
{	
	m_numerator = (m_numerator * a_rational.m_denominator);
    m_denominator =  (m_denominator * a_rational.m_numerator);

	if(m_denominator < 0)
	{
		m_numerator *= (-1);
		m_denominator *= (-1);
	}
	if(m_redused)
	{
		reduce();
	}
	axioms();
}

Rational& Rational::operator+=(Rational const& a_rational)
{
  	this->add(a_rational);
	return *this;
}

Rational& Rational::operator-=(Rational const& a_rational)
{
  	this->sub(a_rational);
	return *this;
}

Rational& Rational::operator*=(Rational const& a_rational)
{
  	this->mul(a_rational);
	return *this;
}

Rational& Rational::operator/=(Rational const& a_rational)
{
  	this->div(a_rational);
	return *this;
}

Rational& Rational::operator++()
{
	this->add(1);
	return *this;
}

Rational Rational::operator++(int)
{
	Rational opening = *this;
	++ *this;
	return opening;
}

Rational& Rational::operator--()
{
	this->sub(1);
	return *this;
}

Rational Rational::operator--(int)
{
	Rational opening = *this;
	this->sub(1);
	return opening;
}

Rational Rational::operator-()const
{
	Rational opening(*this);
	opening.m_numerator = -opening.m_numerator;
	return opening;
}

Rational const& Rational::operator+()const
{
	return *this;
}

void Rational::reduce()
{
int num1 = (int) abs((double)m_numerator);
int num2 = (int) abs((double)m_denominator);
int min;
int max;

	if(m_numerator == 0)
	{
		m_denominator = 1;
		return;
	}

	 if(num1 <= num2)
	 {
		 min = num1;
		 max = num2;
	 }
	 else
	 {
		min = num2;
		max = num1;
	 }
		
	for(int i = min; i > 0; i--)
	{
		if(min % i == 0 && max % i == 0)
		{
			m_numerator = m_numerator/i;
			m_denominator = m_denominator/i;
			break;
		}
	}

	axioms();
}

void Rational::inverse()
{	
	assert(m_numerator != 0);
	swapInt(&m_numerator, &m_denominator);
	if(m_denominator < 0)
	{
		m_numerator *= (-1);
		m_denominator *= (-1);
	}
	if(m_redused)
	{
		reduce();
	}
	axioms();
}

void Rational::display() const
{
	printf("%d/%d\n", m_numerator, m_denominator);
	axioms();
}

int Rational::getNumerator() const
{
	axioms();
	return m_numerator;
}

int Rational::getDenominator() const
{
	axioms();
	return m_denominator;
}

int Rational::compare(Rational a_rational) const
{
 double num1 =  (double) getNumerator()/getDenominator(); 
 double num2 =  (double) a_rational.getNumerator()/a_rational.getDenominator(); 

	if(num1 > num2)
	{
		axioms();
		return 1;
	}
	if(num1 < num2)
	{
		axioms();
		return -1;
	}

axioms();
return 0;
}

bool Rational::equal(Rational a_rational) const
{
	bool result = (getNumerator() == a_rational.getNumerator() && getDenominator() == a_rational.getDenominator());
	axioms();
	return result;
}

 bool Rational::notEqual(Rational a_rational) const
 {
	bool result = ( !!! (getNumerator() == a_rational.getNumerator() && getDenominator() == a_rational.getDenominator()));
	axioms();
	return result;
 }

void Rational::axioms() const
{
	assert(m_denominator != 0);
}

 Rational::operator double()const
{
	return double(m_numerator)/m_denominator;
}

std::ostream& Rational::print(std::ostream& a_os)const
{
	a_os << m_numerator << "/" << m_denominator;
	return a_os;
}

std::ostream& Rational::printAsDouble(std::ostream& a_os)const
{
	a_os << double(*this);
	return a_os;
}

Rational add(Rational a_first, Rational a_second)
{
	Rational result = a_first;
	result.add(a_second);
	return result;
}

Rational sub(Rational a_first, Rational a_second)
{
	Rational result = a_first;
	result.sub(a_second);
	return result;
}

Rational mul(Rational a_first, Rational a_second)
{
	Rational result = a_first;
	result.mul(a_second);
	return result;
}

Rational div(Rational a_first, Rational a_second)
{
	Rational result = a_first;
	result.div(a_second);
	return result;
}

Rational operator+(Rational const& a_first, Rational const& a_second)
{
	Rational result = a_first;
	result.add(a_second);
	return result;
}

Rational operator-(Rational const& a_first, Rational const& a_second)
{
	Rational result = a_first;
	result.sub(a_second);
	return result;
}

Rational operator*(Rational const& a_first, Rational const& a_second)
{
	Rational result = a_first;
	result.mul(a_second);
	return result;
}

Rational operator/(Rational const& a_first, Rational const& a_second)
{
	Rational result = a_first;
	result.div(a_second);
	return result;
}

bool operator==(Rational const& a_first, Rational const& a_second)
{
	return a_first.equal(a_second);
}

bool operator!=(Rational const& a_first, Rational const& a_second)
{
	return a_first.notEqual(a_second);
}

bool operator<(Rational const& a_first, Rational const& a_second)
{
	if(a_first.compare(a_second) == -1)
	{
		return true;
	}
	return false;
}

bool operator>(Rational const& a_first, Rational const& a_second)
{
	return !(a_first < a_second) && !(a_first == a_second);
}

bool operator>=(Rational const& a_first, Rational const& a_second)
{
	return (a_first > a_second) || (a_first == a_second);
}

bool operator<=(Rational const& a_first, Rational const& a_second)
{
	return (a_first < a_second) || (a_first == a_second);
}

std::ostream& operator<<(std::ostream& a_os, Rational const& a_rational)
{
	return a_rational.print(a_os);
}


} //namespace numbers