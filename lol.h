#ifndef UPR_PROJEKT_LOL_H
#define UPR_PROJEKT_LOL_H

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
} Player;

bool checkPlayerFileStructure(char* fileName);
bool checkGameFileStructure(char* fileNameGames, char* fileNamePlayers);
bool checkIDExistence(char* fileName, const int ids[]);
int compare_function (const void *x, const void *y);
int fileLines(char* fileName);
void initializePlayers(Player* players, int playerCount, char* fileName);
void initializePlayerDefaultValue(Player* player, int id, char* nickname);
void printPlayersToConsole(Player *players,int playerCount);


#endif //UPR_PROJEKT_LOL_H