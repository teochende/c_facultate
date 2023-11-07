#include <stdio.h>
//sa se isereze intre fiecare 2 val consecutive media lor aritmetica

int main() {
    float v[100] = {1, 3, 5, 7, 9}, medie;
    int n = 5, i, j, k, nou_n;

    /*
    printf("n: ");
    scanf("%d", &n);

    printf("\nvectorul : \n");
    for(i = 0; i < n; i++) {
        printf("valoare: ");
        scanf("%f", &v[i]);
    }
    */

    printf("\nvectorul initial este:\n");
    for(i = 0; i < n; i++) {
        printf("%.3f\n", v[i]);
    }

    printf("\nCalcul medii termeni consecutivi\n");

    //nou_n = n + n - 1;
    i = 1;

    while(i < n) {
        medie = (v[i] + v[i-1])/2;
        //translatare
        for(j = n; j > i; j--) {
            v[j] = v[j-1];
        }
        v[i] = medie; //bucla for iese cand j = i
        i = i + 2;
        n++;
    }

    printf("\nVectorul final este:\n");
    for(i = 0; i < n; i++) {
        printf("%.3f\n", v[i]);
    }

    /*
    printf("\n Algoritm translatare valori sir:\n");
    k = 1;
    while(n < 5) {
        //printf("n = %d, k = %d\n", n, k);
        for(j = n; j > k; j--) {
            //printf("j = %d\n", j);
            v[j] = v[j-1];
        }
        v[j] = 100;
        n++;
        k++;
    }

    printf("\nNoul n: %d; Vectorul dupa translatare este:\n", n);
    for(i = 0; i < n; i++) {
        printf("%.3f\n", v[i]);
    }
    */
    
    return 0;
}
