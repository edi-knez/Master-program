#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>

//////////////////////////////////////////////////////////////////////////// vježba 7
int vj7_globalnaVarijabla = 10;
void vj7_ispisVrijednostiVarijabla(int y);
int vj7_faktorijele(int n);
double vj7_exp(int n, int preciznost);

//////////////////////////////////////////////////////////////////////////// vježba 8
bool vj8_postoji_li_element(int a[], int pozicija, int trazeniElement);
void vj8_unosElemenataMatrice(int a[][3], int velicina);
int vj8_produktElemenataMatrice(int a[][3], int velicina);
int vj8_my_strlen(const char* tekst);
void vj8_my_strcpy(char* tekst_destination, const char* tekst_source);
int vj8_rekurzija_faktorijele(int n);
int vj8_rekurzija_minMax_elementNiza(int niz[], int velicina, bool max = 0);	// 0 - min, 1 - max
char* vj8_deka_u_bin_okt_heksa(unsigned int dekadski, unsigned int baza);

/////////////////////////////////////////////////////////////////////////// vježba 9
struct Vrijeme {
	int sati, minute, sekunde;
};
struct Vrijeme v9_zbrajanjeVremena(struct Vrijeme* v1, struct Vrijeme* v2);
void v9_ispisVremena(struct Vrijeme* v);

struct Datum {
	int godina, mjesec, dan;
};
int v9_proracunDatuma(struct Datum* c, int dan);
void v9_ispisDatuma(struct Datum* d);

struct Osoba {
	char ime[20], prezime[20];
	Vrijeme satRodenja;
	Datum d;
};
void v9_prvaOsobaPoAbecedi_ime_pa_prezime(struct Osoba osobe[], int kolicina);
void v9_najstarijaOsoba(struct Osoba osobe[], int kolicina);

/////////////////////////////////////////////////////////////////////////////////////// Vježba 10
void vj10_3_u_1(int* suma, int* produkt, int* razlika, int br1, int br2);
int vj10_brPonavljanja_podstringa_u_stringu(const char* tekst, const int velicina, char* podstring);

////////////////////////////////////////////////////////////////////////////////// Vježba 11
void vj11_kopiranjeDatoteke(FILE* fp, FILE* fp_copy, char* naziv1, char* naziv2);
void vj11_citanjeDatoteke(FILE* fp);
void vj11_brojacImenaAna(FILE* fp, int* brojac);
void vj11_citanjeDatoteke2(FILE* fp);
void vj11_ispisRijec_po_Rijec(char* tekst);


/*
 
int main() {

/*---------------------------------------------------------		Vježba 7:	----------------------------------------------------------- */
/*
	1. Napisati program koji unese 3 broja i zatim po želji korisnika (ovisno o tome koje se slovo unese) računa:
	a) rez = x + y + z
	b) rez = x * y * z
	c) rez = x / y + z
	d) rez = (x / y - z)na1/2
	Svi rezultati se računaju preko f-ija (jedna za svaki primjer), s tim da je za primjer
	pod “d” potrebno provjeriti je li izraz ispod korijena > o, i ako nije treba javiti grešku.
*/

	//char odabir = { 0 };
	//int rez, x, y, z;
	//printf("x = ");
	//scanf("%d", &x);
	//printf("y = ");
	//scanf("%d", &y);
	//printf("z = ");
	//scanf("%d", &z);
	//printf("Unesi slovo za zeljenu operciju:\na) rez = x + y + z\nb) rez = x * y * z\nc) rez = x / y + z\nd) rez = (x / y - z)na1 / 2\n");
	//scanf(" %c", &odabir);
	//switch (odabir)
	//{
	//case 'a':
	//case 'A':
	//	rez = x + y + z;
	//	printf("rez = %d", rez);
	//	break;
	//case 'b':
	//case 'B':
	//	rez = x * y * z;
	//	printf("rez = %d", rez);
	//	break;
	//case 'c':
	//case 'C':
	//	rez = x / y + z;
	//	printf("rez = %d", rez);
	//	break;
	//case 'd':
	//case 'D':
	//{
	//	int temp = sqrt(x / y - z);
	//	if (temp < 0) {
	//		printf("Greska! izraz je < 0\n");
	//	}
	//	else {
	//		rez = temp;
	//		printf("rez = %d", rez);
	//	}
	//	break;
	//}
	//default:
	//	printf("Greska! krivi unos\n");
	//	break;
	//}

	/*
	2. Napisati program koji sadrži dvije varijable: globalnu varijablu X i lokalnu varijablu Y(lokalna za f-ju main)
	i dodijeliti im neke vrijednosti. Iz glavnog programa treba pozvati f-ju koja ispisuje vrijednosti obije varijable.
	*/

	//int Y = 5;
	//vj7_ispisVrijednostiVarijabla(Y);

	/*
	3. Napraviti program koji u “običnoj” f-ji računa faktorijele. Rezultat je potrebno ispisati u glavnom programu
	i nije dozvoljeno korištenje globalnih varijabli.
	*/

	//int rezultat = vj7_faktorijele(3);
	//printf("Rezultat 3! = %d\n", rezultat);

	/*
	4. Napisati f-ju kojom se približno određuje vrijednost ex (e = 2.718282), i rezultat usporediti
	s vrijednošću koja se dobije pomoću standardne funkcije exp() deklarirane u math.h.
	Npr. za x = 5, ispisati izračunate rezultate za 5, 10 i 50 ponavljanja. Zašto se program ponaša "čudno" za 50 ponavljanja?
	*/

//	printf("(moj) exp(5): %e\nexp(5): %e\n", vj7_exp(5, 5), exp(5));
//	printf("(moj) exp(10): %e\nexp(10): %e\n", vj7_exp(5, 10), exp(5));
//	printf("(moj) exp(50): %e\nexp(50): %e\n", vj7_exp(5, 50), exp(5));


	/*-----------------------------------------------------------	Vježba 8:	----------------------------------------------------*/
	/*
	1. Napisati program koji traži je li neki broj element niza. U programu treba napraviti f-ju traži
	koja uzima tri argumenta (niz, broj elemenata niza i vrijednost koja se traži),
	a treba vratiti 1 ako broj postoji ili 0 ako broj ne postoji.
	*/

	//const int brElemenata = 6;
	//int testBroj1 = 4, testBroj2 = 5;
	//int A[brElemenata] = { 3, 5, 7, 8, 9, 10 };
	//printf("testBroj1 se ");
	//(vj8_postoji_li_element(A, brElemenata, testBroj1)) ? printf("nalazi u nizu\n") : printf("ne nalazi u nizu\n");
	//printf("testBroj2 se ");
	//(vj8_postoji_li_element(A, brElemenata, testBroj2)) ? printf("nalazi u nizu\n") : printf("ne nalazi u nizu\n");

	/*
	2. Napisati program koji računa produkt svih elemenata matrice dimenzija 3x3. Program ne smije 
	sadržavati ni jednu globalnu varijablu, unos i proračun napraviti u odvojenim funkcijama.
	*/

	//const int vel = 3;
	//int matricaA[vel][vel];
	//vj8_unosElemenataMatrice(matricaA, vel);
	//printf("produkt = %d", vj8_produktElemenataMatrice(matricaA, vel));

	/*
	3. Napisati program koji sadrži f-je my_strlen i my_strcpy, koje rade isto što i f-je strlen i strcpy.
	Ispravnost funkcija provjeriti usporedbom sa stvarnim f-jama strlen i strcpy.
	*/

	//const char* a = { "ovojekratkitest" };
	//printf("my_strlen: %d\nstrlen: %d\n", vj8_my_strlen(a), strlen(a));

	//const char* c = { "tesktZaKopirat" };
	//char d[15];
	//char e[15];
	//vj8_my_strcpy(d, c);
	//strcpy(e, c);
	//printf("c: %s\nd: %s\ne: %s", c, d, e);

	/*
	4. Napisati program koji pomoću rekurzivne f-je računa faktorijele. 
	*/
	
	//int n;
	//printf("Unesi broj: ");
	//scanf("%d", &n);
	//printf("%d! = %d\n", n, vj8_rekurzija_faktorijele(n));

	/*
	5. Napisati program koji korištenjem rekurzivnih funkcija traži minimalni, odnosno maksimalni element niza brojeva.
	*/

	//int niz[5] = { 3, 5, 1, 7, 2 };
	//printf("najmanji element niza je: %d\n", vj8_rekurzija_minMax_elementNiza(niz, 4));
	//printf("najmanji element niza je: %d\n", vj8_rekurzija_minMax_elementNiza(niz, 4, 0));	// 0 - min, 1 - max
	//printf("najveci element niza je: %d\n",vj8_rekurzija_minMax_elementNiza(niz, 4, 1));

	/*
	6. Napraviti program koji uneseni dekadski broj pretvara u binarni, oktalni ili heksadecinalni.
	Dekadski broj, kao i brojevna baza (2, 8, 16) u koju se radi pretvorba se unose u programu, a pretvorbu je potrebno realizirati pomoću
	rekurzivne f-je. Rezultat se ispisuje u mainu.
	*/
	
	//unsigned int deka;
	//printf("Unesi dekadski broj: ");
	//scanf("%d", &deka);
	//unsigned int baza;
	//printf("Odaberi sustav u koji zelis pretvorit:\n2 -> binarni\n8 -> oktalni\n16 -> heksadecimalni\n\n");
	//scanf("%d", &baza);
	//
	//printf("%d(10) = %s(%d)\n", deka, vj8_deka_u_bin_okt_heksa(deka, baza), baza);
	

	/*-----------------------------------------------------------	Vježba 9:	--------------------------------------------------------- */
	/*
	1. Napisati program koji unosi dva proizvoljna vremena (sat, minute, sekunde) i zbraja ih. Za pohranu
	vremena koristiti strukturu, a zbrajanje i ispis napraviti u odvojenim funkcijama.
	*/
	
	//Vrijeme v1 = { 2, 35, 45 };
	//Vrijeme v2 { 3, 50, 30 };

	//Vrijeme v3 = v9_zbrajanjeVremena(&v1, &v2);
	//v9_ispisVremena(&v3);

	/*
	2. Napisati program koji za uneseni datum računa koji je datum bio dan prije i koji će datum biti dan poslije.
	Za pohranu datuma koristiti strukturu datum (dan, mjesec, godina). Proračun i ispis dana prije/poslije
	napraviti u funkciji dan_prije / dan_poslije
	*/

	//struct Datum d1 { 2000, 6, 5 };
	//struct Datum d2 { 2003, 3, 31 };
	//struct Datum d3 { 2000, 4, 30 };
	//struct Datum d4 { 2004, 2, 1 };

	//v9_ispisDatuma(&d1);
	//v9_ispisDatuma(&d2);
	//v9_ispisDatuma(&d3);
	//v9_ispisDatuma(&d4);

	/*
	3. Napisati program koji unosi podatke o 5 osoba (ime, prezime, datum i sat rođenja). U programu napraviti 
	funkciju koja pronalazi najstariju osobu, te funkciju koja pronalazi osobu prvu po abecedi.
	*/

	//const int kolicina = 5;
	//struct Osoba osobe[kolicina];
	//osobe[0] = { "Marko", "Marulic", { 15, 5, 0 }, { 2003, 5, 12  } };
	//osobe[1] = { "Ana", "Marelica", {20, 51, 50 }, { 2001, 5, 17 } };
	//osobe[2] = { "Pero", "Grgulj", { 10, 0, 7 }, { 2000, 8, 1 } };
	//osobe[3] = { "Marta", "Marulic", { 15, 5, 0 }, { 2003, 5, 12 } };
	//osobe[4] = { "Marko", "Marulic", { 15, 5, 0 }, { 2003, 5, 12 } };

	//struct Osoba prva = osobe[0];
	//v9_prvaOsobaPoAbecedi_ime_pa_prezime(osobe, kolicina);


	//v9_najstarijaOsoba(osobe, kolicina);


/*----------------------------------------------------------	Vježba 10	-----------------------------------------------------*/
	/*
	1. Napisati program koji prvo unosi, a zatim ispisuje elemente nekog polja brojeva i polja znakova zajedno s
	adresom svakog elementa. Sve unose i ispise je potrebno napraviti preko pokazivača i ne smiju se koristiti [].
	*/

	//int kolicina = 10;
	//int niz[10];
	//for (int i = 0; i < kolicina; i++) {
	//	scanf("%d", niz+i);
	//}

	//for (int i = 0; i < kolicina; i++) {
	//	printf("niz[%d] = %d	na lokaciji %p\n", i, *(niz + i), niz + i);
	//}

	/*
	2. Napisati program koji u jednoj funkciji računa sumu, produkt i razliku dva broja, a svi se rezultati ispisuju u glavnom programu.
	*/
	
	//int suma, produkt, razlika;
	//_3_u_1(&suma, &produkt, &razlika, 25, 5);
	//printf("broj1: %d\nbroj2: %d\nsuma: %d\nrazlika: %d\nprodukt: %d", 25, 5, suma, razlika, produkt);

	/*
	3. Zadatak s računanjem dana prije i poslije riješiti preko funkcija na način da se sva tri datuma
	deklariraju u mainu, a unos, i proračun dana prije i poslije u f-ji. Rezultate je potrebno ispisati u mainu, a ne u funkciji.
	*/

	//struct Datum d1 { 2000, 6, 5 };
	//struct Datum d2 { 2003, 3, 31 };
	//struct Datum d3 { 2005, 4, 30 };
	//struct Datum d4 { 2004, 2, 1 };

	//printf("dan prije unesenog dana je: %d\n", v9_proracunDatuma(&d1, -1));
	//printf("dan poslije unesenog dana je: %d\n\n", v9_proracunDatuma(&d1, 1));
	//printf("dan prije unesenog dana je: %d\n", v9_proracunDatuma(&d2, -1));
	//printf("dan poslije unesenog dana je: %d\n\n", v9_proracunDatuma(&d2, 1));
	//printf("dan prije unesenog dana je: %d\n", v9_proracunDatuma(&d3, -1));
	//printf("dan poslije unesenog dana je: %d\n\n", v9_proracunDatuma(&d3, 1));
	//printf("dan prije unesenog dana je: %d\n", v9_proracunDatuma(&d4, -1));
	//printf("dan poslije unesenog dana je: %d\n\n", v9_proracunDatuma(&d4, 1));

	/*
	4. Napisati program koji za zadani string traži koliko se puta podstring pojavljuje u stringu.
	Podstring je potrebno unijeti u f-ji. F-ja za pretraživanje treba vratiti broj
	ponavljanja. U funkciji za pretraživanje se može koristiti f-ja strncmp iz string.h.
	*/
	
	//const int velicina = 128;
	//char tekst[velicina] = {"Kratka prica je oblik kratke narativne proze. Kratke price su sazetije u usporedbi s duzim djelima fikcije, kao sto su novele\0"};
	//char podstring[velicina-1];
	//printf("broj ponavljanja podstringa: %d", vj10_brPonavljanja_podstringa_u_stringu(tekst, velicina, podstring));


/*--------------------------------------------------------------	Vježba 11:		---------------------------------------------
	/*
	1. Napisati program koji kopira jednu datoteku u drugu. Nazivi obije datoteke se unose u glavnom programu, a kopiranje se radi u funkciji.
	*/

	//FILE* fp;
	//FILE* fp_copy{};
	//char naziv1[20], naziv2[20];
	//printf("Upisi puni naziv datoteke .txt: ");
	//scanf("%s", naziv1);
	//printf("Upisi puni naziv za kopiju datoteke .txt: ");
	//scanf("%s", naziv2);

	//fp = fopen(naziv1, "w"); 
	//if (fp == NULL)
	//	printf("Greska pri otvaranju datoteke");
	//else 
	//{
	//	fprintf(fp, "Hello World!\n");
	//	fprintf(fp, "Hello World drugi put!");
	//}
	//fclose(fp);
	//vj11_kopiranjeDatoteke(fp, fp_copy, naziv1, naziv2);
	
	/*2. Napisati program koji iz datoteke znak, po znak čita znamenke sve dok ne pročita nešto što nije broj ili
	se dostigne kraj datoteke. Te znamenke je potrebno pretvoriti u broj koji je bio zapisan u datoteci i ispisati ga na ekran.
	*/

	//FILE* fp;
	//FILE* fp_copy;
	//fp = fopen("vj11_zad2.txt", "w");

	//if (fp == NULL)
	//	printf("GRESKA\n");
	//else {
	//	fprintf(fp, "00465gh7686a");
	//	fclose(fp);
	//	fp = fopen("vj11_zad2.txt", "r");
	//	fp_copy = fopen("vj11_zad2.txt", "r");

	//	char broj;
	//	int rezultat = 0;
	//	while (!(feof(fp))) {
	//		broj = getc(fp);
	//		if (!rezultat && broj == '0') {
	//			getc(fp_copy);
	//			continue;
	//		}
	//		if (broj < 48 || broj > 57)
	//			break;
	//		rezultat += putc(broj, fp_copy) - '0';
	//		rezultat *= 10;
	//	}
	//	
	//	printf("%d", rezultat / 10);

	//	fclose(fp);
	//	fclose(fp_copy);
	//}

	/*
	3. Napisati program koji iz datoteke čita maks. 100 podataka o osobama (ime, prezime i godinu rođenja) i
	traži koliko se osoba zove Ana. Čitanje datoteke i brojenje je potrebno napraviti u odvojenim f-jama.
	*/

	//FILE* fp;
	//fp = fopen("vj11_zad3.txt", "w");
	//if (fp == NULL)
	//	printf("GRESKA\n");
	//else {
	//	fprintf(fp, "Ana\nA\n2000\n");
	//	fprintf(fp, "Ana\nB\n2000\n");
	//	fprintf(fp, "Mirko\nA\n2000\n");
	//	fprintf(fp, "Ana\nC\n2000\n");
	//	fprintf(fp, "Boro\nA\n2000\n");
	//	fprintf(fp, "Grga\nA\n2000\n");
	//	fprintf(fp, "Ana\nD\n2000\n");
	//	fprintf(fp, "Pero\nA\n2000\n");
	//	fprintf(fp, "Ana\nE\n2000\n");
	//	fclose(fp);
	//	fp = fopen("vj11_zad3.txt", "r");
	//	vj11_citanjeDatoteke(fp);
	//	fclose(fp);
	//}

	/*
	4. Napisati program koji iz datoteke pročita 1 cijeli redak i onda ga riječ po riječ ispisuje na ekran, a svaka je riječ u svom retku.
	- Datoteke potrebne za ove zadatke je potrebno napraviti u nekom tekstualnom editoru (npr. Notepad, …).
	*/
	
	//FILE* fp = fopen("vj11_zad4.txt", "w");
	//if (fp == NULL) {
	//	printf("GREAKA\n");
	//}
	//else {
	//	fprintf(fp, "Datoteke potrebne za ove zadatke je potrebno napraviti u nekom tekstualnom editoru (npr. Notepad, ...).");
	//	fclose(fp);
	//	fp = fopen("vj11_zad4.txt", "r");
	//	vj11_citanjeDatoteke2(fp);
	//	fclose(fp);
	//	fp = NULL;
	//}


/*-------------------------------------------------------	Vježba 12:	-------------------------------------------------------- 
	/*
	1. Napisati program koji unosi bodove kolokvija svih studenata i računa prosječni broj bodova, nakon što
	su ocjene unesene, uz uvjet da unaprijed nije poznato koliko je bilo studenata.
	*/

	//int brStudenata = 0;
	//int sumaBodova = 0;
	//int bodovi;
	//while (1) {
	//	printf("Unesi bodove: ");
	//	scanf("%d", &bodovi);
	//	if (bodovi < 0 || bodovi > 100)
	//		break;
	//	sumaBodova += bodovi;
	//	brStudenata++;
	//}
	//printf("Prosjecni broj bodova %f\n", float(sumaBodova / brStudenata));

	/*
	2. Napisati program koji neki dekadski broj pretvara u string koji se sastoji od znamenki tog broja. String
	se dinamički alocira ovisno o tome koliko znamenki ima broj.
	*/

	//int broj;
	//printf("Unesi broj: ");
	//scanf("%d", &broj);
	//int tempBr = broj;
	//int velicina = 1;
	//while (tempBr> 0) {
	//	velicina++;
	//	tempBr /= 10;
	//}
	//char* str = (char*)malloc(velicina * sizeof(char));
	//for (int i = 0; i < velicina; i++) {
	//	if (i == velicina - 1) {
	//		*(str + i) = '\0';
	//		break;
	//	}
	//	*(str + velicina - i - 2) = broj % 10 + '0';
	//	broj /= 10;
	//}

	//printf("string: %s\n", str);
	//free(str);

	/*
	3. Napisati program koji čita imena N (unosi se u programu) studenata iz datoteke, a zatim za svakog studenta
	pita koliko je bodova dobio iz svakog od kolokvija (ukupno 3) i zatim računa ukupni broj bodova i ocjenu, prema tablici:
	*/

	//FILE* fp;
	//fp = fopen("vj12_zad3_imena.txt", "w");
	//if (fp == NULL)
	//	printf("Greska pri otvaranju datoteke");
	//else 
	//{
	//	fprintf(fp, "Iva\n");
	//	fprintf(fp, "Marko\n");
	//	fprintf(fp, "Luka\n");
	//	fprintf(fp, "Grga\n");
	//	fclose(fp);
	//}
	//char imeStudenta[15];
	//int bodovi;
	//int ukupno = 0;
	//fp = fopen("vj12_zad3_imena.txt", "r");
	//while (1) {
	//	if (fgets(imeStudenta, 15, fp) == NULL) {
	//		break;
	//	}
	//	printf("%s", imeStudenta);
	//	ukupno = 0;
	//	for (int i = 0; i < 3; i++) {
	//		printf("unesi bodove %d. kolokvija: ", i + 1);
	//		scanf("%d", &bodovi);
	//		ukupno += bodovi;
	//		if (i == 2) {
	//			ukupno /= 3;
	//			if (ukupno > 87 && ukupno < 101) {
	//				printf("\nOcjena: 5, %d posto\n\n", ukupno);
	//			}
	//			else if (ukupno > 74) {
	//				printf("\nOcjena: 4, %d posto\n\n", ukupno);
	//			}
	//			else if (ukupno > 59) {
	//				printf("\nOcjena: 3, %d posto\n\n", ukupno);
	//			}
	//			else if (ukupno > 48) {
	//				printf("\nOcjena: 2, %d posto\n\n", ukupno);
	//			}
	//			else if (ukupno > -1) {
	//				printf("\nOcjena: 1, %d posto\n\n", ukupno);
	//			}
	//			else {
	//				printf("\nGRESKA!\n\n");
	//			}
	//		}
	//	}
	//}
	//fclose(fp);
	
	/*
	4. Napisati program koji pomoću nizova simulira rad reda (podaci se skidaju s početka, a stižu na kraj).
	Red mora biti cirkularan, a dimenzija se unosi u programu. U zadatku koristiti pokazivače na prvi i zadnji element u redu.
	*/

	//int n;
	//printf("Unesi velicinu nizova: ");
	//scanf("%d", &n);
	//int* niz1 = (int*)malloc(n * sizeof(int));
	//int* niz2 = (int*)malloc(n * sizeof(int));

	//for (int i = 0; i < n; i++) {
	//	*(niz1 + i) = i;
	//	*(niz2 + i) = (i+1) * 10;
	//}

	//int* rep1 = niz1 + n - 1;
	//int* rep2 = niz2 + n - 1;

	//while (_getch() != 27) {
	//	Sleep(50);
	//	for (int i = 0; i < n; i++) {
	//		printf("%d ", *(niz1 + i));
	//	}
	//	for (int i = 0; i < n; i++) {
	//		printf("%d ", *(niz2 + i));
	//	}
	//	printf("\n");

	//	int glava1 = *niz1;
	//	int glava2 = *niz2;
	//	for (int i = 0; i < n - 1; i++) {
	//		*(niz1 + i) = *(niz1 + i + 1);
	//	}
	//	*rep1 = glava2;

	//	for (int i = 0; i < n - 1; i++) {
	//		*(niz2 + i) = *(niz2 + i + 1);
	//	}
	//	*rep2 = glava1;
	//	
	//}
	//free(niz1);
	//free(niz2);
//}




/*------------------------------------------------------	FUNKCIJE	--------------------------------------------------------------*/

////////////////////////////////////////////////////////////////////////////////// vježba 7
void vj7_ispisVrijednostiVarijabla(int y) {
	printf("Lokalna varijabla: %d\n", y);
	printf("Globalna varijabla: %d\n", vj7_globalnaVarijabla);
}

int vj7_faktorijele(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

double vj7_exp(int n, int preciznost) {
	double rezultat = 1;
	float temp = 1;
	for (int i = 1; i <= preciznost; i++) {
		temp = (temp * n) / i;
		rezultat += temp;
	}
	return rezultat;
}


//////////////////////////////////////////////////////////////////////////////////////////// vježba 8
bool vj8_postoji_li_element(int a[], int brojElemenata, int trazeniElement) {
	for (int i = 0; i < brojElemenata; i++) {
		if (a[i] == trazeniElement)
			return 1;
	}
	return 0;
}

void vj8_unosElemenataMatrice(int a[][3], int velicina) {
	int temp;
	for (int i = 0; i < velicina; i++) {
		for (int j = 0; j < velicina; j++) {
			printf("A[%d][%d]: ", i, j);
			scanf("%d", &temp);
			a[i][j] = temp;
		}
	}
}

int vj8_produktElemenataMatrice(int a[][3], int velicina) {
	int produkt = 1;
	for (int i = 0; i < velicina; i++) {
		for (int j = 0; j < velicina; j++) {
			produkt *= a[i][j];
		}
	}
	return produkt;
}

int vj8_my_strlen(const char* tekst) {
	int duljina = 0;
	int i = 0;
	while (1) {
		if (tekst[i] != '\0') {
			duljina++;
		}
		else {
			return duljina;
		}
		i++;
	}
}

void vj8_my_strcpy(char* tekst_destination, const char* tekst_source ) {
	int duljina = vj8_my_strlen(tekst_source) + 1;
	for (int i = 0; i < duljina; i++) {
		tekst_destination[i] = tekst_source[i];
	}
	tekst_destination[duljina - 1] = '\0';
}

int vj8_rekurzija_faktorijele(int n) {
	if (n != 1) {
		return vj8_rekurzija_faktorijele(n - 1) * n;
	}
	else {
		return 1;
	}
}

int vj8_rekurzija_minMax_elementNiza(int niz[], int velicina, bool max) {
	static int result = niz[0];
	if (velicina > 0) {
		if (!max) {
			if (result > niz[velicina]) {
				result = niz[velicina];
			}
		}
		else {
			if (result < niz[velicina]) {
				result = niz[velicina];
			}
		}
		vj8_rekurzija_minMax_elementNiza(niz, velicina - 1, max);
	}
	else {
		return result;
	}
}

char* vj8_deka_u_bin_okt_heksa(unsigned int dekadski, unsigned int baza) {
	static char rezultat[33] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };
	static int i = 0;
	if (dekadski > 0) {
		if (baza == 2) {
			i++;
			vj8_deka_u_bin_okt_heksa(dekadski / baza, baza);
			rezultat[33-i-1] = dekadski % baza + 48;
			i--;
		}
		else if (baza == 8) {
			i++;
			vj8_deka_u_bin_okt_heksa(dekadski / baza, baza);
			rezultat[33-i-1] = dekadski % baza + 48;
			i--;
		}
		else if (baza == 16) {
			switch (dekadski % baza)
			{
			case 15:
				i++;
				vj8_deka_u_bin_okt_heksa(dekadski / baza, baza);
				rezultat[33 - i - 1] = 'F';
				i--;
				break;
			case 14:
				i++;
				vj8_deka_u_bin_okt_heksa(dekadski / baza, baza);
				rezultat[33 - i - 1] = 'E';
				i--;
				break;
			case 13:
				i++;
				vj8_deka_u_bin_okt_heksa(dekadski / baza, baza);
				rezultat[33 - i - 1] = 'D';
				i--;
				break;
			case 12:
				i++;
				vj8_deka_u_bin_okt_heksa(dekadski / baza, baza);
				rezultat[33 - i - 1] = 'C';
				i--;
				break;
			case 11:
				i++;
				vj8_deka_u_bin_okt_heksa(dekadski / baza, baza);
				rezultat[33 - i - 1] = 'B';
				i--;
				break;
			case 10:
				i++;
				vj8_deka_u_bin_okt_heksa(dekadski / baza, baza);
				rezultat[33 - i - 1] = 'A';
				i--;
				break;
			default:
				i++;
				vj8_deka_u_bin_okt_heksa(dekadski / baza, baza);
				rezultat[33 - i - 1] = dekadski % baza + 48;
				i--;
				break;
			}
		}
		else {
			printf("Nepodrzana baza!\n");
			return { 0 };
		}
		return rezultat;
	}
	else {
		return rezultat;
	}
}


////////////////////////////////////////////////////////////////////////////////////// vježba 9
struct Vrijeme v9_zbrajanjeVremena(struct Vrijeme* v1, struct Vrijeme* v2) {
	int tempMin = (*v1).sekunde + (*v2).sekunde;
	int tempMin_copy = tempMin;
	int temp = 0;
	while (tempMin_copy > 60) {
		temp++;
		tempMin_copy /= 60;
	}
	int tempSati = (*v1).minute + (*v2).minute + temp;
	int tempSati_copy = tempSati;
	int temp2 = 0;
	while (tempSati_copy > 60) {
		temp2++;
		tempSati_copy /= 60;
	}
	
	return { (*v1).sati + (*v2).sati + temp2, tempSati % 60, tempMin % 60 };
}

void v9_ispisVremena(struct Vrijeme* v) {
	printf("%d : %d : %d", (*v).sati, (*v).minute, (*v).sekunde);
}

int v9_proracunDatuma(struct Datum* c, int dan) {
	int tempDan = (*c).dan;
	if (tempDan == 1 && dan == -1) {
		((*c).mjesec % 2 == 0) ? tempDan = 30 : tempDan = 31;
	}
	else if ((*c).dan == 30 && dan == 1) {
		((*c).mjesec % 2 == 0) ? tempDan = 1 : tempDan = 31;
	}
	else if (tempDan == 31 && dan == 1) {
		tempDan = 1;
	}
	else if (dan == 1)
		tempDan++;
	else
		tempDan--;

	return tempDan;
}

void v9_ispisDatuma(struct Datum* d) {
	printf("dan prije unesenog dana je: %d\n", v9_proracunDatuma(d, -1));
	printf("dan poslije unesenog dana je: %d\n\n", v9_proracunDatuma(d, 1));
}

void v9_unosPodatakaOsobe(struct Osoba* o, int index) {
	printf("Unesi ime %d. osobe: ", index);
	scanf("%s",  (*o).ime);
	printf("Unesi prezime %d. osobe: ", index);
	scanf("%s",  (*o).prezime);
	printf("%d. Unesi datum rodenja (dan): ", index);
	scanf("%d",  &(*o).d.dan);
	printf("%d. Unesi datum rodenja (mjesec): ", index);
	scanf("%d",  &(*o).d.mjesec);
	printf("%d. Unesi datum rodenja (godinu): ", index);
	scanf("%d",  &(*o).d.godina);
	printf("%d. Unesi vrijeme rodenja (sat): ", index);
	scanf("%d",  &(*o).satRodenja.sati);
	printf("%d. Unesi vrijeme rodenja (minutu): ", index);
	scanf("%d",  &(*o).satRodenja.minute);
	printf("%d. Unesi vrijeme rodenja (sekundu): ", index);
	scanf("%d",  &(*o).satRodenja.sekunde);
}

void v9_prvaOsobaPoAbecedi_ime_pa_prezime(struct Osoba osobe[], int kolicina ) {
	struct Osoba prva = osobe[0];
	for (int i = 1; i < kolicina; i++) {
		if (_strcmpi(osobe[i].ime, prva.ime) < 0) {
			prva = osobe[i];
		}
		else if (_strcmpi(osobe[i].ime, prva.ime) == 0) {
			if (_strcmpi(osobe[i].prezime, prva.prezime) < 0) {
				prva = osobe[i];
			}
		}
	}
	printf("Prva osoba po abecedi:\n");
	printf("Ime: %s\n", prva.ime);
	printf("Prezime: %s\n", prva.prezime);
	printf("Godina: %d\n", prva.d.godina);
	printf("Mjesec: %d\n", prva.d.mjesec);
	printf("Dan: %d\n", prva.d.dan);
	printf("Sat: %d\n", prva.satRodenja.sati);
	printf("Minute: %d\n", prva.satRodenja.minute);
	printf("Sekunde: %d\n", prva.satRodenja.sekunde);
	
}

void v9_najstarijaOsoba(struct Osoba osobe[], int kolicina) {
	struct Osoba najstarija = osobe[0];
	for (int i = 1; i < kolicina; i++) 
	{
		if (najstarija.d.godina - osobe[i].d.godina > 0) {
			najstarija = osobe[i];
		}
		else if(najstarija.d.godina == osobe[i].d.godina) {
			if (najstarija.d.mjesec < osobe[i].d.mjesec) {
				najstarija = osobe[i];
			}
			else if (najstarija.d.mjesec == osobe[i].d.mjesec) {
				if (najstarija.d.dan < osobe[i].d.dan) {
					najstarija = osobe[i];
				}
				else if (najstarija.d.dan == osobe[i].d.dan) {
					if (najstarija.satRodenja.sati < osobe[i].satRodenja.sati) {
						najstarija = osobe[i];
					}
					else if (najstarija.satRodenja.sati == osobe[i].satRodenja.sati) {
						if (najstarija.satRodenja.minute < osobe[i].satRodenja.minute) {
							najstarija = osobe[i];
						}
						else if (najstarija.satRodenja.minute == osobe[i].satRodenja.minute) {
							if (najstarija.satRodenja.sekunde < osobe[i].satRodenja.sekunde) {
								najstarija = osobe[i];
							}
						}
					}
				}
			}
		}


	}
	printf("\nNajstarija osoba:\n");
	printf("Ime: %s\n", najstarija.ime);
	printf("Prezime: %s\n", najstarija.prezime);
	printf("Godina: %d\n", najstarija.d.godina);
	printf("Mjesec: %d\n", najstarija.d.mjesec);
	printf("Dan: %d\n", najstarija.d.dan);
	printf("Sat: %d\n", najstarija.satRodenja.sati);
	printf("Minute: %d\n", najstarija.satRodenja.minute);
	printf("Sekunde: %d\n", najstarija.satRodenja.sekunde);
} 



////////////////////////////////////////////////////////////////////////////////////////////// Vježba 10
void vj10_3_u_1(int* suma, int* produkt, int* razlika, int br1, int br2) {
	*suma = br1 + br2;
	*razlika = br1 - br2;
	*produkt = br1 * br2;
}

int vj10_brPonavljanja_podstringa_u_stringu(const char* tekst, const int velicina, char* podstring) {
	int brojPonavljanja = 0;
	printf("Unesi podstring: ");
	scanf("%s", podstring);
	int velicinaPodstringa = strlen(podstring);
	if (velicinaPodstringa > velicina - 1)
		return -1;
	for (int i = 0; i < velicina; i++) {
		for (int j = 0; j < velicinaPodstringa; j++) {
			if (j == velicinaPodstringa-1) {
				brojPonavljanja++;
			}
			if (*(tekst + i + j) != *(podstring + j)) {
				break;
			}
		}
	}
	return brojPonavljanja;
}


////////////////////////////////////////////////////////////////////////////////////// Vježba 11
void vj11_kopiranjeDatoteke(FILE* fp, FILE* fp_copy, char* naziv1, char* naziv2) {
	fp = fopen(naziv1, "r");
	if (fp == NULL)
		printf("Greska pri otvaranju datoteke");
	else {
		fp_copy = fopen(naziv2, "w");
		if (fp_copy == NULL)
			printf("Greska pri otvaranju datoteke");
		else {
			char znak;
			while (!(feof(fp))) {
				znak = getc(fp);
				putc(znak, fp_copy);
			}
		}
	}
	fclose(fp);
	fclose(fp_copy);
}

void vj11_citanjeDatoteke(FILE* fp) {
	int brojac = 0;
	while (!(feof(fp))) {
		vj11_brojacImenaAna(fp, &brojac);
	}
	printf("Ime ''Ana'' se pojavilo %d puta u datoteci.\n", brojac);
}

void vj11_brojacImenaAna(FILE* fp, int *brojac) {
	char ime[15];
	fgets(ime, 15, fp);
	if (_strcmpi(ime, "Ana\n") == 0)
		(*brojac)++;

	fgets(ime, 15, fp);
	fgets(ime, 15, fp);
}

void vj11_citanjeDatoteke2(FILE* fp) {
	char tekst[128] = { 0 };
	while (!(feof(fp))) {
		vj11_ispisRijec_po_Rijec(fgets(tekst, 128, fp));
	}
}

void vj11_ispisRijec_po_Rijec(char* tekst) {
	char rijec[128] = { 0 };
	int index = 0;
	for (int i = 0; i < strlen(tekst)+1; i++) {
		if (tekst[i] != ' ' ) {
			rijec[index] = tekst[i];
			index++;
		}
		else {
			rijec[index] = '\0';
			printf("%s\n", rijec);
			index = 0;
			
		}
	}
	rijec[index] = '\0';
	printf("%s\n", rijec);
	index = 0;
}
