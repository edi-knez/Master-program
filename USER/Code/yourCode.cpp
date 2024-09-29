#include "YourCode.hpp"

void korakIzvrsavanjaFunkcije( const char odabirProjekta, const std::string& odabirCjeline, const std::string& odabirFunkcije );

void USER::executableCode()
{
	if( Master::popisProjekata.size() == 0 )
	{
		std::cout << "Nema niti jednog ucitanog projekta :(\nIzlazim...\n";
		puts( "==========================================================================================" );
		exit( EXIT_SUCCESS );
	}

	char odabirProjekta;
	std::string odabirCjeline, odabirFunkcije;
	char stage = 1;
	do
	{
		Master::goToTheWantedFunctionAndThen( Master::popisFiltriranihImenaFunkcijaPoCjelinama, korakIzvrsavanjaFunkcije, odabirProjekta, odabirCjeline, odabirFunkcije, stage );
	} while( stage > 0 );
}




void korakIzvrsavanjaFunkcije( const char odabirProjekta, const std::string& odabirCjeline, const std::string& odabirFunkcije )
{
	auto iterID_funkcijeZaIzvrsit = Master::popisFiltriranihImenaFunkcijaPoCjelinama[odabirProjekta].at( odabirCjeline ).find( odabirFunkcije );
	if( iterID_funkcijeZaIzvrsit != Master::popisFiltriranihImenaFunkcijaPoCjelinama[odabirProjekta].at( odabirCjeline ).end() )
	{
		try
		{
			//	throw 1;
			bool timeoutEnabled = false; /*NE UKLJUCUJ AKO ZELIS DEBUGIRAT*/
			std::cout << "\nAko zelis stavit timeout od 15 sekundi na izvrsenje zadatka, unesi SAMO enter ";
			{
				std::string ch = "t";
				std::cin.ignore();
				std::getline( std::cin, ch );
				if( ch.length() == 0 )
					timeoutEnabled = true;
			}
			puts( "\n====================================================" );
			std::cout << iterID_funkcijeZaIzvrsit->second.first;
			puts( "====================================================" );
			std::cout << "\nID_funkZaIzvrsit: " << iterID_funkcijeZaIzvrsit->second.second << '\n';
			std::cout << "Pokrecem...\n\n\n";
			std::cout << "Funkcija je vratila sljedeæi rezultat:\n";
			puts( "--------------------------------------------------------" );
			std::thread zadatakThread( Master::popisFunkcija[odabirProjekta][iterID_funkcijeZaIzvrsit->second.second] );
			///Master::popisFunkcija[odabirProjekta][iterID_funkcijeZaIzvrsit->second.second]
			static bool isFuncDone = false;
			std::jthread watcherThd( [&]() {
				using namespace std::chrono_literals;
				bool ponoviUpit = true;
				auto pocetnoVrijeme = std::chrono::high_resolution_clock::now();
				auto vrijmeSada = std::chrono::high_resolution_clock::now();

				while( !isFuncDone )
				{
					if( ponoviUpit && std::chrono::high_resolution_clock::now() - vrijmeSada > std::chrono::high_resolution_clock::duration( 250ms ) )
					{
						std::cout << "Cekam unos korisnika: ";
						vrijmeSada = std::chrono::high_resolution_clock::now();
						ponoviUpit = false;
					}

					if( timeoutEnabled && std::chrono::high_resolution_clock::now() - pocetnoVrijeme > std::chrono::seconds( 15 ) )
					{
						puts( "\n\n=============================================================================================" );
						std::cout << "Proslo je 15 sekundi od pokretanja funkcije, vjerojatnost je da je funkcija zapela u beskonacnoj petlji\nIzlazim...\n";
						puts( "===============================================================================================" );
						std::cout.flush();
						std::cout.seekp( std::ios::end );
						TerminateThread( zadatakThread.native_handle(), 1 ); /// <------- WINDOWS dependent
						std::cout.flush();
						std::cout.seekp( std::ios::end );
						break;
					}

					std::this_thread::sleep_for( 100ms );
				}
			} );


			zadatakThread.join(); // prisili ispis funkcije "puts" poslije izvrsenja funkcije
			isFuncDone = true;
			puts( "\n====================================================\n" );
		}
		catch( std::exception& e ) {
			puts( "\n\n====================================================\n" );
			std::cout
				<< "Funkcija je bacila iznimku: " << e.what()
				<< "\nAko zelis istrazit o cemu se radi pritisni tipku entera.Ukoliko pak zelis nastavit testirat neke druge aspekte, stisni bilo koju drugu tipku: ";
			char c;
			std::cin >> c;
			if( tolower( c ) == 'y' )
				throw;
			puts( "\n====================================================\n" );
		}
		catch( ... ) {
			puts( "\n/n====================================================\n" );
			std::cout << "Funkcija je bacila iznimku!\nAko zelis istrazit o cemu se radi pritisni tipku 'y'.Ukoliko pak zelis nastavit testirat neke druge aspekte, "
				"stisni bilo koju drugu tipku: ";
			char c;
			std::cin >> c;
			if( tolower( c ) == 'y' )
				throw;
			puts( "\n====================================================\n" );
		}
	}
}