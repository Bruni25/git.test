#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVRES 1000

typedef struct {
    char titre[100];
    char auteur[100];
    int année;
    char isbn[20];
} livre;

livre bibliothèque[MAX_LIVRES];
int livre_count = 0;

void ajouter() {
    if (livre_count >= MAX_LIVRES) {
        printf("\nLa bibliothèque est pleine.n");
        return;
    }

    livre livre1;
    printf("\nTitre du livre : ");
    fgets(livre1.titre, sizeof(livre1.titre), stdin);


    printf("Auteur du livre : ");
    fgets(livre1.auteur, sizeof(livre1.auteur), stdin);

    printf("Année de publication : ");
    scanf("%d", &livre1.année);

    printf("Numéro ISBN : ");
    scanf("%s", livre1.isbn);

    bibliothèque[livre_count++] = livre1;
    printf("\n Votre livre a été ajouté avec succès \n");
}
return 0
}