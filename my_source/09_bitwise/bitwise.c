#include <stdio.h>
#include <stdlib.h>

/*
* bitwise operators:
*      &  - AND
*      |  - OR
*      ^  - XOR
*      ~  - NOT
*      << - Right shift
*      >> - Left shift
*/


/**
* Function that calculates the number of
* '1' bits in unsigned integer number.
*/
size_t calculate_set_bits(unsigned int num)
{
    size_t counter = 0;
    while(num)
    {
        counter = (num & 1) ? counter+1 : counter;
        num = num>>1;
    }
    return counter;
}

/**
* Swap without temp variable.
*/
#define SWAP(a, b) do{ (a)^=(b); (b)^=(a); (a)^=(b);}while(0)


/**
* Convert decimal uint to string containing
* binary representation.
*/
char* get_str_binary(unsigned int num)
{
    int bits_in_uint = 32;
    char* str = malloc(bits_in_uint + 1);
    for(int i = 0; i < bits_in_uint; i++)
    {
        str[bits_in_uint-1-i] = (num&1) ? '1' : '0';
        num = num>>1;
    }
    str[bits_in_uint] = '\0';
    return str;
}

/**
* Reverse bits of unsigned integer.
*/
unsigned int reverse_bits(unsigned int num)
{

    int iterations = 31;

    unsigned int rev = 0;
    for(; num; num>>=1)
    {
        rev |= num&1;
        rev <<= 1;
        iterations--;
    }
    while(iterations > 0)
    {
        rev <<= 1;
        iterations--;
    }
    return rev;
}


int main()
{
    printf("calculate_set_bits(53) returns %zu\n", calculate_set_bits(53));

    int a = 3, b = 4;
    printf("Before SWAP(a,b): a=[%d], b=[%d] \n", a, b);
    SWAP(a,b);
    printf("After  SWAP(a,b): a=[%d], b=[%d] \n", a, b);

    char* reverse_str = get_str_binary(reverse_bits(6));
    printf("Original uint: 0b%s, Reversed uint: 0b%s\n",
            get_str_binary(6), reverse_str);
    free(reverse_str);

    return 0;
}




/************************* End Of File *****************************/
