#include"rendering/render.h"
#include"dependencies/struct.h"
#include"map/map.h"
#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include"physics/physics.h"

int main(int argc, char* argv[]){
    
    physicsVoxel* VoxelMap=malloc(sizeof(physicsVoxel)*32*32);
    voxel* VoxelList=malloc(sizeof(voxel)*32*32);
    if (VoxelList==NULL || VoxelMap==NULL){
        return 1;
    }
    int VoxelAmount=LoadLevel(VoxelMap,VoxelList,0);
    player CurrentPlayer;

   if ( RenderSetup()==1){
        return 0;
   }

    int run=1;
    
    while(run==1){
    
    int wait=SDL_GetTicks64()+150;
    
    //MainLoop
    RenderStep(VoxelList,VoxelAmount,CurrentPlayer);
    step(VoxelMap,VoxelList,VoxelAmount);
    

    while (SDL_GetTicks64()<wait){};
    //Events
    SDL_Event ev;


    while(SDL_PollEvent(&ev)){
        switch (ev.type)
        {
        case SDL_QUIT:
            run=0;
            break;
        }
    }
    }

   RenderQuit();
    free(VoxelMap);
    free(VoxelList);
    
    return 0;
}