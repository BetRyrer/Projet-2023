#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#include "../fichier.h/time.h"
#include "../fichier.h/main.h"
#include "../fichier.h/serpent.h"
#define CYCLE 1000000L

/*Affichage du score*/
void Score(int segment){
    int nombre;
    char score[4];
    nombre= (segment-10)*25;
    snprintf(score,4,"%04d0", nombre);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(950,725,1300,800);
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(1000,760,"Score: ",2);
    EcrireTexte(1100,760,score,2);
}
void Update_Timer(int minute, int seconde, char timer[]){
    snprintf(timer,6,"%02d:%02d", minute, seconde);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(20,735,200,75);
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(50,760,"time: ",2);
    EcrireTexte(120,760,timer,2);
}
void Timer(int *minute, int *seconde, unsigned long int *suivant, int *seconde_actuel, int *old_seconde, char timer[]){
    if(Microsecondes()> *suivant){
        *suivant = Microsecondes()+CYCLE;
        *seconde_actuel = (*suivant/1000000)%10;
        if(seconde_actuel !=old_seconde){
            *old_seconde = *seconde_actuel;
            if(*seconde == 59){
                *minute=*minute+1;
                *seconde=0;
                Update_Timer(*minute, *seconde, timer);
            }else{
                *seconde = *seconde+1;
                Update_Timer(*minute, *seconde, timer);
            }
        }
    }
}