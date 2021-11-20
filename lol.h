#ifndef UPR_PROJEKT_LOL_H
#define UPR_PROJEKT_LOL_H

bool checkPlayerFileStructure(char* fileName);
bool checkGameFileStructure(char* fileNameGames, char* fileNamePlayers);
bool checkIDExistence(char* fileName, int ids[]);
int compare_function (const void *x, const void *y);
int fileLines(char* fileName);

#endif //UPR_PROJEKT_LOL_H