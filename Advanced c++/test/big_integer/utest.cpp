#include "mu_test.h"
#include "big_integer.hpp"


BEGIN_TEST(long_initialization)

	BigInteger x(112233445566778899L);
	LinkedList<int> list;
	list = x.getList();
 	ASSERT_EQUAL(x.numOfDigits(),18);
	
	ListIterator<int> it;
	it = list.begin();

	for(int i = 1; i < 10; i++)
	{
		ASSERT_EQUAL(it.data(),i);
		it.next().next();
	}

END_TEST


BEGIN_TEST(char_initialization)

	BigInteger x("-1/g2+3.4'd5,m678'9");
	LinkedList<int> list;
	list = x.getList();
	String s;
	printf("char -123456789: %s\n", x.toString(s));
 	ASSERT_EQUAL(x.numOfDigits(),9);
	
	ListIterator<int> it;
	it = list.begin();

	for(int i = 1; i < 10; i++)
	{
		ASSERT_EQUAL(it.data(),i);
		it.next();
	}

END_TEST


BEGIN_TEST(add_member_print)

	BigInteger a("-352");
	BigInteger b("-783");
	BigInteger c;
	c = a.add(b);
	String aa;
	printf("add -1135: %s\n",c.toString(aa));

	BigInteger d("-842");
	BigInteger e("-256");
	BigInteger f;
	f = d.add(e);
	String bb;
	printf("add -1098: %s\n",f.toString(bb));

	BigInteger g("-742");
	BigInteger h("526");
	BigInteger i;
	i = g.add(h);
	String cc;
	printf("add -216: %s\n",g.toString(cc)); 

	BigInteger j("-325");
	BigInteger k("982");
	BigInteger l;
	l = j.add(k);
	String dd;
	printf("add 657: %s\n",j.toString(dd));

	BigInteger m("5000");
	BigInteger n("-92");
	BigInteger o;
	o = m.add(n);
	String hh;
	printf("add 4908: %s\n",m.toString(hh));

	BigInteger p("25");
	BigInteger q("-92894");
	BigInteger r;
	r = p.add(q);
	String gg;
	printf("add -92869: %s\n",r.toString(gg));

	BigInteger pp("2..6854c.5");
	BigInteger qq("6.5165&$16@5");
	BigInteger rr;
	rr = pp.add(qq);
	String kk;
	printf("add 65433710: %s\n",pp.toString(kk));

	ASSERT_PASS();

END_TEST


BEGIN_TEST(sub_member_print)

	BigInteger a("-352");
	BigInteger b("-783");
	BigInteger c;
	c = a.sub(b);
	String ll;
	printf("sub 431: %s\n",c.toString(ll));

	BigInteger d("-842");
	BigInteger e("-256");
	BigInteger f;
	f = d.sub(e);
	String aa;
	printf("sub -586: %s\n",f.toString(aa));

	BigInteger g("-742");
	BigInteger h("526");
	BigInteger i;
	i = g.sub(h);
	String bb;
	printf("sub -1268: %s\n",g.toString(bb));

	BigInteger j("-325");
	BigInteger k("982");
	BigInteger l;
	l = j.sub(k);
	String cc;
	printf("sub -1307: %s\n",j.toString(cc));

	BigInteger m("5000");
	BigInteger n("-92");
	BigInteger o;
	o = m.sub(n);
	String dd;
	printf("sub 5092: %s\n",m.toString(dd));

	BigInteger p("25");
	BigInteger q("-92894");
	BigInteger r;
	r = p.sub(q);
	String ee;
	printf("sub 92919: %s\n",r.toString(ee));

	BigInteger pp("2..6854c.5");
	BigInteger qq("6.5165&$16@5");
	BigInteger rr;
	rr = pp.sub(qq);
	String ff;
	printf("sub -64896620: %s\n",pp.toString(ff));

	ASSERT_PASS();

END_TEST


BEGIN_TEST(mul_member_print)

	BigInteger a("-352");
	BigInteger b("-783");
	BigInteger c;
	c = a.mul(b);
	String aa;
	printf("mul 275616: %s\n",c.toString(aa));

	BigInteger d("-842");
	BigInteger e("-256");
	BigInteger f;
	f = d.mul(e);
	String bb;
	printf("mul 215552: %s\n",f.toString(bb));

	BigInteger g("-742");
	BigInteger h("526");
	BigInteger i;
	i = g.mul(h);
	String cc;
	printf("mul -390292: %s\n",g.toString(cc)); 

	BigInteger j("-325");
	BigInteger k("982");
	BigInteger l;
	l = j.mul(k);
	String dd;
	printf("mul -319150: %s\n",j.toString(dd)); 

	BigInteger m("5000");
	BigInteger n("-92");
	BigInteger o;
	o = m.mul(n);
	String ee;
	printf("mul -460000: %s\n",m.toString(ee));

	BigInteger p("25");
	BigInteger q("-92894");
	BigInteger r;
	r = p.mul(q);
	String ff;
	printf("mul -2322350: %s\n",r.toString(ff));

	BigInteger pp("2..685.5");
	BigInteger qq("6.516@5");
	BigInteger rr;
	rr = pp.mul(qq);
	String gg;
	printf("mul 1750006075: %s\n",pp.toString(gg));

	ASSERT_PASS();

END_TEST


BEGIN_TEST(add_global)

	BigInteger x(9879);
	BigInteger y("987456");
	BigInteger result;
	result = add(x, y);
	LinkedList<int> list;
	list = result.getList();
	String aa;
	printf("add global 997335: %s\n", result.toString(aa));
 	ASSERT_EQUAL(result.numOfDigits(),6);
	
	ListIterator<int> it;
	it = list.begin();

	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),7);
	it.next();
	ASSERT_EQUAL(it.data(),3);
	it.next();
	ASSERT_EQUAL(it.data(),3);
	it.next();
	ASSERT_EQUAL(it.data(),5);

END_TEST


BEGIN_TEST(add_global_2)

	BigInteger x(9879);
	BigInteger y("987456");
	BigInteger result;
	add(x, y, result);
	LinkedList<int> list;
	list = result.getList();
	String aa;
	printf("add global 2 997335: %s\n", result.toString(aa));
 	ASSERT_EQUAL(result.numOfDigits(),6);
	
	ListIterator<int> it;
	it = list.begin();

	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),7);
	it.next();
	ASSERT_EQUAL(it.data(),3);
	it.next();
	ASSERT_EQUAL(it.data(),3);
	it.next();
	ASSERT_EQUAL(it.data(),5);

END_TEST


BEGIN_TEST(add_global_3)

	BigInteger x(9879);
	BigInteger result;
	result = add(x,987456);
	LinkedList<int> list;
	list = result.getList();
	String aa;
	printf("add global 3 997335: %s\n", result.toString(aa));
 	ASSERT_EQUAL(result.numOfDigits(),6);
	
	ListIterator<int> it;
	it = list.begin();

	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),7);
	it.next();
	ASSERT_EQUAL(it.data(),3);
	it.next();
	ASSERT_EQUAL(it.data(),3);
	it.next();
	ASSERT_EQUAL(it.data(),5);

END_TEST


BEGIN_TEST(sub_global)

	BigInteger x("9879");
	BigInteger y("98");
	BigInteger result;
	result = sub(x, y);
	LinkedList<int> list;
	list = result.getList();
	String aa;
	printf("sub global 9781: %s\n", result.toString(aa));
 	ASSERT_EQUAL(result.numOfDigits(),4);
	
	ListIterator<int> it;
	it = list.begin();

	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),7);
	it.next();
	ASSERT_EQUAL(it.data(),8);
	it.next();
	ASSERT_EQUAL(it.data(),1);

END_TEST


BEGIN_TEST(sub_global_2)

	BigInteger x(9879);
	BigInteger y("98");
	BigInteger result;
	sub(x, y, result);
	LinkedList<int> list;
	list = result.getList();
	String aa;
	printf("sub global 2 9781: %s\n", result.toString(aa));
 	ASSERT_EQUAL(result.numOfDigits(),4);
	
	ListIterator<int> it;
	it = list.begin();

	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),7);
	it.next();
	ASSERT_EQUAL(it.data(),8);
	it.next();
	ASSERT_EQUAL(it.data(),1);
	it.next();

END_TEST


BEGIN_TEST(sub_global_3)

	BigInteger x(9879);
	BigInteger result;
	result = sub(x, 98);
	LinkedList<int> list;
	list = result.getList();
	String aa;
	printf("sub global 3 9781: %s\n", result.toString(aa));
 	ASSERT_EQUAL(result.numOfDigits(),4);
	
	ListIterator<int> it;
	it = list.begin();

	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),7);
	it.next();
	ASSERT_EQUAL(it.data(),8);
	it.next();
	ASSERT_EQUAL(it.data(),1);
	it.next();

END_TEST


BEGIN_TEST(mul_global)

	BigInteger x("98");
	BigInteger y("152");
	BigInteger result;
	result = mul(x, y);
	LinkedList<int> list;
	list = result.getList();
	String aa;
	printf("mul global 14896: %s\n", result.toString(aa));
 	ASSERT_EQUAL(result.numOfDigits(),5);
	
	ListIterator<int> it;
	it = list.begin();

	ASSERT_EQUAL(it.data(),1);
	it.next();
	ASSERT_EQUAL(it.data(),4);
	it.next();
	ASSERT_EQUAL(it.data(),8);
	it.next();
	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),6);

END_TEST


BEGIN_TEST(mul_global_2)

	BigInteger x(98);
	BigInteger y("152");
	BigInteger result;
	mul(x, y, result);
	LinkedList<int> list;
	list = result.getList();
	String aa;
	printf("mul global 2 14896: %s\n", result.toString(aa));
 	ASSERT_EQUAL(result.numOfDigits(),5);
	
	ListIterator<int> it;
	it = list.begin();

	ASSERT_EQUAL(it.data(),1);
	it.next();
	ASSERT_EQUAL(it.data(),4);
	it.next();
	ASSERT_EQUAL(it.data(),8);
	it.next();
	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),6);

END_TEST


BEGIN_TEST(mul_global_3)

	BigInteger x(98);
	BigInteger result;
	result = x.mul(152);
	LinkedList<int> list;
	list = result.getList();
	String aa;
	printf("mul global 3 14896: %s\n", result.toString(aa));
 	ASSERT_EQUAL(result.numOfDigits(),5);
	
	ListIterator<int> it;
	it = list.begin();

	ASSERT_EQUAL(it.data(),1);
	it.next();
	ASSERT_EQUAL(it.data(),4);
	it.next();
	ASSERT_EQUAL(it.data(),8);
	it.next();
	ASSERT_EQUAL(it.data(),9);
	it.next();
	ASSERT_EQUAL(it.data(),6);

END_TEST


BEGIN_TEST(to_string)

	BigInteger x("-11223344+556677889,9112233sd44556asd67788991122hgf33445566778899112,2334455,66778899");
	String aa;
	printf("to_string: %s\n", x.toString(aa));
	ASSERT_PASS();

END_TEST

BEGIN_TEST(equal_test)

	BigInteger x(584);
	ASSERT_EQUAL(x.equal(584),true);

	BigInteger q(584);
	BigInteger z(526);

	ASSERT_EQUAL(q.equal(z),false);

END_TEST


BEGIN_TEST(less_test)

	BigInteger x(584);
	BigInteger y(876);

	ASSERT_EQUAL(x.less(y),true);

	BigInteger q(584);
	ASSERT_EQUAL(q.less(372),false);

END_TEST


BEGIN_TEST(greater_test)

	BigInteger x(782);
	ASSERT_EQUAL(x.greater(584),true);

	BigInteger q(584);
	BigInteger z(896);
	ASSERT_EQUAL(q.greater(896),false);

END_TEST


BEGIN_TEST(lessOrEqua_test)

	BigInteger x("542");
	ASSERT_EQUAL(x.lessOrEqua(584),true);

	BigInteger a(542);
	BigInteger b(542);

	ASSERT_EQUAL(a.lessOrEqua(542),true);

	BigInteger q(1786);
	ASSERT_EQUAL(q.lessOrEqua(896),false);

END_TEST


BEGIN_TEST(greaterOrEqual_test)

	BigInteger x(800);
	BigInteger y(584);

	ASSERT_EQUAL(x.greaterOrEqual(y),true);

	BigInteger a(542);
	BigInteger b(542);

	ASSERT_EQUAL(a.greaterOrEqual(542),true);

	BigInteger q(220);
	ASSERT_EQUAL(q.greaterOrEqual(896),false);

END_TEST


BEGIN_TEST(global_equal)

	BigInteger x(584);
	ASSERT_EQUAL(equal(x, 584),true);

	BigInteger q(584);
	ASSERT_EQUAL(equal(q, 526),false);

END_TEST


BEGIN_TEST(global_less)

	BigInteger x(584);
	ASSERT_EQUAL(less(x, 876),true);

	BigInteger q(584);
	ASSERT_EQUAL(less(q, 372),false);

END_TEST


BEGIN_TEST(glbal_greater)

	BigInteger x(782);
	ASSERT_EQUAL(greater(x, 584),true);

	BigInteger q(584);
	ASSERT_EQUAL(greater(q, 896),false);

END_TEST


BEGIN_TEST(global_lessOrEqua)

	BigInteger x(542);
	ASSERT_EQUAL(lessOrEqua(x, 584),true);

	BigInteger a(542);
	ASSERT_EQUAL(lessOrEqua(a, 542),true);

	BigInteger q(1786);
	ASSERT_EQUAL(lessOrEqua(q, 896),false);

END_TEST


BEGIN_TEST(global_greaterOrEqual)

	BigInteger x(800);
	ASSERT_EQUAL(greaterOrEqual(x, 548),true);

	BigInteger a(542);
	ASSERT_EQUAL(greaterOrEqual(a, 542),true);

	BigInteger q(220);
	ASSERT_EQUAL(greaterOrEqual(q, 896),false);

END_TEST


BEGIN_TEST(long_copying)

	BigInteger x = 850;
	ASSERT_EQUAL(x.numOfDigits(),3);

	ASSERT_EQUAL(x.getList().first(),8);
	ASSERT_EQUAL(x.getList().last(),0);


END_TEST


BEGIN_TEST(big_int_copying)

	BigInteger x(850);
	BigInteger y;
	y=x;
	ASSERT_EQUAL(y.numOfDigits(),3);

	ASSERT_EQUAL(y.getList().first(),8);
	ASSERT_EQUAL(y.getList().last(),0);

END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)

	TEST(long_initialization)
	TEST(char_initialization)
	TEST(add_member_print)
	TEST(sub_member_print)
	TEST(mul_member_print)
	TEST(add_global)
	TEST(add_global_2)
	TEST(add_global_3)
	TEST(sub_global)
	TEST(sub_global_2)
	TEST(sub_global_3)
	TEST(mul_global)
	TEST(mul_global_2)
	TEST(mul_global_3)
	TEST(to_string)
	TEST(equal_test)
	TEST(less_test)
	TEST(greater_test)
	TEST(lessOrEqua_test)
	TEST(greaterOrEqual_test)
	TEST(global_equal)
	TEST(global_less)
	TEST(glbal_greater)
	TEST(global_lessOrEqua)
	TEST(global_greaterOrEqual)
	TEST(long_copying)
	TEST(big_int_copying)

END_SUITE
