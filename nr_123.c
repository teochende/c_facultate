//Sa se verifice daca trei numere naturale citite de la tastatura coincid
//cu valorile 1,2,3. (Obs: cele 3 numere coincid cu 1,2,3 daca suma si
//produsul lor sunt egale cu 6).

#include <stdio.h>

int main() {
    int a, b, c;

    printf("a = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    printf("c = ");
    scanf("%d", &c);

    if(a + b + c == 6 && a*b*c == 6){
        printf("numerele coincid cu 1, 2, 3");
    } else printf("numerele nu coincid cu 1, 2, 3");

    return 0;
}
