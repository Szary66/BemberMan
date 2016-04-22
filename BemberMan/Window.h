#pragma once
#include "SDLSetup.h"
namespace Engine{
	class Window{
	public:
		Window();
		Window(int, int, int, int, bool);
		~Window();

		int Create(int, int, int, int, bool);
		int ReCreate(int, int, int, int, bool);
		
		void Destroy();

		int Height()const;
		int Width()const;

		SDL_Window* Get()const;

	private:
		SDL_Window* window;

		int x;
		int y;

		int width;
		int height;

		bool fullscreen;
	};
}