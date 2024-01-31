#include <graph.h>
#include <stdlib.h>
#include <stdlib.h>

#include "../fichier.h/Oeuf.h"
#include "../fichier.h/time.h"

void InitialiserOeufs(int oeufx[], int oeufy[], int segment) {
    int p;
    int oeuf;
    /*Boucles qui initialse 5 oeufs aléatoirement*/
    for (p = 0; p < 5; p++) {
        oeufx[p] = ((rand() % (55) + 1) * 20);
        oeufy[p] = ((rand() % (35) + 1) * 20);
        ChargerImage("img/oeuf.png", oeufx[p], oeufy[p],0,0, 20,20);
    }
}
void Oeuf(int old_x[], int old_y[], int oeufx[], int oeufy[], int *segment){
    int p;
    int oeuf;  
    for (p = 0; p < 5; p++) {
        ChargerImage("img/oeuf.png", oeufx[p], oeufy[p],0,0, 20,20);
    }
    /*Boucles pour vérifiier la colision avec le serpent */
    for(p=0; p<5; p++){
        if(oeufx[p]==old_x[0] && oeufy[p]==old_y[0]){
            (*segment) +=2;
            oeufx[p] = ((rand() % (55)+1)*20);
            oeufy[p] = ((rand() % (35)+1)*20);
            Score(*segment);
        }
        
    }
}