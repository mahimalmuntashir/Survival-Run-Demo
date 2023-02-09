#include "header.h"

SDL_Texture* knifeTexture=NULL;


void secondMode()
{

    //jumping mechanics
    jump(360);

    //Scroll background
    scrollingOffset=scrollingOffset-6;
    if( scrollingOffset < -SCREEN_WIDTH)
    {
        scrollingOffset = 0;
    }

    coins(437,232,true);

    //star mechanics
    knives();

    //obstacles
    enemies();

    managing_knife();

    //Clear screen
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );

    //Render background
    render(BG2,SCREEN_WIDTH,SCREEN_HEIGHT,scrollingOffset,0,NULL);
    render(BG2,SCREEN_WIDTH,SCREEN_HEIGHT,scrollingOffset+SCREEN_WIDTH,0,NULL);

    //render obstacle
    SDL_RenderCopy(gRenderer,dog,&dog_spriteclips[enemy[DOG].speed++],&enemy[DOG].body);
    SDL_RenderCopy(gRenderer,enemy_zombie,&zombie_spriteclips[enemy[ZOMBIE].speed++],&enemy[ZOMBIE].body);
    SDL_RenderCopy(gRenderer,enemy_ghost,&ghost_spriteclips[enemy[GHOST].speed++],&enemy[GHOST].body);
                
    //Render Current Clip
    SDL_Rect* currentclip=&gSpriteClips[frame/6];
    render(Man,mWidth,mHeight,x_pos,y_pos,currentclip);

    //Render star
    render(knife_texture,60,60,star.x,star.y,NULL);

    //render coin
    render(Coin,40,55,coin.x,coin.y,NULL);

    rendering_knifes();

    //update score
    render(gScoretexture,mWidth-150,mHeight,0,0,NULL);
    int_to_string(score);
    scoreImage=scoreprint(scorestring);
    render(scoreImage,70,60,mWidth-150,0,NULL);

    //update knife
    render(knife_texture,70,65,SCREEN_WIDTH-175,0,NULL);
    int_to_string_knife(knifes_counter);
    knifeTexture=knifeprint(knifestring);
    render(knifeTexture,60,50,SCREEN_WIDTH-100,15,NULL);

    //update life
    for(i=0,j=0;i<alive;i++,j=j+70)
    {
        render(life,70,50,0+j,mHeight,NULL);
    }

    //update screen
    SDL_RenderPresent( gRenderer );

    ++frame;
    if( frame / 6 >= 6 )
        frame = 0;

    if(enemy[DOG].speed>=12)
    {
        enemy[DOG].speed = 0;
    }

    if(enemy[ZOMBIE].speed>=18)
    {
        enemy[ZOMBIE].speed = 0;
    }

    if(enemy[GHOST].speed >=18)
    {
        enemy[GHOST].speed = 0;
    }

}
        
