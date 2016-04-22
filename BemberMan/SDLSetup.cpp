#include "SDLSetup.h"

namespace Engine{
	int Error(const char* message){
		return MessageBox(NULL, message, "Error!", MB_OK);
	}

	SDLSetup::~SDLSetup(){		
		SDL_Quit();
	}

	int SDLSetup::InitSDL(){
		if(InitMainSDL() || InitTTF())
			return -1;
		return 0;
	}

	int SDLSetup::InitMainSDL(){
		if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
			Error("CAN'T INIT SDL!");
			return -1;
		}
		return 0;
	}

	int SDLSetup::InitTTF(){
		if(TTF_Init() != 0){
			Error("Can't init TTF!");
			return -1;
		}
		return 0;
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