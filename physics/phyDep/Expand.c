#include"../../dependencies/struct.h"
#include"PushPhysics.h"
#include<stdio.h>


int AnyLeft(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x-1;
    int y=List[Index].Dposition.y-1;
    int stop=y+size+1;
    int pseen=-1;
    for(;y<stop;y++){

        if(Map[y*32+x].shortData==1){
            return 0;
        }

        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            return 0;
        }
    }
    return 1;
}

int AnyRight(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x+size;
    int y=List[Index].Dposition.y-1;
    int stop=y+size+1;
    int pseen=-1;
    for(;y<stop;y++){

        if(Map[y*32+x].shortData==1){
            return 0;
        }

        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            return 0;
        }
    }
    return 1;
}

int CanExpandRight(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x+size;
    int y=List[Index].Dposition.y-1;
    int stop=y+size+1;
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

int CanExpandLeft(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x-1;
    int y=List[Index].Dposition.y-1;
    int stop=y+size+1;
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

int EPushUp(physicsVoxel* Map,voxel* List,int Index){
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
    y=List[Index].Dposition.y-1;
    for(;x<stop;x++){
        Map[x+y*32].shortData=3;
        Map[x+y*32].voxelIndex=Index;
    }

    List[Index].Dposition.y= List[Index].Dposition.y-1;

    return 1;
}


int ExpandRight(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x+size;
    int y=List[Index].Dposition.y-1;
    int stop=y+size+1;
    int pseen=-1;
    for(;y<stop;y++){

        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            pseen=Map[y*32+x].voxelIndex;
            PushRight(Map,List,pseen);
        }
    }
    

    x=List[Index].Dposition.x+size;
    y=List[Index].Dposition.y-1;
    for(;y<stop;y++){
        Map[x+y*32].shortData=3;
        Map[x+y*32].voxelIndex=Index;
    }
    EPushUp(Map,List,Index);
    List[Index].size=List[Index].size+1;
    return 1;

}

int ExpandLeft(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x-1;
    int y=List[Index].Dposition.y-1;
    int stop=y+size+1;
    int pseen=-1;
    for(;y<stop;y++){

        if(Map[y*32+x].shortData==3 && pseen!=Map[y*32+x].voxelIndex){
            pseen=Map[y*32+x].voxelIndex;
            PushLeft(Map,List,pseen);
        }
    }
    

    x=List[Index].Dposition.x-1;
    y=List[Index].Dposition.y-1;
    for(;y<stop;y++){
        Map[x+y*32].shortData=3;
        Map[x+y*32].voxelIndex=Index;
    }

    EPushUp(Map,List,Index);
    List[Index].Dposition.x=List[Index].Dposition.x-1;
    List[Index].size=List[Index].size+1;
    return 1;
}

int ContractLeft(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x;
    int y=List[Index].Dposition.y;
    int stopy=y+size;
    int stopx=x+size;
    for(;y<stopy;y++){
        Map[x+y*32].shortData=0;
    }

    y=List[Index].Dposition.y;

    for(;x<stopx;x++){
        Map[x+y*32].shortData=0;
    }

    List[Index].Dposition.x=List[Index].Dposition.x+1;
    List[Index].Dposition.y=List[Index].Dposition.y+1;
    List[Index].size=List[Index].size-1;
    return 1;
}

int ContractRight(physicsVoxel* Map,voxel* List,int Index){
    int size=List[Index].size+1;
    int x=List[Index].Dposition.x;
    int y=List[Index].Dposition.y;
    int stopy=y+size;
    int stopx=x+size;

    for(;x<stopx;x++){
        Map[x+y*32].shortData=0;
    }

    for(;y<stopy;y++){
        Map[x+y*32].shortData=0;
    }

   

    List[Index].Dposition.y=List[Index].Dposition.y+1;
    List[Index].size=List[Index].size-1;
    return 1;
}
