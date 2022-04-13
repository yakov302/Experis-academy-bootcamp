#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

namespace numbers{

class Rational
{
public:
	Rational(int a_numerator = 0, int a_denominator = 1, bool a_redused = true);

	void add(Rational a_rational);
	void sub(Rational a_rational);
	void mul(Rational a_rational);
	void div(Rational a_rational);

	Rational& operator+=(Rational const& a_rational);
	Rational& operator-=(Rational const& a_rational);
	Rational& operator*=(Rational const& a_rational);
	Rational& operator/=(Rational const& a_rational);

	Rational& operator++();
	Rational operator++(int);
	Rational& operator--();
	Rational operator--(int);

	Rational operator-()const;
	Rational const& operator+()const;

	void reduce();
	void inverse();
	void display() const;

	int getNumerator() const;
	int getDenominator() const;

	int compare(Rational a_rational) const;
	bool equal(Rational a_rational) const;
	bool notEqual(Rational a_rational) const;

	operator double()const;
	std::ostream& print(std::ostream& a_os)const;
	std::ostream& printAsDouble(std::ostream& a_os)const;

private:
	void axioms() const;

private:
	int m_numerator;
	int m_denominator;
	bool m_redused;
};

Rational add(Rational a_first, Rational a_second);
Rational sub(Rational a_first, Rational a_second);
Rational mul(Rational a_first, Rational a_second);
Rational div(Rational a_first, Rational a_second);

Rational operator+(Rational const& a_first, Rational const& a_second);
Rational operator-(Rational const& a_first, Rational const& a_second);
Rational operator*(Rational const& a_first, Rational const& a_second);
Rational operator/(Rational const& a_first, Rational const& a_second);

bool operator==(Rational const& a_first, Rational const& a_second);
bool operator!=(Rational const& a_first, Rational const& a_second);
bool operator<(Rational const& a_first, Rational const& a_second);
bool operator>(Rational const& a_first, Rational const& a_second);
bool operator>=(Rational const& a_first, Rational const& a_second);
bool operator<=(Rational const& a_first, Rational const& a_second);

std::ostream& operator<<(std::ostream& a_os, Rational const& a_rational);

} //namespace numbers

#endif /*#ifndef RATIONAL_H */


