//////////////////////////////
// before
// ///////////////////////////

void Master::filter( const char odabirProjekta, const std::string& odabirCjeline, const std::string& odabirFunkcije, std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama )
{
	auto getContainerName = [&]() -> std::string_view
	{
		if( &spremnikFunkcijaPoCjelinama == &Master::popisImenaFunkcijaPoCjelinama )	return "popisImenaFunkcijaPoCjelinama";
		else if( &spremnikFunkcijaPoCjelinama == &Master::popisWhitelistanihImenaFunkcijaPoCjelinama )	return "popisWhitelistanihImenaFunkcijaPoCjelinama";
		else if( &spremnikFunkcijaPoCjelinama == &Master::popisBlacklistanihImenaFunkcijaPoCjelinama )	return "popisBlacklistanihImenaFunkcijaPoCjelinama";
		else return "ERROR";
	};


	std::string_view containerName = getContainerName();
	assert( containerName != "ERROR", "not yet supported functionality" );

	std::cout << "Imas sljedece opcije:\n";
	if( &spremnikFunkcijaPoCjelinama == &Master::popisImenaFunkcijaPoCjelinama )
		std::cout << "1) Dodaj funkciju u \"" << containerName << "\" spremnik/nUnesi bilo koji drugi znak ako zelis obustavit trenutacnu operaciju\n\n";
	else
		std::cout << "1) Ukloni funkciju iz \"" << containerName << "\" spremnika/nUnesi bilo koji drugi znak ako zelis obustavit trenutacnu operaciju\n\n";

	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnik1 = Master::popisWhitelistanihImenaFunkcijaPoCjelinama;
	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnik2 = Master::popisBlacklistanihImenaFunkcijaPoCjelinama;
	char odabir;
	std::cout << "Tvoj odabir: "; std::cin >> odabir;
	switch( odabir )
	{
		case '1':
			if( &spremnikFunkcijaPoCjelinama == &Master::popisImenaFunkcijaPoCjelinama )
			{
				std::cout << "Imas sljedece opcije:\n"
					<< "w) ako zelis spremit funkciju u whitelist filter\n"
					<< "b) ako zelis spremit funkciju u blacklist filter\n"
					<< "Bilo koji drugi znak za obustavljanje operacije\n\n";
				std::cout << "Tvoj odabir: "; std::cin >> odabir;

				if( odabir == 'w' || odabir == 'b' )
				{

					if( spremnik1.size() >= Master::popisProjekata.size() && spremnik2.size() >= Master::popisProjekata.size() )
					{
						auto whiteIt1 = spremnik1[odabirProjekta];
						auto blackIt1 = spremnik2[odabirProjekta];
						if( whiteIt1.contains( odabirCjeline ) && blackIt1.contains( odabirCjeline ) )
						{
							auto whiteIt2 = whiteIt1[odabirCjeline];
							auto blackIt2 = blackIt1[odabirCjeline];
							auto entry = spremnikFunkcijaPoCjelinama[odabirProjekta][odabirCjeline][odabirFunkcije];
							if( odabir == 'w' && !whiteIt2.contains( odabirFunkcije ) || !blackIt2.contains( odabirFunkcije ) )
							{
								whiteIt2.emplace( entry );
							}
							else if( odabir == 'b' && !whiteIt2.contains( odabirFunkcije ) || !blackIt2.contains( odabirFunkcije ) )
							{
								blackIt2.emplace( entry );
							}
						}
						else
						{
							auto entry = spremnikFunkcijaPoCjelinama[odabirProjekta][odabirCjeline][odabirFunkcije];
							if( odabir == 'w' && !whiteIt1.contains( odabirCjeline ) || !blackIt1.contains( odabirCjeline ) )
							{
								whiteIt1[odabirCjeline].emplace( entry );
							}
							else if( odabir == 'b' && !whiteIt1.contains( odabirFunkcije ) || !blackIt1.contains( odabirFunkcije ) )
							{
								blackIt1[odabirCjeline].emplace( entry );
							}
						}

					}
					else
					{
						auto entry = spremnikFunkcijaPoCjelinama[odabirProjekta][odabirCjeline][odabirFunkcije];
						if( odabir == 'w' && spremnik1.size() < odabirProjekta )
						{
							if( spremnik2.size() < odabirProjekta )
								spremnik1[odabirProjekta][odabirCjeline].emplace( entry );
							else
							{
								/// copy paste kod na ovo mjesto
							}
						}
						else if( odabir == 'b' && !spremnik2.size() < odabirProjekta )
						{
						//	if( )
							spremnik2[odabirProjekta][odabirCjeline].emplace( entry );
						}
					}
				}
				else return;

			}
			else
			{
				/// ukloni iz filtera
				spremnikFunkcijaPoCjelinama[odabirProjekta][odabirCjeline].erase( odabirFunkcije );
			}
			break;
		default: return;
	}

}


///////////////////////////
// after
///////////////////////////


void Master::filter( const char odabirProjekta, const std::string& odabirCjeline, const std::string& odabirFunkcije, std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama )
{
	auto getContainerName = [&]() -> std::string_view
		{
			if( &spremnikFunkcijaPoCjelinama == &Master::popisImenaFunkcijaPoCjelinama )	return "popisImenaFunkcijaPoCjelinama";
			else if( &spremnikFunkcijaPoCjelinama == &Master::popisWhitelistanihImenaFunkcijaPoCjelinama )	return "popisWhitelistanihImenaFunkcijaPoCjelinama";
			else if( &spremnikFunkcijaPoCjelinama == &Master::popisBlacklistanihImenaFunkcijaPoCjelinama )	return "popisBlacklistanihImenaFunkcijaPoCjelinama";
			else return "ERROR";
		};

	const char OFFSET = 1;

	std::string_view containerName = getContainerName();
	assert( containerName != "ERROR", "not yet supported functionality" );

	std::cout << "Imas sljedece opcije:\n";
	if( &spremnikFunkcijaPoCjelinama == &Master::popisImenaFunkcijaPoCjelinama )
		std::cout << "1) Dodaj funkciju u \"" << containerName << "\" spremnik\nUnesi bilo koji drugi znak ako zelis obustavit trenutacnu operaciju\n\n";
	else
		std::cout << "1) Ukloni funkciju iz \"" << containerName << "\" spremnika\nUnesi bilo koji drugi znak ako zelis obustavit trenutacnu operaciju\n\n";

	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnik1 = Master::popisWhitelistanihImenaFunkcijaPoCjelinama;
	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnik2 = Master::popisBlacklistanihImenaFunkcijaPoCjelinama;
	char odabir;
	std::cout << "Tvoj odabir: "; std::cin >> odabir;
	std::cin.seekg( std::cin.end );
	switch( odabir )
	{
	case '1':
		if( &spremnikFunkcijaPoCjelinama == &Master::popisImenaFunkcijaPoCjelinama )
		{
			std::cout << "Imas sljedece opcije:\n"
				<< "w) ako zelis spremit funkciju u whitelist filter\n"
				<< "b) ako zelis spremit funkciju u blacklist filter\n"
				<< "Bilo koji drugi znak za obustavljanje operacije\n\n";
			std::cout << "Tvoj odabir: "; std::cin >> odabir;

			if( odabir == 'w' || odabir == 'b' )
			{
				std::vector<bool> vTracker1;
				vTracker1.reserve( 5 );
				std::vector<bool> vTracker2;
				vTracker2.reserve( 5 );

				vTracker1.push_back( spremnik1.size() >= odabirProjekta + OFFSET );
				vTracker2.push_back( spremnik2.size() >= odabirProjekta + OFFSET );

				vTracker1.push_back( vTracker1.back() == true && spremnik1[odabirProjekta].contains( odabirCjeline + OFFSET ) );
				vTracker2.push_back( vTracker2.back() == true && spremnik2[odabirProjekta].contains( odabirCjeline + OFFSET ) );

				vTracker1.push_back( vTracker1.back() == true && spremnik1[odabirProjekta + OFFSET][odabirCjeline].contains( odabirFunkcije ) );
				vTracker2.push_back( vTracker2.back() == true && spremnik2[odabirProjekta + OFFSET][odabirCjeline].contains( odabirFunkcije ) );

				if( vTracker1.back() == false && vTracker2.back() == false )
				{
					auto entry = spremnikFunkcijaPoCjelinama[odabirProjekta][odabirCjeline][odabirFunkcije];
					if( odabir == 'w' )
					{
						while( spremnik1.size() < odabirProjekta + OFFSET )	spremnik1.push_back( {} );
						spremnik1[odabirProjekta][odabirCjeline][odabirFunkcije] = entry;
					}
					else if( odabir == 'b' )
					{
						while( spremnik2.size() < odabirProjekta + OFFSET )	spremnik2.push_back( {} );
						spremnik2[odabirProjekta][odabirCjeline][odabirFunkcije] = entry;
					}
				}

			}
			else return;

		}
		else
		{
			/// ukloni iz filtera
			if( spremnikFunkcijaPoCjelinama[odabirProjekta][odabirCjeline].contains( odabirFunkcije ) )
				spremnikFunkcijaPoCjelinama[odabirProjekta][odabirCjeline].erase( odabirFunkcije );
		}
		break;
	default: return;
	}

}