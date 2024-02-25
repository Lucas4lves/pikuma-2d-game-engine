#include <iostream>
#include "../Game.h"

Game::Game()
{
	//TODO:
	std::cout << "Constructor Called!" << std::endl;
}

Game::~Game()
{
	//TODO:
	std::cout << "Destructor Called!" << std::endl;
}

void Game::Initialize()
{
	//TODO:
	std::cout << "Initialize Method  Called!" << std::endl;
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		fprintf(stderr, "Error: %s\n", SDL_GetError());
		return; 
	}

	SDL_DisplayMode display_mode;
	SDL_GetCurrentDisplayMode(0, &display_mode);

	windowHeight = display_mode.h;
	windowWidth = display_mode.w;

	window = SDL_CreateWindow("Macross",
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED,
		windowWidth,
		windowHeight,
		0);
	//If such pointer can be flipped to null, throw an error
	if(!window)
	{
		fprintf(stderr, "Error: %s", SDL_GetError());
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if(!renderer)
	{
		fprintf(stderr, "Error: %s", SDL_GetError());
		return;
	}

	SDL_SetWindowDisplayMode(window, NULL);

	is_running = true;
}



void Game::ProcessInput()
{
	//TODO:
	std::cout << "Process Input  Method  Called!" << std::endl;
	SDL_Event e;

	while(SDL_PollEvent(&e))
	{
		switch(e.type)
		{
			case SDL_QUIT:
				is_running = false;
				break;
			case SDL_KEYDOWN:
				if(e.key.keysym.sym == SDLK_ESCAPE)
				{

				is_running = false;
				}
				break;
		}
	}
}


void Game::Setup(){
	//TODO(Lucas): Initialize game objects
	
}

void Game::Update()
{
	//TODO:
	std::cout << "Update Method  Called!" << std::endl;
}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 150, 21, 21, 255);
	SDL_RenderClear(renderer);
	//TODO: Render game objects
	//Render present swaps the buffers
	SDL_Surface * tank_surface = IMG_Load("./assets/images/tree.png"); //relative path to the game's executable	
	SDL_Texture * tank_texture = SDL_CreateTextureFromSurface(renderer, tank_surface);
	SDL_FreeSurface(tank_surface);
	
	SDL_Rect dstRect = {50, 50, 32, 32};
	SDL_RenderCopy(renderer, tank_texture, NULL, &dstRect);

	SDL_DestroyTexture(tank_texture);


	SDL_RenderPresent(renderer);
}

void Game::Run()
{
	//TODO
	std::cout << "Run  Method  Called!" << std::endl;
	while(is_running)
	{
		ProcessInput();
		Update();
		Render();
	}

}

void Game::Destroy()
{
	//TODO:
	std::cout << "Destroy  Method  Called!" << std::endl;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
