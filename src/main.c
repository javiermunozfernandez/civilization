
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>

#ifndef DEFAULT_HEIGHT
#define DEFAULT_HEIGHT 600
#endif

#ifndef DEFAULT_WIDTH
#define DEFAULT_WIDTH 800
#endif

void (void) {
    SDL_Quit();
}

int main(void)
{
    int initialization_result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    if (initialization_result) {
        fprintf(stderr, "[Error] Failed to initialize SDL2. Error code: %d\n", initialization_result);
    }

    on_exit()

    SDL_Window* main_window = SDL_CreateWindow(
        "Civilization",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        600,
        SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS | SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_FULLSCREEN_DESKTOP
    );

    if (main_window == NULL) {
        fprintf(stderr, "[Error] Failed to create window.\n");
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        fprintf(stderr, "[Error] Failed to create renderer.\n");
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    while (1) {
        SDL_Event event;

        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN: {
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE: {
                            goto EXIT;
                        } break;

                        default: break;
                    }
                } break;

                case SDL_QUIT: {
                    goto EXIT;
                } break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

EXIT:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(main_window);

    SDL_Quit();
    return EXIT_SUCCESS;
}
