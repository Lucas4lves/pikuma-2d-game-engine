#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Game
{
	private:
		//TODO:
		SDL_Window *window;		
		SDL_Renderer *renderer;
		SDL_Rect player;
		bool is_running;
	public:
		Game();
		~Game();
		void Initialize();
		void Setup();
		void Destroy();
		void ProcessInput();
		void Update();
		void Render();
		void Run();

		int windowWidth;
		int windowHeight;
};
#endif
