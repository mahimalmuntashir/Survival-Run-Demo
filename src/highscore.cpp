#include "header.h"
SDL_Texture *Image = NULL;

void start_highscore(char namestring[])
{

    FILE *fptr;
    int tempScore;
    if (mode == 1)
    {
        fptr = fopen("res/score/CITY.txt", "r");

        if (fptr == NULL)
        {
            printf("FILE DOES NOT EXIST\n");
        }
    }
    else if (mode == 2)
    {
        fptr = fopen("res/score/FOREST.txt", "r");
        if (fptr == NULL)
        {
            printf("FILE DOES NOT EXIST\n");
        }
    }
    char ch1[50], ch2[50];
    for (; fgets(ch1, 40, fptr) != NULL;)
    {
    }
    fclose(fptr);
    sscanf(ch1, "%s %s %d", ch2, ch2, &tempScore);
    if (score > tempScore)
    {
        if (mode == 1)
        {
            char ch[50] = "res/score/CITY.txt";
            SAVE_HIGHSCORE(ch, namestring);
        }
        else if (mode == 2)
        {
            char ch[50] = "res/score/FOREST.txt";
            SAVE_HIGHSCORE(ch, namestring);
        }
    }
    mode = 0;
}

void SAVE_HIGHSCORE(char path[], char name[])
{
    FILE *fptr = fopen(path, "r");
    char ch[7][50], temp[50];
    int i, tempScore;
    for (i = 1; i <= 5; i++)
    {
        fgets(ch[i], 40, fptr);
    }
    sprintf(ch[5], "05. %s %d", name, score);
    fclose(fptr);
    for (i = 4; i >= 1; i--)
    {
        sscanf(ch[i], "%s %s %d", ch[0], temp, &tempScore);
        if (score > tempScore)
        {
            sprintf(ch[i], "0%d. %s %d\n", i, name, score);
            sprintf(ch[i + 1], "0%d. %s %d\n", i + 1, temp, tempScore);
        }
        else
        {
            break;
        }
    }

    fptr = fopen(path, "w");
    for (i = 1; i <= 5; i++)
    {
        fprintf(fptr, "%s", ch[i]);
    }
    fclose(fptr);
    if (mode == 1)
    {
        char ch[50] = "res/score/CITY.txt";
        SHOW_HIGHSCORE(ch);
        SDL_Delay(5000);
    }
    else if (mode == 2)
    {
        char ch[50] = "res/score/FOREST.txt";
        SHOW_HIGHSCORE(ch);
        SDL_Delay(5000);
    }
}

void SHOW_HIGHSCORE(char path[])
{
    FILE *FILEPOINTER = fopen(path, "r");
    if (FILEPOINTER == NULL)
    {
        printf("FILE NULL\n");
    }

    char ch[10][50], serial[25], name[25], score[25];
    int i;

    SDL_Rect name_rect, score_rect, serial_rect;
    serial_rect.x = 200;
    serial_rect.y = 50;
    serial_rect.w = 20 * 3;
    serial_rect.h = 50;

    name_rect.x = 300;
    name_rect.y = 50;
    name_rect.w = 20 * 4;
    name_rect.h = 50;

    score_rect.x = 500;
    score_rect.y = 50;
    score_rect.w = 20 * 5;
    score_rect.h = 50;

    render(HighScore, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, NULL);
    render(sl, serial_rect.w, serial_rect.h, serial_rect.x, serial_rect.y, NULL);
    render(nameTexture, name_rect.w, name_rect.h, name_rect.x, name_rect.y, NULL);
    render(ScoreName, score_rect.w, score_rect.h, score_rect.x, score_rect.y, NULL);

    for (i = 0; fgets(ch[i], 40, FILEPOINTER) != NULL; i++)
    {
    }

    for (i = 0; i < 5; i++)
    {
        sscanf(ch[i], "%s %s %s", serial, name, score);

        serial_rect.y += 54;
        serial_rect.w = strlen(serial) * 20;
        Image = scoreprint(serial);
        render(Image, serial_rect.w, serial_rect.h, serial_rect.x + 35, serial_rect.y + 125, NULL);

        name_rect.y += 54;
        name_rect.w = strlen(name) * 20;
        Image = scoreprint(name);
        render(Image, name_rect.w, name_rect.h, name_rect.x + 145, name_rect.y + 125, NULL);

        score_rect.y += 54;
        score_rect.w = strlen(score) * 20;
        Image = scoreprint(score);
        render(Image, score_rect.w, score_rect.h, score_rect.x + 225, score_rect.y + 125, NULL);

        SDL_DestroyTexture(Image);
    }

    SDL_RenderPresent(gRenderer);
    fclose(FILEPOINTER);
}
