#include <cstddef>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <math.h>
#include <cctype>

#include "big_integer.hpp"
#include "hash_set.hpp"

static int giveMeSign(long n);
static int convert2digit(char c);
static int checkSign(char c);
static bool checkIfNumber(char c);
static void zeroPadding(LinkedList<int>& a_first, LinkedList<int>& a_second);
static int enter(int n);
static int remainder(int n);
static void clean(LinkedList<int>& a_list);
static int checkSigns(int first, int second);
static void swapArr(int* First, int* Second, int a_len);
static int checkBiggest(int* First, int* Second, int a_len);
static void moveToArray(LinkedList<int> first, int* First, LinkedList<int> second, int* Second);
static void lend(int* First, int a_frome);
static void DeleteZeros(LinkedList<int>& a_list);
static void PutZeros(LinkedList<int>& a_list, int n);
static char convert2char(int n);

String::String()
: m_str()
{
}

 String::String(String const& source)
: m_str(new char[strlen(source.m_str)])
{
    memcpy(m_str, source.m_str, sizeof(char)*strlen(source.m_str)); 
}

String& String::operator=(String const& source)
{
    char* newArr = new char[sizeof(char)*strlen(source.m_str)];
    memcpy(newArr, source.m_str, sizeof(int)*strlen(source.m_str)); 
    delete[]m_str;
    m_str = newArr;
    return *this;
}

String::~String()
{
    delete[] m_str;
}

const char* String::getStr()const
{
	return m_str;
}

void String::setStr(char* a_arr)
{
	m_str = a_arr;
}

BigInteger::BigInteger()
: m_list()
, m_sign(1)
{
}

BigInteger::BigInteger(long a_number)
: m_list()
, m_sign(1)
{
	m_sign = giveMeSign(a_number);
	while (a_number > 0)
	{
		int digit = a_number % 10;
		a_number = (a_number - digit) / 10;
		m_list.add(digit);
	}
}

BigInteger::BigInteger(char const* a_number)
: m_list()
, m_sign(1)
{
	m_sign = checkSign(a_number[0]);

	int len = strlen(a_number);
	for (int i = len - 1; i >= 0; i--)
	{
		if (checkIfNumber(a_number[i]))
		{
			m_list.add(convert2digit(a_number[i]));
		}
	}
}

BigInteger& BigInteger::operator=(long const& source)
{
	BigInteger result(source);
	*this = result;
	return *this;
}

BigInteger& BigInteger::add(BigInteger const& a_rhs)
{
	BigInteger first = *this;
	BigInteger second = a_rhs;
	if (first.m_sign != second.m_sign)
	{
		clean(this->m_list);
		first.flipSign();
		*this = first.sub(second);
		this->flipSign();
		return *this;
	}
	zeroPadding(first.m_list, second.m_list);
	first.m_list = first.flip();
	second.m_list = second.flip();
	LinkedList<int> result;
	ListIterator<int> itFirst = first.m_list.begin();
	ListIterator<int> itSecond = second.m_list.begin();
	int carry = 0;

	while (itFirst.notEqual(first.m_list.end()))
	{
		result.add(enter(itFirst.data() + itSecond.data() + carry));
		carry = remainder(itFirst.data() + itSecond.data() + carry);
		itFirst.next();
		itSecond.next();
	}

	if (carry != 0)
	{
		result.add(carry);
	}

	clean(this->m_list);
	this->m_list = result;
	return *this;
}

BigInteger& BigInteger::sub(BigInteger const& a_rhs)
{
	BigInteger first = *this;
	BigInteger second = a_rhs;
	if ((first.m_sign == -1 && second.m_sign == 1) || (first.m_sign == 1 && second.m_sign == -1))
	{
		clean(this->m_list);
		first.flipSign();
		*this = first.add(second);
		this->flipSign();
		return *this;
	}
	zeroPadding(first.m_list, second.m_list);
	first.m_list = first.flip();
	second.m_list = second.flip();
	int len = first.m_list.size();
	int *First = new int[len];
	int *Second = new int[len];
	moveToArray(first.m_list, First, second.m_list, Second);
	if (first.m_sign == -1 && second.m_sign == -1)
	{
		this->m_sign = checkBiggest(First, Second, len);
		this->flipSign();
	}
	else
	{
		this->m_sign = checkBiggest(First, Second, len);
	}
	LinkedList<int> result;

	for (int i = 0; i < len; i++)
	{
		if (First[i] - Second[i] >= 0)
		{
			result.add(First[i] - Second[i]);
		}
		else
		{
			lend(First, i);
			result.add(First[i] - Second[i]);
		}
	}

	delete[] First;
	delete[] Second;
	DeleteZeros(result);
	clean(this->m_list);
	this->m_list = result;
	return *this;
}

BigInteger& BigInteger::mul(BigInteger const& a_rhs)
{
	BigInteger first = *this;
	BigInteger second = a_rhs;
	zeroPadding(first.m_list, second.m_list);
	first.m_list = first.flip();
	second.m_list = second.flip();
	BigInteger result;
	BigInteger temp;
	ListIterator<int> itFirst = first.m_list.begin();
	ListIterator<int> itSecond;
	int carry = 0;
	int len = 0;

	while (itFirst.notEqual(first.m_list.end()))
	{
		itSecond = second.m_list.begin();
		PutZeros(temp.m_list, len);
		while (itSecond.notEqual(second.m_list.end()))
		{
			temp.m_list.add(enter(itFirst.data() * itSecond.data() + carry));
			carry = remainder(itFirst.data() * itSecond.data() + carry);
			itSecond.next();
		}
		if (carry != 0)
		{
			temp.m_list.add(carry);
			carry = 0;
		}

		result.add(temp);
		clean(temp.m_list);
		itFirst.next();
		len++;
	}

	DeleteZeros(result.m_list);
	clean(this->m_list);
	this->m_list = result.m_list;
	this->m_sign = checkSigns(first.m_sign, second.m_sign);
	return *this;
}

const char* BigInteger::toString(String& a_str) const
{
	char* str = new char[(sizeof(char)*m_list.size()) + sizeof('\0')*2];
	
	size_t i = 0;
	ListIterator<int> it = m_list.begin();
	if (m_sign == -1)
	{
		str[i] = '-';
		i++;
	}
	while (it.notEqual(m_list.end()))
	{
		str[i] = convert2char(it.data());
		i++;
		it.next();
	}
	str[i] = '\0';

	a_str.setStr(str);
	return a_str.getStr();
}

LinkedList<int> BigInteger::flip()const
{
	LinkedList<int> flip;
	ListIterator<int> it = m_list.begin();
	while (it.notEqual(m_list.end()))
	{
		flip.add(it.data());
		it.next();
	}
	return flip;
}

void BigInteger::flipSign()
{
	m_sign *= (-1);
}

LinkedList<int> BigInteger::getList()const
{
	return m_list;
}

bool BigInteger::equal(BigInteger const& a_rhs)const
{
	if(this == &a_rhs)
	{
		return true;
	}
	if(numOfDigits() != a_rhs.numOfDigits())
	{
		return false;
	}
	if(m_sign != a_rhs.m_sign)
	{
		return false;
	}
	BigInteger first = *this;
	first.sub(a_rhs);
	if(first.numOfDigits() == 1 && first.m_list.begin().data() == 0)
	{
		return true;
	}
	return false;
}

bool BigInteger::notEqual(BigInteger const& a_rhs)const
{
	return equal(a_rhs) == false;
} 

bool BigInteger::less(BigInteger const& a_rhs)const
{
	if(m_sign < a_rhs.m_sign)
	{
		return true;
	}
	if(m_sign > a_rhs.m_sign)
	{
		return false;
	}
	if(m_sign == a_rhs.m_sign)
	{
		if(numOfDigits() < a_rhs.numOfDigits())
		{
			return true;
		}
		if(numOfDigits() > a_rhs.numOfDigits())
		{
			return false;
		}
	}

	BigInteger first = *this;
	first.sub(a_rhs);
	if(first.m_sign == -1)
	{
		return true;
	}
	return false;
}

bool BigInteger::greater(BigInteger const& a_rhs)const
{
	return less(a_rhs) == false;
}

bool BigInteger::lessOrEqua (BigInteger const& a_rhs)const
{
	return less(a_rhs) == true || equal(a_rhs) == true;
}

bool BigInteger::greaterOrEqual(BigInteger const& a_rhs)const
{
	return greater(a_rhs) == true || equal(a_rhs) == true;
}

BigInteger add(BigInteger const& a_lhs, BigInteger const& a_rhs)
{
	BigInteger result = a_lhs;
	result.add(a_rhs);
	return result;
}

void add(BigInteger const& a_lhs, BigInteger const& a_rhs, BigInteger& a_sum)
{
	a_sum.add(a_lhs);
	a_sum.add(a_rhs);
}

BigInteger sub(BigInteger const& a_lhs, BigInteger const& a_rhs)
{
	BigInteger result = a_lhs;
	result.sub(a_rhs);
	return result;
}

void sub(BigInteger const& a_lhs, BigInteger const& a_rhs, BigInteger& a_sum)
{
	a_sum = a_lhs;
	a_sum.sub(a_rhs);
}

BigInteger mul(BigInteger const& a_lhs, BigInteger const& a_rhs)
{
	BigInteger result = a_lhs;
	result.mul(a_rhs);
	return result;
}

void mul(BigInteger const& a_lhs, BigInteger const& a_rhs, BigInteger& a_sum)
{
	a_sum = a_lhs;
	a_sum.mul(a_rhs);
}

bool equal(BigInteger const& a_rhs, BigInteger const& a_lhs)
{
	return 	a_rhs.equal(a_lhs);
}

bool notEqual(BigInteger const& a_rhs, BigInteger const& a_lhs)
{
	return 	a_rhs.notEqual(a_lhs);	
}

bool less(BigInteger const& a_rhs, BigInteger const& a_lhs)
{
	return 	a_rhs.less(a_lhs);
}

bool greater(BigInteger const& a_rhs, BigInteger const& a_lhs)
{
	return 	a_rhs.greater(a_lhs);
}

bool lessOrEqua(BigInteger const& a_rhs, BigInteger const& a_lhs)
{
	return 	a_rhs.lessOrEqua(a_lhs);
}

bool greaterOrEqual(BigInteger const& a_rhs, BigInteger const& a_lhs)
{
	return 	a_rhs.greaterOrEqual(a_lhs);
}

static int giveMeSign(long n)
{
	if (n < 0)
	{
		return -1;
	}
	return 1;
}

static int convert2digit(char c)
{
	return c - '0';
}

static int checkSign(char c)
{
	if (c == '-')
	{
		return -1;
	}
	return 1;
}

static bool checkIfNumber(char c)
{
	return isdigit(c);
}

static void zeroPadding(LinkedList<int>& a_first, LinkedList<int>& a_second)
{
	int len;
	if (a_first.size() > a_second.size())
	{
		len = a_first.size() - a_second.size();
		for (int i = 0; i < len; i++)
		{
			a_second.add(0);
		}
	}
	if (a_first.size() < a_second.size())
	{
		len = a_second.size() - a_first.size();
		for (int i = 0; i < len; i++)
		{
			a_first.add(0);
		}
	}
}

static int enter(int n)
{
	return n % 10;
}

static int remainder(int n)
{
	return (n - enter(n)) / 10;
}

static void clean(LinkedList<int>& a_list)
{
	size_t len = a_list.size();
	for (size_t i = 0; i < len; i++)
	{
		a_list.remove();
	}
}

static int checkSigns(int first, int second)
{
	if ((first == 1) && (second == -1))
	{
		return -1;
	}
	if ((first == -1) && (second == 1))
	{
		return -1;
	}

	return 1;
}

static void swapArr(int* First, int* Second, int a_len)
{
	int *temp = new int[a_len];
	for (int i = a_len - 1; i >= 0; i--)
	{
		temp[i] = First[i];
	}
	for (int i = a_len - 1; i >= 0; i--)
	{
		First[i] = Second[i];
	}
	for (int i = a_len - 1; i >= 0; i--)
	{
		Second[i] = temp[i];
	}
	delete[] temp;
}

static int checkBiggest(int* First, int* Second, int a_len)
{
	int i = a_len - 1;
	if (First[i] > Second[i])
	{
		return 1;
	}
	else if (First[i] < Second[i])
	{
		swapArr(First, Second, a_len);
		return -1;
	}

	for (; i > 0; i--)
	{
		if (First[i] > Second[i])
		{
			return 1;
		}
		else if (First[i] < Second[i])
		{
			swapArr(First, Second, a_len);
			return -1;
		}
	}

	return 0;
}

static void moveToArray(LinkedList<int> first, int* First, LinkedList<int> second, int* Second)
{
	ListIterator<int> it = first.begin();
	int i = 0;
	while (it.notEqual(first.end()))
	{
		First[i] = it.data();
		it.next();
		i++;
	}

	it = second.begin();
	i = 0;
	while (it.notEqual(second.end()))
	{
		Second[i] = it.data();
		it.next();
		i++;
	}
}

static void lend(int* First, int a_frome)
{
	First[a_frome] += 10;
	int i = a_frome + 1;
	while (First[i] == 0)
	{
		First[i] = 9;
		i++;
	}
	First[i] -= 1;
}

static void DeleteZeros(LinkedList<int>& a_list)
{
	ListIterator<int> it;
	while (true)
	{
		if (a_list.size() == 1)
		{
			return;
		}
		it = a_list.begin();
		if (it.data() != 0)
		{
			return;
		}
		else
		{
			a_list.remove();
		}
	}
}

static void PutZeros(LinkedList<int>& a_list, int n)
{
	for (int i = 0; i < n; i++)
	{
		a_list.add(0);
	}
}

static char convert2char(int n)
{
	return n + '0';
}

size_t BigInteger::numOfDigits()const
{
	return m_list.size();
}
