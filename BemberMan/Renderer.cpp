#include "Renderer.h"


namespace Engine{
	Renderer::Renderer():renderer(nullptr) {}

	Renderer::Renderer(Window &window){
		Create(window);
	}


	Renderer::~Renderer(){
		Destroy();
	}

	SDL_Renderer * Renderer::Get()const{
		return renderer;
	}

	int Renderer::Create(Window &window){
		renderer = SDL_CreateRenderer(window.Get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if(!renderer){
			Error("Can't create renderer!");
			return -1;
		}
		return 0;
	}

	int Renderer::ReCreate(Window &window){
		Destroy();
		return Create(window);
		
	}

	void Renderer::Destroy(){
		if(renderer)
			SDL_DestroyRenderer(renderer);
	}


}