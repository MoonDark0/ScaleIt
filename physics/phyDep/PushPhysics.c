#include"../../dependencies/struct.h"
#include"PushPhysics.h"
#include<stdio.h>

int isPusheableRight(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x+size;
   
    int y=List[Index].Dposition.y;
     int stop=y+size;
    int pseen=-1;
    for(;y<stop;y++){
        if(Map[y*32+x].shortData==1){
            return 0;
        }
        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            pseen=Map[y*32+x].voxelIndex;
            if(isPusheableRight(Map,List,pseen)==0){
                return 0;
            }
        }
    }
    return 1;
}

int isPusheableUp(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x;
    int stop=x+size;
    int y=List[Index].Dposition.y-1;
    int pseen=-1;
    for(;x<stop;x++){
        if(Map[y*32+x].shortData==1){
            return 0;
        }
        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            pseen=Map[y*32+x].voxelIndex;
            if(isPusheableUp(Map,List,pseen)==0){
                return 0;
            }
        }
    }
    return 1;
}

int isPusheableDown(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x;
    int stop=x+size;
    int y=List[Index].Dposition.y+size;
    int pseen=-1;
    for(;x<stop;x++){

        if(Map[y*32+x].shortData==1){
            return 0;
        }

        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            pseen=Map[y*32+x].voxelIndex;
            if(isPusheableDown(Map,List,pseen)==0){
                return 0;
            }
        }
    }
    return 1;
}

int isPusheableLeft(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x-1;
    int y=List[Index].Dposition.y;
    int stop=y+size;
    int pseen=-1;
    for(;y<stop;y++){
        if(Map[y*32+x].shortData==1){
            return 0;
        }
        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            pseen=Map[y*32+x].voxelIndex;
            if(isPusheableLeft(Map,List,pseen)==0){
                return 0;
            }
        }
    }
    return 1;
}



int PushRight(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x+size;
    int y=List[Index].Dposition.y;
    int stop=y+size;
    int pseen=-1;
    for(;y<stop;y++){
        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            pseen=Map[y*32+x].voxelIndex;
            PushRight(Map,List,pseen);
        }
    }

    x=List[Index].Dposition.x;
    y=List[Index].Dposition.y;
    for(;y<stop;y++){
        Map[x+y*32].shortData=0;
    }

    x=List[Index].Dposition.x+size;
    y=List[Index].Dposition.y;
    for(;y<stop;y++){
        Map[x+y*32].shortData=3;
        Map[x+y*32].voxelIndex=Index;
    }
    List[Index].Dposition.x= List[Index].Dposition.x+1;
    return 1;

}

int PushUp(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x;
    int stop=x+size;
    int y=List[Index].Dposition.y-1;
    int pseen=-1;
    for(;x<stop;x++){
        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            pseen=Map[y*32+x].voxelIndex;
            PushUp(Map,List,pseen);
        }
    }

    x=List[Index].Dposition.x;
    y=List[Index].Dposition.y+size-1;
    for(;x<stop;x++){
        Map[x+y*32].shortData=0;
    }

    x=List[Index].Dposition.x;
    y=List[Index].Dposition.y-1;
    for(;x<stop;x++){
        Map[x+y*32].shortData=3;
        Map[x+y*32].voxelIndex=Index;
    }

    List[Index].Dposition.y= List[Index].Dposition.y-1;

    return 1;
}

int PushDown(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x;
    int stop=x+size;
    int y=List[Index].Dposition.y+size;
    int pseen=-1;
    for(;x<stop;x++){
        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            pseen=Map[y*32+x].voxelIndex;
            PushDown(Map,List,pseen);
        }
    }

    x=List[Index].Dposition.x;
    y=List[Index].Dposition.y;
    for(;x<stop;x++){
        Map[x+y*32].shortData=0;
    }

    x=List[Index].Dposition.x;
    y=List[Index].Dposition.y+size;
    for(;x<stop;x++){
        Map[x+y*32].shortData=3;
        Map[x+y*32].voxelIndex=Index;
    }

    List[Index].Dposition.y= List[Index].Dposition.y+1;

    return 1;
}

int PushLeft(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x-1;
    int y=List[Index].Dposition.y;
    int stop=y+size;
    int pseen=-1;
    for(;y<stop;y++){
        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            pseen=Map[y*32+x].voxelIndex;
            PushLeft(Map,List,pseen);
        }
    }
    x=List[Index].Dposition.x+size-1;
    y=List[Index].Dposition.y;
    for(;y<stop;y++){
        Map[x+y*32].shortData=0;
    }

    x=List[Index].Dposition.x-1;
    y=List[Index].Dposition.y;
    for(;y<stop;y++){
        Map[x+y*32].shortData=3;
        Map[x+y*32].voxelIndex=Index;
    }
    List[Index].Dposition.x= List[Index].Dposition.x-1;
    return 1;
}

int Gravity(physicsVoxel* Map,voxel* List,int Index,int Frame){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x;
    int stop=x+size;
    int y=List[Index].Dposition.y+size;
    int pseen=-1;
    for(;x<stop;x++){
        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            pseen=Map[y*32+x].voxelIndex;
            Gravity(Map,List,pseen,Frame);
        }
    }

    x=List[Index].Dposition.x;
    y=List[Index].Dposition.y;
    for(;x<stop;x++){
        Map[x+y*32].shortData=0;
    }

    x=List[Index].Dposition.x;
    y=List[Index].Dposition.y+size;
    for(;x<stop;x++){
        Map[x+y*32].shortData=3;
        Map[x+y*32].voxelIndex=Index;
    }

    List[Index].Dposition.y= List[Index].Dposition.y+1;
    List[Index].lastGravityFrame=Frame;
    return 1;
}