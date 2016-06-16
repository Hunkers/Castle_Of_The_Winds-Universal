#include "../include/core.h"
#include "../include/shell.h"

//Default Constructor
Core::Core() {
	//Do Nothing.
}

//Standard Constructor
Core::Core(SDL_Window* a, SDL_Renderer* r) {
	app = a;
	renderer = r;
	gameLoop = true;
	display = new Shell(a, r);
}
