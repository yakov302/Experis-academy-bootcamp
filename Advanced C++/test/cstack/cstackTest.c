#include "mu_test.h"
#include "cstack.h"

BEGIN_TEST(giveCapacityZero)
Stack* stack;
	
	stack = StackCreate (0);

    	ASSERT_EQUAL(stack, NULL); 

END_TEST

BEGIN_TEST(giveCapacityBigerThenZero)
Stack* stack;
	
	stack = StackCreate (10);

    	ASSERT_NOT_EQUAL(stack, NULL);
   	 
END_TEST

BEGIN_TEST(DoubleFree)
Stack* stack;
	
	stack = StackCreate (10);
	StackDestroy(stack);
	StackDestroy(stack);
	ASSERT_PASS();
    	
END_TEST

BEGIN_TEST(StackPushNull)
ReturnMessages result;
Stack* stack = NULL;
int item = 4;

	result = StackPush(stack, item);
	
	ASSERT_EQUAL(result, STACK_NOT_INITIALIZED); 

END_TEST

BEGIN_TEST(StackPushOverFlow)
ReturnMessages result;
Stack* stack = NULL;
int item = 4;
int item2 = 5;
	
	stack = StackCreate (1);
	
	result = StackPush(stack, item);
	result = StackPush(stack, item2);
	
	ASSERT_EQUAL(result, STACK_OVERFLOW); 

END_TEST

BEGIN_TEST(StackPushSuccess)
ReturnMessages result;
Stack* stack;
int item = 4;
	
	stack = StackCreate (1);
	
	result = StackPush(stack, item);
	
	ASSERT_EQUAL(result, STACK_SUCCESS); 

END_TEST

BEGIN_TEST(StackPopNull)
ReturnMessages result;
Stack* stack = NULL;
int* item;
	
	result = StackPop(stack, item);
	
	ASSERT_EQUAL(result, STACK_NOT_INITIALIZED); 

END_TEST

BEGIN_TEST(StackPopNull2)
ReturnMessages result;
Stack* stack;
int* item = NULL;
	
	stack = StackCreate (1);
	
	result = StackPop(stack, item);
	
	ASSERT_EQUAL(result, ITEM_NOT_INITIALIZED); 

END_TEST

BEGIN_TEST(StackPopUnderFlow)
ReturnMessages result;
Stack* stack;
int *item;
	
	stack = StackCreate (1);
	
	result = StackPop (stack , item);
	
	ASSERT_EQUAL(result, STACK_UNDERFLOW); 

END_TEST

BEGIN_TEST(StackPopSuccess)
ReturnMessages result;
Stack* stack;
int *item = (int*) malloc(sizeof(int)*1);
int num = 4;
	
	stack = StackCreate (1);
	
	StackPush(stack, num);
	StackPop (stack , item);	
	ASSERT_EQUAL(*item, 4);
	
	result = StackPop (stack , item);
	ASSERT_EQUAL(result, STACK_UNDERFLOW);

END_TEST

BEGIN_TEST(StackTopNull)
ReturnMessages result;
Stack* stack = NULL;
int* item;
	
	result = StackTop(stack, item);
	
	ASSERT_EQUAL(result, STACK_NOT_INITIALIZED); 

END_TEST

BEGIN_TEST(StackTopNull2)
ReturnMessages result;
Stack* stack;
int* item = NULL;
	
	stack = StackCreate (1);
	
	result = StackTop(stack, item);
	
	ASSERT_EQUAL(result, ITEM_NOT_INITIALIZED); 

END_TEST

BEGIN_TEST(StackTopUnderFlow)
ReturnMessages result;
Stack* stack;
int *item;
	
	stack = StackCreate (1);
	
	result = StackTop (stack , item);
	
	ASSERT_EQUAL(result, STACK_UNDERFLOW); 

END_TEST

BEGIN_TEST(StackTopSuccess)
ReturnMessages result;
Stack* stack;
int *item = (int*) malloc(sizeof(int)*1);
int num = 4;
	
	stack = StackCreate (1);
	
	StackPush(stack, num);
	StackTop (stack , item);	
	ASSERT_EQUAL(*item, 4);
	
	result = StackPop (stack , item);
	ASSERT_EQUAL(result, STACK_SUCCESS); 

END_TEST

BEGIN_TEST(StackIsEmptyNull)
ReturnMessages result;
Stack* stack = NULL;
		
	result = StackIsEmpty(stack);
	
	ASSERT_EQUAL(result, STACK_NOT_INITIALIZED); 

END_TEST

BEGIN_TEST(StackIsEmptyEmpty)
ReturnMessages result;
Stack* stack;
	
	stack = StackCreate (1);	

	result = StackIsEmpty(stack);
	
	ASSERT_EQUAL(result, STACK_EMPTY); 

END_TEST

BEGIN_TEST(StackIsEmptyNotEmpty)
ReturnMessages result;
Stack* stack;
int num = 4;
	
	stack = StackCreate (1);	
	StackPush(stack, num);
	result = StackIsEmpty(stack);
	
	ASSERT_EQUAL(result, STACK_NOT_EMPTY); 

END_TEST

BEGIN_TEST(StackIsFullNull)
ReturnMessages result;
Stack* stack = NULL;
	
	result = StackIsFull(stack);
	
	ASSERT_EQUAL(result, STACK_NOT_INITIALIZED); 

END_TEST

BEGIN_TEST(StackIsFullNotFull)
ReturnMessages result;
Stack* stack;
	
	stack = StackCreate (1);	

	result = StackIsFull(stack);
	
	ASSERT_EQUAL(result, STACK_NOT_FULL); 

END_TEST

BEGIN_TEST(StackIsFullFully)
ReturnMessages result;
Stack* stack;
int num = 4;
	
	stack = StackCreate (1);	
	StackPush(stack, num);
	result = StackIsFull(stack);
	
	ASSERT_EQUAL(result, STACK_FULL); 

END_TEST

BEGIN_SUITE(不耻下问 this is a description)
    TEST(giveCapacityZero)
    TEST(giveCapacityBigerThenZero)
    TEST(DoubleFree)
    TEST(StackPushNull)
    TEST(StackPushOverFlow)
    TEST(StackPushSuccess)
    TEST(StackPopNull)
    TEST(StackPopNull2)
    TEST(StackPopUnderFlow)
    TEST(StackPopSuccess)
    TEST(StackTopNull)
    TEST(StackTopNull2)
    TEST(StackTopUnderFlow)
    TEST(StackTopSuccess)
    TEST(StackIsEmptyNull)
    TEST(StackIsEmptyEmpty)
    TEST(StackIsEmptyNotEmpty)
    TEST(StackIsFullNull)
    TEST(StackIsFullNotFull)
    TEST(StackIsFullFully)                
END_SUITE
