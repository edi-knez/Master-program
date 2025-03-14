# Testinator_3000
## program za testiranje koda

### O programu:
Ovaj program je zamisljen kao alat za testiranje i debugiranje koda. Osim sto olaksava debugiranje zato sto ces imat samo kod ispred sebe koji ti je potreban, smanjiti ces i izgubljeno vrijeme cekajuci razne nepovezane datoteke da se kompajlaju.
Trenutno se nalazi u prototip verziji i podrzava samo C++ programski jezik.

### Ogranicenja:
* /// - podrzava samo jedno linijske komentare za tekst zadataka	<-
* /// - funkcije koje te zanimaju moraju biti u namespaceu /
* ///		odvoji sve funkcije koje te zanimaju u zasebnu .cpp datoteku i stavi je u mapu "FilesToParse"
* /// - funkcije moraju imat povratni tip "void" (trenutacno)	<-
* /// - nepodrzava template funkcije
* /// - nepodrzava function overloading

### Opis kako radi:
* Prije 1. pokretanja stavi sve datoteke kojima zelis testirat funkcionalnost na odgovarajuce mjesto.
* Pokreni program. Ako ga 1. puta pokreces, program ce procitat datoteke i spremiti ce sve potrebne informacije u json datoteku.
* Kompajlaj program.
* Pokreni program i unesi znak '1' pa onda znak 'y'. Program ce procitat informacije iz json datoteke te ce nadopisat kod za ubacivanje funkcijskih pointera u "Function list.cpp" datoteku
* Kompajlaj program.
* Pokreni program i unesi znak '1' pa bilo koji znak osim 'y'. Program ce ucitat sve potrebne informacije u podatkovne strukture:
	* std::vector < std::string> popisProjekata;
	* std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>> popisImenaFunkcijaPoCjelinama;
	* std::vector<std::vector<void ( * )( )>> popisFunkcija;
	i biti ce spreman za koristenje. 


### Demonstracija:
Video se nalazi na sljedecoj poveznici: https://mega.nz/file/kzIRkJYB#JBXIftEnvWpU5Q4TPzoiUH1mG0yNJU67e-P7B4c9owk

Video je uklonjen iz projektnog foldera jer nije bio vidljiv na github stranici.

### Instalacija:
* Step 1: Kloniraj projekt
* Step 2: Gotovo
* Datoteke za ovaj demo se vec nalaze na pravom mjestu



