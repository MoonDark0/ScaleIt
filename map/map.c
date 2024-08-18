#include"../dependencies/struct.h"
#include"../dependencies/vectormath.h"
#include"map.h"
#include<stdio.h>
#include<stdlib.h>
#include"../physics/physics.h"

typedef struct 
{
    int type; //-1 static//0 and onwards size;
    vector2 pos;

}Vxl;

typedef struct
{
    int amount;
    Vxl* array;
} returnOpen;

int strtobin(char big,char small){
    int val=0;
    switch (small)
    {
    case '1':
        val=1;
        break;

    case '2':
        val=2;
        break;

    case '3':
        val=3;
        break;

    case '4':
        val=4;
        break;

    case '5':
        val=5;
        break;

    case '6':
        val=6;
        break;

    case '7':
        val=7;
        break;

    case '8':
        val=8;
        break;

    case '9':
        val=9;
        break;

    case 'a':
        val=10;
        break;

    case 'b':
        val=11;
        break;

    case 'c':
        val=12;
        break;

    case 'd':
        val=13;
        break;

    case 'e':
        val=14;
        break;

    case 'f':
        val=15;
        break;
    }
    if (big=='1'){
        val+=16;
    }
    return val; 

}


returnOpen openFile(int number){
    FILE* pF=NULL;
    switch (number)
    {
    case 0:
        pF=fopen("levels/Test.lvl","r");
        break;
    
    }

    if(pF==NULL){
        printf("ERRORNF");
        returnOpen Error={0,NULL};
        return Error;
    }

    fseek(pF,0,SEEK_END);
    int fsize=ftell(pF);
    rewind(pF);

    char* charB=malloc(sizeof(char)*fsize);
    fread(charB,fsize,1,pF);
    fclose(pF);


    int len=0;
    for(int i=0;i<fsize;i++){
        if (charB[i]==';'){
            len++;
        }
    }

    Vxl* ReturnArray=malloc(sizeof(Vxl)*len);

    int pointer=0;
    int i=0;
    while(pointer<fsize){
        if(charB[pointer]=='E'){
            pointer=pointer+1;
            vector2 pos={strtobin(charB[pointer],charB[pointer+1])+1,strtobin(charB[pointer+2],charB[pointer+3])+1};
            pointer=pointer+5;
            Vxl tempvxl={-1,pos};
            ReturnArray[i]=tempvxl;
            i++;
        }
        else if (charB[pointer]=='B')
        {
            pointer=pointer+1;
            vector2 pos={strtobin(charB[pointer],charB[pointer+1])+1,strtobin(charB[pointer+2],charB[pointer+3])+1};
            Vxl tempvxl={strtobin(charB[pointer+4],charB[pointer+5]),pos};
            pointer=pointer+7;
            ReturnArray[i]=tempvxl;
            i++;
        }
        else{
            printf("ERROR");
            returnOpen Error={0,NULL};
            return Error;
        }
        

    }
    free(charB);
    returnOpen retur={len,ReturnArray};
    return retur;
}

int LoadLevel(physicsVoxel* PhysicsVoxelMap,voxel*voxelList,int number){
    int amount=0;
    

    for(int x=0;x<32;x++){
        for(int y=0;x<32;x++){
        physicsVoxel temp={0,0};
        PhysicsVoxelMap[x+y*32]=temp;
    }
    }

    int y=0;
    int x=0;
    for(x=0;x<32;x++){
        vector2 Position={x,y};
        physicsVoxel temp={1,amount};
        PhysicsVoxelMap[x+y*32]=temp;
        voxel Temp2={0,Position,0,0,-1};
        voxelList[amount]=Temp2;
        amount++;
    }
    x=0;
    for(y=1;y<32;y++){
        vector2 Position={x,y};
        physicsVoxel temp={1,amount};
        PhysicsVoxelMap[x+y*32]=temp;
        voxel Temp2={0,Position,0,0,-1};
        voxelList[amount]=Temp2;
        amount++;
    }
    x=31;
    for(y=1;y<32;y++){
        vector2 Position={x,y};
        physicsVoxel temp={1,amount};
        PhysicsVoxelMap[x+y*32]=temp;
        voxel Temp2={0,Position,0,0,-1};
        voxelList[amount]=Temp2;
        amount++;
    }
    y=31;
     for(x=1;x<31;x++){
        vector2 Position={x,y};
        physicsVoxel temp={1,amount};
        PhysicsVoxelMap[x+y*32]=temp;
        voxel Temp2={0,Position,0,0,-1};
        voxelList[amount]=Temp2;
        amount++;
    }

    returnOpen Map=openFile(0);
    int len=Map.amount;
    Vxl* toProcess=Map.array;

    for(int i=0;i<len;i++){
        switch (toProcess[i].type)
        {
        case -1:
            vector2 pos=toProcess[i].pos;
            physicsVoxel temp={1,amount};
            PhysicsVoxelMap[pos.x+pos.y*32]=temp;
            voxel Temp2={0,pos,0,0,-1};
            voxelList[amount]=Temp2;
            amount++;
            break;
        
        default:
            printf("%d\n",amount);
            vector2 pos1=toProcess[i].pos;
            physicsVoxel temp1={3,amount};
            PhysicsVoxelMap[pos1.x+pos1.y*32]=temp1;
            voxel Temp21={9,pos1,0,0,-1};
            voxelList[amount]=Temp21;
            

            for(int j=0;j<toProcess[i].type;j++){
                expand(PhysicsVoxelMap,voxelList,amount);
            }
            amount++;
            break;
        }
    }

    return amount;

}