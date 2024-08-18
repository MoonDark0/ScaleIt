static int frame=0;
#include"../dependencies/struct.h"
#include"phyDep/PushPhysics.h"
#include"phyDep/Expand.h"
#include"stdio.h"

int expand(physicsVoxel *VoxelMap, voxel *VoxelList, int Index){
    if((VoxelList[Index].data&0x01)==1 && isPusheableUp(VoxelMap,VoxelList,Index)==1){
        int expandDirx=(VoxelList[Index].data&0x08)>>3;
        if (expandDirx==0){
            if(AnyLeft(VoxelMap,VoxelList,Index)==1){
                ExpandLeft(VoxelMap,VoxelList,Index);
                VoxelList[Index].growx=VoxelList[Index].growx & ~(0x0001<<VoxelList[Index].size);
                return 1;
            }
            if(AnyRight(VoxelMap,VoxelList,Index)==1){
                ExpandRight(VoxelMap,VoxelList,Index);
                VoxelList[Index].growx=VoxelList[Index].growx|0x0001<<VoxelList[Index].size;
                return 1;
            }
            if(CanExpandLeft(VoxelMap,VoxelList,Index)==1){
                
                ExpandLeft(VoxelMap,VoxelList,Index);
                VoxelList[Index].growx=VoxelList[Index].growx& ~(0x0001<<VoxelList[Index].size);;
                return 1;
            }
            if(CanExpandRight(VoxelMap,VoxelList,Index)==1){
                
                ExpandRight(VoxelMap,VoxelList,Index);
                VoxelList[Index].growx=VoxelList[Index].growx|0x0001<<VoxelList[Index].size;
                return 1;
            }
            return 0;
        }

            if(AnyRight(VoxelMap,VoxelList,Index)==1){
                ExpandRight(VoxelMap,VoxelList,Index);
                VoxelList[Index].growx=VoxelList[Index].growx|0x0001<<VoxelList[Index].size;
                return 1;
            }

             if(AnyLeft(VoxelMap,VoxelList,Index)==1){
                ExpandLeft(VoxelMap,VoxelList,Index);
                VoxelList[Index].growx=VoxelList[Index].growx& ~(0x0001<<VoxelList[Index].size);
                return 1;
            }
            
            if(CanExpandRight(VoxelMap,VoxelList,Index)==1){
                ExpandRight(VoxelMap,VoxelList,Index);
                VoxelList[Index].growx=VoxelList[Index].growx|0x0001<<VoxelList[Index].size;
                return 1;
            }

            if(CanExpandLeft(VoxelMap,VoxelList,Index)==1){
                
                ExpandLeft(VoxelMap,VoxelList,Index);
                VoxelList[Index].growx=VoxelList[Index].growx& ~(0x0001<<VoxelList[Index].size);
                return 1;
            }
            
           
            return 0;

    }
}


int contract(physicsVoxel *VoxelMap, voxel *VoxelList, int Index){
    if((VoxelList[Index].data&0x01)==1 && VoxelList[Index].size>0){
        if (((VoxelList[Index].growx>>VoxelList[Index].size)&0x0001)==1){
            ContractRight(VoxelMap,VoxelList,Index);
            return 1;
        }
        ContractLeft(VoxelMap,VoxelList,Index);
        return 1;
    }
    return 0;
}

int step(physicsVoxel *VoxelMap, voxel *VoxelList, int Amount){
    
    for(int i=0;i<Amount;i++){
        if ((VoxelList[i].data&0x01)==1 && (VoxelList[i].lastGravityFrame)!=frame){
            if(isPusheableDown(VoxelMap,VoxelList,i)==1){
                Gravity(VoxelMap,VoxelList,i,frame);
            }
        }
    }
    if(frame==30){
        contract(VoxelMap,VoxelList,412);
    }
    if (frame==25){
        expand(VoxelMap,VoxelList,444);
    }


    frame++;
}