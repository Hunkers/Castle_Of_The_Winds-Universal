/**
Project Gamma: Castle of the Winds Redux
@author Julien F.
@version 0.02a Wherein We Start Clean
**/

//Standard Include
#include <fstream>
//SDL Include
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//User Include
#include "../include/logError.h"

/** Initial Settings Variables
Variables that the main function needs in order to launch the game initially
with the correct settings loaded from storage. These variables should be set by
a call to the initRead() function.
**/
int WINDOW_X = 1024; //Window X Dimension.
int WINDOW_Y = 600;  //Window Y Dimension.
int TILE_SIZE = 32;  //Dimension in pixes of one tile in the game.

//Read initialization variables from settings.ini. Return true if reading 
//went as expected. Return false if an issue was found.
bool initRead() {
	std::ifstream infile("settings.ini"); //Open input filestream.
	if (infile.is_open()) { //Ensure the file opened.
		std::string settingIn;
		while (getline(infile, settingIn)) { //Read in lines one at a time.
			std::size_t found = settingIn.find("#");
			//If we see a # indicating a comment we discard the comment from execution consideration.
			if (found != std::string::npos) { settingIn = settingIn.substr(0, found); }
			found = settingIn.find("=");
			if (found != std::string::npos) {
				std::string variable = settingIn.substr(0, found);
				std::string value = settingIn.substr(found+1, settingIn.length());

				//std::cout << variable << std::endl;
				//std::cout << value << std::endl << std::endl;
			}
		}
		return true;	
	} else { 
		return false;
	}
}

//Main function, starting point of execution for the program.
int main(int argc, char** argv) {
	/**PRE-GAME LOOP**/
	//Read settings.ini
	if (!initRead()) {
		logError(std::cout, "Initialization from settings.ini failed."); 
		return EXIT_FAILURE; 
	}

	//SDL Video Subsystem Initialization
	if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
		logSDLError(std::cout, "SDL_INIT failed.");
		return EXIT_FAILURE;
	}
	
	//SDL_Image Subsystem Initialization
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
		logSDLError(std::cout, "IMG_INIT failed.");
		SDL_Quit();
		return EXIT_FAILURE;
	}

	//SDL Window Creation
	SDL_Window* app = SDL_CreateWindow("Hello World!", 100, 100, WINDOW_X, WINDOW_Y, SDL_WINDOW_SHOWN);
	//Error Handling
	if (app == nullptr) {
		logSDLError(std::cout, "CreateWindow");
		IMG_Quit();
		SDL_Quit();
		return EXIT_FAILURE;
	}

	//SDL Renderer Creation
	SDL_Renderer* renderer = SDL_CreateRenderer(app, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//Error Handling
	if (renderer == nullptr) {
		logSDLError(std::cout, "CreateRenderer");
		cleanup(app);
		IMG_Quit();
		SDL_Quit();
		return EXIT_FAILURE;
	}
	
	/**Game Creation
	Sets up the game for the application.
	**/
	static Core game(app, renderer);
	if (game.initFailed()) {
		return EXIT_FAILURE;
	}	

	/**Clock & Time Creation**/
	const float DELTA_T = 0.0f;
	const float INTERPOLATION = 0.0f;
	
	/**GAME LOOP**/
	while (game.isRunning()) {
		//Clear the application window for new update and drawing.
		SDL_RenderClear(renderer);
		
		/**Logic Update**/
		//Update the game logic in DELTA_T increments for the Core.
		game.update(DELTA_T);

		/**Display Draw**/
		//Update the game display taking INTERPOLATION into account.
		game.draw(INTERPOLATION);

		/**Update Renderer**/
		//Update the SDL Renderer to display to the player.
		SDL_RenderPresent(renderer);
	}

	/**POST GAME LOOP**/
	//Clean everything up and quit SDL.
	cleanup(renderer, app);
	SDL_Quit();

	//Program closed successfully reaching end of execution.
	return EXIT_SUCCESS;
}
