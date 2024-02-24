#pragma once

//////////////////////////////////////////////////////////////////////////// vježba 7
int vj7_globalnaVarijabla = 10;
void vj7_ispisVrijednostiVarijabla( int y );
int vj7_faktorijele( unsigned int n );
double vj7_exp( int n, int preciznost );

//////////////////////////////////////////////////////////////////////////// vježba 8
bool vj8_postoji_li_element( int a[], unsigned int pozicija, int trazeniElement );
void vj8_unosElemenataMatrice( int a[][3], unsigned int velicina );
int vj8_produktElemenataMatrice( int a[][3], unsigned int velicina );
size_t vj8_my_strlen( const char* tekst );
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

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
	size_t duljina = vj8_my_strlen( tekst_source ) + 1;
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

void v9_ispisVremena( struct Vrijeme* v )
{
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


