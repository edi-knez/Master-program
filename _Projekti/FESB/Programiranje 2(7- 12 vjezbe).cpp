#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>

//////////////////////////////////////////////////////////////////////////// vježba 7
int vj7_globalnaVarijabla = 10;
void vj7_ispisVrijednostiVarijabla( int y );
int vj7_faktorijele( unsigned int n );
double vj7_exp( int n, int preciznost );

//////////////////////////////////////////////////////////////////////////// vježba 8
bool vj8_postoji_li_element( int a[], unsigned int pozicija, int trazeniElement );
void vj8_unosElemenataMatrice( int a[][3], unsigned int velicina );
int vj8_produktElemenataMatrice( int a[][3], unsigned int velicina );
int vj8_my_strlen( const char* tekst );
void vj8_my_strcpy( char* tekst_destination, const char* tekst_source );
int vj8_rekurzija_faktorijele( int n );
int vj8_rekurzija_minMax_elementNiza( int niz[], unsigned int velicina, bool max = false );	// 0 - min, 1 - max
char* vj8_deka_u_bin_okt_heksa( unsigned int dekadski, unsigned int baza );

/////////////////////////////////////////////////////////////////////////// vježba 9
struct Vrijeme {
	int sati, minute, sekunde;

	bool jeRanijeVrijemeOd( const Vrijeme& other )
	{
		if( this->sati > other.sati )	return 1;
		else if( this->sati == other.sati )
		{
			if( this->minute > other.minute )	return 1;
			else if( this->minute == other.minute )
			{
				if( this->sekunde > other.sekunde )	return 1;
			}
		}
		return 0;
	}
};
struct Vrijeme v9_zbrajanjeVremena( struct Vrijeme* v1, struct Vrijeme* v2 );
void v9_ispisVremena( struct Vrijeme* v );

struct Datum {
	int godina, mjesec, dan;

	/// <summary>
	///		usporeduje 2 datuma
	/// </summary>
	/// <param name="other">Datum sa kojim provjeravas</param>
	/// <returns>1 ako je datum raniji
	///			 0 ako su isti datumi
	///			-1 ako je datum kasniji</returns>
	int usporedbaSaDatumom( const Datum& other )
	{
		if( this->godina > other.godina )	return 1;
		else if( this->godina == other.godina )
		{
			if( this->mjesec > other.mjesec )	return 1;
			else if( this->mjesec == other.mjesec )
			{
				if( this->dan > other.dan )	return 1;
				else if( this->dan == other.dan )	return 0;
			}
		}
		return -1;
	}
};
int v9_proracunDatuma( struct Datum* c, int dan );
void v9_ispisDatuma( struct Datum* d );

struct Osoba {
	char ime[20], prezime[20];
	Vrijeme rodenaU;
	Datum rodenaNa;

	/// <summary>
	///		Ova funkcija govori je li osoba starija od one sa kojom je usporedujes
	///		
	///		koristi obrnutu logiku da se rijesi slucaja 
	/// </summary>
	/// <param name="other"></param>
	/// <returns>1 ako je osoba od koje usporedujes mlada, 0 ako su jednake dobi ili -1 ako je osoba od koje usporedujes starija</returns>
	int compareWith( const Osoba& other )
	{
		int usporedbaDatuma = this->rodenaNa.usporedbaSaDatumom( other.rodenaNa );
		if( usporedbaDatuma > 0 )	return true;
		else if( usporedbaDatuma == 0 )	return  this->rodenaU.jeRanijeVrijemeOd( other.rodenaU );
		else return -1;
	}
	void ispisOsobe()
	{
		printf( "Ime: %s\n", this->ime );
		printf( "Prezime: %s\n", this->prezime );
		printf( "Godina: %d\n", this->rodenaNa.godina );
		printf( "Mjesec: %d\n", this->rodenaNa.mjesec );
		printf( "Dan: %d\n", this->rodenaNa.dan );
		printf( "Sat: %d\n", this->rodenaU.sati );
		printf( "Minute: %d\n", this->rodenaU.minute );
		printf( "Sekunde: %d\n", this->rodenaU.sekunde );
	}
};
void v9_prvaOsobaPoAbecedi_ime_pa_prezime( struct Osoba osobe[], int kolicina );
void v9_najstarijaOsoba( struct Osoba osobe[], int kolicina );

/////////////////////////////////////////////////////////////////////////////////////// Vježba 10
void vracanjeVrijednosti_3_varijableUfunkciji( int* suma, int* produkt, int* razlika, int br1, int br2 );
int vj10_brPonavljanja_podstringa_u_stringu( const char* tekst, const int velicina, char* podstring );

////////////////////////////////////////////////////////////////////////////////// Vježba 11
void vj11_kopiranjeDatoteke( FILE* fp, FILE* fp_copy, char* naziv1, char* naziv2 );
void vj11_citanjeDatoteke( FILE* fp );
void vj11_brojacImenaAna( FILE* fp, int* brojac );
void vj11_citanjeDatoteke2( FILE* fp );
void vj11_ispisRijec_po_Rijec( char* tekst );



/*------------------------------------------------------	FUNKCIJE	--------------------------------------------------------------*/

////////////////////////////////////////////////////////////////////////////////// vježba 7

/// <summary>
///		Ispisuje vrijednost lokalne i globalne varijable
/// </summary>
/// <param name="y">pristup lokalnoj varijabli</param>
void vj7_ispisVrijednostiVarijabla( int y )
{
	printf( "Lokalna varijabla: %d\n", y );
	printf( "Globalna varijabla: %d\n", vj7_globalnaVarijabla );
}

int vj7_faktorijele( unsigned int n )
{
	int result = 1;
	for( int i = 1; i <= n; ++i )
	{
		result *= i;
	}
	return result;
}

/// <summary>
///		Racuna prirodni logaritam za broj sa zeljenim brojem decimala tocnosti
/// </summary>
/// <param name="n">broj za koji zelis prirodni logaritam</param>
/// <param name="brojDecimala">koliko decimala tocnisti</param>
/// <returns>prirodni logaritam tog broja</returns>
double vj7_exp( int n, int brojDecimala )
{
	if( brojDecimala < 0 )	return -1;
	double preciznost = pow( 0.1, brojDecimala + 1 );
	double rezultat = 1;
	double temp = 1;
	for( unsigned int i = 1; ( temp = ( ( temp * n ) / i ) ) >= preciznost; ++i )
	{
		rezultat += temp;
	}
	return rezultat;
}


//////////////////////////////////////////////////////////////////////////////////////////// vježba 8
bool vj8_postoji_li_element( int a[], unsigned int brojElemenata, int trazeniElement )
{
	for( int i = 0; i < brojElemenata; ++i )
	{
		if( a[i] == trazeniElement )
			return true;
	}
	return false;
}

void vj8_unosElemenataMatrice( int a[][3], unsigned int velicina )
{
	int temp;
	for( int i = 0; i < velicina; ++i )
	{
		for( int j = 0; j < velicina; ++j )
		{
			printf( "A[%d][%d]: ", i, j );
			scanf_s( "%d", &temp );
			a[i][j] = temp;
		}
	}
}

int vj8_produktElemenataMatrice( int a[][3], unsigned int velicina )
{
	int produkt = 1;
	for( int i = 0; i < velicina; ++i )
	{
		for( int j = 0; j < velicina; ++j )
		{
			produkt *= a[i][j];
		}
	}
	return produkt;
}

size_t vj8_my_strlen( const char* tekst )
{
	unsigned int duljina = 0;
	while( tekst[duljina] != '\0' )
	{
		++duljina;
	}
	return duljina;
}

void vj8_my_strcpy( char* tekst_destination, const char* tekst_source )
{
	int duljina = vj8_my_strlen( tekst_source ) + 1;
	for( int i = 0; i < duljina; ++i )
	{
		tekst_destination[i] = tekst_source[i];
	}
	tekst_destination[duljina - 1] = '\0';
}

int vj8_rekurzija_faktorijele( int n )  // ne podrzava negativne brojeve
{
	if( n != 1 )
	{
		return vj8_rekurzija_faktorijele( n - 1 ) * n;
	}
	else
	{
		return 1;
	}
}

int vj8_rekurzija_minMax_elementNiza( int niz[], unsigned int velicina, bool max )
{
	static int result = niz[0];
	if( velicina > 0 )
	{
		if( !max )
		{
			if( result > niz[velicina] )
			{
				result = niz[velicina];
			}
		}
		else
		{
			if( result < niz[velicina] )
			{
				result = niz[velicina];
			}
		}
		vj8_rekurzija_minMax_elementNiza( niz, velicina - 1, max );
	}
	else if( velicina == 0 )
	{
		return result;
	}
	return -1;
}

char* vj8_deka_u_bin_okt_heksa( unsigned int dekadski, unsigned int baza )
{
	// dovoljno prostora za najvecu pretvorbu, 32 bita za binaerni izraz
	static char rezultat[33] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };
	static unsigned char currentPlacementPosition;
	currentPlacementPosition = 0;

	if( dekadski == 0 ) { rezultat[currentPlacementPosition + 1] = '0'; currentPlacementPosition = 0; return rezultat; }

	switch( baza )
	{
	case 16:	// sve podrzane baze koje sadrze znakove
	{
		vj8_deka_u_bin_okt_heksa( dekadski / baza, baza );
		unsigned char tempOstatak = dekadski % baza;
		if( tempOstatak >= 10 )	// gornji limit broja je ogranicen operatorom %
		{
			unsigned char offsetZaZnak = tempOstatak - 10;
			rezultat[currentPlacementPosition] = 'A' + offsetZaZnak;
		}
		else { rezultat[currentPlacementPosition] = dekadski % baza + '0'; }
		++currentPlacementPosition;
		break;
	}
	case 2: case 8:	// sve podrzane baze koje sadrze samo brojeve
		vj8_deka_u_bin_okt_heksa( dekadski / baza, baza );
		rezultat[currentPlacementPosition] = dekadski % baza + '0';
		++currentPlacementPosition;
		break;
	default:
		printf( "Nepodrzana baza!\n" );
		rezultat[1] = '0';	// omogucava provjeru nepodrzane baze tako sto provjeris 2. znak ako nista ne ispise
		rezultat[0] = '\0';
		return rezultat;
	}

	rezultat[currentPlacementPosition] = '\0';
	return rezultat;
}


////////////////////////////////////////////////////////////////////////////////////// vježba 9
struct Vrijeme v9_zbrajanjeVremena( struct Vrijeme* v1, struct Vrijeme* v2 )
{
	int brojSekunda = v1->sekunde + v2->sekunde;
	int temp = brojSekunda;
	int preljev_U_Minute = 0;
	while( temp > 60 )
	{
		++preljev_U_Minute;
		temp /= 60;
	}
	int brojMinuta = v1->minute + v2->minute + preljev_U_Minute;
	temp = brojMinuta;
	int preljev_U_Sate = 0;
	while( temp > 60 )
	{
		++preljev_U_Sate;
		temp /= 60;
	}

	return { ( v1->sati + v2->sati + preljev_U_Sate ) % 24, brojMinuta % 60, brojSekunda % 60 };
}

void v9_ispisVremena( struct Vrijeme* v ) {
	printf( "%d : %d : %d", v->sati, v->minute, v->sekunde );
}

int v9_proracunDatuma( struct Datum* c, int dan )
{
	int tempDan = c->dan;
	if( tempDan == 1 && dan == -1 )	// edge case: prosli dan od parnih i neparnih mjeseci
	{
		tempDan = ( c->mjesec % 2 == 0 ) ? 30 : 31;
		--c->mjesec;
	}
	else if( c->dan == 30 && dan == 1 )	// edge case: sljedeci dan od parnih i neparnih mjeseci
	{
		tempDan = ( c->mjesec % 2 == 0 ) ? 1 : 31;
		++c->mjesec;
	}
	else if( tempDan == 31 && dan == 1 )	// edge case: sljedeci dan na mjesece koji imaju 31 dan
	{
		tempDan = 1;
	}
	else if( dan == 1 )		++tempDan;
	else					--tempDan;

	return tempDan;
}

void v9_ispisDatuma( struct Datum* d )
{
	printf( "dan prije unesenog dana je: %d\n", v9_proracunDatuma( d, -1 ) );
	printf( "dan poslije unesenog dana je: %d\n\n", v9_proracunDatuma( d, 1 ) );
}

void v9_unosPodatakaOsobe( struct Osoba* o, int index ) {
	printf( "Unesi ime %d. osobe: ", index );
	scanf_s( "%s", o->ime );
	printf( "Unesi prezime %d. osobe: ", index );
	scanf_s( "%s", o->prezime );
	printf( "%d. Unesi datum rodenja (dan): ", index );
	scanf_s( "%d", &o->rodenaNa.dan );
	printf( "%d. Unesi datum rodenja (mjesec): ", index );
	scanf_s( "%d", &o->rodenaNa.mjesec );
	printf( "%d. Unesi datum rodenja (godinu): ", index );
	scanf_s( "%d", &o->rodenaNa.godina );
	printf( "%d. Unesi vrijeme rodenja (sat): ", index );
	scanf_s( "%d", &o->rodenaU.sati );
	printf( "%d. Unesi vrijeme rodenja (minutu): ", index );
	scanf_s( "%d", &o->rodenaU.minute );
	printf( "%d. Unesi vrijeme rodenja (sekundu): ", index );
	scanf_s( "%d", &o->rodenaU.sekunde );
}

void v9_prvaOsobaPoAbecedi_ime_pa_prezime( struct Osoba osobe[], int kolicina )
{
	struct Osoba prva = osobe[0];
	for( int i = 1; i < kolicina; ++i )
	{
		if( _strcmpi( osobe[i].ime, prva.ime ) < 0 )
		{
			prva = osobe[i];
		}
		else if( _strcmpi( osobe[i].ime, prva.ime ) == 0 )
		{
			if( _strcmpi( osobe[i].prezime, prva.prezime ) < 0 )
			{
				prva = osobe[i];
			}
		}
	}
	printf( "Prva osoba po abecedi:\n" );
	prva.ispisOsobe();
}

void v9_najstarijaOsoba( struct Osoba osobe[], const int brOSOBA )
{
	struct Osoba najstarija = osobe[0];
	for( int i = 1; i < brOSOBA; ++i )
	{
		if( najstarija.compareWith( osobe[i] ) == 1 )		najstarija = osobe[i];
	}
	printf( "najstarija osoba je:\n" );
	najstarija.ispisOsobe();
}



////////////////////////////////////////////////////////////////////////////////////////////// Vježba 10
void vracanjeVrijednosti_3_varijableUfunkciji( int* suma, int* produkt, int* razlika, int br1, int br2 )
{
	*suma = br1 + br2;
	*razlika = br1 - br2;
	*produkt = br1 * br2;
}

int vj10_brPonavljanja_podstringa_u_stringu( const char* tekst, const int velicina, char* podstring )
{
	int brojPonavljanja = 0;
	printf( "Unesi podstring: " );
	scanf_s( "%s", podstring );
	int velicinaPodstringa = strlen( podstring );
	if( velicinaPodstringa > velicina - 1 )
		return -1;
	for( int i = 0; tekst[i] != '\0'; ++i )
	{
		for( int j = 0; j < velicinaPodstringa; ++j )
		{
			if( *( tekst + i + j ) != *( podstring + j ) )
			{
				break;
			}
			if( j == velicinaPodstringa - 1 )
			{
				brojPonavljanja++;
				break;
			}
			if( tekst[i + j] == '\0' )	return brojPonavljanja;
		}
	}
	return brojPonavljanja;
}


////////////////////////////////////////////////////////////////////////////////////// Vježba 11
void vj11_kopiranjeDatoteke( FILE* fp, FILE* fp_copy, char* naziv1, char* naziv2 )
{
	fopen_s( &fp, naziv1, "r" );
	if( fp == NULL )
		printf( "Greska pri otvaranju datoteke" );
	else
	{
		fopen_s( &fp_copy, naziv2, "w" );
		if( fp_copy == NULL )
			printf( "Greska pri otvaranju datoteke" );
		else
		{
			char znak = fgetc( fp );
			while( znak != EOF )
			{
				fputc( znak, fp_copy );
				znak = fgetc( fp );
			}
			fclose( fp_copy );
		}
		fclose( fp );
	}
}

void vj11_citanjeDatoteke( FILE* fp )
{
	int brojac = 0;
	while( fgetc( fp ) != EOF )
	{
		fseek( fp, -1, SEEK_CUR );
		vj11_brojacImenaAna( fp, &brojac );
	}
	printf( "Ime \"Ana\" se pojavilo %d puta u datoteci.\n", brojac );
}

void vj11_brojacImenaAna( FILE* fp, int* brojac )
{
	char ime[15];
	fgets( ime, 15, fp );
	if( _strcmpi( ime, "Ana\n" ) == 0 )
		++( *brojac );

	fgets( ime, 15, fp );
	fgets( ime, 15, fp );
}

void vj11_citanjeDatoteke2( FILE* fp )
{
	char tekst[128] = { 0 };
	while( fgetc( fp ) != EOF )
	{
		fseek( fp, -1, SEEK_CUR );
		vj11_ispisRijec_po_Rijec( fgets( tekst, 128, fp ) );
	}
}

void vj11_ispisRijec_po_Rijec( char* tekst )
{
	char rijec[128] = { 0 };
	int index = 0;
	for( int i = 0; i < strlen( tekst ) + 1; ++i )
	{
		if( tekst[i] != ' ' && tekst[i] != '.' && tekst[i] != ',' && tekst[i] != ':' )
		{
			rijec[index] = tekst[i];
			++index;
		}
		else if( rijec[0] == '\0' || rijec[0] == '\\' )
		{
			index = 0; continue;	// preskoci praznu rijec
		}
		else
		{
			rijec[index] = '\0';
			printf( "%s\n", rijec );
			index = 0;
		}
	}
	rijec[index] = '\0';
	printf( "%s\n", rijec );
	index = 0;
}



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
void aazad1()
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
void aazad2()
{
	int Y = 5;
	vj7_ispisVrijednostiVarijabla( Y );
}

	/*
	3. Napraviti program koji u “običnoj” f-ji računa faktorijele. Rezultat je potrebno ispisati u glavnom programu
	i nije dozvoljeno korištenje globalnih varijabli.
	*/
void aazad3()
{
	int rezultat = vj7_faktorijele( 3 );
	printf( "Rezultat 3! = %d\n", rezultat );
}

	/*
	4. Napisati f-ju kojom se približno određuje vrijednost ex (e = 2.718282), i rezultat usporediti
	s vrijednošću koja se dobije pomoću standardne funkcije exp() deklarirane u math.h.
	Npr. za x = 5, ispisati izračunate rezultate za 5, 10 i 50 ponavljanja. Zašto se program ponaša "čudno" za 50 ponavljanja?
	*/

void aazad4()
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
void abzad1()
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
void abzad2()
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
void abzad3()
{
	const char* a = { "ovojekratkitest" };
	printf( "my_strlen: %d\nstrlen: %zd\n", vj8_my_strlen( a ), strlen( a ) );

	const char* c = { "tesktZaKopirat" };
	char* d = (char*) malloc( vj8_my_strlen( c ) + 1 );
	size_t duljina = strlen( c );
	char* e = (char*) malloc( duljina + 1 );
	if( d )	vj8_my_strcpy( d, c );
	if( e )	strcpy_s( e, duljina, c );
	printf( "c: %s\nd: %s\ne: %s", c, d, e );
}

	/*
	4. Napisati program koji pomoću rekurzivne f-je računa faktorijele.
	*/
void abzad4()
{
	int n;
	printf( "Unesi broj: " );
	scanf_s( "%d", &n );
	printf( "%d! = %d\n", n, vj8_rekurzija_faktorijele( n ) );
}

	/*
	5. Napisati program koji korištenjem rekurzivnih funkcija traži minimalni, odnosno maksimalni element niza brojeva.
	*/
void abzad5()
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
void abzad6()
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

void aczad1()
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
void aczad2()
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
void aczad3()
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
void adzad1()
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
void adzad2()
{
	int suma, produkt, razlika;
	vracanjeVrijednosti_3_varijableUfunkciji( &suma, &produkt, &razlika, 25, 5 );
	printf( "broj1: %d\nbroj2: %d\nsuma: %d\nrazlika: %d\nprodukt: %d", 25, 5, suma, razlika, produkt );
}

	/*
	3. Zadatak s računanjem dana prije i poslije riješiti preko funkcija na način da se sva tri datuma
	deklariraju u mainu, a unos, i proračun dana prije i poslije u f-ji. Rezultate je potrebno ispisati u mainu, a ne u funkciji.
	*/
void adzad3()
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
void adzad4()
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
void aezad1()
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
void aezad2()
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
void aezad3()
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
void aezad4()
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
void afzad1()
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
void afzad2()
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
	char* str = (char*) malloc( velicina * sizeof( char ) );
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
void afzad3()
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
void afzad4()
{
	int n;
	printf( "Unesi velicinu nizova: " );
	scanf_s( "%d", &n );
	int* niz1 = (int*) malloc( n * sizeof( int ) );
	int* niz2 = (int*) malloc( n * sizeof( int ) );
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
