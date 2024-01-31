#ifndef SERPENT_H
#define SERPENT_H

void Serpent(int pos_x[], int pos_y[], int old_x[], int old_y[], int *segment, int murx[], int mury[], int *go_on, int *direction);
void Collision_Serpent(int pos_x[], int pos_y[], int segment, int murx[], int mury[], int *go_on);
void Update_Serpent(int pos_x[], int pos_y[], int segment, int old_x[], int old_y[], int*);
void Controle(int *direction, int last_direction, int *go_on, int *pause);
void dessinerSerpent(int pos_x[], int pos_y[], int segment, int old_x[], int old_y[]);
#endif
