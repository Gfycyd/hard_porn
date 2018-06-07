#include <stdlib.h>
#include "stdio.h"
#include <assert.h>
#include <stdbool.h>
#include "bitMap.h"

bool* decimal_to_binary(int value, int size_of_int){
    int val = 0;
    bool* bin_val = (bool*) malloc(sizeof(bool)*size_of_int);
    //printf("%i",(int)sizeof(*bin_val));
    for(int i = 0; i < size_of_int; i++){
        bin_val[i] = false;
        //printf("%i", bin_val[i]);
    }
    //printf("\n");
    int i = size_of_int - 1;
    for(val = value; val >= 1; val = (val/2)){
        bin_val[i] = val % 2 == 1 ? true : false;
        //printf("%i",bin_val[i]);
        i--;
    }
    printf("\n");
    return bin_val;
}

int binary_to_decimal(const bool* bin){
    int value = 0;
    int multer = 1;
    for (int i = sizeof(bin) - 1; i >= 0; i--){
        value += bin[i] * multer;
        multer *= 2;
    }
    return value;
}
void setBitByNumber(int* array, int bit, int position, int size_of_int)
{
    printf("BEGIN\n");
    int counter = position/ size_of_int;
    printf("Index of our element in the array is %i\n",counter);
    printf("Int before change %i\n",*(array+counter));

    int shift_right = size_of_int*(counter+1)-position-1;
    int shift_left = position;
//    printf("%i\n",shift_right);
//    printf("%i\n",shift_left);
    unsigned int zero = 0;
    unsigned int mask010 =(((~zero)>>shift_right)<<(shift_left+shift_right))>>shift_left;
    unsigned int mask101 = ~mask010;
    if (bit==1){
        *(array+counter)=*(array+counter)|mask010;
    }else if (bit==0){
        *(array+counter)=*(array+counter)&mask101;
    }
    printf("Resulting int is %i\n",*(array+counter));
    printf("END\n\n");

//    char * p = (char*) array;
//    array[position] = bit;
}

int getBitByNumber(int* array, int position, int size_of_int)
{
    // this function returns position's bit from the array
    int finder = position;
    int index = 0;
    while (finder > size_of_int - 1){
        finder -= size_of_int;
        index++;
    }
    bool* ar = decimal_to_binary(array[index], size_of_int);
    return ar[finder];

}

void setBitByAddress(void* position, int bit)
{
   //change the last position
    /* int num = *((int *) position);
    if(bit==0) {
        num>>=1;
        num<<=1;
    }
    else if(bit==1) {
        num>>=1;

        num<<=1;
        num++;
    }

    *(int *) position = num;

    //for the case where need to change first bit
   /* int num = *((int *) position);
    if(bit==0) {
      num = abs(num);
    }
    else if(bit==1) {
        num = abs(num) * (-1);
    }

    *(int *) position = num; */
    unsigned char *pos = position;
    unsigned char ex1 = 1;
    unsigned char ex2 = 126;

    if (bit == 1){
        pos[0] = pos[0] | ex1;
    }else{
        pos[0] = pos[0] & ex2;
    }
}

int getBitByAddress(void* position)
{
    // this function returns first bit by memory address 'position'
    unsigned int a = *(unsigned int*)(position);
    a >>= sizeof(a)*8 -1;
    return a;
}
