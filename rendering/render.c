#include<SDL2/SDL.h>
#include"render.h"
#include"../dependencies/struct.h"
#include"../dependencies/vectormath.h"

static SDL_Window* window=NULL;
static SDL_Renderer* renderer=NULL;
static SDL_Texture *particleTexture=NULL;

int RenderSetup(){


    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Program",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1024,1024,0);

    if(window==NULL){
        return 1;
    }


   renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    if (window==NULL || renderer==NULL){
        return 1;
    }

    



    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);


    SDL_RenderPresent(renderer);

    return 0;

};

int RenderStep(voxel* VoxeList,int amount,player CurrentPlayer){

    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);

    for(int i=0;i<amount;i++){
        vector2 position = VoxeList[i].Dposition;
        SDL_Rect Rect1;
            Rect1.h=28*(VoxeList[i].size+1);
            Rect1.w=28*(VoxeList[i].size+1);
            Rect1.x=2*32+position.x*28;
            Rect1.y=2*32+position.y*28;

            SDL_Rect Rect2;
            Rect2.h=26+28*(VoxeList[i].size);
            Rect2.w=26+28*(VoxeList[i].size);
            Rect2.x=2*32+position.x*28+1;
            Rect2.y=2*32+position.y*28+1;

            SDL_SetRenderDrawColor(renderer,160,160,160,255);
            SDL_RenderDrawRect(renderer,&Rect1);
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            SDL_RenderDrawRect(renderer,&Rect2);
    }

    
    SDL_RenderPresent(renderer);
    return 1;
}

int RenderQuit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    for(int i=0;i<100;i++){
        SDL_DestroyTexture(particleTexture);
    }
    SDL_Quit();
};