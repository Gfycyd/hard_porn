#ifndef __BITMAP_H_
#define __BITMAP_H_

bool* decimal_to_binary(int value, int size_of_int);

int binary_to_decimal(const bool* bin);

void setBitByNumber(int* array, int bit, int position, int size_of_int);

int getBitByNumber(int* array, int position, int size_of_int);

void setBitByAddress(void* position, int bit);

int getBitByAddress(void* position);


#endif //__BITMAP_H_