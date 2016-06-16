#ifndef CORE_H
#define CORE_H

//SDL Include
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//User Include
#include "shell.h"

class Core {
	private:
		Shell* display;
		SDL_Window* app;
		SDL_Renderer* renderer;

		int pX, pY;
		bool gameLoop;
		int TILE_SIZE;
		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;
	public:
		/**Constructors**/
		Core();
		Core(SDL_Window* a, SDL_Renderer* r);

		/**Accessors & Mutators**/
		//Tells the Core who the Shell is.
		void setShell(Shell* s) { display = s; }
		//Checks if the Core is running and thus by extension the game itself.
		bool isRunning();
		//Set to true if the constructor detected an error while initializing.
		bool initFailed();
		
		/**Update Function**/
		//Updates the Game Logic by time change DELTA_T.
		void update(const float DELTA_T);
		/**Draw Function**/
		void draw(const float INTERPOLATION);
};

#endif //CORE_H INCLUDED
