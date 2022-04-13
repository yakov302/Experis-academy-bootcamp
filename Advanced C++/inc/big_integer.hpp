#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include "single_list.hpp"

class String
{
public:
    String();
	String(String const& source);
	String& operator=(String const& source);
	~String();
	const char* getStr()const;
    void setStr(char* a_arr);

private:
	char* m_str;
};

class BigInteger
{
public:
    BigInteger();
    BigInteger(long a_number);
    explicit BigInteger(char const* a_number);
    BigInteger& operator=(long const& source);

    BigInteger& add(BigInteger const& a_rhs);
    BigInteger& sub(BigInteger const& a_rhs);
    BigInteger& mul(BigInteger const& a_rhs);

    bool equal(BigInteger const& a_rhs)const; 
    bool notEqual(BigInteger const& a_rhs)const;
    bool less(BigInteger const& a_rhs)const;
    bool greater(BigInteger const& a_rhs)const;
    bool lessOrEqua(BigInteger const& a_rhs)const;
    bool greaterOrEqual(BigInteger const& a_rhs)const;

    const char* toString(String& a_str)const;
    size_t numOfDigits()const;
    LinkedList<int> getList()const;

private:
    LinkedList<int> flip()const;
    void flipSign();

private:
    LinkedList<int> m_list;
    int m_sign;
};

BigInteger add(BigInteger const& a_lhs, BigInteger const& a_rhs);
void add(BigInteger const& a_lhs, BigInteger const& a_rhs, BigInteger& a_sum);

BigInteger sub(BigInteger const &a_lhs, BigInteger const &a_rhs);
void sub(BigInteger const &a_lhs, BigInteger const &a_rhs, BigInteger &a_sum);

BigInteger mul(BigInteger const &a_lhs, BigInteger const &a_rhs);
void mul(BigInteger const &a_lhs, BigInteger const &a_rhs, BigInteger &a_sum);

bool equal(BigInteger const& a_rhs, BigInteger const& a_lhs); 
bool notEqual(BigInteger const& a_rhs, BigInteger const& a_lhs);
bool less(BigInteger const& a_rhs, BigInteger const& a_lhs);
bool greater(BigInteger const& a_rhs, BigInteger const& a_lhs);
bool lessOrEqua(BigInteger const& a_rhs, BigInteger const& a_lhs);
bool greaterOrEqual(BigInteger const& a_rhs, BigInteger const& a_lhs);



#endif // LINKED_LIST_HPP