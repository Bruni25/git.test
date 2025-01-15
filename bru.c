#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titre[100];
    char auteur[100];
    int  anneepublication;
    char isbn[20];
} livre;

livre bibliotheque [1000];
int livre_count = 0;
void ajouter() {
    if (livre_count >= 1000) {
        printf("\nLa bibliotheque est pleine. Impossible d'ajouter un nouveau livre.\n");
        return;
    }

    livre livre1;
    printf("\nTitre du livre : ");
    scanf("%s", livre1.titre);

    printf("Auteur du livre : ");
   scanf("%s", livre1.auteur);
  
   

    printf("Annee de publication : ");
    scanf("%d", &livre1.anneepublication);

    printf("Numero ISBN : ");
    scanf("%s", livre1.isbn);

    bibliotheque[livre_count++] = livre1;
    printf("\nLivre ajoute avec succes !\n");
}
void afficher() {
    if (livre_count == 0) {
        printf("\nAucun livre disponible dans la bibliotheque.\n");
        return;
    }

    printf("\nListe des livres:\n");
    for (int i = 0; i < livre_count; i++) {
        printf("Livre %d:\n", i + 1);
        printf("  ISBN: %s\n", bibliotheque[i].isbn);
        printf("  Titre: %s\n", bibliotheque[i].titre);
        printf("  Auteur: %s\n", bibliotheque[i].auteur);
        printf("  Année de publication: %d\n\n", bibliotheque[i].anneepublication);
    }

}

void recherche() {
    char recherche[100];
    printf("\nEntrez le titre ou l'auteur � rechercher : ");
    scanf("%s", recherche);
  

    printf("\nResultats de la recherche :\n");
    int cherche = 0;
    for (int i = 0; i < livre_count; i++) {
        if (strstr(bibliotheque[i].titre, recherche) || strstr(bibliotheque[i].auteur, recherche)) {
            printf("\nTitre : %s\nAuteur : %s\nAnnee : %d\nISBN : %s\n",
                   bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].anneepublication, bibliotheque[i].isbn);
             cherche= 1;
        }
    }
    if (!cherche) {
        printf("Aucun livre trouve pour %s.\n", recherche);
    }
}
void supprimer() {
    char isbn[20];
    printf("\nEntrez le numéro ISBN du livre à supprimer : ");
    fgets(isbn, sizeof(isbn), stdin);


    for (int i = 0; i < livre_count; i++) {
        if (strcmp(bibliotheque[i].isbn, isbn) == 0) {
            for (int j = i; j < livre_count - 1; j++) {
                bibliotheque[j] = bibliotheque[j + 1];
            }
            livre_count--;
            printf("\nLivre supprimé avec succès !\n");
            return;
        }
    }
}
void enregistrer() {
    FILE *file = fopen("bibliotheque.dat", "wb");
    if (!file) {
        printf("\nErreur lors de la sauvegarde des données.\n");
        return;
    }
    fwrite(&livre_count, sizeof(int), 1, file);
    fwrite(bibliotheque, sizeof(livre), livre_count, file);
    fclose(file);
    printf("\n livres sauvegardées avec succès dans le fichier bibliotheque .dat.\n");
}




int main() {
    int choix;

    do {
        printf("\nSystème de gestion de bibliothèque\n");
        printf("1. Ajouter un nouveau livre\n");
        printf("2. Rechercher un livre\n");
        printf("3. Afficher tous les livres\n");
        printf("4. Supprimer un livre\n");
        printf("5. Sauvegarder et quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                recherche();
                break;
            case 3:
                afficher();
                break;
            case 4:
                supprimer();
                break;
            case 5:
                enregistrer();
                printf("\nMerci d'avoir utilise notre système de gestion de bibliothèque.\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 5);

    return 0;
}