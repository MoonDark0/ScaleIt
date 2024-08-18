#ifndef PHYSICSP
#define PHYSICSP
#include"../../dependencies/struct.h"


int isPusheableDown(physicsVoxel* Map,voxel* List,int Index);
int isPusheableRight(physicsVoxel* Map,voxel* List,int Index);
int isPusheableLeft(physicsVoxel* Map,voxel* List,int Index);
int isPusheableUp(physicsVoxel* Map,voxel* List,int Index);

int PushUp(physicsVoxel* Map,voxel* List,int Index);
int PushLeft(physicsVoxel* Map,voxel* List,int Index);
int PushRight(physicsVoxel* Map,voxel* List,int Index);
int Gravity(physicsVoxel* Map,voxel* List,int Index,int Frame);
#endif