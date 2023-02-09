#ifndef SECONDMODE_H
#define SECONDMODE_H
#include "survivalRun.h"

extern SDL_Texture *BG2;
extern SDL_Texture *Star;
extern SDL_Texture *dog;
extern SDL_Texture *enemy_zombie;
extern SDL_Texture *knife_texture;
extern SDL_Texture *enemy_ghost;
extern SDL_Texture *knifeTexture;
extern SDL_Texture *gKnifeTexture;

extern SDL_Rect dog_spriteclips[12];
extern SDL_Rect zombie_spriteclips[30];
extern SDL_Rect ghost_spriteclips[30];

extern int knifes_counter;
extern char knifestring[500];

enum TYPE
{
    DOG,
    ZOMBIE,
    GHOST,
    TOTAL
};

struct animal
{
    SDL_Rect body;
    int speed;
    int lives;
};

extern struct animal enemy[5];

struct weapon
{
    SDL_Rect hit = {150, 420, 40, 40};
    bool available = false;
};

extern struct weapon knife[80];

struct start_and_end
{
    int start = 0;
    int finish = 0;
};

extern struct start_and_end indicator;
extern SDL_Rect star;

void man_sprite();
void dog_sprite();
void zombie_sprite();
void ghost_sprite();
void setup_enemy();
void setup_knifes();
void rendering_knifes();
void managing_knife();
void int_to_string_knife(int a);
SDL_Texture *knifeprint(std::string textureText);
void knives();
void enemies();
void Killing_Enemy(SDL_Rect oponent, int a, SDL_Rect star);
void secondMode();
#endif