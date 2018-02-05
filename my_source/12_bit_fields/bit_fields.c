#include <stdio.h>


typedef struct SingleBitFlag
{
    unsigned int flag : 1; //Only one bit will be used
} SingleBitFlag;

typedef struct Flags
{
    unsigned char flag1 : 1; //Only one bit will be used
    unsigned char flag2 : 1; //Only one bit will be used
    unsigned char flag3 : 1; //Only one bit will be used
    unsigned char flag4 : 1; //Only one bit will be used
} Flags;


int main()
{
    SingleBitFlag bitFlag;

    bitFlag.flag = 1;
    //Output: flag value: 1
    printf("flag value: %d\n", bitFlag.flag);

    bitFlag.flag = 2; //Warning.
    //Output: flag value: 0
    printf("flag value: %d\n", bitFlag.flag);


    /*
    * Note that Flags struct has 4 flags (one bit each).
    * sizeof this struct is 1 byte, even that only 4 bits
    * are used.
    *
    * We can define up to 8 single bit flags in this struct,
    * and its size will remain one byte.
    * If 9 flags defined, structs size will increase to 2 bytes.
    */
    Flags flags;
    //Output: sizeof(flags) is: 1
    printf("sizeof(flags) is: %zu\n", sizeof(flags));


    return 0;
}



/*************************** End Of File ***************************/
