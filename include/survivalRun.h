#ifndef SURVIVALRUN_H
#define SURVIVALRUN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <time.h>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;

bool init();
bool loadMedia();
void close();
SDL_Texture *loadtexture(std::string path);

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern SDL_Texture *gameOver;
extern SDL_Texture *mTexture;

extern SDL_Texture *Coin;
extern SDL_Texture *Man;

extern SDL_Texture *scoreTexture;
extern SDL_Texture *gScoretexture;
extern SDL_Texture *scoreImage;
extern SDL_Texture *life;
extern SDL_Texture *ScoreName;
extern SDL_Texture *HighScore;
extern SDL_Texture *sl;
extern SDL_Texture *Image;

extern Mix_Music *menusound;
extern Mix_Music *citysound;
extern Mix_Music *forestsound;
extern Mix_Chunk *dogsound;
extern Mix_Chunk *zombiesound;
extern Mix_Chunk *coinsound;
extern Mix_Chunk *diesound;
extern Mix_Chunk *collidesound;
extern Mix_Chunk *weaponsound;
extern Mix_Chunk *mouseclick;

extern SDL_Rect coin;
extern TTF_Font *gFont;

extern SDL_Rect gSpriteClips[6];
extern char scorestring[100];

extern int mWidth;
extern int mHeight;

extern int frame;
extern int scrollingOffset;
extern int x_pos;
extern int y_pos;
extern int up;
extern int down;
extern int ground;
extern int y_velocity;

extern int score;
extern int mode;
extern int Scoremode;
extern bool sound;

extern int alive;
extern int i, j, k;
extern bool start;

void render(SDL_Texture *, int, int, int, int, SDL_Rect *);
SDL_Texture *loadFromRenderedText(std::string textureText, SDL_Color textColor);
void int_to_string(int);
SDL_Texture *scoreprint(std::string textureText);
void coins(int coin_position1, int coin_position2, bool star_or_not);
void jump(int y_pos_start);
void gameover();
void start_highscore(char namestring[]);
void SAVE_HIGHSCORE(char path[], char name[]);
void SHOW_HIGHSCORE(char path[]);
#endif
