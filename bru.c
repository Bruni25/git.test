#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXlivres 1000
typedef struct {
    char titre[100];
    char auteur[100];
    int  anneepublication;
    char isbn[20];
} livre;

livre bibliotheque [1000];
int livre_count = 0;
void ajouter() {
    if (livre_count >= MAXlivres) {
        printf("\nLa bibliotheque est pleine. Impossible d'ajouter un nouveau livre.\n");
        return;
    }

    livre livre1;
    printf("\nTitre du livre : ");
    fgets(livre1.titre, sizeof(livre1.titre), stdin);
  

    printf("Auteur du livre : ");
    fgets(livre1.auteur, sizeof(livre1.auteur), stdin);
   

    printf("Annee de publication : ");
    scanf("%d", &livre1.anneepublication);

    printf("Numero ISBN : ");
    scanf("%s", livre1.isbn);

    bibliotheque[livre_count++] = livre1;
    printf("\nLivre ajoute avec succes !\n");
}
void afficher() {
    if (livre_count == 0) {
        printf("\nAucun livre disponible dans la biblioth�que.\n");
        return;
    }

    printf("\nListe des livres:\n");
    for (int i = 0; i < livre_count; i++) {
        printf("Livre %d:\n", i + 1);
        printf("  ISBN: %s\n", bibliotheque[i].isbn);
        printf("  Titre: %s\n", bibliotheque[i].titre);
        printf("  Auteur: %s\n", bibliotheque[i].auteur);
        printf("  Année: %d\n\n", bibliotheque[i].anneepublication);
    }

}

void recherche() {
    char recherche[100];
    printf("\nEntrez le titre ou l'auteur � rechercher : ");
    fgets(recherche, sizeof(recherche), stdin);
  

    printf("\nResultats de la recherche :\n");
    int cherche = 0;
    for (int i = 0; i < livre_count; i++) {
        if (strstr(bibliotheque[i].titre, recherche) || strstr(bibliotheque[i].auteur, recherche)) {
            printf("\nTitre : %s\nAuteur : %s\nAnn�e : %d\nISBN : %s\n",
                   bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].anneepublication, bibliotheque[i].isbn);
             cherche= 1;
        }
    }
    if (!cherche) {
        printf("Aucun livre trouv� pour %s.\n", recherche);
    }
}


int main()
{
    printf("hello bruni");
    ajouter();
    afficher();
    recherche();
    return 0;
}