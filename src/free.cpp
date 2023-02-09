#include "header.h"

void close()
{
    SDL_DestroyTexture(BG1);
    SDL_DestroyTexture(Man);
    SDL_DestroyTexture(Coin);
    SDL_DestroyTexture(Obstacle1);
    SDL_DestroyTexture(Obstacle2);
    SDL_DestroyTexture(Obstacle3);
    SDL_DestroyTexture(life);
    SDL_DestroyTexture(gameOver);
    SDL_DestroyTexture(menu);
    SDL_DestroyTexture(menu1);
    SDL_DestroyTexture(menu2);
    SDL_DestroyTexture(Continue);
    SDL_DestroyTexture(city);
    SDL_DestroyTexture(forest);
    SDL_DestroyTexture(newgame);
    SDL_DestroyTexture(help);
    SDL_DestroyTexture(highscore);
    SDL_DestroyTexture(gEnd);
    SDL_DestroyTexture(scoreTexture);
    SDL_DestroyTexture(tutorial);
    SDL_DestroyTexture(gScoretexture);
    SDL_DestroyTexture(sl);
    SDL_DestroyTexture(nameTexture);
    SDL_DestroyTexture(ScoreName);
    SDL_DestroyTexture(HighScore);
    SDL_DestroyTexture(EnterName);
    SDL_DestroyTexture(BG2);
    SDL_DestroyTexture(Star);
    SDL_DestroyTexture(dog);
    SDL_DestroyTexture(knife_texture);
    SDL_DestroyTexture(enemy_zombie);
    SDL_DestroyTexture(enemy_ghost);
    SDL_DestroyTexture(knifeTexture);
    SDL_DestroyTexture(gKnifeTexture);
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    Mix_FreeMusic(menusound);
    Mix_FreeMusic(citysound);
    Mix_FreeMusic(forestsound);
    Mix_FreeChunk(dogsound);
    Mix_FreeChunk(zombiesound);
    Mix_FreeChunk(diesound);
    Mix_FreeChunk(collidesound);
    Mix_FreeChunk(coinsound);
    Mix_FreeChunk(weaponsound);
    Mix_FreeChunk(mouseclick);

    TTF_CloseFont( gFont );
    gFont = NULL;
    gWindow = NULL;
    gRenderer = NULL;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

