#include <stdio.h>
#include <stdbool.h>

#include "generalhelper.h"

/**
 * Check if a file exist or not
 * @param fileName string - Name of the file
 * @return true if file exist /  else if file doesn't exist
 */
bool checkFileExistence(const char *fileName)
{
    FILE* file;
    if((file = fopen(fileName, "r")))
    {
        fclose(file);
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Compare function for qsort()
 * @param x void* - address of first number
 * @param y void* - address of second number
 * @return 0 - numbers are the same / >0 - first number is larger / <0 - second number is larger
 */
int compare_function (const void *x, const void *y)
{
    int* a = (int*) x;
    int* b = (int*) y;
    return  *a - *b;
}
