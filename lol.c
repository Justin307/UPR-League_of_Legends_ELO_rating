//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lol.h"

/**
 * Check if the structure inside the file is ok or if the file isn't empty
 * File containing players id and name
 * @param fileName String - Name of the file
 * @return true if file structure is ok / else if file structure is not ok
 */
bool checkPlayerFileStructure(char* fileName)
{
    FILE* file = fopen(fileName,"r");
    if(!file)
    {
        printf("File could not be opened");
        return false;
    }

    int id = 0;
    char nickname[100];
    int fsOutput;
    bool firstLine = true;

    while(true)
    {
        /*
         * fscanf return number of items successfully matched
         * -1 -> line is empty
         *  0 -> nothing matched
         * >0 -> how many were matched
        */
        fsOutput = fscanf(file,"%d,%s",&id, nickname);

        // empty file
        if(fsOutput == -1)
        {
            if(firstLine == true)
            {
                printf("File is empty");
                return false;
            }
            break;
        }

        //some line didn't match
        if(fsOutput != 2)
        {
            printf("Structure of file %s is wrong",fileName);
            return false;
        }

        //test printf
        printf("%d - %s\n", id,nickname);

        //not first line
        if(firstLine == true)
        {
            firstLine = false;
        }
    }
    return true;
}

/**
 * Check if the structure inside the file is ok or if the file isn't empty
 * File containing history of games
 * @param fileName String - Name of the file
 * @return true if file structure is ok / else if file structure is not ok
 */
bool checkGameFileStructure(char* fileName)
{
    FILE* file = fopen(fileName,"r");
    if(!file)
    {
        printf("File could not be opened");
        return false;
    }

    char match[50];
    int ids[2*3];
    int kda[2*9];
    char color[20];
    int fsOutput[6];
    bool firstLine = true;

    while(true)
    {
        /*
         * fscanf return number of items successfully matched
         * -1 -> line is empty
         *  0 -> nothing matched
         * >0 -> how many were matched
        */
        fsOutput[0] = fscanf(file,"%s",match);
        fsOutput[1] = fscanf(file,"%d,%d,%d",&ids[0],&ids[1],&ids[2]);
        fsOutput[2] = fscanf(file,"%d;%d;%d,%d;%d;%d,%d;%d;%d",&kda[0],&kda[1],&kda[2],&kda[3],&kda[4],&kda[5],&kda[6],&kda[7],&kda[8]);
        fsOutput[3] = fscanf(file,"%d,%d,%d",&ids[3],&ids[4],&ids[5]);
        fsOutput[4] = fscanf(file,"%d;%d;%d,%d;%d;%d,%d;%d;%d",&kda[9],&kda[10],&kda[11],&kda[12],&kda[13],&kda[14],&kda[15],&kda[16],&kda[17]);
        fsOutput[5] = fscanf(file,"%s",color);

        // empty file
        if (fsOutput[0] == -1) {
            if (firstLine == true) {
                printf("File is empty");
                return false;
            }
            break;
        }

        //some line didn't match
        if(fsOutput[0] != 1 || fsOutput[1] != 3 || fsOutput[2] != 9 || fsOutput[3] != 3 || fsOutput[4] != 9 || fsOutput[5] != 1)
        {
            printf("Structure of file %s is wrong",fileName);
            return false;
        }

        //test printf
        printf("%s\n",match);
        printf("%d %d %d\n",ids[0],ids[1],ids[2]);
        printf("%d %d %d %d %d %d %d %d %d\n",kda[0],kda[1],kda[2],kda[3],kda[4],kda[5],kda[6],kda[7],kda[8]);
        printf("%d %d %d\n",ids[3],ids[4],ids[5]);
        printf("%d %d %d %d %d %d %d %d %d\n",kda[9],kda[10],kda[11],kda[12],kda[13],kda[14],kda[15],kda[16],kda[17]);
        printf("%s\n\n",color);

        //Check for the word "match"
        if(strcmp("match",match) != 0)
        {
            printf("The word \"match\" wasn't found");
            return false;
        }

        //Check for same id
        qsort(ids,6,sizeof(*ids),compare_function);
        for(int i = 0; i < 5; i++)
        {
            if (ids[i] == ids[i + 1])
            {
                printf("Players ID was found multiplke times in one match");
                return false;
            }
        }

        //Check color of winning team
        if(!(strcmp("red",color) == 0 || strcmp("blue",color) == 0))
        {
            printf("Wrong color on the of the winning team");
            return false;
        }

        //not first line
        if(firstLine == true)
        {
            firstLine = false;
        }
    }
    return true;
}

/**
 * Compare function for qsort()
 */
int compare_function (const void *x, const void *y)
{
    int* a = (int*) x;
    int* b = (int*) y;
    return  *a - *b;
}