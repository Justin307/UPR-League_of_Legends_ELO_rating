#ifndef UPR_PROJEKT_LOL_H
#define UPR_PROJEKT_LOL_H

#include <stdbool.h>

typedef struct
{
    int id;
    char nickname[17];
    int elo;
    int kills;
    int assists;
    int deaths;
    int matchPlayed;
    int matchWon;
    int teamRed;
    int teamBlue;
}Player;

bool checkPlayerFileStructure(char* fileName);
bool checkGameFileStructure(char* fileNameGames, char* fileNamePlayers);
bool checkIDExistence(char* fileName, const int ids[]);
int countPlayers(char* fileName);
void initializePlayers(Player* players, int playerCount, char* fileName);
void initializePlayerDefaultValue(Player* player, int id, char* nickname);
void printPlayersToConsole(Player *players,int playerCount);
void updatePlayersFromMatchFile(Player *players,int playerCount, char* filename);
int getELOOfPlayer(int id, Player *players, int playerCount);
char* getDivision(int elo);
bool createPlayerHTMLFile(char* fileName, Player* players, int playerCount);
int matchCount(char* fileName);

#endif //UPR_PROJEKT_LOL_H