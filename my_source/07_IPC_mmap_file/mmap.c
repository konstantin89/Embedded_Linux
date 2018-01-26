/**
* Example of mapping file to process memory.
* This technique can be used for inter process communication.
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define MY_ERROR -1
#define SUCCESS 0

#define __IN__
#define __OUT__

/*
* Make sure that you use file located under /tmp
* file system.
* This will prevent data written to disk.
*/
#define FILE_NAME "/tmp/mmap_example"


/**
* Get file length in bytes.
*
* @param: fileName - Full file name.
* @return: On success, length of file in bytes.
*          On error, -1.
*/
int getFileSize(char* __IN__ fileName)
{
    int fd;
    struct stat sb;

    fd = open(fileName, O_RDONLY);
    if(fd == MY_ERROR)
    {
        perror("open");
        return MY_ERROR;
    }

    if(fstat(fd, &sb) == -1)
    {
        perror("fstat");
        return MY_ERROR;
    }

    if(close(fd) == MY_ERROR)
    {
        perror("close");
        return MY_ERROR;
    }

    return sb.st_size;
}

/**
* Map file to process memory.
*
* @param: retPtr - Pointer to mapped file in memory.
* @param: fileToMap - Full file name to be mapped.
* @return: On success 0, otherwise -1.
*/
int mapFile(char** __OUT__ retPtr, char* __IN__ fileToMap)
{
    struct stat sb;
    char *p;
    int fd;

    fd = open(fileToMap, O_RDONLY);
    if(fd == MY_ERROR)
    {
        perror("open");
        return MY_ERROR;
    }

    if(fstat(fd, &sb) == -1)
    {
        perror("fstat");
        return MY_ERROR;
    }

    p = mmap (0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED)
    {
        perror("mmap");
        return MY_ERROR;
    }

    if(close(fd) == MY_ERROR)
    {
        perror("close");
        return MY_ERROR;
    }

    *retPtr = p;
    return SUCCESS;
}


/**
* Read mapped file from process memory.
*
* @param: ptrToFile - Pointer to file in memory.
* @param: fileName - Full file name.
* @return: void.
*/
void readMappedFile(char* __IN__ ptrToFile, char* __IN__ fileName)
{
    int file_len = getFileSize(fileName);
    for(int len = 0; len < file_len; len++)
    {
        putchar(ptrToFile[len]);
    }
}

int main()
{
    /*
    * mmap is mapping memory in multiples of page size.
    * If you try to map memory length that is not multiple
    * of page size, memory length will be rounded toward
    * closest multiple of system page size.
    */
    long page_size = sysconf (_SC_PAGESIZE);
    printf("system page size is [%ld]\n", page_size);

    char* mappedFilePtr = NULL;
    if(mapFile(&mappedFilePtr, FILE_NAME) == MY_ERROR)
    {
        printf("%s\n", "mapFile failed");
        return MY_ERROR;
    }

    while(1)
    {
        /*
        * Since the file is mapped in to process memory,
        * changing it in disk will change it in processes
        * memory.
        */
        readMappedFile(mappedFilePtr, FILE_NAME);
        printf("\n%s%s\n", "***Press any key to read file again, ",
                           "or press ctrl+c to exit***");
        getchar();
    }
    return SUCCESS;
}



/***************** End Of File ******************/
