#ifndef SHELL_H
#define SHELL_H

//Standard Include
#include <string>
//SDL Include
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//User Include
#include "gameScreen.h"

class Shell {
	private:
		SDL_Window* app;
		SDL_Renderer* renderer;

		const std::string resPath;
		bool init;

		const int SCREEN_WIDTH = 1024; //Window X Dimension.
		const int SCREEN_HEIGHT = 600; //Window Y Dimension.
		const int TILE_SIZE = 32; //The dimensions in pixels of one tile in the game.

		//Game Screens
		GameScreen* game;

		int pX, pY;

	public:
		/**Constructors**/
		Shell(); 
		Shell(SDL_Window* a, SDL_Renderer* r);

		/**Accessors & Mutators**/
		std::string getResPath() { return resPath; }
		void setPX(int x) { pX = x; }
		int getPX() { return pX; }
		void setPY(int y) { pY = y; }
		int getPY() { return pY; }
		int getScreenWidth() { return SCREEN_WIDTH; }
		int getScreenHeight() { return SCREEN_HEIGHT; }
		int getTileSize() { return TILE_SIZE; }

		/**Utility Functions**/
		//Allows the main function to gracefully error out if something failed to initilize in the constructor.
		bool initFailed();

		/**Draw Function**/
		//Updates the GUI taking into consideration INTERPOLATION
		void draw(const float INTERPOLATION);
};

#endif //SHELL_H INCLUDED
