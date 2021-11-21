//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lol.h"

//TODO FILE CLOSING
//TODO CHECK NICKNAME LENGTH

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
 * @param fileNameGames String - Name of the file with games history
 * @param fileNameGames String - Name of the file with players names and ids
 * @return true if file structure is ok / else if file structure is not ok
 */
bool checkGameFileStructure(char* fileNameGames, char* fileNamePlayers)
{
    FILE* file = fopen(fileNameGames,"r");
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
            printf("Structure of file %s is wrong",fileNameGames);
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
                printf("Players ID was found multiple times in one match");
                return false;
            }
        }

        if(checkIDExistence(fileNamePlayers,ids) == false)
        {
            return false;
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
 * Check if all players in the match are in the player file
 * @param fileName String - name of files with player names and ids
 * @param ids int[] - IDs of player in match
 * @return true - all IDs exist / false - some id doesn't exist
 */
bool checkIDExistence(char* fileName, const int ids[6])
{
    int *playerIds;
    int playersCount;

    FILE* file = fopen(fileName,"r");
    if(file == NULL)
    {
        printf("File doesn't exist");
        return false;
    }

    playersCount = fileLines(fileName);
    playerIds = (int*) malloc(sizeof(int) * playersCount);

    char temp[100];

    for(int i  = 0; i < playersCount; i++)
    {
        fscanf(file,"%d,%s",&playerIds[i],temp);
    }

    for(int i  = 0; i < 6; i++)
    {
        for(int j = 0; j <= playersCount; j++)
        {
            if(ids[i] == playerIds[j])
            {
                break;
            }
            if(j == playersCount)
            {
                fclose(file);
                free(playerIds);
                playerIds = NULL;
                printf("Nonexistent player id found in match");
                return false;
            }
        }
    }

    fclose(file);
    free(playerIds);
    playerIds = NULL;

    return true;
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

void initializePlayers(Player* players, int playerCount, char* fileName)
{
    FILE* file = fopen(fileName,"r");
    if(!file)
    {
        printf("File could not be opened");
        return;
    }

    int id;
    char nickname[16];
    for(int i = 0; i < playerCount; i++)
    {
        fscanf(file,"%d,%s", &id, nickname);
        initializePlayerDefaultValue(&players[i],id,nickname);
    }
}

void initializePlayerDefaultValue(Player* player, int id, char* nickname)
{
    player->id = id;
    strcpy(player->nickname,nickname);
    player->elo = 1000;
    player->kills = 0;
    player->assists = 0;
    player->deaths = 0;
    player->matchPlayed = 0;
    player->matchWon = 0;
    player->teamRed = 0;
    player->teamBlue = 0;
}

void printPlayersToConsole(Player *players,int playerCount)
{
    for(int i = 0; i < playerCount; i++)
    {
        printf("ID: %d\n",players[i].id);
        printf("Nickname: %s\n",players[i].nickname);
        printf("ELO: %d\n",players[i].elo);
        printf("K/D/A: %d/%d/%d\n",players[i].kills,players[i].deaths,players[i].assists);
        printf("Match won/played: %d/%d\n",players[i].matchWon,players[i].matchPlayed);
        printf("Team Red/Blue: %d/%d\n\n",players[i].teamRed,players[i].teamBlue);

    }
}
















