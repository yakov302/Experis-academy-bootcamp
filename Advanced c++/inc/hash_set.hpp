#ifndef HACH_SET_H
#define HACH_SET_H

/********************rename structHash***********************/

typedef struct Hash Hash;

/********************function typedef***********************/

typedef size_t (*HashFunction)(void* _data);
typedef int (*EqualityFunction)(void* _firstData, void* _secondData);
typedef void (*keyDestroy)(void* _data);
typedef void (*PrintKey)(void*);

/********************returnMessages***********************/

typedef enum HashSetResult{
SET_SUCCESS,
SET_UNINITIALIZED,
SET_KEY_DUPLICATE,
SET_KEY_NOT_FOUND,
SET_OVERFLOW
}HashSetResult;

/*Description:
Create generic Hash in which each element is void* and can point to any type.

Input:
_size - The size of the hash.
_HashFunction - pointer to mathematical function that make hash on the key. (received from the user)
_EqualityFunction - pointer to function that compares the key received from the user to the key in the hashindex]. Returns 1 if they are the same and 0 if different. (received from the user)

Output:
NULL - if one of the memory allocations failed.
hash - Pointer to the Hash structure.*/
Hash* HashCreate(size_t _size, HashFunction _HashFunction, EqualityFunction _EqualityFunction);

/*Description:
Destroys all the Hash elements, the Hash arrays, and the Hash structure.

Input:
**_hash - Pointer to pointer to the Hash structure. get &*hash.
_keyDestroy - pointer to function that destroys all the Hash elements. (if necessary)*/
void HashDestroy(Hash** _hash, keyDestroy _keyDestroy);

/*Description:
insert new element to the Hash. get void* that can point to any type.

Input:
*_hash - Pointer to the Hash structure.
*_data - new element (pointer) that will enter the Hash.

Output:
SET_UNINITIALIZED - if _hash == NULL || _data == NULL
SET_OVERFLOW - If number of elements in the Hash equal to the Hash size.
SET_SUCCESS -  If the new element enters the Hash successfully.
SET_KEY_DUPLICATE - If the key that the user wants to enter into the hash already exists in the hash. (No duplicate key in the Hash)*/
HashSetResult HashInsert(Hash* _hash, void* _data);

/*Description:
Deletes element with the _key (void*) frome the Hash and put his data it _data variable - get &(void*).

Input:
*_hash - Pointer to the Hash structure.
*_key - The element with the key we want to delete from the hash.
**_data - pointer to pointer variable that will receive the deleted element data - get &(*void).

Output:
SET_UNINITIALIZED - if _hash == NULL || _data == NULL || *_data == NULL || _key == NULL. 
SET_SUCCESS - If the deleted element was deleted successfully.
SET_KEY_NOT_FOUND - If the key of the element we want to delete is not found in the hash*/
HashSetResult HashRemove(Hash* _hash, void* _key, void** _data);

/*Description:
Checks if an element is in the hash or not.

Input:
*_hash - Pointer to the Hash structure.
*_key - The element we want to check.

Output:
1 - if the element is in the hash.
0 - if the element is not in the hash.*/
int HashIsFound(const Hash* _hash, void* _key);

/*Description:
Returns the number of elements in the hash.

Input:
*_hash - Pointer to the Hash structure.

Output:
0 - if _hash == NULL or if there are no elements in the hash.
_hash -> m_numOfItem - the number of elements in the hash*/
size_t HashNumOfItem(const Hash* _hash);

/*Description:
Returns the size of the original hash received from the user.

Input:
*_hash - Pointer to the Hash structure.

Output:
0 - if _hash == NULL.
_hash -> m_hashSize - the size of the hash.*/
size_t HashCapacity(const Hash* _hash);

/*Description:
Returns the average Rehashes number.

Input:
*_hash - Pointer to the Hash structure.

Output:
0 - if _hash == NULL.
AverageRehashes - the average Rehashes number.*/
double HashAverageRehashes(const Hash* _hash);

/*Description:
Returns the maximum Rehashes number

Input:
*_hash - Pointer to the Hash structure.

Output:
0 - if _hash == NULL or if the maximum Rehashes number is 0.
_hash -> m_maxOfRehashOperations - the maximum Rehashes number.*/
size_t HashMaxEeHash(const Hash* _hash);

/*Description:
Print all the elements in the hash.

Input:
*_hash - Pointer to the Hash structure.
_PrintKey - Pointer to the print function received from the user.*/
void HashPrint(const Hash* _hash, PrintKey _PrintKey);

#endif /*#ifndef HACH_SET_H*/