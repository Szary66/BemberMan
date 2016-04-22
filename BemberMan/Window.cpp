#include "Window.h"

Engine::Window::Window():window(nullptr) {}

Engine::Window::Window(int x, int y, int width, int height, bool fullcreen){
	Create(x, y, width, height, fullcreen);
}

Engine::Window::~Window(){
		Destroy();
}

int Engine::Window::Create(int x, int y, int width, int height, bool fullscreen = false){
	if(fullscreen)
		window = SDL_CreateWindow("SDL GAME", x, y, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
	else
		window = SDL_CreateWindow("SDL GAME", x, y, width, height, SDL_WINDOW_SHOWN);
	if(window){
		Error("Can't create window!");
		return -1;
	}
	
	this->fullscreen = fullscreen;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	return 0;
}

int Engine::Window::ReCreate(int x, int y, int width, int height , bool fullscreen){
	Destroy();
	return Create(x, y, width, height, fullscreen);
}

void Engine::Window::Destroy(){
	if(window)
		SDL_DestroyWindow(window);
}

int Engine::Window::Height() const{
	return height;
}

int Engine::Window::Width() const{
	return width;
}

SDL_Window * Engine::Window::Get()const{
	return window;
}
