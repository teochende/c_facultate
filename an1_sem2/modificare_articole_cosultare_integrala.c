#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct {
	int nrm;             //enrolment number
	char CNP[14];        //string ASCIIZ
	char nume[30];       //string
	int an;              //study year
	int grupa;           //group
	unsigned char note[20];  //grades
} STUDENT;

int converteste_bin_txt(char* nameb, char* namet) {
    STUDENT x;
    int i;
    FILE* f_bin; //fisierul binar
    FILE *f_txt; //fisierul txt
    //rewind(f_bin);

  f_bin = fopen(nameb, "rb+"); //fisierub binar din care citesc

  f_txt = fopen(namet, "wt+");

    fread(&x, sizeof(STUDENT), 1, f_bin);
    while (!feof(f_bin))
    {   fprintf(f_txt, "%d\n", x.nrm);
        fprintf(f_txt, "%s\n", x.CNP);
        fprintf(f_txt, "%s\n", x.nume);
        fprintf(f_txt, "%d\n", x.an);
        fprintf(f_txt, "%d\n", x.grupa);
        for(i = 0; i < 20; i++) {
            fprintf(f_txt, "%hhi ", x.note[i]);
        }
        fprintf(f_txt, "\n");

        fread(&x, sizeof(STUDENT), 1, f_bin);
    }
    fclose(f_txt);
	fclose(f_bin);

}

int modificare_nota(char* nameb) {
    STUDENT x;
    int i, vb, sgr;
    int nota_noua = 0;
    FILE* f_bin; //fisierul binar

    f_bin = fopen(nameb, "rb+"); //fisierub binar din care citesc
    if (!f_bin) {
		printf("File %s can not be opened. Maybe you misplaced your file.",nameb);
        return 0;
    } else {
        printf("\nNr grupa: ");
        scanf("%d", &sgr); // daca sgr == 0 => ma opresc

        while(sgr != 0) {
            rewind(f_bin);
            vb = 0;
            fread(&x, sizeof(STUDENT), 1, f_bin);

            while(!feof(f_bin)) {
                if(x.grupa == sgr) {
                    vb = 1;
                    //nota la ATP de modificat se afla pe pozotia 5
                    printf("studentul: %s, nota la ATP: %d\n", x.nume, x.note[5]);
                    printf("nota noua la ATP: ");
                    scanf("%d", &nota_noua);

                    if(nota_noua != 0) {
                        x.note[5] = nota_noua;
                        //suprascriu articolul cu cel modificat
                        fseek(f_bin, ftell(f_bin) - sizeof(STUDENT), 0);
                        fwrite(&x, sizeof(STUDENT), 1, f_bin);
                        fseek(f_bin, 0, 1);
                    }
                }
                fread(&x, sizeof(STUDENT), 1, f_bin);
            }

            if (!vb)
                printf("\nNU exista studenti in grupa %d",sgr);

            printf("\n\nTry again? Search group nr. (0 to stop): ");
            scanf("%d", &sgr);
        }
        fclose(f_bin);
        return 1;
    }

}

int main() {
    char nameb[30] = "Studenti_s_f2.dat";
	char namet[40] = "./fisier_txt_pt_popular_func.txt";

	FILE* f_txt;

	const int MAX_LINE = 256;
	char buffer[MAX_LINE];

	STUDENT x;

    //modificare_nota(f);

    if(modificare_nota(nameb) != 0) {
        converteste_bin_txt(nameb, namet);
    }
	
	/*********************************************
	 * afisare fisier text
	 **********************************************/
	f_txt = fopen(namet, "rt");
	while(fgets(buffer, MAX_LINE, f_txt)) {
		printf(buffer);
	}

	printf("\n\nDone, press a key to finish...");
	_getch();

    return 0;
}

