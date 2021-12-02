#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "lol.h"
#include "htmlwriter.h"
#include "generalhelper.h"

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
                fclose(file);
                return false;
            }
            break;
        }

        //some line didn't match
        if(fsOutput != 2)
        {
            printf("Structure of file %s is wrong",fileName);
            fclose(file);
            return false;
        }

        if(strlen(nickname) > 16)
        {
            printf("At least one of the nicknames has more then 16 characters.");
            fclose(file);
            return false;
        }

        //test printf
        printf("%d - %s - %d\n", id,nickname, strlen(nickname));

        //not first line anymore
        if(firstLine == true)
        {
            firstLine = false;
        }
    }
    fclose(file);
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
    int kad[2 * 9];
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
        fsOutput[2] = fscanf(file, "%d;%d;%d,%d;%d;%d,%d;%d;%d", &kad[0], &kad[1], &kad[2], &kad[3], &kad[4], &kad[5], &kad[6], &kad[7], &kad[8]);
        fsOutput[3] = fscanf(file,"%d,%d,%d",&ids[3],&ids[4],&ids[5]);
        fsOutput[4] = fscanf(file, "%d;%d;%d,%d;%d;%d,%d;%d;%d", &kad[9], &kad[10], &kad[11], &kad[12], &kad[13], &kad[14], &kad[15], &kad[16], &kad[17]);
        fsOutput[5] = fscanf(file,"%s",color);

        // empty file
        if (fsOutput[0] == -1) {
            if (firstLine == true) {
                printf("File is empty");
                fclose(file);
                return false;
            }
            break;
        }

        //some line didn't match
        if(fsOutput[0] != 1 || fsOutput[1] != 3 || fsOutput[2] != 9 || fsOutput[3] != 3 || fsOutput[4] != 9 || fsOutput[5] != 1)
        {
            printf("Structure of file %s is wrong",fileNameGames);
            fclose(file);
            return false;
        }

        //test printf
        printf("%s\n",match);
        printf("%d %d %d\n",ids[0],ids[1],ids[2]);
        printf("%d %d %d %d %d %d %d %d %d\n", kad[0], kad[1], kad[2], kad[3], kad[4], kad[5], kad[6], kad[7], kad[8]);
        printf("%d %d %d\n",ids[3],ids[4],ids[5]);
        printf("%d %d %d %d %d %d %d %d %d\n", kad[9], kad[10], kad[11], kad[12], kad[13], kad[14], kad[15], kad[16], kad[17]);
        printf("%s\n\n",color);

        //Check for the word "match"
        if(strcmp("match",match) != 0)
        {
            printf("The word \"match\" wasn't found");
            fclose(file);
            return false;
        }

        //Check for same id
        qsort(ids,6,sizeof(*ids),compare_function);
        for(int i = 0; i < 5; i++)
        {
            if (ids[i] == ids[i + 1])
            {
                printf("Players ID was found multiple times in one match");
                fclose(file);
                return false;
            }
        }

        if(checkIDExistence(fileNamePlayers,ids) == false)
        {
            printf("Nonexistent player id found in match");
            fclose(file);
            return false;
        }


        //Check color of winning team
        if(!(strcmp("red",color) == 0 || strcmp("blue",color) == 0))
        {
            printf("Wrong color on the of the winning team");
            fclose(file);
            return false;
        }

        //not first line
        if(firstLine == true)
        {
            firstLine = false;
        }
    }
    fclose(file);
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
                return false;
            }
        }
    }

    fclose(file);
    free(playerIds);
    playerIds = NULL;
    return true;
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
    fclose(file);
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

void updatePlayersFromMatchFile(Player *players,int playerCount, char* fileName)
{
    int matchesRemaining = matchCount(fileName);
    FILE* file = fopen(fileName,"r");
    if(!file)
    {
        printf("File could not be opened");
        return;
    }
    char match[6];
    int ids[2*3];
    int kad[2*9];
    char color[5];
    int playerStructID = 0;
    int opponentsELO;
    int playerELO;
    int didHeWon;
    int coefficient = 30;
    float playerMatchELO;



    //TODO SECURE MATCH COUNT
    while(matchesRemaining != 0)
    {
        fscanf(file,"%s",match);
        fscanf(file,"%d,%d,%d",&ids[0],&ids[1],&ids[2]);
        fscanf(file, "%d;%d;%d,%d;%d;%d,%d;%d;%d", &kad[0], &kad[1], &kad[2], &kad[3], &kad[4], &kad[5], &kad[6], &kad[7], &kad[8]);
        fscanf(file,"%d,%d,%d",&ids[3],&ids[4],&ids[5]);
        fscanf(file, "%d;%d;%d,%d;%d;%d,%d;%d;%d", &kad[9], &kad[10], &kad[11], &kad[12], &kad[13], &kad[14], &kad[15], &kad[16], &kad[17]);
        fscanf(file,"%s",color);
        matchesRemaining--;

        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < playerCount; j++)
            {
                if(ids[i] == players[j].id)
                {
                    playerStructID = j;
                    break;
                }
            }
            players[playerStructID].kills += kad[i*3+0];
            players[playerStructID].assists += kad[i*3+1];
            players[playerStructID].deaths += kad[i*3+2];
            players[playerStructID].matchPlayed +=1;
            if(i<3)
            {
                players[playerStructID].teamRed +=1;
                if(!strcmp(color,"red"))
                {
                    players[playerStructID].matchWon +=1;
                    didHeWon = 1;
                }
                else
                {
                    didHeWon = 0;
                }

                playerELO = getELOOfPlayer(ids[i],players,playerCount);
                opponentsELO = (getELOOfPlayer(ids[3],players,playerCount) + getELOOfPlayer(ids[4],players,playerCount) + getELOOfPlayer(ids[3],players,playerCount)) / 3.0;
                playerMatchELO = 1 / (1 + pow(10,(opponentsELO-playerELO)/400));
                players[playerStructID].elo = playerELO + coefficient * (didHeWon - playerMatchELO);

            }
            else
            {
                players[playerStructID].teamBlue +=1;
                if(!strcmp(color,"blue"))
                {
                    players[playerStructID].matchWon +=1;
                    didHeWon = 1;
                }
                else {
                    didHeWon = 0;
                }

                playerELO = getELOOfPlayer(ids[i],players,playerCount);
                opponentsELO = (getELOOfPlayer(ids[0],players,playerCount) + getELOOfPlayer(ids[1],players,playerCount) + getELOOfPlayer(ids[2],players,playerCount)) / 3.0;
                playerMatchELO = 1 / (1 + pow(10,(opponentsELO-playerELO)/400));
                players[playerStructID].elo = playerELO + coefficient * (didHeWon - playerMatchELO);
            }
        }
    }

    fclose(file);
}

int getELOOfPlayer(int id, Player *players, int playerCount)
{
    for(int i = 0; i < playerCount; i++)
    {
        if(id == players[i].id)
        {
            return players[i].elo;
        }
    }
    return 1000;
}

char* getDivision(int elo)
{
    if(elo<=1149)
        return "Bronze";
    else if(elo<=1499)
        return "Silver";
    else if(elo<=1849)
        return "Gold";
    else if(elo<=2199)
        return "Platinum";
    else
        return "Diamond";
}

bool createPlayerHTMLFile(char* fileName, Player* players, int playerCount)
{
    FILE* file = fopen(fileName,"w");
    if(file == NULL)
    {
        printf("File couldn't be opened");
        return false;
    }

    writeHtmlHeader(file);
    writeTableTop(file);
    writeTableTh(file,"#");
    writeTableTh(file,"Nickname");
    writeTableTh(file,"ELO rating");
    writeTableTh(file,"Division");
    writeTableTh(file,"K/D/A");
    writeTableTh(file,"Match won/played");
    writeTableTh(file,"Team red/blue");
    writeTableMiddle(file);
    for(int i = 0; i < playerCount; i++)
    {
        writeTableTrBeginning(file);

        //ID
        writeTableTdBeginning(file);
        writeInt(file,players[i].id);
        writeTableTdEnd(file);
        //Nickname
        writeTableTd(file,players[i].nickname);
        //ELO
        writeTableTdBeginning(file);
        writeInt(file,players[i].elo);
        writeTableTdEnd(file);
        //Division
        writeTableTd(file,getDivision(players[i].elo));
        //K/D/A
        writeTableTdBeginning(file);
        writeInt(file,players[i].kills);
        writeChar(file,'/');
        writeInt(file,players[i].deaths);
        writeChar(file,'/');
        writeInt(file,players[i].assists);
        writeTableTdEnd(file);
        //Match won/played
        writeTableTdBeginning(file);
        writeInt(file,players[i].matchWon);
        writeChar(file,'/');
        writeInt(file,players[i].matchPlayed);
        writeTableTdEnd(file);
        //Team red/blue
        writeTableTdBeginning(file);
        writeInt(file,players[i].teamRed);
        writeChar(file,'/');
        writeInt(file,players[i].teamBlue);
        writeTableTdEnd(file);

        writeTableTrEnd(file);
    }
    writeTableBottom(file);
    WriteHtmlFooter(file);

    fclose(file);
    return true;
}

int matchCount(char* fileName)
{
    FILE* file = fopen(fileName,"r");
    int matchCount = 0;
    if(file != NULL)
    {
        char string[51];
        while(!feof(file))
        {
            fscanf(file,"%s",string);
            if(strcmp(string,"match") == 0)
                matchCount++;
        }
    }
    else
    {
        printf("File doesn't exist\n");
    }
    fclose(file);
    return matchCount;
}















