#include <stdio.h>

/**
* Typical union usage.
* We can define union that allows us
* to access 4 registers(each one byte).
*/
typedef union
{
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } bytes;
    unsigned int dword;
} HW_Register;


int main()
{
    HW_Register reg;
    reg.dword = 0x12345678;

    //Output: Second byte of 12345678 is 56
    printf("Second byte of %x is %x\n", reg.dword, reg.bytes.byte2);

    reg.bytes.byte2 = 0x99;

    //Output: Second byte of 12349978 is 99
    printf("Second byte of %x is %x\n", reg.dword, reg.bytes.byte2);

    return 0;
}



/************************* End Of File **************************/
