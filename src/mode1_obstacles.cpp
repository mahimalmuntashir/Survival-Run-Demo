#include "header.h"

int obs_x1;
int obs_x2;
int obs_x3;
int obs_x1_width;
int obs_x2_width ;
int obs_x3_width;

void obstacle()
{
    obs_x1 -=6;
    if(obs_x1 + 70 <=0)
    {
        OBSTACLES_AND_COIN_POSITION(&obs_x1,&obs_x1_width,&coin.x,&coin.w,&obs_x2,&obs_x2_width,&obs_x3,&obs_x3_width,2000,true);
    }
    if (x_pos+35>= obs_x1 && x_pos+35 <= obs_x1 + obs_x1_width && !((y_pos + 145) < 472))
    {
        alive--;
        if(score>=10 && alive>1)
        	score=score-10;
        if(alive>0)
        {
            Mix_PlayChannel(-1,collidesound,0);
            x_pos=x_pos+obs_x1_width;
        }
    }

    obs_x2 -=6;
    if(obs_x2 + 130 <=0)
    {
        OBSTACLES_AND_COIN_POSITION(&obs_x2,&obs_x2_width,&coin.x,&coin.w,&obs_x1,&obs_x1_width,&obs_x3,&obs_x3_width,2000,true);
    }
    if (x_pos+35 >= obs_x2 && x_pos+35<= obs_x2 + obs_x2_width && !((y_pos + 145) < 462))
    {             
        alive--;
        if(score>=10 && alive>1)
        	score=score-10;
        if(alive>0)
        {
            Mix_PlayChannel(-1,collidesound,0);
            x_pos=x_pos+obs_x2_width;
        }
                        
    }

    obs_x3 -=6;
    if(obs_x3 + 200 <=0)
    {
        OBSTACLES_AND_COIN_POSITION(&obs_x3,&obs_x3_width,&coin.x,&coin.w,&obs_x1,&obs_x1_width,&obs_x2,&obs_x2_width,2000,true);
    }
    if (x_pos+35 >= obs_x3 && x_pos+35<= obs_x3 + obs_x3_width && !((y_pos + 145) < 452))
    {        
        alive--;
        if(score>=10 && alive>1)
        	score=score-10;
        if(alive>0)
        {
            Mix_PlayChannel(-1,collidesound,0);
            x_pos=x_pos+obs_x3_width;
        }
    }
 
}



void OBSTACLES_AND_COIN_POSITION(int *targetx,int *targetwidth,int *obs_x1,int *obs_x1_width,int *obs_x2,int *obs_x2_width,int *obs_x3,int *obs_x3_width,int not_too_close,bool coin_or_not)
{

    bool distance = true;

    while(distance)
    {
        *targetx =  800 + rand()%not_too_close;
        if(*targetx>=*obs_x1 && *targetx<= *obs_x1 + *obs_x1_width )
        {
            continue;
        }
        else if(*targetx + *targetwidth >=*obs_x1 && *targetx + *targetwidth <= *obs_x1 + *obs_x1_width)
        {
            continue;
        }
        else
        {
            if(*targetx<=*obs_x1)
            {
                if(*targetx + *targetwidth + 55 > *obs_x1)
                {
                    continue;
                }
            }
            else if(*targetx>=*obs_x1 + *obs_x1_width)
            {
                if(*obs_x1 + *obs_x1_width + 55 > *targetx)
                {
                    continue;
                }
            }
        }
        if(*targetx >=*obs_x2 && *targetx <= *obs_x2 + *obs_x2_width)
        {
            continue;
        }
        else if(*targetx + *targetwidth >= *obs_x2 && *targetx + *targetwidth <= *obs_x2 + *obs_x2_width)
        {
            continue;
        }
        else
        {
            if(coin_or_not)
            {
                if(*targetx<=*obs_x2)
                {
                    if(*targetx + *targetwidth + 100 > *obs_x2)
                    {
                        continue;
                    }
                }
                else if(*targetx>=*obs_x2 + *obs_x2_width)
                {
                    if(*obs_x2 + *obs_x2_width + 100 > *targetx)
                    {
                        continue;
                    }
                }
                else
                {
                    if(*targetx<=*obs_x2)
                    {
                        if(*targetx + *targetwidth + 55 > *obs_x2)
                        {
                            continue;
                        }
                    }
                    else if(*targetx>=*obs_x2 + *obs_x2_width)
                    {
                        if(*obs_x2 + *obs_x2_width + 55 > *targetx)
                        {
                            continue;
                        }
                    } 
                }
            }


        }

        if(*targetx >=*obs_x3 && *targetx <= *obs_x3 + *obs_x3_width)
        {
            continue;
        }
        else if(*targetx + *targetwidth>= *obs_x3 && *targetx + *targetwidth <= *obs_x3 + *obs_x3_width)
        {
            continue;
        }
        else
        {
            if(coin_or_not)
            {
                if(*targetx<=*obs_x3)
                {
                    if(*targetx + *targetwidth + 100 > *obs_x3)
                    {
                        continue;
                    }
                }
                else if(*targetx>=*obs_x3 + *obs_x3_width)
                {
                    if(*obs_x3 + *obs_x3_width + 100 > *targetx)
                    {
                        continue;
                    }
                }
                else
                {
                    if(*targetx<=*obs_x3)
                    {
                        if(*targetx + *targetwidth + 55 > *obs_x3)
                        {
                            continue;
                        }
                    }
                    else if(*targetx>=*obs_x3 + *obs_x3_width)
                    {
                        if(*obs_x3 + *obs_x3_width + 55 > *targetx)
                        {
                            continue;
                        }
                    }
                }
            }

        }

        distance = false;
    }

}

