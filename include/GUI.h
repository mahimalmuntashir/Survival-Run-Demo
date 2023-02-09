#ifndef UI_H
#define UI_H
#include "survivalRun.h"

extern SDL_Texture *menu;
extern SDL_Texture *menu1;
extern SDL_Texture *newgame;
extern SDL_Texture *help;
extern SDL_Texture *highscore;
extern SDL_Texture *gEnd;
extern SDL_Texture *Continue;
extern SDL_Texture *city;
extern SDL_Texture *forest;
extern SDL_Texture *menu2;
extern SDL_Texture *mcredit;
extern SDL_Texture *name;
extern SDL_Texture *EnterName;
extern SDL_Texture *tutorial;
extern SDL_Texture *nameTexture;

extern int buttons, mouse_x, mouse_y, buttons1, mouse_x1, mouse_y1;

extern bool go_to_menu;
extern bool quit;
extern bool pause;
extern bool go_to_help;
extern bool openCredit;
extern bool showmodemenu;
extern bool showhighscore;
extern bool stop_music;

void nameprint();
void middle_menu();
void start_menu();
void mode_menu();
void mousehandling_middle();
void mousehandling_start();
void mousehandling_mode();
void pollevent();
void instruction();
void myCredit();
void mousehandling_highscore();
#endif
