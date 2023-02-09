#include "header.h"

int x_pos;
int y_pos;
int up;
int down;
int ground;
int y_velocity;
void man_sprite()
{
    gSpriteClips[ 0 ].x =   0;
    gSpriteClips[ 0 ].y =   0;
    gSpriteClips[ 0 ].w =  71;
    gSpriteClips[ 0 ].h =  145;

    gSpriteClips[ 1 ].x =  98;
    gSpriteClips[ 1 ].y =  0;
    gSpriteClips[ 1 ].w =  83;
    gSpriteClips[ 1 ].h =  145;

    gSpriteClips[ 2 ].x = 212;
    gSpriteClips[ 2 ].y =   0;
    gSpriteClips[ 2 ].w =  98;
    gSpriteClips[ 2 ].h = 145;;

    gSpriteClips[ 3 ].x =   329;
    gSpriteClips[ 3 ].y =  0;
    gSpriteClips[ 3 ].w =  87;
    gSpriteClips[ 3 ].h = 145;

    gSpriteClips[ 4 ].x =   440;
    gSpriteClips[ 4 ].y =  0;
    gSpriteClips[ 4 ].w = 74;
    gSpriteClips[ 4 ].h = 145;

    gSpriteClips[ 5 ].x =  540;
    gSpriteClips[ 5 ].y =  0;
    gSpriteClips[ 5 ].w =  85;
    gSpriteClips[ 5 ].h = 145;
    
}
void jump(int y_pos_start)
{
    if(ground && up && !down)
    {
        y_velocity = 20;
        ground =0;
    }
    if(up)
    {
        y_velocity--;
        y_pos -= y_velocity;
    }
    if(down)
    {
        y_velocity++;
        y_pos +=y_velocity;
    }
    if(!ground && y_velocity<=0)
    {
        down = 1;
        up =0;
    }
    if(y_pos >= y_pos_start)
    {
        y_pos=y_pos_start;
        up=0;
        down=0;
        ground = 1;
        y_velocity=0;
    }
}