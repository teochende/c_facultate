#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    float ma, mg, mh;

    printf("a = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    printf("a este: %d\n", a);
    printf("b este: %d\n", b);




    ma = ((float)a + b) / 2;
    printf("media aritmetica este: %-20.3f-x\n", ma);

    if( a * b > 0){
        mg = sqrt(a*b);
        printf("media geometrica este: %f\n", mg);
    } else {
        printf("media geomerica nu se poate calcula\n");
    }


    return 0;
}
