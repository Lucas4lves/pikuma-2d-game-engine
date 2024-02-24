#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
class Game
{
	private:
		//TODO:
		SDL_Window *window;		
		SDL_Renderer *renderer;
		bool is_running;
	public:
		Game();
		~Game();
		void Initialize();
		void Destroy();
		void ProcessInput();
		void Update();
		void Render();
		void Run();
};
#endif