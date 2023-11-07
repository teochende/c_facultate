//Sa se scrie un program care citeste ora, minutul si secunda la care a inceput un eveniment, precum si
//momentul final al acestuia si sa se determine durata (exprimata in secunde).
//Obs: se face diferenta intre momentul de inceput si momentul final si se transforma in secunde.

#include <stdio.h>

int main() {
    int ora_inc, min_inc, sec_inc, ora_fin, min_fin, sec_fin, timp_1, timp_2, timp_t;
    int ora_t, min_t, sec_t;

    printf("ora de inceput (nr de la 1 la 12) = ");
    do{
        scanf("%d", &ora_inc);
    } while( ora_inc > 12);

    printf("minut de inceput ( nr de la 0 la 60 ) = ");
    scanf("%d", &min_inc);

    printf("secunde de inceput = ");
    scanf("%d", &sec_inc);

    printf("ora sfarsit = ");
    scanf("%d", &ora_fin);

    printf("minut sfarsit = ");
    scanf("%d", &min_fin);

    printf("secunde sfarsit = ");
    scanf("%d", &sec_fin);


    timp_1 = ora_inc * 3600 + min_inc * 60 + sec_inc;
    timp_2 = ora_fin * 3600 + min_fin * 60 + sec_fin;

    timp_t = timp_2 - timp_1;

    ora_t = timp_t / 3600;

    min_t = (timp_t % 3600) / 60;

    printf("min finale: %d", min_t);






    return 0;
}
