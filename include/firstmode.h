#ifndef FIRSTMODE_H
#define FIRSTMODE_H
#include "survivalRun.h"
extern SDL_Texture *BG1;
extern SDL_Texture *Obstacle1;
extern SDL_Texture *Obstacle2;
extern SDL_Texture *Obstacle3;

extern int obs_x1;
extern int obs_x2;
extern int obs_x3;
extern int obs_x1_width;
extern int obs_x2_width;
extern int obs_x3_width;

void OBSTACLES_AND_COIN_POSITION(int *, int *, int *, int *, int *, int *, int *, int *, int, bool);
void obstacle();
void firstMode();
#endif
