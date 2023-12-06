#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <conio.h>


//int main()
//{
	/* -------------------------------------------------------  Vježba 1: --------------------------------------------------- */
	/*
	1. Napisati program koji definira 4 varijable(char, int, float, double).Ispisati sve četiri varijable,
	zajedno s njihovim adresama i izračunati koliko su bajtova u memoriji sve te varijable zajedno zauzele.
	*/
void fesb_vj1_1()
{
	char a = 'a';
	int b = 5;
	float c = 6.4;
	double d = 7.444444444;

	int mem = sizeof( a ) + sizeof( b ) + sizeof( c ) + sizeof( d );
	printf( "%c %p\n", a, &a );
	printf( "%d %p\n", b, &b );
	printf( "%f %p\n", c, &c );
	printf( "%e %p\n", d, &d );
	printf( "Varijable su zauzele %d bajtova\n", mem );
}

	/*
	2. Napisati program koji definira 3 varijable tipa znak. Prvoj dodijeliti znak 0, drugoj dodijeliti znak 9,
	a treću izraču nati kao sumu prve dvije. Ispisati sva tri znaka kao znak i kao ASCII vrijednosti.
	*/

void fesb_vj1_2()
{
	char a = '0', b = '9', c = a + b;
	printf( "a: %c b: %c c: %c\n", a, b, c );
	printf( "a: %d b: %d c: %d\n", a, b, c );
}

	/*3.
	Napisati program koji računa sumu, produkt, razliku i kvocijent dva cijela broja.Ispisati sve rezultate na ekran.
	*/
void fesb_vj1_3()
{
	int a = 15, b = 5;
	printf( "suma: %d\n", a + b );
	printf( "razlika: %d\n", a - b );
	printf( "produkt: %d\n", a * b );
	printf( "kvocijent: %d\n", a / b );
}

	/*
	4. Napisati program koji računa sumu prvih 50 brojeva.
	*/
void fesb_vj1_4()
{
	int suma = 0;
	for( int i = 0; i < 50; ++i )
		suma += i;
	printf( "suma: %d\n", suma );
}

	/*5.
	Napisati program koji na ekran ispisuje:
	E E E E E
	D D D D
	C C C
	B B
	A
	U programu je dozvoljeno koristiti najviše 2 printf() naredbe.*/
void fesb_vj1_5()
{
	const int SIRINA = 5;
	const int VISINA = 5;
	char slovo = 'E';
	for( int redak = 0; redak < VISINA; ++redak )
	{
		for( int brojPonavljanja = SIRINA - redak; brojPonavljanja > 0; --brojPonavljanja )
		{
			printf( "%c ", slovo - redak );	// Umanjuj ASCII vrijednost tako da dobijes zeljeno slovo
		}
		printf( "\n" );
	}
}


	/*---------------------------------------------------------  Vježba 2: ------------------------------------------------*/
	/*
	1. Napisati program koji pretvara uneseni realni broj u cijeli na način da ako je prva znamenka iza decimalne točke >= 5
	zaokružuje se na prvi veći. Program mora raditi i za pozitivne i za negativne brojeve.
	*/
void fesb_vj2_1()
{
	int cijeliBr;
	float realniBr;
	printf( "unesi realni broj: " );
	scanf_s( "%f", &realniBr );
	cijeliBr = ( (int) ( realniBr * 10 ) % 10 >= 5 ) ? realniBr + 1 : realniBr;	// OPTIMIZACIJA: koristi znanje o prikazu float brojeva u memoriji i uz pomoc pravih bitova utvrdi treba li povecat broj
	printf( "cijeli broj: %d\n", cijeliBr );
}

	/*
	2. Napisati program koji unosi 10 brojeva ali na ekran ispisuje samo neparne. Broj se ispisuje čim je unesen.
	*/
void fesb_vj2_2()
{
	const int INPUT_LIMIT = 10;
	int broj, brojac = 0;
	while( brojac < INPUT_LIMIT )
	{
		printf( "unesi broj: " );
		scanf_s( "%d", &broj );
		if( broj % 2 == 1 )	// OPTIMIZACIJA: koristi znanje o reprezentaciji inta u memoriji i provjeri tocan bit
		{
			printf( "%d\n", broj );
		}
		++brojac;
	}
}
	/*
	3. Napisati program koji unosi 10 brojeva i računa koliko ih je djeljivo s 3.
	*/
void fesb_vj2_3()
{
	const int INPUT_LIMIT = 10;
	int broj, brojac = 0, brojacNeparan = 0;
	while( brojac < INPUT_LIMIT )
	{
		printf( "unesi broj: " );
		scanf_s( "%d", &broj );
		if( broj % 3 == 0 )
		{
			++brojacNeparan;
		}
		++brojac;
	}
	printf( "%d broja je djeljivo sa 3\n", brojacNeparan );
}

/*
4. Napisati program koji unosi 10 znakova i računa koliko ih je uneseno: a) malim slovima;
																		 b) koliko ih je = H.
*/
void fesb_vj2_4()
{
	const int INPUT_LIMIT = 10;
	char slovo;
	int  brojac = 0, brojac_MalihSlova = 0, brojac_H = 0;
	while( brojac < INPUT_LIMIT )
	{
		printf( "unesi slovo: " );
		scanf_s( " %c", &slovo, 2 );
		printf( "\n" );
		if( slovo >= 'a' && slovo <= 'z' )
		{
			brojac_MalihSlova++;
		}
		else if( slovo == 'H' )
		{
			++brojac_H;
		}
		++brojac;
	}
	printf( "\nMalih slova ima: %d\nNjih %d je bilo = H", brojac_MalihSlova, brojac_H );
}

/*
5. Napisati program koji unosi bodove kolokvija za 5 učenika (između 0 i 100) te računa koliko je učenika prošlo (više od 50)
i koliki je prosječni broj bodova.
*/
void fesb_vj2_5()
{
	const int BROJ_UCENIKA = 5;
	int bodovi, sumaBodova = 0, prolaz = 0;
	for( int i = 0; i < BROJ_UCENIKA; ++i )
	{
		printf( "Unesi bodove %d. ucenika\n", i + 1 );
		scanf_s( "%d", &bodovi );
		if( bodovi > 50 )	// OPTIMIZACIJA: branchless increment
			prolaz++;
		sumaBodova += bodovi;
	}
	printf( "Kolokvij je proslo %d ucenika\nProsjecni broj bodova je %d\n", prolaz, sumaBodova / BROJ_UCENIKA );
}


/*------------------------------------------------      Vježba 3     --------------------------------------------------  */
/*
1. Napisati program koji računa aritmetičku sumu brojeva. Nije unaprijed poznato koliko će se brojeva unijeti,
program prestaje s radom kad se unese 0, ali nju netreba računati za prosjek.
*/
void fesb_vj3_1()
{
	int broj, suma = 0, brojac = 0;
	printf( "Unesi brojeve razlicite od 0 za daljnji unos\n" );
	do
	{
		scanf_s( "%d", &broj );
		if( broj != 0 )
		{
			suma += broj;
			++brojac;
		}
		else
		{
			break;
		}

	} while( true );
	printf( "Arihmeticka sredina: %f", (float) suma / brojac );
}

/*
2. Napisati program koji uneseni cijeli broj razbija na dekadske znamenke. Potrebno je ispisati svaku znamenku
posebno i to u obrnutom redoslijedu.
Npr. broj 4893 je potrebno ispisati kao 3 9 8 4
*/
void fesb_vj3_2()
{
	int broj, reverseBroj = 0;
	printf( "Unesi broj: " );
	scanf_s( "%d", &broj );
	while( broj > 0 )
	{
		reverseBroj *= 10;
		reverseBroj += broj % 10;
		broj /= 10;
	}
	printf( "Obrnuti redoslijed znamenaka: %d\n", reverseBroj );
}

/*
3. Napisati program koji generira slučajni broj i korisnik pogađa o kojem se broju radi.
Program svaki put treba javiti je li uneseni broj > ili < od generiranog. Pogađanje traje sve dok se broj ne pogodi.
Potrebno je ispisati iz kojeg je puta broj pogođen.
*/
void fesb_vj3_3()
{
	int generiraniBroj, korisnikBroj, pokusaj = 0;
	srand( (unsigned) time( NULL ) );
	generiraniBroj = rand() % 1000;
	do
	{
		printf( "Unesi broj o kojem mislis da odgovara izabranom broju: " );
		scanf_s( "%d", &korisnikBroj );
		printf( "\n" );

		++pokusaj;
		if( korisnikBroj > generiraniBroj ) { printf( "Generirani broj je manji od unesenog!\n" ); }
		else if( korisnikBroj < generiraniBroj ) { printf( "Generirani broj je veci od unesenog!\n" ); }
		else
		{
			printf( "Pogodak iz %d. pokusaja!\n", pokusaj );
			break;
		}
	} while( 1 );
}

/*
4. Napisati program koji ispisuje sve primitivne brojeve od 0 – 100.
*/
void fesb_vj3_4()
{
	//for( int i = 1; i <= 100; ++i )
	//{
	//	bool primitivan = false;
	//	for( int j = 2; j < i / 2 + 1; ++j )	// svi brojevi koji su veci od i / 2 + 1 nemogu biti primitivni
	//	{
	//		if( i % j == 0 )
	//		{
	//			primitivan = true;
	//			break;
	//		}
	//	}
	//	if( primitivan )	printf( "Broj %d je primitivan\n", i );
	//}
}


	/*-------------------------------------------------------     Vjezba 4    ---------------------------------------------------------*/
	/*
	1. Napisati program koji s tastature unosi dva cijela broja i matematičku operaciju
	(+, -, * ili /). Ovisno o operaciji je potrebno izračunati i ispisati rezultat.
	*/
void fesb_vj4_1()
{
	int broj, broj2;
	char operacija = 0;
	while( !operacija )
	{
		printf( "Unesi broj: " );
		scanf_s( "%d", &broj );
		printf( "Unesi operaciju: " );
		scanf_s( " %c", &operacija, 2 );
		printf( "Unesi broj: " );
		scanf_s( "%d", &broj2 );
		switch( operacija )
		{
		case '+':
			printf( "Rezultat operacije %d %c %d = %d", broj, operacija, broj2, broj + broj2 );
			break;
		case '-':
			printf( "Rezultat operacije %d %c %d = %d", broj, operacija, broj2, broj - broj2 );
			break;
		case '*':
			printf( "Rezultat operacije %d %c %d = %d", broj, operacija, broj2, broj * broj2 );
			break;
		case '/':
			printf( "Rezultat operacije %d %c %d = %d", broj, operacija, broj2, broj / broj2 );
			break;
		case '^':
		{
			int rezultat = pow( broj, broj2 );
			printf( "Rezultat operacije %d %c %d = %d", broj, operacija, broj2, rezultat );
		}
		break;
		case '%':
			printf( "Rezultat operacije %d %c %d = %d", broj, operacija, broj2, broj % broj2 );
			break;
		case '<':
			printf( "Jednakost %d %c %d je %s", broj, operacija, broj2, ( broj < broj2 ) ? "tocna" : "netocna" );
			break;
		case '>':
			printf( "Jednakost %d %c %d je %s", broj, operacija, broj2, ( broj > broj2 ) ? "tocna" : "netocna" );
			break;
		default:
			printf( "Kriv unos, pokusaj ponovno\n" );
			operacija = 0;
			break;
		}
	}
}

/*
2. Napisati program koji unosi 20 rezultata ocjena s kolokvija (sprema ih u niz). Ocjene mogu biti od 1-5 i
ako se unese krivi broj unos se ponavlja. Kada su ocjene unesene program
računa histogram ocjena u 5 grupa (koliko je bilo kojih ocjena) i ispisuje ga na ekran.
*/
void fesb_vj4_2()
{
	const int INPUT_LIMIT = 20;
	int ocjeneKolokvija[20];
	int histogram[6] = {};
	int ocjena = 0;
	printf( "Unesi 20 ocjena\n" );
	for( int i = 0; i < INPUT_LIMIT; ++i )
	{
		while( ocjena < 1 || ocjena > 5 )
		{
			printf( "Unesi ocjenu (1-5): " );
			scanf_s( "%d", &ocjena );
		}
		ocjeneKolokvija[i] = ocjena;
		++histogram[ocjena];
		ocjena = 0;
	}
	printf( "5 - %d\n4 - %d\n3 - %d\n2 - %d\n1 - %d", histogram[5], histogram[4], histogram[3], histogram[2], histogram[1] );
}

/*
3. Napisati program koji za uneseni niz od 10 cijelih brojeva:
a) traži najmanji element niza;
b) traži najveći element niza;
c) sortira niz od najmanjeg prema najvećem elementu.
Napomena: najmanji i najveći element niza se ne smiju samo ispisati nakon
sortiranja. Potrebno ih je pronaći prije sortiranja.
*/
void fesb_vj4_3()
{
	const int BROJ_ELEMENATA = 10;
	int niz[BROJ_ELEMENATA];
	int broj;
	for( int el = 0; el < BROJ_ELEMENATA; ++el )
	{
		printf( "Unesi broj: " );
		scanf_s( "%d", &broj );
		niz[el] = broj;
	}

	int min = niz[0], max = niz[0];
	for( int i = 1; i < 10; ++i )
	{
		if( min > niz[i] )			min = niz[i];
		else if( max < niz[i] )	max = niz[i];
	}

	for( int i = 0; i < BROJ_ELEMENATA; ++i )
	{
		for( int j = i; j < BROJ_ELEMENATA; ++j )
		{
			if( niz[i] > niz[j] )
			{
				int temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}

	printf( "min: %d\nmax: %d\n", min, max );
	for( int el = 0; el < BROJ_ELEMENATA; ++el )
	{
		printf( "%d ", niz[el] );
	}
}


/*  ------------------------------------------------------  Vježba 5    ---------------------------------------------------
/*
1. Napravi program koji uzima znakove s tastature (sa ili bez prikaza tih znakova na
ekranu) sve dok se ne unese znak ESC. Tada se izlazi iz programa.
*/
void fesb_vj5_1()
{
	char znak = 0;
	while( znak != 27 )
		znak = _getche();
}

/*
2. Napravit program koji iz unesenog stringa stvara novi (u novoj varijabli), na način da iz prvog prebaci sve znakove osim brojeva.
*/
void fesb_vj5_2()
{
	const int STRING_LIMIT = 20;
	char str1[STRING_LIMIT] = { 0 };
	char str2[STRING_LIMIT] = { 0 };
	printf( "Unesi tekst u varijablu: " );
	scanf( " %s", &str1 );
	for( int idx = 0; str1[idx] != '\0' && idx < STRING_LIMIT; ++idx )
	{
		if( !( isdigit( str1[idx] ) ) ) { str2[idx] += str1[idx]; }
		else { str2[idx] += ' '; }
	}
	str2[STRING_LIMIT - 1] = '\0';	// forsiraj zadnji karakter drugog stringa da bude 0 terminator (sprijecava citanje memorije koje mu ne pripada ako korisnik unese vise znakova od STRING_LIMITA)
	printf( "str1: %s\nstr2: %s", str1, str2 );
}

/*
3. Napraviti program koji uneseni string mijenja u 3 koraka i rezultat svakog ispisati. Smije se koristiti samo jedan string.
a) U stringu trebaju ostati samo slova.  -> (pise "samo slova" ali nemoze se ostavit prazan znak '', razmak smije bit ' ')? linija 408
b) Iz tog stringa treba izbaciti sve samoglasnike (velika i mala slova).
c) Sva velika slova pretvoriti u mala i obrnuto.
*/
void fesb_vj5_3()
{
	const int STRING_LIMIT = 20;
	char str[STRING_LIMIT] = { 0 };
	printf( "Unesi tekst: " );
	scanf_s( " %s", &str );
	str[STRING_LIMIT - 1] = '\0';	// forsiraj kraj stringa
	for( int idx = 0; str[idx] != '\0'; ++idx )
	{
		if( isdigit( str[idx] ) )	str[idx] = ' ';
	}
	printf( "str: %s\n", str );
	//
	for( int idx = 0; str[idx] != '\0'; ++idx )
	{
		if( str[idx] == 'a' || str[idx] == 'e' || str[idx] == 'i' || str[idx] == 'o' || str[idx] == 'u' ||
			str[idx] == 'A' || str[idx] == 'E' || str[idx] == 'I' || str[idx] == 'O' || str[idx] == 'U' )
			str[idx] = ' ';
	}
	printf( "str: %s\n", str );
	//
	for( int idx = 0; str[idx] != '\0'; ++idx )
	{
		if( islower( str[idx] ) )		str[idx] = str[idx] - 'a' + 'A';
		else if( isupper( str[idx] ) )	str[idx] = str[idx] - 'A' + 'a';
	}
	printf( "str: %s\n", str );
}

/*
4. Napravi program koji unesenu dekadsku vrijednost pretvara u heksadecimalnu, s tim da je znamenke potrebno
ispisati svaku u svom redu i to u pravom rasporedu.
*/
void fesb_vj5_4()
{
	unsigned int deka;
	char heksa[9] = { '0', '0', '0', '0', '0', '0', '0', '0', '\0' };
	unsigned int pozicija = 0;
	printf( "Unesi dekadski broj: " );
	scanf_s( "%d", &deka );
	while( deka > 0 )
	{
		int temp = deka % 16;
		switch( temp )
		{
		case 10: case 11: case 12: case 13: case 14: case 15:
			heksa[pozicija] = temp - 10 + 'A';	// koristi 10 kao offset 0, 11 kao offset 1, ...
			break;
		default:
			heksa[pozicija] = temp + '0';
			break;
		}
		++pozicija;
		deka /= 16;
	}
	for( int i = 7; i >= 0; --i )
		printf( "%c\n", heksa[i] );
}


/*-------------------------------------------------     Vježba 6    --------------------------------------------------------*/
/*
1. Napisati program koji unosi jednu matricu (A dimenzija 3x3) i iz te matrice
računa matricu B = 5*A. Matricu B je potrebno ispisati.
*/
void fesb_vj6_1()
{
	int A[3][3], B[3][3];
	int broj;
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			printf( "A[%d][%d]: ", i, j );
			scanf( "%d", &broj );
			A[i][j] = broj;
			B[i][j] = 5 * A[i][j];
		}
	}
	//
	printf( "matrica B\n" );
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			printf( "%d ", B[i][j] );
		}
		printf( "\n" );
	}
}

/*
2. Napisati program koji unosi jednu matricu (A dimenzija 3x3) i iz te matrice stvara matricu B = AT. Matricu B je potrebno ispisati.
*/
void fesb_vj6_2()
{
	int A[3][3], B[3][3];
	int broj;
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			printf( "A[%d][%d]: ", i, j );
			scanf( "%d", &broj );
			A[i][j] = broj;
		}
	}

	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			B[i][j] = A[j][i];
		}
	}

	printf( "matrica B\n" );
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			printf( "%d ", B[i][j] );
		}
		printf( "\n" );
	}
}

/*
3. Napisati program koji unosi dvije matrice (A i B dimenzija 3x3), a zatim računa matricu C = A + B i
matricu D = A * B. Matrice C i D je potrebno ispisati.
*/
void fesb_vj6_3()
{
	int A[3][3], B[3][3], C[3][3], D[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
	int broj;
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			printf( "A[%d][%d]: ", i, j );
			scanf( "%d", &broj );
			A[i][j] = broj;
			printf( "B[%d][%d]: ", i, j );
			scanf( "%d", &broj );
			B[i][j] = broj;
		}
	}

	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}


	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			for( int k = 0; k < 3; ++k )
			{
				D[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	printf( "matrica C\n" );
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			printf( "%d ", C[i][j] );
		}
		printf( "\n" );
	}
	printf( "matrica D\n" );
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			printf( "%d ", D[i][j] );
		}
		printf( "\n" );
	}
}

/*
4. Napisati program koji unosi 5 imena i zatim:
a) pronalazi indeks imena prvog po abecedi, te ispisuje indeks i ime;
b) pronalazi indeks imena zadnjeg po abecedi, te ispisuje indeks i ime;
c) sortira imena po abecedi i ispisuje ih.
Pri tome rezultati pretraživanja ne smiju razlikovati velika i mala slova, tj. bez obzira je li ime uneseno
velikim ili malim slovom treba biti na ispravnom mjestu po abecedi.
*/
void fesb_vj6_4()
{
	const unsigned int BROJ_LJUDI = 5;
	const unsigned int NAME_LIMIT = 20;
	char imena[BROJ_LJUDI][NAME_LIMIT];
	for( int idx = 0; idx < BROJ_LJUDI; ++idx )
	{
		printf( "Unesi %d. ime: ", idx + 1 );
		gets_s( imena[idx] );
		//imena[idx][NAME_LIMIT - 1] = '\0';	// forsiraj kraj stringa
	}
	//
	int idx1 = 0, idx2 = 0;
	for( int tempIdx = 0; tempIdx < BROJ_LJUDI - 1; ++tempIdx )
	{
		idx1 = ( _strcmpi( imena[tempIdx + 1], imena[idx1] ) < 0 ) ? tempIdx + 1 : idx1;
		if( _strcmpi( imena[tempIdx + 1], imena[idx2] ) > 0 )
		{
			idx2 = tempIdx + 1;
		}

	}
	printf( "Prvi po abecedi je: %s, index: %d\nZadnji po abecedi je: %s, index: %d\n", imena[idx1], idx1, imena[idx2], idx2 );
	//
	//sortiranje (Selection sort - vrlo efikasan jer nema puno kopiranja stringa)
	for( unsigned int i = 0; i < BROJ_LJUDI; ++i )
	{
		unsigned int j = i + 1;		// potreban izvan unutarnje petlje
		unsigned int tempIdx = i;	// potreban izvan unutarnje petlje
		bool foundBetterResult = false;
		for( ; j < BROJ_LJUDI; ++j )
		{
			for( unsigned int k = 0; k < NAME_LIMIT && imena[tempIdx][k] != '\0' && imena[j][k] != '\0'; ++k )
			{
				char curr = tolower( imena[j][k] );
				char candidate = tolower( imena[tempIdx][k] );
				if( curr < candidate )
				{
					tempIdx = j;
					break;
				}
				else if( curr > candidate )	break;
			}
		}
		if( bool foundBetterResult = tempIdx != i )
		{
			char temp[NAME_LIMIT];
			strcpy_s( temp, NAME_LIMIT, imena[i] );
			strcpy_s( imena[i], NAME_LIMIT, imena[tempIdx] );
			strcpy_s( imena[tempIdx], NAME_LIMIT, temp );
		}
	}
	puts( "\nSortiran ispis:" );
	for( unsigned int idx = 0; idx < BROJ_LJUDI; ++idx )
		printf_s( "%d. %s\n", idx + 1, imena[idx] );
}
//}

