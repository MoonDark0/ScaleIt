#ifndef STRUCT
#define STRUCT

typedef struct{
    unsigned char x;
    unsigned char y;

} vector2;

typedef struct{
    double x;
    double y;

} Fvector2;

typedef struct
{
    Fvector2 position;
    double vVel;
}player ;


typedef struct
{
    unsigned char shortData;
    unsigned short voxelIndex;

    /*
    0->Empty
    1->Static
    2->Empty(should Never happen)
    3->Empty CanMove
    */

    /*
    Little endian
    0-Uninteracteable 1-Interacteable
    Gravity->0,1
    Pull->0,1
    Expand direction x 0,<-, 1 ->
    */

} physicsVoxel;

typedef struct
{
    unsigned char data;
    vector2 Dposition;
    unsigned int growx;
    unsigned char size;
    int lastGravityFrame;
} voxel;



#endif