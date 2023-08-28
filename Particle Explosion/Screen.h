// screen header source

#pragma once
#include <iostream>
#include <SDL.h>

namespace kribsplosion
{
	class Screen
	{
	public:
		// public because we might need to refer to them outside this class
		// static because we only want one of them for the whole screen class
		const static int SCREEN_WIDTH = 1920;
		const static int SCREEN_HEIGHT = 1080;

	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		Uint32* m_buffer1;
		Uint32* m_buffer2;

	public:
		// creating constructor
		Screen();
		// method to update 
		void update();
		// method to take an x and y coordinate to set the pixel at
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		// method to return true or false (false if it fails, true if it succeeds)
		bool init();
		// method to implement event processing 
		bool processEvents();
		// method to close the program
		void close();
		void boxBlur();
	};

}
