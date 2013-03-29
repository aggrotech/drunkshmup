#include "SDL.h"
#include "Graphics.h"
#include "Input.h"
#include "World.h"
#include <cstdlib>

void Initialize()
{

}

void GameLoop()
{
    Aggrotech::World world;
    Aggrotech::Graphics graphics;
    bool isQuitting = false;
    SDL_Event ev;

    world.CreateTestWorld();
    bool isButtonDown = false;

    while (1)
    {
        while(SDL_PollEvent(&ev) != 0)
        {
            if (ev.type == SDL_QUIT)
            {
                isQuitting = true;
                break;
            }

            isButtonDown = (ev.type == SDL_KEYDOWN) && (ev.key.keysym.sym == SDLK_RIGHT);
        }

        if (isQuitting)
        {
            break;
        }

        Aggrotech::Input currentInput(isButtonDown);

        world.Update(0.0f, currentInput);

        graphics.Prepare();
        world.Render(&graphics);
        graphics.Render(0.0f);
    }
}

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption("Aggrotech::Drunkshmup", NULL);

    GameLoop();
    
    SDL_Quit();
    return EXIT_SUCCESS;
}
