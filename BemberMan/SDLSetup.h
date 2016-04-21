#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <fstream>
#include <Windows.h>
#include <string>
/*namespace Engine - whose store component of SDL library */
namespace Engine{
	/*
	Display error in window MessageBox
	@param const char* - error desription
	*/
	
	int Error(const char* message);


	/*
	*Class SDLSetup - Init SDL library and create a windows and store basic information about windows
	@ Size window
	@ Coords window
	@ Buffer a draw
	@ Flag to fullscreen or window
	*/
	class SDLSetup{
	public:
		
		/*Constructor SDLSetup and create window*/
		SDLSetup();
		/*Clear buffor, destroy object and delete*/
		~SDLSetup();
		/*
		Geter Renderer
		@param void
		@return SDL_Renderer* 
		*/
		SDL_Renderer* Renderer()const;
		
		/*
		*Geter window width
		@param void
		@return int &width window*/
		const int &Width()const;

		/*Getter window height
		@param void
		@return int& height window*/
		const int &Height()const;

	private:
		/*Set window possition
		@param void
		@return void*/
		void SetWindowPosition();

		//load screen parameter from file
		//void load();


		/*Pointer renderer window - buffer to draw on window*/
		SDL_Renderer* renderer;

		/*Pointer display window - disply window on screen*/
		SDL_Window* display;
		/*bool fulscreen - contained information about window maximize*/
		bool fullScreen;
		/*unsigned int - contained screen width*/
		size_t width;
		/*unsigned int - contained screen height*/
		size_t height;
		/*int x - coordest x*/
		int x;
		/*int y - coordest y*/
		int y;
	};
}