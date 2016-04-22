#pragma once
#include "Window.h"
namespace Engine{
	class Renderer{
	public:
		Renderer();
		Renderer(Window&);
		~Renderer();

		SDL_Renderer* Get()const;

		int Create(Window&);
		int ReCreate(Window&);
		void Destroy();
	private:
		SDL_Renderer* renderer;
	};
}
