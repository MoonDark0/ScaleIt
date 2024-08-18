#ifndef PHYSICSEX
#define PHYSICSEX
#include"../../dependencies/struct.h"

int AnyLeft(physicsVoxel* Map,voxel* List,int Index);
int AnyRight(physicsVoxel* Map,voxel* List,int Index);
int CanExpandRight(physicsVoxel* Map,voxel* List,int Index);
int CanExpandLeft(physicsVoxel* Map,voxel* List,int Index);
int ExpandRight(physicsVoxel* Map,voxel* List,int Index);
int ExpandLeft(physicsVoxel* Map,voxel* List,int Index);
int ContractRight(physicsVoxel* Map,voxel* List,int Index);
int ContractLeft(physicsVoxel* Map,voxel* List,int Index);
#endif