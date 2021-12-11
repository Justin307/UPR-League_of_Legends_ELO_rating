#include <stdio.h>
#include <stdlib.h>

#include "lol.h"
#include "generalhelper.h"

//argv[1] - file with games / argv[2] - file with players / argv[3] - output file
int main(int argc, char * argv[])
{
    if((argc-1) < 3)
    {
        printf("\nNot enough files on the input");
        return 1;
    }

    for(int i = 1; i < 3; i++)
    {
        if(!(checkFileExistence(argv[i])))
        {
            printf("\nFile %s not found",argv[i]);
            return 1;
        }
    }

    if(!(checkPlayerFileStructure(argv[2])))
    {
        return 1;
    }

    if(!(checkGameFileStructure(argv[1],argv[2])))
    {
        return 1;
    }

    int playerCount = countPlayers(argv[2]);

    Player *players;
    players = (Player*) malloc(sizeof(Player) * playerCount);

    initializePlayers(players,playerCount,argv[2]);
    printPlayersToConsole(players,playerCount);
    updatePlayersFromMatchFile(players,playerCount,argv[1]);
    printPlayersToConsole(players,playerCount);

    createPlayerHTMLFile(argv[3],players,playerCount);

    free(players);
    players = NULL;
    return 0;
}
