#include <iostream>
#include "../Game.h"
/*
# Game Loop: 
PROCESS INPUT -> UPDATE THE GAME -> RENDER (displaying things)
*/

int main(int argc, const char * argv[]) 
{
    //TODO: Start a simple game loop
	Game game;

	game.Initialize();

	game.Run();

	game.Destroy();

    return 0;
}
