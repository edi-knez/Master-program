#include "../Cjelina7.hpp"

static void pisi_u_consolu_iz_datoteke(std::ifstream& datoteka);
static void pisi_u_consolu_iz_datoteke(const std::string& naziv, const std::string& ekstenzija);


/// <summary>
///		Filtriraj gradove u filter.txt datoteku koja se otvara za citanje i brise sav sadrzaj pri pozivu funkcije
/// 
///		Gradovi se nalaze u datoteci cities.txt
/// </summary>
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
		// grad je spremljen u varijabli
		if (c == ' ')
		{
			if (result != "zzz" && result != "")	// ako se nalazi deliminator zzz ili je varijabla prazna, preskoci taj input
				filter << result << "\n";

			result = "";	// resetiraj string
			continue;
		}

		result += c;
	}
}

/// <summary>
///		Spremi u memoriji prvih 1000 float vrijednosti drugog korijena u niz
///		Onda iz tog niza zapisi u datoteku kompleks.txt
///		
///		Nakon toga otvori binaernu datoteku kompleks.bin i zapisi rezultate
///		Da provjeris uspjeh binaernog zapisa stvori novi niz od 1000 kompleksnih brojeva i procitaj podatke iz binaerne datoteke
/// </summary>
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

/// <summary>
///		Ispisi datoteku u konzolu uz pomoc buffera
/// </summary>
/// <param name="datoteka">datoteka iz koje citas</param>
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

/// <summary>
///		REDUDANTNA FUNKCIJA
/// </summary>
/// <param name="naziv"></param>
/// <param name="ekstenzija"></param>
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