#include <iostream>
#include <SDL2/SDL.h>
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

	windowHeight = 400;
	windowWidth = 600;

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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	if(!renderer)
	{
		fprintf(stderr, "Error: %s", SDL_GetError());
		return;
	}

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

void Game::Update()
{
	//TODO:
	std::cout << "Update Method  Called!" << std::endl;
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

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
