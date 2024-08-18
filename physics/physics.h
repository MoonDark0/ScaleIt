#ifndef PHYSICS
#define PHYSICS
#include"../dependencies/struct.h"

int step(physicsVoxel *VoxelMap, voxel *VoxelList, int Amount);
int expand(physicsVoxel *VoxelMap, voxel *VoxelList, int Index);
#endif