#include "../Cjelina3.hpp"
/**********************************************************************/
// ove funkcije su potrebne samo u ovoj cpp datoteci

static void rect_area( float lwidth, float lheight, float& larea );
//
static void trokut_Opseg( float& o, const float& s1, const float& s2, const float& s3 );
static void kvadrat_Opseg( float& o, const float& s );
static void krug_Opseg( float* o, const float* s );
/************************************************************************/


/// <summary>
///		Primjer upotrebe pointera i referenca u funkcijama
/// </summary>
void Cjelina3::zad1()
{
	double rad, pPov, refPov;
	double povrsina, opseg;

	std::cout << "Upisi radijus kruga: ";
	std::cin >> rad;

	std::cout << "Povrsina kruga = " << povrsinaVrijednost( rad ) << " m2\n";

	povrsinaPokazivac( rad, &pPov );
	std::cout << "Povrsina kruga (pok)= " << pPov << " m2\n";

	povrsinaReferenca( rad, refPov );
	std::cout << "Povrsina kruga (ref)= " << refPov << " m2\n";

	povrsinaOpseg( povrsina, opseg, rad );
	std::cout << "Radijus: " << rad << "\nPovrsina = " << povrsina << " m2\n" << "Opseg = " << opseg << " m2\n";
}

/// <summary>
///		Racuna povrsinu pravokutnika
/// </summary>
void Cjelina3::zad3()
{
	float width = 2.5, height = 3.1, area = 0.0;
	rect_area( width, height, area );
	std::cout << "Povrsina pravokutnika je= " << area << '\n';
}

/// <summary>
///		Racunanje opsega za trokut, kvadrat ili kruga zavisno o inputu
/// </summary>
void Cjelina3::zad4()
{
	using std::cin; using std::cout;
	uint32_t izbor = 0;
	float opseg;
	cout << "Upisi broj:\n1 - za opseg trokuta\n2 - za opseg kvadrata\n3 - za opseg kruga\n";
	cin >> izbor;
	switch( izbor )
	{
	case 1:
	{
		float str1, str2, str3;
		cout << "Unesi stranice trokuta: (str1 str2 str3): ";
		cin >> str1 >> str2 >> str3;
		trokut_Opseg( opseg, str1, str2, str3 );
		cout << "Opseg trokuta = " << opseg << '\n';
		break;
	}
	case 2:
	{
		float str;
		cout << "Unesi stranicu kvadrata: ";
		cin >> str;
		kvadrat_Opseg( opseg, str );
		cout << "Opseg kvadrata = " << opseg << '\n';
		break;
	}
	case 3:
	{
		float rad;
		cout << "Unesi radijus kruga: ";
		cin >> rad;
		krug_Opseg( &opseg, &rad );
		cout << "Opseg kruga = " << opseg;
		break;
	}
	default:
		cout << "Pogresan odabir!";
		break;
	}
}

/// <summary>
///		Testiranje funkcionalnosti klase Registracija
/// </summary>
void Cjelina3::zad5()
{
	Registracija r1( 534, 234 );
	Registracija r2;
	Registracija r3;
	r2.ispisi();
	r1.ispisi();
	r1.Set( 999, 544 );
	r1.ispisi();
	//r3.Set(1001, 1000);
}


/// <summary>
///		Racuna i ispisuje povrsinu pravokutnika. Rezultat se sprema u referencu larea parametar.
/// </summary>
/// <param name="lwidth">sirina stranice</param>
/// <param name="lheight">visina stranice</param>
/// <param name="larea">varijabla za rezultat</param>
void rect_area( float lwidth, float lheight, float& larea ) {
	larea = lwidth * lheight;
	std::cout << "Povrsina funkcije je= " << larea << '\n';
}


/// <summary>
///		Racuna opseg trokuta
/// </summary>
/// <param name="o">varijabla za rezultat</param>
/// <param name="s1">stranica a</param>
/// <param name="s2">stranica b</param>
/// <param name="s3">stranica c</param>
void trokut_Opseg( float& o, const float& s1, const float& s2, const float& s3 ) {
	o = s1 + s2 + s3;
}

/// <summary>
///		Racuna opseg kvadrata uz koristenje referenca
/// </summary>
/// <param name="o">varijabla za rezultat</param>
/// <param name="s"></param>
void kvadrat_Opseg( float& o, const float& s ) {
	o = 4 * s;
}

/// <summary>
///		racuna opseg kruga uz koristenje pointera
/// </summary>
/// <param name="o">varijabla za rezultat</param>
/// <param name="s">radijus</param>
void krug_Opseg( float* o, const float* s ) {
	*o = 2 * ( *s ) * 3.14;
}


