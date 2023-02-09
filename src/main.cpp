#include "header.h"
bool go_to_menu;
bool pause = false;
bool start = false;
bool showmodemenu = false;
bool openCredit = false;
bool sound = false;
int main(int argc, char *args[])
{
    // MAHIM AL MUNTASHIR BILLAH
    // BSc. in Computer Science and Technology
    // NANTONG UNIVERSITY

    // Start up SDL and create window
    if (!init())
        printf("Failed to initialize!\n");
    else
    {
        // Load media
        if (!loadMedia())
            printf("Failed to load media!\n");
        else
        {
            go_to_menu = true;
            // Main loop flag
            quit = false;
            while (!quit)
            {
                pollevent();
                if (pause && !go_to_help && !showhighscore && !go_to_menu && !openCredit)
                    continue;

                if (pause && go_to_menu)
                {
                    mousehandling_middle();
                    continue;
                }

                if (go_to_menu)
                {
                    mousehandling_start();
                }
                else
                {
                    if (go_to_help)
                    {
                        instruction();
                    }
                    else if (openCredit)
                    {
                        myCredit();
                    }
                    else if (showhighscore)
                    {
                        if (showmodemenu)
                        {
                            mousehandling_highscore();
                        }
                        else
                        {
                            if (Scoremode == 1)
                            {
                                char ch[50] = "res/score/CITY.txt";
                                SHOW_HIGHSCORE(ch);
                            }
                            else if (Scoremode == 2)
                            {
                                char ch[50] = "res/score/FOREST.txt";
                                SHOW_HIGHSCORE(ch);
                            }
                        }
                    }
                    else if (start)
                        mousehandling_mode();
                    else
                    {

                        if (mode == 1)
                            firstMode();
                        else if (mode == 2)
                            secondMode();
                        if (alive == 0)
                            gameover();
                    }
                }
            }
        }
    }
    // Free resources and close SDL
    close();
    return 0;
}

void gameover()
{
    Mix_HaltMusic();
    Mix_PlayChannel(-1, diesound, 0);
    SDL_Delay(500);
    // Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);

    render(gameOver, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, NULL);
    render(gScoretexture, mWidth + 50, mHeight + 50, (SCREEN_WIDTH / 3) - 120, (SCREEN_HEIGHT / 2) + 50, NULL);
    render(scoreImage, 110, 110, (SCREEN_WIDTH / 3) - 120 + mWidth + 50, (SCREEN_HEIGHT / 2) + 50, NULL);
    // update screen
    SDL_RenderPresent(gRenderer);
    SDL_Delay(2000);
    nameprint();
    go_to_menu = true;
    mode = 0;
}
