#include "Cjelina7.h"

static void pisi_u_consolu_iz_datoteke(std::ifstream& datoteka);
static void pisi_u_consolu_iz_datoteke(const std::string& naziv, const std::string& ekstenzija);



void Cjelina7::zad1()
{
	//// napravi datoteku i popuni je gradovima
	//std::ofstream out_file("cities.txt");

	//out_file << "Atlanta" << " " << "Baltimore";
	//out_file << " " << "Cincinnati" << " " << "Dallas";
	//out_file << " " << " " << "zzz" << " " << "zzz";

	//out_file.close();



	std::ifstream in_file("cities.txt", std::ios::in);
	std::ofstream filter("filter.txt", std::ios::out | std::ios::trunc);
	char c;
	std::string result = "";
	// dohvati karakter
	while (in_file.get(c))
	{
		// grad u varijabli
		if (c == ' ')
		{
			if (result != "zzz" && result != "")
				filter << result << "\n";

			result = "";
			continue;
		}

		result += c;
	}
}

void Cjelina7::zad2()
{
    //kompleks a, b;
//std::cout << "Upisite 2 kompleksna broja (dva para vrijednosti): \n";
//std::cin >> a;
//std::cin >> b;

//std::cout << "Upisali ste brojeve\n";
//std::cout << a;
//std::cout << b;

//if (a < b)
//    std::cout << "a je manji od b!\n";
//else
//    std::cout << "a je veci od b!\n";

    Kompleks A[1000];
    int i;
    // izracunaj i zapisi u memoriju
    for (i = 0; i < 1000; ++i)
    {
        A[i].setReal(sqrt(static_cast<float>(i)));
        A[i].setImag(A[i].getReal());
    }

    // zapisi u datoteku iz memorije
    std::ofstream fTxt("kompleks.txt");
    for (i = 0; i < 1000; ++i)
        fTxt << A[i] << std::endl;
    fTxt.close();

    // zapisi u binarnom obliku
    std::ofstream fBin("kompleks.bin", std::ios::binary);
    fBin.write(reinterpret_cast<char*>(A), 1000 * sizeof(Kompleks));
    fBin.close();

    Kompleks B[1000];
    std::stringstream ss;
    std::ifstream bin_ulaz("kompleks.bin", std::ios::in | std::ios::binary);
    if (bin_ulaz)
    {
        // zapisi u memoriju iz binarne datoteke
        bin_ulaz.read(reinterpret_cast<char*>(&B), 1000 * sizeof(Kompleks));
        bin_ulaz.close();
        std::cout << "Citanje iz kompleks.bin:\n";
        for (i = 0; i < 1000; ++i)
            ss << B[i];
        std::cout << ss.view();
        std::cout << "\t\tEND\n";
    }
}

void Cjelina7::zad4()
{
    std::ifstream datoteka("datoteka.txt", std::ios::in);
    //pisi_u_consolu_iz_datoteke(datoteka);
    pisi_u_consolu_iz_datoteke("datoteka", "dat");

}

/*********************************************************
 * parametri:                                            *
 *                                                       *
 *   - std::ifstream& datoteka -> datoteka iz koje se cita */
void pisi_u_consolu_iz_datoteke(std::ifstream& datoteka) 
{
    std::string blob;
    blob.reserve(512);
    if (datoteka.is_open()) {
        char c;
        for (int i = 0; datoteka.get(c); ++i) {
            if (i < 511)
                blob += c;
            else {
                std::cout << blob << ' ';
                blob = "";
                i = 0;
            }
        }
        std::cout << blob;
    }
    else {
        std::cout << "Nema datoteke :(\n";
    }
}


void pisi_u_consolu_iz_datoteke(const std::string& naziv, const std::string& ekstenzija) 
{
    std::string blob;
    blob.reserve(512);
    std::ifstream datoteka((naziv + '.' + ekstenzija), std::ios::in);
    if (datoteka.is_open()) {
        char c;
        for (int i = 0; datoteka.get(c); ++i) {
            if (i < 511)
                blob += c;
            else {
                std::cout << blob;
                blob = "";
                i = 0;
            }
        }
        std::cout << blob;
    }
    else {
        std::cout << "Nema datoteke :(\n";
    }
}