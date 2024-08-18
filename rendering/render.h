#ifndef RENDER
#define RENDER
#include"../dependencies/struct.h"
int RenderSetup();
int RenderStep(voxel* VoxeList,int amount,player CurrentPlayer);
int RenderQuit();
#endif