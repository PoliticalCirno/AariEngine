#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

static const int W = 1500;
static const int H = 800;

int main(int argc, char**argv)
{
    //Video Init? more like tommy init HAHAHAHAIAMFUNNYYOUCANNOTARGUE
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048);

    Mix_Music * Chirumiru = Mix_LoadMUS("Chirumiru.wav");
    Mix_Music * Jump = Mix_LoadMUS("Orange.mp3");
    Mix_Music * Midi = Mix_LoadMUS("Miditest.midi");


    SDL_Window*window = SDL_CreateWindow("Audio Test - Build 210513", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W, H, SDL_WINDOW_OPENGL);

    SDL_Renderer*Drawcall =SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    SDL_Surface * WelcomeImage = IMG_Load("Instruct_screen.png");
    SDL_Texture * Image_render = SDL_CreateTextureFromSurface(Drawcall,WelcomeImage);
    SDL_FreeSurface(WelcomeImage);

    SDL_Rect TexturePos;
    TexturePos.y = 0;
    TexturePos.x = 0;
    TexturePos.w = 1500;
    TexturePos.h = 800;

    //Mix_PlayMusic(Chirumiru, -1);
    bool running=true;
    SDL_Event event;
    while(running)
    {
        while(SDL_PollEvent (&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }

             else if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_1)
            {
              ;

                Mix_PlayMusic(Jump, -1);
            }
            else if(event.key.keysym.sym == SDLK_2)
            {

                Mix_PlayMusic(Chirumiru, -1);
            }
            else if(event.key.keysym.sym == SDLK_3)
            {


                Mix_PlayMusic(Midi, -1);
            }
        }
        }



        SDL_RenderClear(Drawcall);// tag rc

        SDL_RenderCopy(Drawcall, Image_render, NULL,&TexturePos);

        SDL_RenderPresent(Drawcall);// tag rp



    }

    SDL_DestroyTexture(Image_render);
    SDL_DestroyRenderer(Drawcall);
    SDL_DestroyWindow(window);
    Mix_FreeMusic(Chirumiru);
    Mix_FreeMusic(Jump);
    Mix_FreeMusic(Midi);
    Mix_CloseAudio();
    IMG_Quit;
    SDL_QUIT;

    return 0;

}
