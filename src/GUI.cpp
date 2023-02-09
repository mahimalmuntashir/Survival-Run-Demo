#include "header.h"

int buttons, mouse_x, mouse_y, buttons1, mouse_x1, mouse_y1;
int mode;
int Scoremode;
bool go_to_help = false;
bool showhighscore = false;
bool quit;
bool stop_music = false;

void pollevent()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        // User requests quit
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
        if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.scancode)
            {
            case SDL_SCANCODE_SPACE:
                if (!pause)
                {
                    if (ground)
                    {
                        up = 1;
                        down = 0;
                    }
                }
                break;

            case SDL_SCANCODE_P:

                if (!go_to_menu && !go_to_help && !showhighscore && !showmodemenu && !openCredit)
                {
                    pause = true;
                    Mix_PauseMusic();
                }

                break;

            case SDL_SCANCODE_BACKSPACE:
                if (!go_to_menu)
                {
                    if (go_to_help)
                    {
                        go_to_menu = true;
                        go_to_help = false;
                    }
                    else if (openCredit)
                    {
                        go_to_menu = true;
                        openCredit = false;
                    }
                    else if (showhighscore)
                    {
                        if (showmodemenu)
                        {
                            showhighscore = false;
                            go_to_menu = true;
                        }
                        else
                        {
                            showmodemenu = true;
                        }
                    }
                    else
                    {
                        pause = true;
                        go_to_menu = true;
                    }
                }
                break;

            case SDL_SCANCODE_C:

                if (pause && !go_to_menu && !go_to_help && !showhighscore && !showmodemenu && !openCredit)
                {
                    pause = false;
                    if (!stop_music)
                        Mix_ResumeMusic();
                }
                break;

            case SDL_SCANCODE_S:
                if (!pause)
                {
                    if (knifes_counter > 0)
                    {
                        knife[indicator.finish].hit.x = x_pos + 100;
                        knife[indicator.finish++].hit.y = y_pos + 40; // where the knives will come from
                        knifes_counter--;
                        Mix_PlayChannel(-1, weaponsound, 0);
                    }
                }
                break;

            case SDL_SCANCODE_M:
                if (!pause || go_to_menu || showhighscore || go_to_help || openCredit)
                {
                    if (Mix_PausedMusic() == 1)
                    {
                        // Resume the music
                        Mix_ResumeMusic();
                        stop_music = false;
                    }
                    // If the music is playing
                    else
                    {
                        // Pause the music
                        Mix_PauseMusic();
                        stop_music = true;
                    }
                }
                break;
            }
        }
    }
}

void mousehandling_middle()
{
    if (sound == false)
    {
        Mix_HaltMusic();
        Mix_PlayMusic(menusound, -1);
        sound = true;
    }
    middle_menu();
    // get mouse coordinates
    buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
    // continue
    if (mouse_x >= 10 && mouse_x <= mWidth && mouse_y >= (SCREEN_HEIGHT / 2) - 100 && mouse_y <= (SCREEN_HEIGHT / 2) - 100 + mHeight - 15)
    {
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            go_to_menu = false;
            pause = false;
            if (mode == 1)
            {
                Mix_HaltMusic();
                Mix_PlayMusic(citysound, -1);
                sound = false;
            }
            if (mode == 2)
            {
                Mix_HaltMusic();
                Mix_PlayMusic(forestsound, -1);
                sound = false;
            }
        }
    }
    // newgame
    if (mouse_x >= 10 && mouse_x <= 10 + mWidth && mouse_y >= (SCREEN_HEIGHT / 2) - 50 + 15 && mouse_y <= (SCREEN_HEIGHT / 2) - 70 + mHeight)
    {
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            showmodemenu = true;
            start = true;
            go_to_menu = false;
            pause = false;
            mode = 0;
        }
    }

    // help
    if (mouse_x >= 10 && mouse_x <= 10 + mWidth - 180 && mouse_y >= (SCREEN_HEIGHT / 2) + 15 && mouse_y <= (SCREEN_HEIGHT / 2) + mHeight - 20)
    {
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            go_to_menu = false;
            go_to_help = true;
        }
    }

    // highscore
    if (mouse_x >= 10 && mouse_x <= mWidth && mouse_y >= (SCREEN_HEIGHT / 2) + 50 + 15 && mouse_y <= (SCREEN_HEIGHT / 2) + 50 + mHeight - 15)
    {
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            go_to_menu = false;
            showmodemenu = true;
            showhighscore = true;
        }
    }
    // exit
    if (mouse_x >= 10 && mouse_x <= 10 + mWidth - 180 && mouse_y >= (SCREEN_HEIGHT / 2) + 100 + 10 && mouse_y <= (SCREEN_HEIGHT / 2) + 100 + mHeight - 10)
    {
        // int menuSelect=0;
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            quit = true;
        }
    }
    // credit @MAHIM
    if (mouse_x >= SCREEN_WIDTH - 100 && mouse_x <= SCREEN_WIDTH && mouse_y >= SCREEN_HEIGHT - 58 && mouse_y <= SCREEN_HEIGHT)
    {
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            go_to_menu = false;
            openCredit = true;
        }
    }
}

void mousehandling_start()
{
    if (sound == false)
    {
        Mix_PlayMusic(menusound, -1);
        sound = true;
    }
    start_menu();
    // get mouse coordinates
    buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
    // newgame
    if (mouse_x >= 10 && mouse_x <= 10 + mWidth && mouse_y >= (SCREEN_HEIGHT / 2) - 50 && mouse_y <= (SCREEN_HEIGHT / 2) - 70 + mHeight)
    {
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            showmodemenu = true;
            go_to_menu = false;
            start = true;
            mode = 0;
        }
    }

    // help
    if (mouse_x >= 10 && mouse_x <= 10 + mWidth - 180 && mouse_y >= (SCREEN_HEIGHT / 2) + 15 && mouse_y <= (SCREEN_HEIGHT / 2) + mHeight - 20)
    {
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            go_to_menu = false;
            go_to_help = true;
        }
    }

    // highscore
    if (mouse_x >= 10 && mouse_x <= mWidth && mouse_y >= (SCREEN_HEIGHT / 2) + 50 + 15 && mouse_y <= (SCREEN_HEIGHT / 2) + 50 + mHeight - 15)
    {
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            go_to_menu = false;
            showmodemenu = true;
            showhighscore = true;
        }
    }
    // exit
    if (mouse_x >= 10 && mouse_x <= 10 + mWidth - 180 && mouse_y >= (SCREEN_HEIGHT / 2) + 100 + 10 && mouse_y <= (SCREEN_HEIGHT / 2) + 100 + mHeight - 10)
    {

        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            SDL_Delay(100);
            quit = true;
        }
    }

    // credit @MAHIM
    if (mouse_x >= SCREEN_WIDTH - 100 && mouse_x <= SCREEN_WIDTH && mouse_y >= SCREEN_HEIGHT - 58 && mouse_y <= SCREEN_HEIGHT)
    {
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            go_to_menu = false;
            openCredit = true;
        }
    }
}

void mousehandling_mode()
{
    mode_menu();

    buttons1 = SDL_GetMouseState(&mouse_x1, &mouse_y1);
    if (mouse_x1 >= (SCREEN_WIDTH / 2) - 80 && mouse_x1 <= (SCREEN_WIDTH / 2) - 80 + mWidth && mouse_y1 >= (SCREEN_HEIGHT / 2) - 150 && mouse_y1 <= (SCREEN_HEIGHT / 2) - 150 + mHeight + 20)
    {
        if (buttons1 & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            Mix_HaltMusic();
            sound = false;
            Mix_PlayMusic(citysound, -1);
            showmodemenu = false;
            stop_music = false;
            go_to_menu = false;
            start = false;
            frame = 0;
            scrollingOffset = 0;
            i = 0;
            x_pos = 50;
            y_pos = 400;
            up = 0;
            down = 0;
            ground = 1;
            y_velocity = 20;
            score = -10;

            pause = false;

            coin.x = x_pos + 80;
            coin.y = 477;

            obs_x1 = 800;
            obs_x2 = 1100;
            obs_x3 = 1500;
            obs_x1_width = 100;
            obs_x2_width = 140;
            obs_x3_width = 100;
            srand(time(0));

            alive = 3;
            mode = 1;
        }
    }
    if (mouse_x1 >= (SCREEN_WIDTH / 2) - 80 && mouse_x1 <= (SCREEN_WIDTH / 2) - 80 + mWidth && mouse_y1 >= (SCREEN_HEIGHT / 2) && mouse_y1 <= (SCREEN_HEIGHT / 2) + mHeight + 20)
    {
        if (buttons1 & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            Mix_HaltMusic();
            sound = false;
            Mix_PlayMusic(forestsound, -1);
            showmodemenu = false;
            stop_music = false;
            go_to_menu = false;
            start = false;
            frame = 0;
            scrollingOffset = 0;
            i = 0;
            x_pos = 50;
            y_pos = 360;
            up = 0;
            down = 0;
            ground = 1;
            y_velocity = 20;
            score = 0;

            pause = false;

            star.x = 1000;
            star.y = 232;

            coin.x = 700;
            coin.y = 232;

            setup_enemy();
            setup_knifes();

            indicator.start = 0;
            indicator.finish = 0;

            knifes_counter = 3;
            srand(time(0));

            obs_x1 = 800;
            obs_x2 = 1100;
            obs_x3 = 1500;
            obs_x1_width = 80;
            obs_x2_width = 130;
            obs_x3_width = 80;

            alive = 3;
            mode = 2;
        }
    }
}

void mousehandling_highscore()
{
    mode_menu();
    buttons1 = SDL_GetMouseState(&mouse_x1, &mouse_y1);

    if (mouse_x1 >= (SCREEN_WIDTH / 2) - 80 && mouse_x1 <= (SCREEN_WIDTH / 2) - 80 + mWidth && mouse_y1 >= (SCREEN_HEIGHT / 2) - 150 && mouse_y1 <= (SCREEN_HEIGHT / 2) - 150 + mHeight + 20)
    {
        if (buttons1 & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            Scoremode = 1;
            showmodemenu = false;
        }
    }
    if (mouse_x1 >= (SCREEN_WIDTH / 2) - 80 && mouse_x1 <= (SCREEN_WIDTH / 2) - 80 + mWidth && mouse_y1 >= (SCREEN_HEIGHT / 2) && mouse_y1 <= (SCREEN_HEIGHT / 2) + mHeight + 20)
    {
        if (buttons1 & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            Mix_PlayChannel(-1, mouseclick, 0);
            Scoremode = 2;
            showmodemenu = false;
        }
    }
}

void nameprint()
{
    char namestring[30] = " ";
    SDL_Event e;
    int k = 1;

    bool rendertext = true;
    bool quit = false;
    ;
    SDL_StartTextInput();

    while (rendertext)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_TEXTINPUT)
            {
                if (k < 7 && e.text.text[0] != ' ')
                {
                    namestring[k++] = e.text.text[0];
                    namestring[k] = '\0';
                }
            }
            else if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_BACKSPACE)
                {
                    if (k > 1)
                    {
                        namestring[--k] = '\0';
                    }
                }
                else if (e.key.keysym.scancode == SDL_SCANCODE_RETURN && k > 1)
                {
                    rendertext = false;
                }
            }
        }

        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
        SDL_RenderClear(gRenderer);
        SDL_Texture *temp = scoreprint(namestring);
        render(name, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, NULL);
        render(EnterName, mWidth + 150, mHeight + 50, (SCREEN_WIDTH / 2 - 200), 0, NULL);
        render(temp, k * 40, 120, (SCREEN_WIDTH / 2 - k * 20), (SCREEN_HEIGHT / 2) - 60, NULL);
        SDL_RenderPresent(gRenderer);
    }
    SDL_StopTextInput();

    for (i = 1;; i++)
    {
        namestring[i - 1] = namestring[i];
        if (namestring[i] == '\0')
        {
            break;
        }
    }
    start_highscore(namestring);
}
