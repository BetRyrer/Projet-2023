#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <graph.h>

#include "../fichier.h/time.h"
#include "../fichier.h/terrain.h"
#include "../fichier.h/serpent.h"
#include "../fichier.h/main.h"
#include "../fichier.h/Oeuf.h"

void Scene(int murx[], int mury[], int minute, int seconde, char timer []){
    int mur;
    int i;
     snprintf(timer,6,"%02d:%02d", minute ,seconde);
     ChoisirCouleurDessin(CouleurParComposante(218,209,77));
     RemplirRectangle(20,20,1160,700);
     ChoisirCouleurDessin(CouleurParComposante(255,255,255)); 
     srand(time(NULL));
    /*Initialisation de 30 obstacles */
     for(i=0; i<30; i++){
        murx[i] = ((rand() % (55)+1)*20);
        mury[i] = ((rand() % (35)+1)*20);
         ChargerImage("img/cactus.png", murx[i], mury[i],0,0, 20,20);
    }
}
