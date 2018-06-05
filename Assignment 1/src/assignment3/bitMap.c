#include <stdlib.h>
#include "stdio.h"
#include <assert.h>
#include "bitMap.h"

void setBitByNumber(int* array, int bit, int position)
{
    // array - pointer to the begining of the array
    // position - number of the bit in the 'array'
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit with number 'position' to the 'bit'

    assert(((position < (int)sizeof(array)) && (position >= 0)));
    assert(bit == 0 || bit == 1);
    array[position] = bit;
}

int getBitByNumber(int* array, int position)
{
    // this function returns position's bit from the array
    assert(position < (int)sizeof(array) && position >= 0);
    return array[position];
}

void setBitByAddress(void* position, int bit)
{
    // position - pointer to the bit to change
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit by memory address to 'bit'
    assert(bit == 0 || bit == 1);
    *(int*)position = bit;
}

int getBitByAddress(void* position)
{
    // this function returns first bit by memory address 'position'

    return *(int*)(position);
}