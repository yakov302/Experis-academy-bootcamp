#include "mu_test.h"
#include "rational.hpp"

BEGIN_TEST(add_test_positive_rational)

	numbers::Rational r(1, 2, true);
	ASSERT_EQUAL(r.getNumerator(), 1);
	ASSERT_EQUAL(r.getDenominator(), 2);

	r = numbers::Rational(5, 10);
	ASSERT_EQUAL(r.getNumerator(), 1);
	ASSERT_EQUAL(r.getDenominator(), 2);

	r = numbers::Rational(7, 32);
	ASSERT_EQUAL(r.getNumerator(), 7);
	ASSERT_EQUAL(r.getDenominator(), 32);

	r = numbers::Rational(-7, -32);
	ASSERT_EQUAL(r.getNumerator(), 7);
	ASSERT_EQUAL(r.getDenominator(), 32);

END_TEST


BEGIN_TEST(create_a_zero_test)

	numbers::Rational r(0, 2);
	ASSERT_EQUAL(r.getNumerator(), 0);
	ASSERT_EQUAL(r.getDenominator(), 1);

	r = numbers::Rational(0, 12);
	ASSERT_EQUAL(r.getNumerator(), 0);
	ASSERT_EQUAL(r.getDenominator(), 1);

END_TEST


BEGIN_TEST(create_infinity_test)

numbers::Rational r(1, 0);
ASSERT_FAIL("can't divide by zero");

END_TEST


BEGIN_TEST(add_test_negative_rational)

	numbers::Rational r = numbers::Rational(-1, 2);
	ASSERT_EQUAL(r.getNumerator(), -1);
	ASSERT_EQUAL(r.getDenominator(), 2);

	r = numbers::Rational(5, -10);
	ASSERT_EQUAL(r.getNumerator(), -1);
	ASSERT_EQUAL(r.getDenominator(), 2);

	r = numbers::Rational(7, -32);
	ASSERT_EQUAL(r.getNumerator(), -7);
	ASSERT_EQUAL(r.getDenominator(), 32);

END_TEST


BEGIN_TEST(default_parameters)

	numbers::Rational zero;	 // == one(0, 1)
	numbers::Rational one(1); // == one(1, 1)
	numbers::Rational w(2);	 // == one(2, 1)

	numbers::Rational q1(3, 4);
	numbers::Rational q2(3, 4);
	numbers::Rational q3(3, 4);
	numbers::Rational q4(3, 4);

	q2.mul(one);
	q3.mul(zero);
	q4.mul(zero);

	ASSERT_THAT(q1.compare(q2) == 0);
	ASSERT_THAT(q3.compare(zero) == 0);
	ASSERT_THAT(q4.compare(w) == -1);

END_TEST


BEGIN_TEST(add_positive_and_negative)

	numbers::Rational r1(2, 4);
	numbers::Rational r2(5, 10);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(2, 4);
	r2 = numbers::Rational(5, -10);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), 0);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(-3, 12);
	r2 = numbers::Rational(17, 56);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), 3);
	ASSERT_EQUAL(r1.getDenominator(), 56);

	r1 = numbers::Rational(3, -12);
	r2 = numbers::Rational(17, 22);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), 23);
	ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = numbers::Rational(3, -12);
	r2 = numbers::Rational(-17, 22);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), -45);
	ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = numbers::Rational(-3, -9);
	r2 = numbers::Rational(-15, -22);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), 67);
	ASSERT_EQUAL(r1.getDenominator(), 66);

END_TEST


BEGIN_TEST(sub_positive_and_negative)

	numbers::Rational r1(2, 4);
	numbers::Rational r2(5, 10);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), 0);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(2, 4);
	r2 = numbers::Rational(5, -10);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(-3, 12);
	r2 = numbers::Rational(17, 56);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), -31);
	ASSERT_EQUAL(r1.getDenominator(), 56);

	r1 = numbers::Rational(3, -12);
	r2 = numbers::Rational(17, 22);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), -45);
	ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = numbers::Rational(3, -12);
	r2 = numbers::Rational(-17, 22);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), 23);
	ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = numbers::Rational(-3, -9);
	r2 = numbers::Rational(-15, -22);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), -23);
	ASSERT_EQUAL(r1.getDenominator(), 66);

END_TEST


BEGIN_TEST(mul_positive_and_negative)

	numbers::Rational r1(2, 4);
	numbers::Rational r2(5, 10);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 4);

	r1 = numbers::Rational(2, 4);
	r2 = numbers::Rational(5, -10);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), -1);
	ASSERT_EQUAL(r1.getDenominator(), 4);

	r1 = numbers::Rational(-3, 12);
	r2 = numbers::Rational(17, 56);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), -17);
	ASSERT_EQUAL(r1.getDenominator(), 224);

	r1 = numbers::Rational(3, -12);
	r2 = numbers::Rational(17, 22);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), -17);
	ASSERT_EQUAL(r1.getDenominator(), 88);

	r1 = numbers::Rational(3, -12);
	r2 = numbers::Rational(-17, 22);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), 17);
	ASSERT_EQUAL(r1.getDenominator(), 88);

	r1 = numbers::Rational(-3, -9);
	r2 = numbers::Rational(-15, -22);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), 5);
	ASSERT_EQUAL(r1.getDenominator(), 22);

END_TEST


BEGIN_TEST(div_positive_and_negative)

	numbers::Rational r1(2, 4);
	numbers::Rational r2(5, 10);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(2, 4);
	r2 = numbers::Rational(5, -10);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), -1);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(-3, 12);
	r2 = numbers::Rational(17, 56);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), -14);
	ASSERT_EQUAL(r1.getDenominator(), 17);

	r1 = numbers::Rational(3, -12);
	r2 = numbers::Rational(17, 22);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), -11);
	ASSERT_EQUAL(r1.getDenominator(), 34);

	r1 = numbers::Rational(3, -12);
	r2 = numbers::Rational(-17, 22);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), 11);
	ASSERT_EQUAL(r1.getDenominator(), 34);

	r1 = numbers::Rational(-3, -9);
	r2 = numbers::Rational(-15, -22);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), 22);
	ASSERT_EQUAL(r1.getDenominator(), 45);

END_TEST


BEGIN_TEST(reduce_positive_and_negative)

	numbers::Rational r1(8, 16);
	r1.reduce();
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 2);

	r1 = numbers::Rational(2, 8);
	r1.reduce();
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 4);

	r1 = numbers::Rational(-2, 8);
	r1.reduce();
	ASSERT_EQUAL(r1.getNumerator(), -1);
	ASSERT_EQUAL(r1.getDenominator(), 4);

	r1 = numbers::Rational(2, -4);
	r1.reduce();
	ASSERT_EQUAL(r1.getNumerator(), -1);
	ASSERT_EQUAL(r1.getDenominator(), 2);

	r1 = numbers::Rational(-5, -15);
	r1.reduce();
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 3);

	r1 = numbers::Rational(20, 400);
	r1.reduce();
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 20);

	r1 = numbers::Rational(400, 8000);
	r1.reduce();
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 20);

	r1 = numbers::Rational(18, 18);
	r1.reduce();
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 1);

END_TEST


BEGIN_TEST(inverse_positive_and_negative)

	numbers::Rational r1(8, 16);
	r1.inverse();
	ASSERT_EQUAL(r1.getNumerator(), 2);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(2, 8);
	r1.inverse();
	ASSERT_EQUAL(r1.getNumerator(), 4);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(-2, 8);
	r1.inverse();
	ASSERT_EQUAL(r1.getNumerator(), -4);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(2, -4);
	r1.inverse();
	ASSERT_EQUAL(r1.getNumerator(), -2);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(-5, -15);
	r1.inverse();
	ASSERT_EQUAL(r1.getNumerator(), 3);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(20, 400);
	r1.inverse();
	ASSERT_EQUAL(r1.getNumerator(), 20);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(400, 8000);
	r1.inverse();
	ASSERT_EQUAL(r1.getNumerator(), 20);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = numbers::Rational(18, 18);
	r1.inverse();
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 1);

END_TEST


BEGIN_TEST(display)

	using numbers::Rational;

	Rational r;

	for(int i = 1; i < 10; i++)
	{
		r = Rational(20, i);
		r.display();
	}

	ASSERT_PASS();

END_TEST


BEGIN_TEST(compare_positive_and_negative)

	using numbers::Rational;

	Rational r1(8, 16);
	Rational r2(8, 16);
	ASSERT_EQUAL(r1.compare(r2), 0);

	r1 = Rational(4, 16);
	r2 = Rational(4, 8);
	ASSERT_EQUAL(r1.compare(r2), -1);

	r1 = Rational(-4, 8);
	r2 = Rational(2, 8);
	ASSERT_EQUAL(r1.compare(r2), -1);

	r1 = Rational(4, 8);
	r2 = Rational(2, -8);
	ASSERT_EQUAL(r1.compare(r2), 1);

END_TEST


BEGIN_TEST(isEqual)

	using numbers::Rational;
	
	Rational h(2, 4);
	Rational q(2, 8);
	ASSERT_THAT(!h.equal(q));

	h = Rational(2, 4);
	q = Rational(1, 2);
	ASSERT_THAT(h.equal(q));

	h = Rational(-2, 4);
	q = Rational(2, 4);
	ASSERT_THAT(!h.equal(q));

END_TEST


BEGIN_TEST(notEqual)

	using numbers::Rational;
	
	Rational h(2, 4);
	Rational q(2, 8);
	ASSERT_THAT(h.notEqual(q));

	h = Rational(2, 4);
	q = Rational(1, 2);
	ASSERT_THAT(!h.notEqual(q));

	h = Rational(-2, 4);
	q = Rational(2, 4);
	ASSERT_THAT(h.notEqual(q));

END_TEST


BEGIN_TEST(add_global_positive_and_negative)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r3;
	r3 = add(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 1);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r3 = add(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 0);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r3 = add(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 3);
	ASSERT_EQUAL(r3.getDenominator(), 56);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r3 = add(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 23);
	ASSERT_EQUAL(r3.getDenominator(), 44);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r3 = add(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), -45);
	ASSERT_EQUAL(r3.getDenominator(), 44);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r3 = add(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 67);
	ASSERT_EQUAL(r3.getDenominator(), 66);

END_TEST


BEGIN_TEST(sub_global_positive_and_negative)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r3;
	r3 = sub(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 0);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r3 = sub(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 1);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r3 = sub(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), -31);
	ASSERT_EQUAL(r3.getDenominator(), 56);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r3 = sub(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), -45);
	ASSERT_EQUAL(r3.getDenominator(), 44);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r3 = sub(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 23);
	ASSERT_EQUAL(r3.getDenominator(), 44);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r3 = sub(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), -23);
	ASSERT_EQUAL(r3.getDenominator(), 66);

END_TEST


BEGIN_TEST(mul_global_positive_and_negative)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r3;
	r3 = mul(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 1);
	ASSERT_EQUAL(r3.getDenominator(), 4);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r3 = mul(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), -1);
	ASSERT_EQUAL(r3.getDenominator(), 4);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r3 = mul(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), -17);
	ASSERT_EQUAL(r3.getDenominator(), 224);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r3 = mul(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), -17);
	ASSERT_EQUAL(r3.getDenominator(), 88);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r3 = mul(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 17);
	ASSERT_EQUAL(r3.getDenominator(), 88);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r3 = mul(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 5);
	ASSERT_EQUAL(r3.getDenominator(), 22);

END_TEST


BEGIN_TEST(div_global_positive_and_negative)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r3;
	r3 = div(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 1);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r3 = div(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), -1);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r3 = div(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), -14);
	ASSERT_EQUAL(r3.getDenominator(), 17);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r3 = div(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), -11);
	ASSERT_EQUAL(r3.getDenominator(), 34);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r3 = div(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 11);
	ASSERT_EQUAL(r3.getDenominator(), 34);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r3 = div(r1, r2);
	ASSERT_EQUAL(r3.getNumerator(), 22);
	ASSERT_EQUAL(r3.getDenominator(), 45);

END_TEST


BEGIN_TEST(add_positive_and_negative_member_opertaor)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r;
	r = r1 += r2;
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 1);
	ASSERT_EQUAL(r.getNumerator(), 1);
	ASSERT_EQUAL(r.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r1 += r2;
	ASSERT_EQUAL(r1.getNumerator(), 0);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r1 += r2;
	ASSERT_EQUAL(r1.getNumerator(), 3);
	ASSERT_EQUAL(r1.getDenominator(), 56);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r1 += r2;
	ASSERT_EQUAL(r1.getNumerator(), 23);
	ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r1 += r2;
	ASSERT_EQUAL(r1.getNumerator(), -45);
	ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r1 += r2;
	ASSERT_EQUAL(r1.getNumerator(), 67);
	ASSERT_EQUAL(r1.getDenominator(), 66);

END_TEST


BEGIN_TEST(sub_positive_and_negative_mmber_operator)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r;
	r = r1 -= r2;
	ASSERT_EQUAL(r1.getNumerator(), 0);
	ASSERT_EQUAL(r1.getDenominator(), 1);
	ASSERT_EQUAL(r.getNumerator(), 0);
	ASSERT_EQUAL(r.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r1 -= r2;
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r1 -= r2;
	ASSERT_EQUAL(r1.getNumerator(), -31);
	ASSERT_EQUAL(r1.getDenominator(), 56);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r1 -= r2;
	ASSERT_EQUAL(r1.getNumerator(), -45);
	ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r1 -= r2;
	ASSERT_EQUAL(r1.getNumerator(), 23);
	ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r1 -= r2;
	ASSERT_EQUAL(r1.getNumerator(), -23);
	ASSERT_EQUAL(r1.getDenominator(), 66);

END_TEST


BEGIN_TEST(mul_positive_and_negative_mmber_operator)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r;
	r = r1 *= r2;
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 4);
	ASSERT_EQUAL(r.getNumerator(), 1);
	ASSERT_EQUAL(r.getDenominator(), 4);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r1 *= r2;
	ASSERT_EQUAL(r1.getNumerator(), -1);
	ASSERT_EQUAL(r1.getDenominator(), 4);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r1 *= r2;
	ASSERT_EQUAL(r1.getNumerator(), -17);
	ASSERT_EQUAL(r1.getDenominator(), 224);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r1 *= r2;
	ASSERT_EQUAL(r1.getNumerator(), -17);
	ASSERT_EQUAL(r1.getDenominator(), 88);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r1 *= r2;
	ASSERT_EQUAL(r1.getNumerator(), 17);
	ASSERT_EQUAL(r1.getDenominator(), 88);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r1 *= r2;
	ASSERT_EQUAL(r1.getNumerator(), 5);
	ASSERT_EQUAL(r1.getDenominator(), 22);

END_TEST


BEGIN_TEST(div_positive_and_negative_mmber_operator)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r;
	r = r1 /= r2;
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 1);
	ASSERT_EQUAL(r.getNumerator(), 1);
	ASSERT_EQUAL(r.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r1 /= r2;
	ASSERT_EQUAL(r1.getNumerator(), -1);
	ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r1 /= r2;
	ASSERT_EQUAL(r1.getNumerator(), -14);
	ASSERT_EQUAL(r1.getDenominator(), 17);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r1 /= r2;
	ASSERT_EQUAL(r1.getNumerator(), -11);
	ASSERT_EQUAL(r1.getDenominator(), 34);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r1 /= r2;
	ASSERT_EQUAL(r1.getNumerator(), 11);
	ASSERT_EQUAL(r1.getDenominator(), 34);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r1 /= r2;
	ASSERT_EQUAL(r1.getNumerator(), 22);
	ASSERT_EQUAL(r1.getDenominator(), 45);

END_TEST


BEGIN_TEST(add_global_positive_and_negative_operator)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r3;
	r3 =  r1 + r2;
	ASSERT_EQUAL(r3.getNumerator(), 1);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r3 =  r1 + r2;
	ASSERT_EQUAL(r3.getNumerator(), 0);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r3 =  r1 + r2;
	ASSERT_EQUAL(r3.getNumerator(), 3);
	ASSERT_EQUAL(r3.getDenominator(), 56);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r3 =  r1 + r2;
	ASSERT_EQUAL(r3.getNumerator(), 23);
	ASSERT_EQUAL(r3.getDenominator(), 44);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r3 =  r1 + r2;
	ASSERT_EQUAL(r3.getNumerator(), -45);
	ASSERT_EQUAL(r3.getDenominator(), 44);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r3 =  r1 + r2;
	ASSERT_EQUAL(r3.getNumerator(), 67);
	ASSERT_EQUAL(r3.getDenominator(), 66);

END_TEST


BEGIN_TEST(sub_global_positive_and_negative_operator)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r3;
	r3 = r1 - r2;
	ASSERT_EQUAL(r3.getNumerator(), 0);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r3 = r1 - r2;
	ASSERT_EQUAL(r3.getNumerator(), 1);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r3 = r1 - r2;
	ASSERT_EQUAL(r3.getNumerator(), -31);
	ASSERT_EQUAL(r3.getDenominator(), 56);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r3 = r1 - r2;
	ASSERT_EQUAL(r3.getNumerator(), -45);
	ASSERT_EQUAL(r3.getDenominator(), 44);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r3 = r1 - r2;
	ASSERT_EQUAL(r3.getNumerator(), 23);
	ASSERT_EQUAL(r3.getDenominator(), 44);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r3 = r1 - r2;
	ASSERT_EQUAL(r3.getNumerator(), -23);
	ASSERT_EQUAL(r3.getDenominator(), 66);

END_TEST


BEGIN_TEST(mul_global_positive_and_negative_operator)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r3;
	r3 = r1 * r2;
	ASSERT_EQUAL(r3.getNumerator(), 1);
	ASSERT_EQUAL(r3.getDenominator(), 4);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r3 = r1 * r2;
	ASSERT_EQUAL(r3.getNumerator(), -1);
	ASSERT_EQUAL(r3.getDenominator(), 4);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r3 = r1 * r2;
	ASSERT_EQUAL(r3.getNumerator(), -17);
	ASSERT_EQUAL(r3.getDenominator(), 224);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r3 = r1 * r2;
	ASSERT_EQUAL(r3.getNumerator(), -17);
	ASSERT_EQUAL(r3.getDenominator(), 88);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r3 = r1 * r2;
	ASSERT_EQUAL(r3.getNumerator(), 17);
	ASSERT_EQUAL(r3.getDenominator(), 88);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r3 = r1 * r2;
	ASSERT_EQUAL(r3.getNumerator(), 5);
	ASSERT_EQUAL(r3.getDenominator(), 22);

END_TEST


BEGIN_TEST(div_global_positive_and_negative_operator)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(5, 10);
	Rational r3;
	r3 =r1 / r2;
	ASSERT_EQUAL(r3.getNumerator(), 1);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r3 =r1 / r2;
	ASSERT_EQUAL(r3.getNumerator(), -1);
	ASSERT_EQUAL(r3.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r3 =r1 / r2;
	ASSERT_EQUAL(r3.getNumerator(), -14);
	ASSERT_EQUAL(r3.getDenominator(), 17);

	r1 = Rational(3, -12);
	r2 = Rational(17, 22);
	r3 =r1 / r2;
	ASSERT_EQUAL(r3.getNumerator(), -11);
	ASSERT_EQUAL(r3.getDenominator(), 34);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r3 =r1 / r2;
	ASSERT_EQUAL(r3.getNumerator(), 11);
	ASSERT_EQUAL(r3.getDenominator(), 34);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r3 =r1 / r2;
	ASSERT_EQUAL(r3.getNumerator(), 22);
	ASSERT_EQUAL(r3.getDenominator(), 45);

END_TEST


BEGIN_TEST(increment_operator)

	using numbers::Rational;
	
	Rational a(2, 4);
	Rational r;
	r = ++a;
	ASSERT_EQUAL(a.getNumerator(), 3);
	ASSERT_EQUAL(a.getDenominator(), 2);
	ASSERT_EQUAL(r.getNumerator(), 3);
	ASSERT_EQUAL(r.getDenominator(), 2);

	Rational b(2, 4);
	Rational z;
	z = b++;
	ASSERT_EQUAL(b.getNumerator(), 3);
	ASSERT_EQUAL(b.getDenominator(), 2);
	ASSERT_EQUAL(z.getNumerator(), 1);
	ASSERT_EQUAL(z.getDenominator(), 2);

	Rational c(-2, 4);
	z = ++c;
	ASSERT_EQUAL(c.getNumerator(), 1);
	ASSERT_EQUAL(c.getDenominator(), 2);
	ASSERT_EQUAL(z.getNumerator(),1);
	ASSERT_EQUAL(z.getDenominator(), 2);

	Rational d(-2, 4);
	d++;
	ASSERT_EQUAL(d.getNumerator(), 1);
	ASSERT_EQUAL(d.getDenominator(), 2);

END_TEST


BEGIN_TEST(decrement_operator)

	using numbers::Rational;
	
	Rational a(2, 4);
	Rational r;
	r = --a;
	ASSERT_EQUAL(a.getNumerator(), -1);
	ASSERT_EQUAL(a.getDenominator(), 2);
	ASSERT_EQUAL(r.getNumerator(), -1);
	ASSERT_EQUAL(r.getDenominator(), 2);

	Rational b(2, 4);
	Rational z;
	Rational z2;
	z = b--;
	ASSERT_EQUAL(b.getNumerator(), -1);
	ASSERT_EQUAL(b.getDenominator(), 2);
	ASSERT_EQUAL(z.getNumerator(), 1);
	ASSERT_EQUAL(z.getDenominator(), 2);

	Rational c(-2, 4);
	--c;
	ASSERT_EQUAL(c.getNumerator(), -3);
	ASSERT_EQUAL(c.getDenominator(), 2);

	Rational d(-2, 4);
	d--;
	ASSERT_EQUAL(d.getNumerator(), -3);
	ASSERT_EQUAL(d.getDenominator(), 2);

END_TEST


BEGIN_TEST(minus_operator)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(-5, 10);
	Rational r3;
	r3 = -r1;
	ASSERT_EQUAL(r3.getNumerator(), -1);
	ASSERT_EQUAL(r3.getDenominator(), 2);
	ASSERT_EQUAL(r1.getNumerator(), 1);
	ASSERT_EQUAL(r1.getDenominator(), 2);

	r3 = -r2;
	ASSERT_EQUAL(r3.getNumerator(), 1);
	ASSERT_EQUAL(r3.getDenominator(), 2);

END_TEST


BEGIN_TEST(plus_operator)

	using numbers::Rational;
	
	Rational r1(2, 4);
	Rational r2(-5, 10);
	Rational r3;
	r3 = +r1;
	ASSERT_EQUAL(r3.getNumerator(), 1);
	ASSERT_EQUAL(r3.getDenominator(), 2);

	r3 = +r2;
	ASSERT_EQUAL(r3.getNumerator(), -1);
	ASSERT_EQUAL(r3.getDenominator(), 2);

END_TEST


BEGIN_TEST(equal_operator)

	using numbers::Rational;
	
	Rational h(2, 4);
	Rational q(2, 8);
	ASSERT_THAT(!(h == q));

	h = Rational(2, 4);
	q = Rational(1, 2);
	ASSERT_THAT(h == q);

	h = Rational(-2, 4);
	q = Rational(2, 4);
	ASSERT_THAT(!(h == q));

END_TEST


BEGIN_TEST(notEqual_operator)

	using numbers::Rational;
	
	Rational h(2, 4);
	Rational q(2, 8);
	ASSERT_THAT(h != q);

	h = Rational(2, 4);
	q = Rational(1, 2);
	ASSERT_THAT(!(h != q));

	h = Rational(-2, 4);
	q = Rational(2, 4);
	ASSERT_THAT(h != q);

END_TEST


BEGIN_TEST(less_operator)

	using numbers::Rational;
	
	Rational h(2, 8);
	Rational q(2, 4);
	ASSERT_THAT(h < q);

	h = Rational(1, 2);
	q = Rational(1, 4);
	ASSERT_THAT(!(h < q));

	h = Rational(-2, 4);
	q = Rational(2, 4);
	ASSERT_THAT(h < q);

END_TEST


BEGIN_TEST(greater_operator)

	using numbers::Rational;
	
	Rational h(2, 8);
	Rational q(2, 4);
	ASSERT_THAT(!(h > q));

	h = Rational(1, 2);
	q = Rational(1, 4);
	ASSERT_THAT(h > q);

	h = Rational(-2, 8);
	q = Rational(-2, 4);
	ASSERT_THAT(h > q);

	h = Rational(1, 2);
	q = Rational(2, 4);
	ASSERT_THAT(!(h > q));

END_TEST


BEGIN_TEST(greater_or_equal_operator)

	using numbers::Rational;
	
	Rational h(2, 8);
	Rational q(2, 4);
	ASSERT_THAT(!(h >= q));

	h = Rational(1, 2);
	q = Rational(1, 4);
	ASSERT_THAT(h >= q);

	h = Rational(-2, 8);
	q = Rational(-2, 4);
	ASSERT_THAT(h >= q);

	h = Rational(1, 2);
	q = Rational(2, 4);
	ASSERT_THAT((h >= q));

END_TEST


BEGIN_TEST(less_or_equal_operator)

	using numbers::Rational;
	//using numbers::print;

	Rational h(2, 8);
	Rational q(2, 4);
	ASSERT_THAT(h <= q);

	h = Rational(1, 2);
	q = Rational(1, 4);
	ASSERT_THAT(!(h <= q));

	h = Rational(-2, 4);
	q = Rational(2, 4);
	ASSERT_THAT(h <= q);

	h = Rational(6, 12);
	q = Rational(2, 4);
	ASSERT_THAT(h <= q);

END_TEST


BEGIN_TEST(print_operator)

	using numbers::Rational;

	Rational h(1, 18);
	Rational q(2, 4);

	std::cout << "\n" << "my rationals are: " << h << " and " << q << "\n" << "i.e : " << double(h) << " and " << double(q) << "\n";
	ASSERT_PASS();

END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)

TEST(add_test_positive_rational)
TEST(create_a_zero_test)
IGNORE_TEST(create_infinity_test)
TEST(add_test_negative_rational)
TEST(default_parameters)
TEST(add_positive_and_negative)
TEST(sub_positive_and_negative)
TEST(mul_positive_and_negative)
TEST(div_positive_and_negative)
TEST(reduce_positive_and_negative)
TEST(inverse_positive_and_negative)
TEST(display)
TEST(compare_positive_and_negative)
TEST(isEqual)
TEST(notEqual)
TEST(add_global_positive_and_negative)
TEST(sub_global_positive_and_negative)
TEST(mul_global_positive_and_negative)
TEST(div_global_positive_and_negative)
TEST(add_positive_and_negative_member_opertaor)
TEST(sub_positive_and_negative_mmber_operator)
TEST(mul_positive_and_negative_mmber_operator)
TEST(div_positive_and_negative_mmber_operator)
TEST(add_global_positive_and_negative_operator)
TEST(sub_global_positive_and_negative_operator)
TEST(mul_global_positive_and_negative_operator)
TEST(div_global_positive_and_negative_operator)
TEST(increment_operator)
TEST(decrement_operator)
TEST(minus_operator)
TEST(plus_operator)
TEST(equal_operator)
TEST(notEqual_operator)
TEST(less_operator)
TEST(greater_operator)
TEST(greater_or_equal_operator)
TEST(less_or_equal_operator)
TEST(print_operator)

END_SUITE
