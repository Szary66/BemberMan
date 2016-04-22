#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "ReDefinitions.h"
#include <fstream>
#include <Windows.h>
#include <string>
/*namespace Engine - whose store component of SDL library */
namespace Engine{
	/*
	Display error in window MessageBox
	@param const char* - error desription*/
	int Error(const char* message);


	/*
	*Class SDLSetup - Init SDL library and create a windows and store basic information about windows
	@Size window
	@Coords window
	@Buffer a draw
	@Flag to fullscreen or window mode*/
	class SDLSetup{
	public:
		/*Clear buffor, destroy object and delete*/
		~SDLSetup();
		/*
		Geter Renderer
		@param void
		@return SDL_Renderer* 
		*/
		int InitSDL();

	private:		
		//load screen parameter from file
		//void load();

		int InitMainSDL();

		int InitTTF();
	};
}