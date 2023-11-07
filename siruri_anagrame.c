#include <stdio.h>

//siruri anagrame = siruri care pe aceleasi elemente pe aceeasi pozitie sau pe pozitii diferite
//pentru a arata ca doua siruri sunt anagrame:
//   - ordonez ambele siruri
//   - compar elementele

int main() {
    float v[100], x[100], aux;
    int n, m, i, j, ok;

    printf("n: ");
    scanf("%d", &n);

    printf("m: ");
    scanf("%d", &m);

    printf("vectorul 1: \n");

    for(i = 0; i < n; i++) {
        printf("valoare: ");
        scanf("%f", &v[i]);
    }

    printf("vectorul 2: \n");

    for(i = 0; i < m; i++) {
        printf("valoare: ");
        scanf("%f", &x[i]);
    }

    ok = 1;
    if(n != m){
        ok = 0;
    } else {
        for(i = 0; i < n-1; i++){
            for(j = i+1; j < n; j++){
                if(v[i] > v[j]){
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }

                if(x[i] > x[j]) {
                    aux = x[i];
                    x[i] = x[j];
                    x[j] = aux;
                }
            }
        }

        printf("vectorul v sortat este:\n");
        for(i = 0; i < n; i++){
            printf("%lf\n", v[i]);
        }

        printf("\n\nvectorul x sortat este:\n");
        for(i = 0; i < n; i++){
            printf("%lf\n", x[i]);
        }

        for(i = 0; i < n; i++ && ok == 1){
            if(v[i] != x[i]) {
                ok = 0;
            }
        }
    }

    if(ok == 1) {
        printf("sirurile sunt anagrame");
    } else{
        printf("sirurile NU sunt anagrame");
    }


    return 0;
}
