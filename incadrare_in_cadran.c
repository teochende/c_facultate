//Cititi coordonatele (x,y) ale unui numar si determinati
//in ce cadran se afla (I, II, III sau IV).

#include <stdio.h>

int main(){
    int x, y;

    printf("x = ");
    scanf("%d", &x);

    printf("y = ");
    scanf("%d", &y);

    if( x > 0){
        if(y > 0)
            printf("punctul este in primul cadran");
        else printf("numarul este in cadranul 2");
    } else{
        if(y > 0)
            printf("punctul este in cadranul 4");
        else printf("numarul este in cadranul 3");
    }


    return 0;
}
