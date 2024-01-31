#include <graph.h>
#include <stdlib.h>
#include <stdio.h>

#include <graph.h>
#include "../fichier.h/serpent.h"
#include "../fichier.h/main.h"

void Update_Serpent(int pos_x[], int pos_y[], int segment, int old_x[], int old_y[], int* direction){
    int i = 0;
    for (i=1 ; i<segment ; i++){
        pos_x[i]=old_x[i-1];
        pos_y[i]=old_y[i-1];
    }
    /*Afficher tête serpent selon la direction*/
    if (*direction == 1 && *direction !=2 ){
        pos_y[0]=old_y[0]-20;
        ChargerImage("img/tete_up.png", pos_x[0], pos_y[0], 0,0,20,20);
    }
    if (*direction == 2 && *direction !=1) {
        pos_y[0]=old_y[0]+20;
        ChargerImage("img/tete_down.png", pos_x[0], pos_y[0], 0,0,20,20);
    }
    if (*direction == 3 && *direction !=4) {
        pos_x[0]=old_x[0]-20;
        ChargerImage("img/tete_left.png", pos_x[0], pos_y[0], 0,0,20,20);
    }
    if (*direction == 4 && *direction !=3) {
        pos_x[0]=old_x[0]+20;
        ChargerImage("img/tete_right.png", pos_x[0], pos_y[0], 0,0,20,20);
   }
    return;
}

void dessinerSerpent(int pos_x[], int pos_y[], int segment, int old_x[], int old_y[]){
    int i;
    /*Afficher le serpent*/
    for (i=0 ; i<segment ; i++){
        ChargerImage("img/serpent.png", old_x[i], old_y[i],0,0, 20,20);
    }
    /*Incrémentation du fond par rapport au déplacement du serpent*/
    for (i=0 ; i<segment ; i++){
        ChoisirCouleurDessin(CouleurParComposante(218,209,77));
        RemplirRectangle(old_x[segment-1], old_y[segment-1], 20,20);
        old_x[i]=pos_x[i];
        old_y[i]=pos_y[i];
    } 
    /*Affichier la queue du serpent*/
    for (i=0 ; i<segment; i++){
        ChargerImage("img/queue.png", old_x[segment-1], old_y[segment-1],0,0, 20,20);
        ChoisirCouleurDessin(CouleurParNom("black"));
        RemplirRectangle(0,0,20,20);
}
}
void Collision_Serpent(int pos_x[], int pos_y[], int segment, int murx[], int mury[], int *go_on){
    int i;
    /*Serpent contre coté*/
    if (pos_x[0] >1160 || pos_x[0]<=0){
         *go_on = 0;
    }
    /*Serpent contre coté*/
    if (pos_y[0]<20 || pos_y[0] >=720){
        *go_on = 0;
    }
    /*Serpent contre Serpent*/
    for (i = 1; i < segment; i++) {
        if (pos_x[0] == pos_x[i] && pos_y[0] == pos_y[i]){
        *go_on = 0;
        }
    }
    /*Serpent contre mur*/
    for(i=0; i<30;i++){
        if(pos_x[0] == murx[i] && pos_y[0] == mury[i]){
         *go_on = 0;
        }
    }
    return;
}

void Controle(int *direction, int last_direction, int *go_on, int *pause) {
    int t;
    while(ToucheEnAttente()) {
        t = Touche();
        switch(t) {
            case XK_Left:
                if (*direction != 4) {
                    *direction = 3;
                }
                return;
            case XK_Right:
                if (*direction != 3) {
                    *direction = 4;
                }
                return;
            case XK_Up:
                if (*direction != 2) {
                    *direction = 1;
                }
                return;
            case XK_Down:
                if (*direction != 1) {
                    *direction = 2;
                }
                return;
            case XK_Escape:
                *direction = 0;
                *go_on = 0;
                return;
                case XK_space :
                    *pause = 1;
                    ChargerImage("img/PAUSE.png", 400,720,0,0,400,150);
                    while(*pause){
                        t = Touche();
                        if (t == XK_space){
                            *pause = 0;
                            ChoisirCouleurDessin(CouleurParNom("black"));
                            RemplirRectangle(200,720,800,200);                
                 }
            }
        }
    }
}
void Serpent(int pos_x[], int pos_y[], int old_x[], int old_y[], int *segment, int murx[], int mury[], int *go_on, int *direction) {
    int serpent;
     int i = 0;
    /*Position initial serpent*/
    pos_x[0] = 600;
    pos_y[0] = 400;
    for (i = 0; i < *segment; i++){
      pos_x[i]= pos_x[0];
      pos_y[i]= pos_y[0];
      old_x[i]=pos_x[i];
      old_y[i]=pos_y[i];
    }
}