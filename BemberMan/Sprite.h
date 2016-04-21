#pragma once
#include "SDLSetup.h"
#include "SDL_image.h"
namespace Engine{
	class Sprite{
	public:
		enum KIND{ EMPTY, GROUND, OBSTANCLE, FURNITURE, MOSTER, HUMAN };

		Sprite(std::string, SDL_Renderer*, int, int, int, int, int*, int*, int, int, KIND, int);
		Sprite(SDL_Texture*, std::string, SDL_Renderer*, int, int, int, int, int*, int*, int, int, KIND, int);
		~Sprite();

		void draw()const;

		//animation when texture is moving
		void setAnimation(int, float);

		//animation when texture isn't moving
		void stopAnimation();

		//load texture from file *.jpg
		SDL_Texture* loadTexture_IMG(std::string file)const;


		SDL_Rect rectSprite;

		int numberOfTexture;

		KIND kind;
	private:
		SDL_Rect rectTexture;
		SDL_Renderer* renderer;
		SDL_Texture* texture;

		int row;
		int xTile;
		int xPlate;
		int yPlate;
		int animationDelay;

		int* xCamera;
		int* yCamera;

		bool firsSprite;

		std::string file;

	};
}