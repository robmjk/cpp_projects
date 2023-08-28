// screen cpp source

#include <iostream>
#include <SDL.h>
#include "Screen.h"

namespace kribsplosion
{
	// prefixing with Screen:: to say what class these methods and constructors belong to
	// constructor to initialize the private instance variables
    Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL)
	{

	}
    
    // method to return true or false (false if it fails, true if it succeeds)
	bool Screen::init()
	{
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            // handle initialization error
            return false;
        }

        // creating the window with window name
        m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        // if issue encountered producing window
        if (m_window == NULL)
        {
            SDL_Quit();
            return false; // value of 2 just signifies an error occurrence during execution
        }

        // create essential objects
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC); // ensures our rendering is synchronised with our refresh
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT); // RGBA8888 uses one byte for each pixel (so 4 bytes) - for each pixel we can use from 0 to 255 different shades of each colour

        if (m_renderer == NULL)
        {
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false; // return non-0 integer to signal an error
        }

        if (m_texture == NULL)
        {
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        // contains all memory for the pixels 
        m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // is a type declared by SDL which is equivalent to an int - as an int is 32bits - buffer means area of memory
        m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32)); // memset allows us to set a block of memory with a particular value - sets screen to white (255 or 0xFF)
        memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		return true;
	}

    void Screen::boxBlur() {
        // swap the buffers, so pixel is in m_buffer2 and we are drawing to m_buffer1.
        Uint32* temp = m_buffer1;
        m_buffer1 = m_buffer2;
        m_buffer2 = temp;

        // loop through each pixel in the screen
        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            for (int x = 0; x < SCREEN_WIDTH; x++) {

                /*
                 * box blur matrix:
                 * 0 0 0
                 * 0 1 0
                 * 0 0 0
                 */

                int redTotal = 0;    // accumulator for red channel
                int greenTotal = 0;  // accumulator for green channel
                int blueTotal = 0;   // accumulator for blue channel

                // iterate through a 3x3 neighbourhood around the current pixel
                for (int row = -1; row <= 1; row++) {
                    for (int col = -1; col <= 1; col++) {
                        int currentX = x + col;  // x-coordinate of the current neighbouring pixel
                        int currentY = y + row;  // y-coordinate of the current neighbouring pixel

                        // check if the current neighbour is within the screen bounds
                        if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
                            Uint32 color = m_buffer2[currentY * SCREEN_WIDTH + currentX];  // get color of neighbour

                            // extract individual colors (RGBA)
                            Uint8 red = color >> 24;  
                            Uint8 green = color >> 16; 
                            Uint8 blue = color >> 8;  

                            // accumulate color channel values
                            redTotal += red;
                            greenTotal += green;
                            blueTotal += blue;
                        }
                    }
                }

                // calculate the average color for the current pixel's neighborhood
                Uint8 red = redTotal / 9;
                Uint8 green = greenTotal / 9;
                Uint8 blue = blueTotal / 9;

                // set the current pixel's color to the calculated average
                setPixel(x, y, red, green, blue);
            }
        }
    }

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
    {
        if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
            return;
        }

        Uint32 color = 0;

        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF;

        m_buffer1[(y * SCREEN_WIDTH) + x] = color;
    }

    void Screen::update()
    {
        SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL); // 1st null: specifies we want to use the entire texture - 2nd null: specifies we want to use the entire renderer
        SDL_RenderPresent(m_renderer);
    }

	// method to implement event processing 
	bool Screen::processEvents()
	{
        SDL_Event event;

        while (SDL_PollEvent(&event)) // fetch latest event in order and fill in information here
        {
            if (event.type == SDL_QUIT) // QUIT event is raised if you click on whatever decoration you have set on your window to close the window
            {
                return false;
            }
        }
		return true;
	}

	// method to close the program
		void Screen::close()
	{
            delete[] m_buffer1; // delete buffer array to free up memory
            delete[] m_buffer2;
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyTexture(m_texture);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
	}
}
