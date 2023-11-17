#include "Cjelina8.hpp"


template<class T> static T maximum(T a, T b);
template<typename T> static T apsolutnaVrijednost(T a);
static bool palindrom(std::string_view s);

/// <summary>
///		Razlika izmedu rada sa C i C++ stringom
/// </summary>
void Cjelina8::zad1()
{
    // C
    char ime[50] = "Ivan";
    char prezime[50] = "Peras";
    char ImePrezime[100] = "";
    char kopija[100] = "";

    // C++
    using std::string; using std::cout;
    string sIme = "Ivan";
    string sPrezime = "Peras";
    string sImePrezime = "";
    string sKopija = "";

    cout << "Kopiranje:\n";

    strcpy_s(ImePrezime, ime);
    cout << "C:\t" << ImePrezime << '\n';

    sImePrezime = sIme;
    cout << "C++:\t" << sImePrezime << '\n';

    cout << "Spajanje:\n";

    strcat_s(ImePrezime, " ");
    strcat_s(ImePrezime, prezime);
    cout << "C:\t" << ImePrezime << '\n';

    sImePrezime = sImePrezime + " " + sPrezime;
    cout << "C++:\t" << sImePrezime << '\n';

    cout << "Mjerenje duljine:\n";

    cout << "C:\t" << strlen(ImePrezime) << '\n';

    cout << "C++:\t" << sImePrezime.length() << '\n';

    cout << "Usporedba:\n";

    cout << "C:\t" << !strcmp(ImePrezime, ime) << '\n';

    cout << "C++:\t" << (sImePrezime == sIme) << '\n';


}

/// <summary>
///		Unos zeljenih brojeva u vektor pod strukturu sve dok se ne upise slovo
///		Onda izracunaj i ispisi sumu pa prosjecnu vrijednost
///		Nakon toga prikazi sve unesene brojeve
/// </summary>
void Cjelina8::zad2()
{
    using std::cout; using std::cin; using std::vector;
    vector<double> vec;
    vector<double> revVec;
    double val;

    cout << "Unos proizvoljnog niza brojeva u vektor.\n";
    cout << "Unos zavrsava kada se otkuca neko slovo!\n";

    while (cin >> val) {
        vec.push_back(val);
    }
    cin.clear();	// ocisti failbit zastavicu
    cin.ignore();	// ignoriraj zadnji pritisnuti enter
    double sum = 0;

    for (vector<double>::const_iterator it = vec.begin(); it != vec.end(); it++) {
        sum += *it;
    }

    for (int i = vec.size() - 1; i > -1; i--) {
        revVec.push_back(vec[i]);
    }

    double avg = sum / vec.size();

    cout << "Suma od " << vec.size()
        << " elemenata: " << sum
        << ". Srednja vrijednost: " << avg << '\n';

    for (vector<double>::iterator it = revVec.begin(); it != revVec.end(); it++) {
        cout << *it << '\n';
    }
}

/// <summary>
///		Testiranje template funkcije maximum sa integerima i double
///		Testiranje template funkcije apsolutnaVrijednost sa integerom i double
///		Testiranje palindrom funkcije
/// </summary>
void Cjelina8::zad3()
{
    using std::cout; using std::string;
    int a = 3,
        b = 5;

    double c = 3.1,
        d = 5.2;

    cout << "maximum(int): " << maximum(a, b) << '\n';
    cout << "maximum(double): " << maximum(c, d) << '\n';

    cout << "apsolutno a: " << apsolutnaVrijednost(a) << '\n';;
    cout << "apsolutno -6.77: " << apsolutnaVrijednost(-6.77) << '\n';


    string s1 = "bob",
        s2 = "jabuka",
        s3 = "anavolimilovana";

    cout << "palindrom(bob): " << palindrom(s1) << '\n'
        << "palindrom(jabuka): " << palindrom(s2) << '\n'
        << "palindrom(anavolimilovana): " << palindrom(s3) << '\n';

}
	/// amaterski nacin za template funkciju maximum
    //
    //template<class T>
    //T maximum(T a, T b) {
    //    if (a > b) {
    //        return a;
    //    }
    //    else {
    //        return b;
    //    }
    //}

    /// <summary>
    ///		branchless template funkcija za odredivanje max broja
    /// </summary>
    /// <typeparam name="T">tip podatka</typeparam>
    /// <param name="a">broj1</param>
    /// <param name="b">broj2</param>
    /// <returns></returns>
    template<class T>
    T maximum(T a, T b) {
        return (a > b) * a + (b > a) * b;	// (a>b) moze dat 0 ili 1 (zavisi tko je veci) * taj broj, druga strana ce biti 0 * broj = 0
    }

	/// amaterski nacin za template funkciju apsolutnaVrijednost
    //template<typename T>
    //T apsolutnaVrijednost(T a) {
    //    if (a < 0)   a *= -1;
    //    return a;
    //}

    /// <summary>
    ///		branchless template funkcija za apsolutnuVrijednost broja
    /// </summary>
    /// <typeparam name="T">tip podatka</typeparam>
    /// <param name="a">Broj za pretvorit</param>
    /// <returns>Pretvoreni broj</returns>
    template<typename T>
    T apsolutnaVrijednost(T a) {
        return a - a * (a < 0) - a * (a < 0);
    }

	/// amaterski nacin za palindrom funkciju
    //bool palindrom(std::string s) {
    //    std::string compare = "";
    //    for (int i = s.size() - 1; i > -1; i--) {
    //        compare += s[i];
    //    }
    //    return (s == compare);
    //}

    /// <summary>
    ///		Optimizirani nacin za provjeru je li rijec palindrom
    /// </summary>
    /// <param name="s">Rijec za provjerit</param>
    /// <returns>True/False</returns>
    bool palindrom(std::string_view s) 
    {
        uint8_t kraj = s.size();	// netreba veci podatkovni tip jer niti jedna rijec niju duza od 256 znakova
        uint8_t polovica = kraj / 2;
        for (uint8_t i = 0; true; ++i) 
        {
            if (s[i] != s[kraj - 1 - i]) return false;
            if (i == polovica)  return true;
        }  
    }