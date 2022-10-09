#include <SDL.h>
#include <stdio.h>
#include <thread> //std::this_thread;
//#include <chrono>

#include "Window.h"
#include "Functions.h"
#include "main.h"
#include <chrono>

//Screen dimension constants
constexpr int BUTTON_ON_LENGTH = 0xff;
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;
constexpr int tileSize = 16; 
constexpr int NUM_OF_LETTERS = 26;
size_t GetIndex(char a) {
	return a - 'a'; 
}
SDL_Event e; 
long long i; 
int main(int argc, char* args[]) {

	GameState_t gamestate;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		long long buttonTimes[NUM_OF_LETTERS] = { 0 };
		double totalFrameTime = 0; 
		auto tp1 = std::chrono::system_clock::now(); 
		Player player(16, 16, 16, 16);
		World world;
		auto eh = Window("default test Window", SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
		auto ss = SDL_GetWindowSurface(eh.wind);
		SDL_Rect screenRect = { 0,0,0,0 };
		SDL_Rect wRect = { 16,16,16,16 }; 
		SDL_GetWindowSize(eh.wind, &screenRect.w, &screenRect.h);
		long long drawWRectTime = 0;
		long long buttonFade = 0x0;

		while (!gamestate.quit) {
			auto ss = SDL_GetWindowSurface(eh.wind);
			SDL_Rect screenRect = { 0,0,0,0 };
			SDL_GetWindowSize(eh.wind, &screenRect.w, &screenRect.h);
			SDL_FillRect(ss, &screenRect, 0xffffff);

			while (SDL_PollEvent(&e) != NULL)
			{
				PopulateGameState(e, gamestate);
				if (gamestate.isKeyDown == true) {
					size_t index = GetIndex(gamestate.lastKeyDown);
					if(index < NUM_OF_LETTERS && index>0){
						buttonTimes[index] = BUTTON_ON_LENGTH;
						
					}
				}
				if (gamestate.quit) {
					printf("\n\nthanks for playing\n\n"); 
				}

			}
			//BUTTON_ON_LENGTH
			if (buttonTimes[GetIndex('w')]) {
				auto color = 0xffffff - buttonFade; 
				printf("color #%X\n", buttonFade);
				SDL_FillRect(ss, &wRect, color);
 				--buttonTimes[GetIndex('w')];
				buttonFade += 0x010101;

			}
			i++;
			SDL_UpdateWindowSurface(eh.wind);
			auto tp2 = std::chrono::system_clock::now();
			auto deltaTime = std::chrono::duration_cast<std::chrono::duration<double,std::milli>>(tp2 - tp1).count();
			totalFrameTime += deltaTime; 
			if (i % 1000 == 0) {
				auto averageRenderTime = totalFrameTime / (double)i; 
				auto afps = 1.0 / averageRenderTime;
				afps *= 1000;

				auto spbp = (double)BUTTON_ON_LENGTH/afps; 
				auto mpbp = spbp/60.0;
				printf("average frame time over %d frames : %f (%f fps) \n ", i, averageRenderTime, afps);
				printf("\tseconds per a button press = %fs (%fm) \n ", spbp, mpbp);
			}

			tp1 = tp2;
				}
		//SDL_Quit(); //this is not nessisary in C++ because the implicit destructors are called
		//and what ever is not trivaly descructable is cleaned up by the kernal
		//for somereason this is causing the program to hang on quit so do not use.
		return 0;
	}
}