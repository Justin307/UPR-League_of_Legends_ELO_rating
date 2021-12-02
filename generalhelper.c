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

/**
 * Return number of lines in file
 * @param fileName String - name of file
 * @return -1 - file doesn't exist / 0 - file is empty / >0 - number of lines in file
 */
int fileLines(char* fileName)
{
    FILE* file = fopen(fileName,"r");
    if(file == NULL)
    {
        printf("File doesn't exist");
        return -1;
    }

    char ch;
    int lines = 0;

    if(feof(file))
    {
        return lines;
    }

    while(!feof(file))
    {
        ch = fgetc(file);
        if(ch == '\n')
        {
            lines++;
        }
    }

    fclose(file);
    return lines+1;
}