#include "header.h"

SDL_Rect coin= {700,232,55,55};

void coins(int coin_position1,int coin_position2,bool star_or_not)
{
    if(coin.y == coin_position1)
    {
        if(x_pos +71 >= coin.x && x_pos<= coin.x + coin.w && !((y_pos + 145) < coin.y))
        {
            Mix_PlayChannel(-1,coinsound,0);
            score=score+10;
            int i = rand()%10;
            if(i%2==0)
            {
                coin.y = coin_position2;
                coin.x = 800 + rand()%400;
                if(star_or_not)
                {
                    if((star.x>=coin.x && star.x  <= coin.x + coin.w && star.y == coin.y) || (star.x<=coin.x && star.x + star.w >=coin.x && star.y == coin.y))
                    {
                        coin.x += 100;
                    }
                }

            }
            else
            {
                coin.y = coin_position1;
                OBSTACLES_AND_COIN_POSITION(&coin.x,&coin.w,&obs_x1,&obs_x1_width,&obs_x2,&obs_x2_width,&obs_x3,&obs_x3_width,400,false);

            }
        }
    }
    else if(coin.y == coin_position2)
    {
        if(x_pos +71 >= coin.x && x_pos<= coin.x + coin.w && y_pos<=coin.y + coin.h)
        {
            Mix_PlayChannel(-1,coinsound,0);
            score=score+10;
            int i = rand()%10;
            if(i%2==0)
            {
                coin.y = coin_position2;
                coin.x = 800 + rand()%400;
                if(star_or_not)
                {
                    if((star.x>=coin.x && star.x  <= coin.x + coin.w && star.y == coin.y) || (star.x<=coin.x && star.x + star.w >=coin.x && star.y == coin.y))
                    {
                        coin.x += 100;
                    }
                }

            }
            else
            {
                coin.y = coin_position1;
                OBSTACLES_AND_COIN_POSITION(&coin.x,&coin.w,&obs_x1,&obs_x1_width,&obs_x2,&obs_x2_width,&obs_x3,&obs_x3_width,400,false);
            }
        }
    }

    coin.x -=6;
    if(coin.x + coin.w <=0)
    {
         int i = rand()%10;
         if(i%2==0)
            {
                coin.y = coin_position2;
                coin.x = 800 + rand()%400;
                if(star_or_not)
                {
                    if((star.x>=coin.x && star.x  <= coin.x + coin.w && star.y == coin.y) || (star.x<=coin.x && star.x + star.w >=coin.x && star.y == coin.y))
                    {
                        coin.x += 100;
                    }
                }

            }
            else
            {
                coin.y = coin_position1;
                OBSTACLES_AND_COIN_POSITION(&coin.x,&coin.w,&obs_x1,&obs_x1_width,&obs_x2,&obs_x2_width,&obs_x3,&obs_x3_width,400,false);
            }
        
    }

}