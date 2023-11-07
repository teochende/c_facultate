#include <stdio.h>
//sa se det daca un vector reprezita o progresie aritmetica

int main() {
    float v[100];
    int n, i, ok;

    printf("n: ");
    scanf("%d", &n);

    printf("\nvectorul : \n");

    for(i = 0; i < n; i++) {
        printf("valoare: ");
        scanf("%f", &v[i]);
    }

    ok = 1;
    for(i = 0; i < n-2; i++ && ok == 1) {
        if(v[i+1] != (v[i] + v[i+2]) / 2) {
            ok = 0;
        }
    }

    if(ok == 1) printf("vectorul este progresie aritmetica");
    else printf("NU este progresie aritmetica");
    return 0;
}
