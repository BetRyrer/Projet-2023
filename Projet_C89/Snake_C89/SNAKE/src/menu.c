#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

#include "../fichier.h/main.h"
#include "../fichier.h/time.h"

void Menu_debut(void) {
    int af = ChargerSprite("img/image.jpg");
        AfficherSprite(af, 0, 0);
}
void Menu_fin(void){
    int fin = ChargerSprite("img/Menu_Fin.jpg");
        AfficherSprite(fin, 0,0);
}

int Menu(void) {
    int choix = 1;
    InitialiserGraphique();
    Menu_debut();
    while (1) {
        if (ToucheEnAttente()) {
            int touche = Touche();
            switch (touche) {
                case XK_e:
                    choix = 1;
                    return choix;
                case XK_q:
                    FermerGraphique();
                    return choix;
            }
        }
    }
}
void bordure(int segment){
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(20,720,1180,200);
    RemplirRectangle(0,0,20,900);
    RemplirRectangle(0,0,1200,20);
    RemplirRectangle(1180,0,1200,900);
    Score(segment);
}

