
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>

#include "../_helperFunc_Programiranje2.1.hpp"
#include "../../Master program/PotrebneDatotekeIDeklaracijeFunkcija.hpp"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
void FESB::vj7_1()
{
	char odabir = { 0 };
	int rez, x, y, z;
	printf( "x = " );
	scanf_s( "%d", &x );
	printf( "y = " );
	scanf_s( "%d", &y );
	printf( "z = " );
	scanf_s( "%d", &z );
	printf( "Unesi slovo za zeljenu operciju:\na) rez = x + y + z\nb) rez = x * y * z\nc) rez = x / y + z\nd) rez = (x / y - z)na1 / 2\n" );
	scanf_s( " %c", &odabir );
	switch( tolower( odabir ) )
	{
	case 'a':
		rez = x + y + z;
		printf( "rez = %d", rez );
		break;
	case 'b':
		rez = x * y * z;
		printf( "rez = %d", rez );
		break;
	case 'c':
		rez = x / y + z;
		printf( "rez = %d", rez );
		break;
	case 'd':
	{
		int temp = sqrt( x / y - z );
		if( temp < 0 )
		{
			printf( "Greska! izraz je < 0\n" );
		}
		else
		{
			rez = temp;
			printf( "rez = %d", rez );
		}
		break;
	}
	default:
		printf( "Greska! krivi unos\n" );
		break;
	}
}

	/*
	2. Napisati program koji sadrži dvije varijable: globalnu varijablu X i lokalnu varijablu Y(lokalna za f-ju main)
	i dodijeliti im neke vrijednosti. Iz glavnog programa treba pozvati f-ju koja ispisuje vrijednosti obije varijable.
	*/
void FESB::vj7_2()
{
	int Y = 5;
	vj7_ispisVrijednostiVarijabla( Y );
}

	/*
	3. Napraviti program koji u “običnoj” f-ji računa faktorijele. Rezultat je potrebno ispisati u glavnom programu
	i nije dozvoljeno korištenje globalnih varijabli.
	*/
void FESB::vj7_3()
{
	int rezultat = vj7_faktorijele( 3 );
	printf( "Rezultat 3! = %d\n", rezultat );
}

	/*
	4. Napisati f-ju kojom se približno određuje vrijednost ex (e = 2.718282), i rezultat usporediti
	s vrijednošću koja se dobije pomoću standardne funkcije exp() deklarirane u math.h.
	Npr. za x = 5, ispisati izračunate rezultate za 5, 10 i 50 ponavljanja. Zašto se program ponaša "čudno" za 50 ponavljanja?
	*/

void FESB::vj7_4()
{
	printf( "(moj) exp(5): %e\nexp(5): %e\n", vj7_exp( 1, 5 ), exp( 1 ) );
	printf( "(moj) exp(5): %e\nexp(5): %e\n", vj7_exp( 5, 5 ), exp( 5 ) );
	printf( "(moj) exp(10): %e\nexp(10): %e\n", vj7_exp( 5, 10 ), exp( 5 ) );
	printf( "(moj) exp(50): %e\nexp(50): %e\n", vj7_exp( 5, 50 ), exp( 5 ) );
}


/*-----------------------------------------------------------	Vježba 8:	----------------------------------------------------*/
	/*
	1. Napisati program koji traži je li neki broj element niza. U programu treba napraviti f-ju traži
	koja uzima tri argumenta (niz, broj elemenata niza i vrijednost koja se traži),
	a treba vratiti 1 ako broj postoji ili 0 ako broj ne postoji.
	*/
void FESB::vj8_1()
{
	const int BROJ_ELEMENATA = 6;
	int testBroj1 = 4, testBroj2 = 5;
	int A[BROJ_ELEMENATA] = { 3, 5, 7, 8, 9, 10 };
	printf( "niz: " );
	for( const auto br : A )
		printf( "%d ", br );
	printf( "\n\ntestBroj1(%d) se ", testBroj1 );
	( vj8_postoji_li_element( A, BROJ_ELEMENATA, testBroj1 ) ) ? printf( "nalazi u nizu\n" ) : printf( "ne nalazi u nizu\n" );
	printf( "testBroj2(%d) se ", testBroj2 );
	( vj8_postoji_li_element( A, BROJ_ELEMENATA, testBroj2 ) ) ? printf( "nalazi u nizu\n" ) : printf( "ne nalazi u nizu\n" );
}

	/*
	//2. Napisati program koji računa produkt svih elemenata matrice dimenzija 3x3. Program ne smije
	//sadržavati ni jednu globalnu varijablu, unos i proračun napraviti u odvojenim funkcijama.
	*/
void FESB::vj8_2()
{
	const int vel = 3;
	int matricaA[vel][vel];
	vj8_unosElemenataMatrice( matricaA, vel );
	printf( "produkt = %d", vj8_produktElemenataMatrice( matricaA, vel ) );
}

	/*
	//3. Napisati program koji sadrži f-je my_strlen i my_strcpy, koje rade isto što i f-je strlen i strcpy.
	//Ispravnost funkcija provjeriti usporedbom sa stvarnim f-jama strlen i strcpy.
	//*/
void FESB::vj8_3()
{
	const char* a = { "ovojekratkitest" };
	printf( "my_strlen: %zd\nstrlen: %zd\n", vj8_my_strlen( a ), strlen( a ) );

	const char* c = { "tesktZaKopirat" };
	char* d = (char*)malloc( vj8_my_strlen( c ) + 1 );
	size_t duljina = strlen( c );
	char* e = (char*)malloc( duljina + 1 );
	if( d )	vj8_my_strcpy( d, c );
	if( e )	strcpy_s( e, duljina, c );
	printf( "c: %s\nd: %s\ne: %s", c, d, e );
}

	/*
	4. Napisati program koji pomoću rekurzivne f-je računa faktorijele.
	*/
void FESB::vj8_4()
{
	int n;
	printf( "Unesi broj: " );
	scanf_s( "%d", &n );
	printf( "%d! = %d\n", n, vj8_rekurzija_faktorijele( n ) );
}

	/*
	5. Napisati program koji korištenjem rekurzivnih funkcija traži minimalni, odnosno maksimalni element niza brojeva.
	*/
void FESB::vj8_5()
{
	int niz[5] = { 3, 5, 1, 7, 2 };
	printf( "najmanji element niza je: %d\n", vj8_rekurzija_minMax_elementNiza( niz, 4 ) );
	printf( "najmanji element niza je: %d\n", vj8_rekurzija_minMax_elementNiza( niz, 4, false ) );	// 0 - min, 1 - max
	printf( "najveci element niza je: %d\n", vj8_rekurzija_minMax_elementNiza( niz, 4, true ) );
}

	/*
	6. Napraviti program koji uneseni dekadski broj pretvara u binarni, oktalni ili heksadecinalni.
	Dekadski broj, kao i brojevna baza (2, 8, 16) u koju se radi pretvorba se unose u programu, a pretvorbu je potrebno realizirati pomoću
	rekurzivne f-je. Rezultat se ispisuje u mainu.
	*/
void FESB::vj8_6()
{
	unsigned int deka;
	printf( "Unesi dekadski broj: " );
	scanf_s( "%d", &deka );
	unsigned int baza;
	printf( "Odaberi sustav u koji zelis pretvorit:\n2 -> binarni\n8 -> oktalni\n16 -> heksadecimalni\n\n" );
	scanf_s( "%d", &baza );

	printf( "%d(10) = %s(%d)\n", deka, vj8_deka_u_bin_okt_heksa( deka, baza ), baza );
}



/*-----------------------------------------------------------	Vježba 9:	--------------------------------------------------------- */
/*
	1. Napisati program koji unosi dva proizvoljna vremena (sat, minute, sekunde) i zbraja ih. Za pohranu
	vremena koristiti strukturu, a zbrajanje i ispis napraviti u odvojenim funkcijama.
	*/

void FESB::vj9_1()
{
	Vrijeme v1 = { 2, 35, 45 };
	Vrijeme v2{ 3, 50, 30 };
	Vrijeme v3 = v9_zbrajanjeVremena( &v1, &v2 );
	v9_ispisVremena( &v3 );
}

	/*
	2. Napisati program koji za uneseni datum računa koji je datum bio dan prije i koji će datum biti dan poslije.
	Za pohranu datuma koristiti strukturu datum (dan, mjesec, godina). Proračun i ispis dana prije/poslije
	napraviti u funkciji dan_prije / dan_poslije
	*/
void FESB::vj9_2()
{
	struct Datum d1 { 2000, 6, 5 };
	struct Datum d2 { 2003, 3, 31 };
	struct Datum d3 { 2000, 4, 30 };
	struct Datum d4 { 2004, 2, 1 };
	v9_ispisDatuma( &d1 );
	v9_ispisDatuma( &d2 );
	v9_ispisDatuma( &d3 );
	v9_ispisDatuma( &d4 );
}

	/*
	3. Napisati program koji unosi podatke o 5 osoba (ime, prezime, datum i sat rođenja). U programu napraviti
	funkciju koja pronalazi najstariju osobu, te funkciju koja pronalazi osobu prvu po abecedi.
	*/
void FESB::vj9_3()
{
	const int BROJ_OSOBA = 5;
	struct Osoba osobe[BROJ_OSOBA];
	osobe[0] = { "Marko", "Marulic", { 15, 5, 0 }, { 2003, 5, 12  } };
	osobe[1] = { "Ana", "Marelica", {20, 51, 50 }, { 2001, 5, 17 } };
	osobe[2] = { "Pero", "Grgulj", { 10, 0, 7 }, { 2000, 8, 1 } };
	osobe[3] = { "Marta", "Marulic", { 15, 5, 0 }, { 2003, 5, 12 } };
	osobe[4] = { "Marko", "Marulic", { 15, 5, 0 }, { 2003, 5, 12 } };

	struct Osoba prva = osobe[0];
	v9_prvaOsobaPoAbecedi_ime_pa_prezime( osobe, BROJ_OSOBA );
	puts( "" );
	v9_najstarijaOsoba( osobe, BROJ_OSOBA );	// popravi
}




/*----------------------------------------------------------	Vježba 10	-----------------------------------------------------*/
	/*
	1. Napisati program koji prvo unosi, a zatim ispisuje elemente nekog polja brojeva i polja znakova zajedno s
	adresom svakog elementa. Sve unose i ispise je potrebno napraviti preko pokazivača i ne smiju se koristiti [].
	*/
void FESB::vj10_1()
{
	const int LIMIT_ELEMENATA = 10;
	int niz[LIMIT_ELEMENATA];
	printf( "Unesi 10 cijelih brojeva\n" );
	for( int i = 0; i < LIMIT_ELEMENATA; i++ )
	{
		printf( "Unesi %d. el: ", i );
		scanf_s( "%d", niz + i );
	}
	puts( "" );
	for( int i = 0; i < LIMIT_ELEMENATA; i++ )
	{
		printf( "niz[%d] = %d	na lokaciji %p\n", i, *( niz + i ), niz + i );
	}
}

	/*
	2. Napisati program koji u jednoj funkciji računa sumu, produkt i razliku dva broja, a svi se rezultati ispisuju u glavnom programu.
	*/
void FESB::vj10_2()
{
	int suma, produkt, razlika;
	vracanjeVrijednosti_3_varijableUfunkciji( &suma, &produkt, &razlika, 25, 5 );
	printf( "broj1: %d\nbroj2: %d\nsuma: %d\nrazlika: %d\nprodukt: %d", 25, 5, suma, razlika, produkt );
}

	/*
	3. Zadatak s računanjem dana prije i poslije riješiti preko funkcija na način da se sva tri datuma
	deklariraju u mainu, a unos, i proračun dana prije i poslije u f-ji. Rezultate je potrebno ispisati u mainu, a ne u funkciji.
	*/
void FESB::vj10_3()
{
	struct Datum d1 { 2000, 6, 5 };
	struct Datum d2 { 2003, 3, 31 };
	struct Datum d3 { 2005, 4, 30 };
	struct Datum d4 { 2004, 2, 1 };

	printf( "dan prije unesenog dana je: %d\n", v9_proracunDatuma( &d1, -1 ) );
	printf( "dan poslije unesenog dana je: %d\n\n", v9_proracunDatuma( &d1, 1 ) );
	printf( "dan prije unesenog dana je: %d\n", v9_proracunDatuma( &d2, -1 ) );
	printf( "dan poslije unesenog dana je: %d\n\n", v9_proracunDatuma( &d2, 1 ) );
	printf( "dan prije unesenog dana je: %d\n", v9_proracunDatuma( &d3, -1 ) );
	printf( "dan poslije unesenog dana je: %d\n\n", v9_proracunDatuma( &d3, 1 ) );
	printf( "dan prije unesenog dana je: %d\n", v9_proracunDatuma( &d4, -1 ) );
	printf( "dan poslije unesenog dana je: %d\n\n", v9_proracunDatuma( &d4, 1 ) );
}

	/*
	4. Napisati program koji za zadani string traži koliko se puta podstring pojavljuje u stringu.
	Podstring je potrebno unijeti u f-ji. F-ja za pretraživanje treba vratiti broj
	ponavljanja. U funkciji za pretraživanje se može koristiti f-ja strncmp iz string.h.
	*/
void FESB::vj10_4()
{
	const int BUFFER_LIMIT = 128;
	char tekst[BUFFER_LIMIT] = { "Kratka prica je oblik kratke narativne proze. Kratke price su sazetije u usporedbi s duzim djelima fikcije, kao sto su novele\0" };
	char podstring[BUFFER_LIMIT - 1];	// inicijalizacija u funkciji vj10_brPonavljanja_podStringa_u_stringu
	printf( "broj ponavljanja podstringa: %d", vj10_brPonavljanja_podstringa_u_stringu( tekst, BUFFER_LIMIT, podstring ) );
}



/*--------------------------------------------------------------	Vježba 11:		---------------------------------------------
	/*
	1. Napisati program koji kopira jednu datoteku u drugu. Nazivi obije datoteke se unose u glavnom programu, a kopiranje se radi u funkciji.
	*/
void FESB::vj11_1()
{
	FILE* fp;
	FILE* fp_copy{};
	char naziv1[20], naziv2[20];
	printf( "Upisi puni naziv datoteke .txt: " );
	scanf_s( "%s", naziv1 );
	printf( "Upisi puni naziv za kopiju datoteke .txt: " );
	scanf_s( "%s", naziv2 );

	fopen_s( &fp, naziv1, "w" );
	if( fp == NULL )
		printf( "Greska pri otvaranju datoteke" );
	else
	{
		fprintf( fp, "Hello World!\n" );
		fprintf( fp, "Hello World drugi put!" );
		fclose( fp );
	}
	vj11_kopiranjeDatoteke( fp, fp_copy, naziv1, naziv2 );
}

	/*2. Napisati program koji iz datoteke znak, po znak čita znamenke sve dok ne pročita nešto što nije broj ili
	se dostigne kraj datoteke. Te znamenke je potrebno pretvoriti u broj koji je bio zapisan u datoteci i ispisati ga na ekran.
	*/
void FESB::vj11_2()
{
	FILE* fp;
	fopen_s( &fp, "vj11_zad2.txt", "r" );

	if( fp == NULL )
		printf( "GRESKA\n" );
	else
	{
		char broj;
		int rezultat = 0;
		while( ( broj = fgetc( fp ) ) != EOF && ( broj >= '0' && broj <= '9' ) )
		{
			rezultat *= 10;
			rezultat += broj - '0';
		}
		fclose( fp );

		printf( "%d", rezultat );
	}
}

	/*
	3. Napisati program koji iz datoteke čita maks. 100 podataka o osobama (ime, prezime i godinu rođenja) i
	traži koliko se osoba zove Ana. Čitanje datoteke i brojenje je potrebno napraviti u odvojenim f-jama.
	*/
void FESB::vj11_3()
{
	FILE* fp;
	fopen_s( &fp, "vj11_zad3.txt", "r" );	// provjeri postoji li
	if( fp )
	{
		vj11_citanjeDatoteke( fp );	// samo procitaj iz nje
		fclose( fp );
	}
	else
	{
		fopen_s( &fp, "vj11_zad3.txt", "w" );	// stvori je
		if( fp )
		{
			fprintf( fp, "Ana\nA\n2000\n" );	// i popuni vrijednostima
			fprintf( fp, "Ana\nB\n2000\n" );
			fprintf( fp, "Mirko\nA\n2000\n" );
			fprintf( fp, "Ana\nC\n2000\n" );
			fprintf( fp, "Boro\nA\n2000\n" );
			fprintf( fp, "Grga\nA\n2000\n" );
			fprintf( fp, "Ana\nD\n2000\n" );
			fprintf( fp, "Pero\nA\n2000\n" );
			fprintf( fp, "Ana\nE\n2000\n" );
			fclose( fp );

			fopen_s( &fp, "vj11_zad3.txt", "r" );
			if( fp )
			{
				vj11_citanjeDatoteke( fp );					// te procitaj je
				fclose( fp );
			}
			else	printf( "GRESKA PRILIKOM OTVARANJA \"vj11_zad3.txt\" datoteke\n" );
		}
		else	printf( "GRESKA PRILIKOM OTVARANJA \"vj11_zad3.txt\" datoteke\n" );
	}
}

	/*
	4. Napisati program koji iz datoteke pročita 1 cijeli redak i onda ga riječ po riječ ispisuje na ekran, a svaka je riječ u svom retku.
	- Datoteke potrebne za ove zadatke je potrebno napraviti u nekom tekstualnom editoru (npr. Notepad, …).
	*/
void FESB::vj11_4()
{
	FILE* fp;
	fopen_s( &fp, "vj11_zad4.txt", "r" );
	if( fp )
	{
		vj11_citanjeDatoteke2( fp );
		fclose( fp );
		fp = NULL;
	}
	else printf( "GRESKA\nNapravi datoteku imena \"vj11_zad4.txt\" i zapisi nesto u nju u programu za obradu teksta" );

}



/*-------------------------------------------------------	Vježba 12:	--------------------------------------------------------
	/*
	1. Napisati program koji unosi bodove kolokvija svih studenata i računa prosječni broj bodova, nakon što
	su ocjene unesene, uz uvjet da unaprijed nije poznato koliko je bilo studenata.
	*/
void FESB::vj12_1()
{
	int brStudenata = 0;
	int sumaBodova = 0;
	int zelimJosStudenata = -1;
	do
	{
		zelimJosStudenata = -1;
		while( zelimJosStudenata == -1 )
		{
			printf( "Imas li jos studenata na popisu?( stisni Esc - ne ili Tab - da )\n" );
			char znak = _getch();
			if( znak == 27 ) { zelimJosStudenata = false; }
			else if( znak == '\t' ) { zelimJosStudenata = true; }
		}
		if( !zelimJosStudenata )	break;
		puts( "" );
		do
		{
			int bodovi = -2;
			while( bodovi < -1 || bodovi > 100 )
			{
				printf( "Ako zelis prekinut unos bodova, unesi -1\n" );
				printf( "Unesi bodove [0-100]: " );
				scanf_s( "%d", &bodovi );
				puts( "" );
			}
			if( bodovi == -1 )	break;
			sumaBodova += bodovi;
			++brStudenata;
		} while( 1 );
		puts( "----" );
	} while( 1 );

	if( brStudenata > 0 ) printf( "\nProsjecni broj bodova svih studenata: %f\n", float( sumaBodova / float( brStudenata ) ) );
	else printf( "\nNisi unio bodove za niti jednog studenta!" );
}

	/*
	2. Napisati program koji neki dekadski broj pretvara u string koji se sastoji od znamenki tog broja. String
	se dinamički alocira ovisno o tome koliko znamenki ima broj.
	*/
void FESB::vj12_2()
{
	int broj;
	printf( "Unesi broj: " );
	scanf_s( "%d", &broj );
	int tempBr = broj;
	int velicina = tempBr > 0 ? 1 : 2;
	while( tempBr > 0 )
	{
		velicina++;
		tempBr /= 10;
	}
	char* str = (char*)malloc( velicina * sizeof( char ) );
	if( str )
	{
		for( int i = 1; i < velicina; ++i )
		{
			*( str + velicina - i - 1 ) = broj % 10 + '0';
			broj /= 10;
		}
		*( str + velicina - 1 ) = '\0';
		printf( "string: %s\n", str );
		free( str );
	}
}

	/*
	3. Napisati program koji čita imena N (unosi se u programu) studenata iz datoteke, a zatim za svakog studenta
	pita koliko je bodova dobio iz svakog od kolokvija (ukupno 3) i zatim računa ukupni broj bodova i ocjenu, prema tablici:
	*/
void FESB::vj12_3()
{
	FILE* fp;
	fopen_s( &fp, "vj12_zad3_imena.txt", "w" );
	if( fp == NULL )
		printf( "Greska pri otvaranju datoteke" );
	else
	{
		fprintf( fp, "Iva\n" );
		fprintf( fp, "Marko\n" );
		fprintf( fp, "Luka\n" );
		fprintf( fp, "Grga\n" );
		fclose( fp );
	}
	char imeStudenta[15];
	int bodovi;
	fopen_s( &fp, "vj12_zad3_imena.txt", "r" );
	if( fp )
	{
		while( fgets( imeStudenta, 15, fp ) != NULL )
		{
			printf( "%s", imeStudenta );
			int ukupno = 0;
			for( int i = 0; i < 3; i++ )
			{
				bool isValidScore = false;
				while( !isValidScore )
				{
					printf( "unesi bodove %d. kolokvija: ", i + 1 );
					scanf_s( "%d", &bodovi );
					if( bodovi >= 0 && bodovi <= 100 )
					{
						ukupno += bodovi;
						isValidScore = true;
					}
				}
			}
			ukupno /= 3;
			if( ukupno > 87 && ukupno <= 100 )
			{
				printf( "\nOcjena: 5, sa %d ukupnih bodova\n\n", ukupno );
			}
			else if( ukupno > 74 )
			{
				printf( "\nOcjena: 4, sa %d ukupnih bodova\n\n", ukupno );
			}
			else if( ukupno > 59 )
			{
				printf( "\nOcjena: 3, sa %d ukupnih bodova\n\n", ukupno );
			}
			else if( ukupno > 48 )
			{
				printf( "\nOcjena: 2, sa %d ukupnih bodova\n\n", ukupno );
			}
			else if( ukupno >= 0 )
			{
				printf( "\nOcjena: 1, sa %d ukupnih bodova\n\n", ukupno );
			}
			else
			{
				printf( "\nGRESKA!\n\n" );
			}
		}
		fclose( fp );
	}
	else printf( "\nNemogu otvorit datoteku za citanje!" );
}
	/*
	4. Napisati program koji pomoću nizova simulira rad reda (podaci se skidaju s početka, a stižu na kraj).
	Red mora biti cirkularan, a dimenzija se unosi u programu. U zadatku koristiti pokazivače na prvi i zadnji element u redu.
	*/
void FESB::vj12_4()
{
	int n;
	printf( "Unesi velicinu nizova: " );
	scanf_s( "%d", &n );
	int* niz1 = (int*)malloc( n * sizeof( int ) );
	int* niz2 = (int*)malloc( n * sizeof( int ) );
	if( niz1 == NULL )	return;
	if( niz2 == NULL ) { free( niz1 ); return; }

	for( int i = 0; i < n; i++ )	// napuni nizove vrijednostima
	{
		*( niz1 + i ) = i;
		*( niz2 + i ) = ( i + 1 ) * 10;
	}

	int* rep1 = niz1 + n - 1;
	int* rep2 = niz2 + n - 1;

	while( _getch() != 27 )	// update na pritisak tipke, zavrsi kada se stisne Esc
	{
		Sleep( 50 );
		for( int i = 0; i < n; i++ )	// ispisi stanje nizova
		{
			printf( "%d ", *( niz1 + i ) );
		}
		for( int i = 0; i < n; i++ )
		{
			printf( "%d ", *( niz2 + i ) );
		}
		printf( "\n" );

		int glava1 = *niz1;
		int glava2 = *niz2;
		for( int i = 0; i < n - 1; ++i )	// pomakni sve el u niz1 ulijevo
		{
			*( niz1 + i ) = *( niz1 + i + 1 );
		}
		*rep1 = glava2; // premjesti el sa niz od glave2 na niz repa1

		for( int i = 0; i < n - 1; ++i )
		{
			*( niz2 + i ) = *( niz2 + i + 1 );	// pomakni sve el u nizu za ulijevo
		}
		*rep2 = glava1; // premjesti el sa niz od glave1 na niz repa2
	}
	free( niz1 );
	free( niz2 );
}
