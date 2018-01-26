#include <stdio.h>

/*
* MIN macro.
*/
#define MIN(a,b) ((a)<(b))?(a):(b)

/*
* Macro that returns name of variable as string.
*/
#define VAR_NAME(a) #a

int main()
{
	printf("MIN(5,6) = %d\n", MIN(5,6));
	
	int i = 0;
	printf("VAR_NAME(i)=%s\n", VAR_NAME(i));

}



/****************** End Of File *********************/
