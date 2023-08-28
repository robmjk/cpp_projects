// particle explosion source using the SDL2 graphical library

#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using namespace std;
using namespace kribsplosion;

int SDL_main(int argc, char* argv[])
{

    srand(time(NULL));

    Screen screen;

    if (screen.init() == false)
    {
        cout << "Error initializing SDL" << endl;
    }

    Swarm swarm;

    while (true)
    {
        // update particles (positions/states, colour, etc...)
        // draw particles

        int elapsed = SDL_GetTicks();

        swarm.update(elapsed);

        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

        const Particle* const pParticles = swarm.getParticles();

        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];
            
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

            screen.setPixel(x, y, red, green, blue);
        }

        // blur screen box
        screen.boxBlur();

        // draw screen 
        screen.update();
        
        // checking multiple events one after another
        if (screen.processEvents() == false)
        {
            break;
        }
    }

    screen.close();

    return 0;
}