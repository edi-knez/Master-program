#include "../Cjelina1.hpp"

/// <summary>
///		napisi funkciju koja racuna povrsinu kvadrata
/// </summary>
/// <param name="funX">duljina stranice kvadrata (double)</param>
/// <returns>povrsinu kvadrata (double)</returns>
double Cjelina1::_kvadPovrsina( double funX ) {
	double funX2;
	funX2 = funX * funX;
	return funX2;
}

/// <summary>
///		Ispisi i izracunaj x, x^2, x^4
/// </summary>
void Cjelina1::zad4_kvadrat() {
	using std::cout;
	double x = 5.5;
	double x2 = _kvadPovrsina( x );	// kvadriraj x		da dobijes x^2
	double x4 = _kvadPovrsina( x2 );	// kvadriraj x^2	da dobijes x^4
	cout << "x: " << x << '\n';
	cout << "x2: " << x2 << '\n';
	cout << "x4: " << x4 << '\n';
}

/// <summary>
///		Ispis teksta u konzolu
/// </summary>
void Cjelina1::zad5_ispis()
{
	using std::cout;
	cout << "\nI like to write \n before I've read it. \n\n";
	cout << "Then, with my pen, I always edit.\n";
	cout << "But, with computer\s, now I type ";
	cout << "and never, ever get it right.\n";
}

/// <summary>
///		Pozovi funkciju iz druge cpp datoteke
/// </summary>
void Cjelina1::vj1_2datoteke()
{
	std::cout << "Ovo je moj C++ program\n";
	z121_datoteka();
}

/// <summary>
///		Izracunaj i ispisi povrsinu kruga u konzolu
/// </summary>
void Cjelina1::vj3_krug()
{
	double r, kvadrat, area;
	r = 2;
	kvadrat = r * r;
	area = kvadrat * 3.14;
	std::cout << "Povrsina kruga = " << area << " m" << std::endl;
}