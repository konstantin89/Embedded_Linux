#include <stdio.h>
#include <stdlib.h>


void allocate_2d_array(int*** arr,size_t columns, size_t rows)
{
    *arr = malloc(sizeof(int*) * rows);

    for (size_t i = 0; i < rows; i++) {

        (*arr)[i] = malloc(sizeof(int) * columns);
    }
}

int main()
{

/****************** Array of pointers *****************/
    int* array_of_pointers[3];

    for(size_t i=0; i<3; i++)
    {
        array_of_pointers[i] = malloc(sizeof(int));
        *array_of_pointers[i] = i;
    }
    for(size_t i=0; i<3; i++)
    {
        printf("%d ", *array_of_pointers[i]);
    }
    for (size_t i = 0; i < 3; i++) {
        free(array_of_pointers[i]);
    }
    printf("\n");

    /******************* Pointer to array ******************/
    int arr[] = {0,1,2};
    int (*pointer_to_array)[3] = &arr;
    int* pointer_to_int = arr;

    printf("sizeof(*pointer_to_array) = [%zu]\n", sizeof(*pointer_to_array)); //12
    printf("sizeof(*pointer_to_int)   = [%zu]\n", sizeof(*pointer_to_int));   //4


    /********************** 2D arrays *********************/
    size_t columns = 4;
    size_t rows = 3;
    int** arr_2d = NULL;
    allocate_2d_array(&arr_2d, columns,rows);

    for(size_t i=0; i<rows; i++)
    {
        for(size_t j=0; j<columns; j++)
        {
            arr_2d[i][j] = j;
        }
    }

    /**************** Pointer Arithmetics *********************/

    /*
    * Note the following operator precedence:
    *
    * 1)Postfix inc/dec (a++, a--).
    * 2)Postfix inc/dex (++a, --a).
    * 3)Dereference (*a).
    *
    */
    const char* str = "Hello";
    printf("%c\n", *str);      //H
    printf("%c\n", *str++);    //H
    printf("%c\n", *str);      //e
    str--;
    printf("%c\n", *++str);    //e
    //printf("%c\n", ++*str);  //Error, changing read-only value.

    /*************/

    char *c[] = {"First", "Second", "Third", "Fourth"};
    char **cp[] = {c+3, c+2, c+1, c};
    char ***cpp = cp;

    printf("%s ", **++cpp);
    printf("%s ", *--*++cpp+3);
    printf("%s ", *cpp[-2]+3);
    printf("%s \n", cpp[-1][-1]+1);

    return 0;
}



/********************* End Of File ********************/
