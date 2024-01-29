#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Carte {
    char titlu[100];
    char autor[100];
    char isbn[20];
};
struct Biblioteca {
    struct Carte carti[100];
    int numarCarti;
};
void adaugaCarte(struct Biblioteca *biblioteca) {
    printf("Introduceti titlul: ");
    scanf("%s", biblioteca->carti[biblioteca->numarCarti].titlu);
    printf("Introduceti autorul: ");
    scanf("%s", biblioteca->carti[biblioteca->numarCarti].autor);
    printf("Introduceti ISBN-ul: ");
    scanf("%s", biblioteca->carti[biblioteca->numarCarti].isbn);
    printf("Cartea '%s' a fost adaugata in biblioteca.\n", biblioteca->carti[biblioteca->numarCarti].titlu);
    biblioteca->numarCarti++;
}
void stergeCarte(struct Biblioteca *biblioteca) {
    char titlu[100];
    printf("Introduceti titlul cartii de sters: ");
    scanf("%s", titlu);
    int gasit = 0;
    for (int i = 0; i < biblioteca->numarCarti; i++) {
        if (strcmp(biblioteca->carti[i].titlu, titlu) == 0) {
            for (int j = i; j < biblioteca->numarCarti - 1; j++) {
                biblioteca->carti[j] = biblioteca->carti[j + 1];
            }
            biblioteca->numarCarti--;
            gasit = 1;
            printf("Cartea '%s' a fost stearsa din biblioteca.\n", titlu);
            break;
        }
    }
    if (!gasit) {
        printf("Cartea '%s' nu a fost gasita in biblioteca.\n", titlu);
    }
}
void afiseazaCarti(struct Biblioteca *biblioteca) {
    if (biblioteca->numarCarti == 0) {
        printf("Nu exista carti in biblioteca.\n");
    } else {
        printf("Carti din biblioteca:\n");
        for (int i = 0; i < biblioteca->numarCarti; i++) {
            printf("Titlu: %s, Autor: %s, ISBN: %s\n", biblioteca->carti[i].titlu, biblioteca->carti[i].autor, biblioteca->carti[i].isbn);
        }
    }
}
int main() {
    struct Biblioteca biblioteca;
    biblioteca.numarCarti = 0;
    while (1) {
        printf("\nMeniu:\n");
        printf("1. Adauga o carte\n");
        printf("2. Sterge o carte\n");
        printf("3. Afiseaza toate cartile\n");
        printf("4. Iesire\n");
        int optiune;
        printf("Introduceti optiunea (1-4): ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                adaugaCarte(&biblioteca);
                break;
            case 2:
                stergeCarte(&biblioteca);
                break;
            case 3:
                afiseazaCarti(&biblioteca);
                break;
            case 4:
                exit(0);
            default:
                printf("Optiune invalida. Va rugam introduceti un numar intre 1 si 4.\n");
        }
    }
    return 0;
}
