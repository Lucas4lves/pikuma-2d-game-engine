#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Logger/Logger.h" 
#include <glm/glm.hpp>

//Capping framerate
const int FPS = 60; 
const int MILLISECONDS_PER_FRAME = 1000 / FPS;

class Game
{
	private:
		//TODO:
		int milliseconds_prev_frame = 0;
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
