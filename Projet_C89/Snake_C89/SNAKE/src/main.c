#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>

#include "../fichier.h/serpent.h"
#include "../fichier.h/Oeuf.h"
#include "../fichier.h/time.h"
#include "../fichier.h/main.h"
#include "../fichier.h/menu.h"
#include "../fichier.h/terrain.h"

#define CYCLE 100000L
#define DELAI_MILLISECONDES 100

void attente(int milliseconds) {
    clock_t start_time = clock();
    while ((clock() - start_time) * 1000 / CLOCKS_PER_SEC < milliseconds) {
    }
}

int lancer_jeu(){
    /*Variable jeu*/
    int go_on=1;
    int pause = 1;
    /*Variable Serpent*/
    int segment = 10;
    int direction = 4;   
    int pos_x[2400];
    int pos_y[2400];
    int old_x[2400];
    int old_y[2400];
    /*Variable pour le temps*/
    int minute = 0;
    int seconde = 0;
    int seconde_actuel = 0;
    int old_seconde = 0;
    char timer[6];
    unsigned long int suivant;
    /*Variable Oeufs*/
    int oeufx[5];
    int oeufy[5];
    /*Variable Murs*/
    int murx[30];
    int mury[30];
    /*Pointeur */
    int *pointeur_segment = &segment;
    int *pointeur_direction = &direction;
    int *pointeur_minute = &minute;
    int *pointeur_seconde = &seconde;
    int *pointeur_seconde_actuel = &seconde_actuel;
    int *pointeur_old_seconde = &old_seconde;
    int *pointeur_pause = &pause;
    unsigned long int *pointeur_suivant = &suivant;
     suivant = Microsecondes()+CYCLE;
     old_seconde=(suivant/1000000)%10;
      Scene(murx, mury, minute, seconde ,timer);
      InitialiserOeufs(oeufx, oeufy, segment);
      Serpent(pos_x, pos_y, old_x, old_y, pointeur_segment, murx, mury, &go_on, pointeur_direction);
      bordure(segment);
      Update_Serpent(pos_x, pos_y, segment, old_x, old_y, pointeur_direction);
      /*Lancement du jeu*/
    while(go_on==1){
        Controle(pointeur_direction, 0, &go_on, pointeur_pause);
        if(pause == 1){
         Timer( pointeur_minute, pointeur_seconde,  pointeur_suivant, pointeur_seconde_actuel, pointeur_old_seconde, timer);
         Update_Serpent(pos_x, pos_y, segment, old_x, old_y, pointeur_direction);
         dessinerSerpent(pos_x, pos_y, segment, old_x, old_y);
         Collision_Serpent(pos_x, pos_y, segment, murx, mury, &go_on);
         attente(DELAI_MILLISECONDES);
         Oeuf(pos_x, pos_y, oeufx, oeufy, pointeur_segment);
    }else{
         Controle(pointeur_direction, 0, &go_on, pointeur_pause);
         Timer( pointeur_minute, pointeur_seconde,  pointeur_suivant, pointeur_seconde_actuel, pointeur_old_seconde, timer);
         Update_Serpent(pos_x, pos_y, segment, old_x, old_y, pointeur_direction);
         dessinerSerpent(pos_x, pos_y, segment, old_x, old_y);
         Collision_Serpent(pos_x, pos_y, segment, murx, mury, &go_on);
         attente(DELAI_MILLISECONDES);
         Oeuf(pos_x, pos_y, oeufx, oeufy, pointeur_segment);
     }

    }
}
int main(void){
    int choix = 0;
     InitialiserGraphique();
     CreerFenetre(350,100,1200,900);
     EffacerEcran(CouleurParComposante(0,0,0));
      Menu();
      if(Menu() == 1){
       lancer_jeu();
    }
     FermerGraphique();
}
