#include "SDLSetup.h"
#include <iostream>

namespace Engine{
	int Error(const char* message){
		return MessageBox(NULL, message, "Error!", MB_OK);
	}

	SDLSetup::SDLSetup()
		:width(800), height(600), display(nullptr), renderer(nullptr), fullScreen(false){
		if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
			Error("CAN'T INIT SDL!");
			EXIT_FAILURE;
		}
	/*	if(TTF_Init() != 0){
			Error("Can't init TTF!");
		}*/
		SetWindowPosition();

		renderer = SDL_CreateRenderer(display, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if(renderer == nullptr){
			Error("Can't create renderer!");
			exit(1);
		}
	}


	SDLSetup::~SDLSetup(){
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(display);

		SDL_Quit();
	}


	const int &SDLSetup::Width()const{
		return width;
	}


	const int &SDLSetup::Height()const{
		return height;
	}


	void SDLSetup::SetWindowPosition(){
		//load ();

		if(fullScreen)
			display = SDL_CreateWindow("ROJO GAME", 0, 0, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
		else{
			display = SDL_CreateWindow("ROJO GAME", 50, 50, width, height, SDL_WINDOW_SHOWN);
		}

		if(display == nullptr){
			Error("CAN'T CREATE WINDOW! \n display = null");
			exit(1);
		}
	}


	SDL_Renderer* SDLSetup::Renderer()const{
		return renderer;
	}

	//
	//void SDLSetup::load(){
	//	std::ifstream fin("../Date/mainSave.dat", std::ios::in | std::ios::binary);
	//	int x, y;
	//	if(fin.is_open()){
	//		fin.seekg(8);
	//
	//		fin.read((char*)&w, sizeof w);
	//		fin.read((char*)&h, sizeof h);
	//		fin.read((char*)&fullScreen, sizeof fullScreen);
	//		fin.read((char*)&x, sizeof x);
	//		fin.read((char*)&y, sizeof y);
	//		fin.close();
	//	}
}