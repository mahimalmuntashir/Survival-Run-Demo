#include "header.h"

void render(SDL_Texture *mTexture, int Width, int Height, int x, int y, SDL_Rect *clip)
{
    SDL_Rect renderQuad = {x, y, Width, Height};
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}

void middle_menu()
{
    render(menu1, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, NULL);
    render(Continue, mWidth, mHeight, 10, (SCREEN_HEIGHT / 2) - 100, NULL);
    render(newgame, mWidth, mHeight, 10, (SCREEN_HEIGHT / 2) - 50, NULL);
    render(help, mWidth - 180, mHeight, 10, (SCREEN_HEIGHT / 2), NULL);
    render(highscore, mWidth, mHeight, 10, (SCREEN_HEIGHT / 2) + 50, NULL);
    render(gEnd, mWidth - 180, mHeight, 10, (SCREEN_HEIGHT / 2) + 100, NULL);
    SDL_RenderPresent(gRenderer);
}

void start_menu()
{
    render(menu, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, NULL);
    render(newgame, mWidth, mHeight, 10, (SCREEN_HEIGHT / 2) - 50, NULL);
    render(help, mWidth - 180, mHeight, 10, (SCREEN_HEIGHT / 2), NULL);
    render(highscore, mWidth, mHeight, 10, (SCREEN_HEIGHT / 2) + 50, NULL);
    render(gEnd, mWidth - 180, mHeight, 10, (SCREEN_HEIGHT / 2) + 100, NULL);
    SDL_RenderPresent(gRenderer);
}

void mode_menu()
{
    render(menu2, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, NULL);
    render(city, mWidth, mHeight + 50, (SCREEN_WIDTH / 2) - 80, (SCREEN_HEIGHT / 2) - 150, NULL);
    render(forest, mWidth, mHeight + 50, (SCREEN_WIDTH / 2) - 80, (SCREEN_HEIGHT / 2), NULL);
    SDL_RenderPresent(gRenderer);
}

void myCredit() // credit
{
    // Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);

    render(mcredit, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, NULL);
    SDL_RenderPresent(gRenderer);
}

void instruction()
{
    render(tutorial, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, NULL);
    SDL_RenderPresent(gRenderer);
}