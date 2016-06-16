#ifndef GAMESCREEN_H
#define GAMESCREEN_H

//SDL Include
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//User Include
#include "screen.h"

class GameScreen : public Screen {
	private:
		SDL_Texture* background;
		SDL_Texture* foreground;

		int SCREEN_WIDTH; 
		int SCREEN_HEIGHT; 
		int TILE_SIZE;

		std::string respath;

	public:
		/**Constructors**/
		GameScreen();
		GameScreen(SDL_Window* a, SDL_Renderer* r, std::string re);

		/**Utility Functions**/
		//Allows the main function to gracefully error out if something failed to initialize in the constructor.
		//Initializes the graphical elements of the screen.
		bool initialize();

		/**GameScreen Functions**/
		void hideScreen();
		void showScreen();

		/**Draw Function**/
		void draw(const float INTERPOLATION);
};

#endif //GAMESCREEN_H INCLUDED
