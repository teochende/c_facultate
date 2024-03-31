#define _CRTECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

typedef struct {
	int nrm;             //enrolment number - works as relative key
	char CNP[14];        //string ASCIIZ
	char nume[30];       //string
	int an;              //study year
	int grupa;           //group
	unsigned char note[20];  //grades
	char is;
} STUDENT;

int filesize(FILE* f, int rec_size)
{
	long crt_pos;
	int size;

	crt_pos = ftell(f);
	fseek(f, 0, SEEK_END);
	size = ftell(f) / rec_size;
	fseek(f, crt_pos, SEEK_SET);
	return size;
}

void afisare_in_txt_f_bin(char* nume_f_b) {
	FILE* f_bin;
	STUDENT s;
	f_bin = fopen(nume_f_b, "rb");

	while(!feof(f_bin)) {
		fread(&s, sizeof(STUDENT), 1, f_bin);
		printf("key: %5d, nume: %-15s, CNP: %15s, grupa: %d, x.is: %hhi \n", s.nrm, s.nume, s.CNP, s.grupa, s.is);
	}


	fclose(f_bin);
}

int main()
{
	char numefr[30] = "Studenti_r.dat";
	FILE* f;
	STUDENT x;
	int i, key, dim;

	f=fopen(numefr, "wb+");
	//optionally preform the file

	freopen("Input.txt", "rt", stdin);  //remove if reading data from keyboard and uncomment the printf lines

	//printf("Enrollment number: ");
	scanf("%d", &key);
	while (!feof(stdin))
	{
		//check key range
		dim = filesize(f, sizeof(STUDENT));

		//verifica daca exista deja articolul in fisierul binar
		//presupunem ca elemntul nu exista
		x.is = 0;
		//caut pozitia de la cheia respectiva si verific daca am un articol deja
		fseek(f, key * sizeof(STUDENT), SEEK_SET);
		fread(&x, sizeof(STUDENT), 1, f);
		//dupa fread, x este populat cu ce este in f. bin deci avem o valoare pentru x.is
		if (x.is == 1)
			printf("\nError: duplicate key %d. Skipping.", key);
		else
		{
			x.nrm = key;
			//citesc din fisierul text o inregistrare element cu element
			//printf("Name: ");
			gets(x.nume);
			gets(x.nume);
			//printf("CNP: ");
			gets(x.CNP);
			//printf("Year: ");
			scanf("%d", &x.an);
			//printf("Group: ");
			scanf("%d", &x.grupa);
			for (i = 0; i < 20; i++) {
				scanf("%hhi", &x.note[i]);
			}

			if (key >= dim)
			{ //extend the file
				x.is = 1;
				fseek(f, 0, SEEK_END);
				//for (i = 0; i < key - dim; i++)
				fwrite(&x, sizeof(STUDENT), 1, f);
			}
		}

		//printf("\nEnrollment number (or CTRL+Z): ");
		scanf("%d", &key);
	}

	afisare_in_txt_f_bin(numefr);

	fclose(f);
	fclose(stdin);

	printf("\nDone. File <%s> was created. Press a key.", numefr);
	_getch();
	return 0;
}
