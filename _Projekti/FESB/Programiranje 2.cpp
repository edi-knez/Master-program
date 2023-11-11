#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <conio.h>


//int main()
//{
    /* -------------------------------------------------------  Vježba 1: --------------------------------------------------- */
    /*
    1. Napisati program koji definira 4 varijable(char, int, float, double).Ispisati sve četiri varijable, 
    zajedno s njihovim adresama i izračunati koliko su bajtova u memoriji sve te varijable zajedno zauzele.
    */

    //char a = 'a';
    //int b = 5;
    //float c = 6.4;
    //double d = 7.444444444;
    //int mem = sizeof(a) + sizeof(b) + sizeof(c) + sizeof(d);
    //printf("%c %p\n", a, &a);
    //printf("%d %p\n", b, &b);
    //printf("%f %p\n", c, &c);
    //printf("%e %p\n", d, &d);
    //printf("Varijable su zauzele %d bajtova\n", mem);

    /*
    2. Napisati program koji definira 3 varijable tipa znak. Prvoj dodijeliti znak 0, drugoj dodijeliti znak 9, 
    a treću izraču nati kao sumu prve dvije. Ispisati sva tri znaka kao znak i kao ASCII vrijednosti.
    */

    //char a = '0', b = '9', c = a + b;
    //printf("a: %c b: %c c: %c\n", a, b, c);
    //printf("a: %d b: %d c: %d\n", a, b, c);

    /*3.
    Napisati program koji računa sumu, produkt, razliku i kvocijent dva cijela broja.Ispisati sve rezultate na ekran.
    */

    //int a = 15, b = 5;
    //printf("suma: %d\n", a + b);
    //printf("razlika: %d\n", a - b);
    //printf("produkt: %d\n", a * b);
    //printf("kvocijent: %d\n", a / b);

    /*
    4. Napisati program koji računa sumu prvih 50 brojeva.
    */

    //int suma = 0;
    //for (int i = 0; i < 50; i++)
    //    suma += i;
    //printf("suma: %d\n", suma);

    /*5. 
    Napisati program koji na ekran ispisuje: 
    E E E E E 
    D D D D 
    C C C 
    B B 
    A
    U programu je dozvoljeno koristiti najviše 2 printf() naredbe.*/

    //char slovo = 'E';
    //for (int i = 0; i < 5; i++) {
    //    for (int j = i; j < 5; j++) {
    //        printf("%c ", slovo - i);
    //    }
    //    printf("\n");
    //}


    /*---------------------------------------------------------  Vježba 2: ------------------------------------------------*/
    /*
    1. Napisati program koji pretvara uneseni realni broj u cijeli na način da ako je prva znamenka iza decimalne točke >= 5 
    zaokružuje se na prvi veći. Program mora raditi i za pozitivne i za negativne brojeve.
    */

    //int cijeliBr;
    //float realniBr;
    //printf("unesi realni broj: ");
    //scanf_s("%f", &realniBr);
    //cijeliBr = ( (int)(realniBr * 10) % 10 >= 5 ) ? realniBr + 1 : realniBr;
    //printf("cijeli broj: %d\n", cijeliBr);

    /*
    2. Napisati program koji unosi 10 brojeva ali na ekran ispisuje samo neparne. Broj se ispisuje čim je unesen.
    */

    //int broj, brojac = 0;
    //while (brojac < 10) {
    //    printf("unesi broj: ");
    //    scanf_s("%d", &broj);
    //    if (broj % 2 == 1) {
    //        printf("%d\n", broj);
    //    }
    //    brojac++;
    //}

    /*
    3. Napisati program koji unosi 10 brojeva i računa koliko ih je djeljivo s 3.
    */

    //int broj, brojac = 0, brojacNeparan = 0;
    //while (brojac < 10) {
    //  printf("unesi broj: ");
    //  scanf_s("%d", &broj);
    //  if (broj % 3 == 0) {
    //      brojacNeparan++;
    //  }
    //  brojac++;
    //}
    //printf("%d broja je djeljivo sa 3\n", brojacNeparan);

    /*
    4. Napisati program koji unosi 10 znakova i računa koliko ih je uneseno: a) malim slovima;
                                                                             b) koliko ih je = H.
    */

    //char slovo;
    //int  brojac = 0, brojac_MalihSlova = 0, brojac_H = 0;
    //while (brojac < 10) {
    //  printf("unesi slovo: ");
    //  scanf_s(" %c", &slovo, 2);
    //  printf("\n");
    //  if (slovo >= 'a' && slovo <= 'z') {
    //     brojac_MalihSlova++;
    //  }
    //  else if (slovo == 'H') {
    //      brojac_H++;
    //  }
    //  brojac++;
    //}
    //printf("\nMalih slova ima: %d\nNjih %d je bilo = H", brojac_MalihSlova, brojac_H);

    /*
    5. Napisati program koji unosi bodove kolokvija za 5 učenika (između 0 i 100) te računa koliko je učenika prošlo (više od 50) 
    i koliki je prosječni broj bodova.
    */
    
    //int bodovi, sumaBodova = 0, prolaz = 0;
    //const int ucenici = 5;
    //for (int i = 0; i < ucenici; i++) {
    //    printf("Unesi bodove %d. ucenika\n", i + 1);
    //    scanf_s("%d", &bodovi);
    //    if (bodovi > 50)
    //        prolaz++;
    //    sumaBodova += bodovi;
    //}
    //printf("Kolokvij je proslo %d ucenika\nProsjecni broj bodova je %d\n", prolaz, sumaBodova / ucenici);


    /*------------------------------------------------      Vježba 3     --------------------------------------------------  */
    /*
    1. Napisati program koji računa aritmetičku sumu brojeva. Nije unaprijed poznato koliko će se brojeva unijeti, 
    program prestaje s radom kad se unese 0, ali nju netreba računati za prosjek.
    */

    //int broj, suma = 0, brojac = 0;
    //printf("Unesi brojeve razlicite od 0 za daljnji unos\n");
    //do
    //{
    //    scanf_s("%d", &broj);
    //    if (broj != 0) {
    //        suma += broj;
    //        brojac++;
    //    }
    //    else {
    //        break;
    //    }
    //    
    //} while (1);

    //printf("Arihmeticka sredina: %f", (float)suma / brojac);

    /*
    2. Napisati program koji uneseni cijeli broj razbija na dekadske znamenke. Potrebno je ispisati svaku znamenku 
    posebno i to u obrnutom redoslijedu.
    Npr. broj 4893 je potrebno ispisati kao 3 9 8 4
    */
    
    //int broj, reverseBroj = 0;
    //printf("Unesi broj: ");
    //scanf_s("%d", &broj);
    //while (broj > 0) {
    //    reverseBroj += broj % 10;
    //    reverseBroj *= 10;
    //    broj /= 10;
    //}
    //reverseBroj /= 10;
    //printf("Obrnuti redoslijed znamenaka: %d\n", reverseBroj);

    /*
    3. Napisati program koji generira slučajni broj i korisnik pogađa o kojem se broju radi. 
    Program svaki put treba javiti je li uneseni broj > ili < od generiranog. Pogađanje traje sve dok se broj ne pogodi. 
    Potrebno je ispisati iz kojeg je puta broj pogođen.
    */

    //int generiraniBroj, korisnikBroj, pokusaj = 0;
    //srand((unsigned)time(NULL));
    //generiraniBroj = rand() % 1000;
    //do {
    //    printf("Unesi broj o kojem mislis da odgovara izabranom broju: ");
    //    scanf_s("%d", &korisnikBroj);
    //    printf("\n");

    //    pokusaj++;
    //    if (korisnikBroj > generiraniBroj) {
    //        printf("Generirani broj je manji od unesenog!\n");
    //    }
    //    else if (korisnikBroj < generiraniBroj) {
    //        printf("Generirani broj je veci od unesenog!\n");
    //    }
    //    else {
    //        printf("Pogodak iz %d. pokusaja!\n", pokusaj);
    //        break;
    //    }
    //} while (1);

    /*
    4. Napisati program koji ispisuje sve primitivne brojeve od 0 – 100.
    */

    //for (int i = 1; i < 101; i++) {
    //    bool primitivan = false;
    //    for (int j = 2; j < i / 2 + 1 ; j++) {
    //        if (i % j == 0) {
    //            primitivan = true;
    //            break;
    //        }
    //    }
    //    if (primitivan)
    //        printf("Broj %d je primitivan\n", i);
    //}


    /*-------------------------------------------------------     Vjezba 4    ---------------------------------------------------------*/
    /*
    1. Napisati program koji s tastature unosi dva cijela broja i matematičku operaciju
    (+, -, * ili /). Ovisno o operaciji je potrebno izračunati i ispisati rezultat.
    */

    //int broj, broj2;
    //char operacija = 0;
    //while (!operacija) {
    //    printf("Unesi broj: ");
    //    scanf_s("%d", &broj);
    //    printf("Unesi operaciju: ");
    //    scanf_s(" %c", &operacija, 2);
    //    printf("Unesi broj: ");
    //    scanf_s("%d", &broj2);
    //    switch (operacija)
    //    {
    //    case '+':
    //        printf("Rezultat operacije %d %c %d = %d", broj, operacija, broj2, broj + broj2);
    //        break;
    //    case '-':
    //        printf("Rezultat operacije %d %c %d = %d", broj, operacija, broj2, broj - broj2);
    //        break;
    //    case '*':
    //        printf("Rezultat operacije %d %c %d = %d", broj, operacija, broj2, broj * broj2);
    //        break;
    //    case '/':
    //        printf("Rezultat operacije %d %c %d = %d", broj, operacija, broj2, broj / broj2);
    //        break;
    //    case '^':
    //    {
    //        int rezultat = pow(broj, broj2);
    //        printf("Rezultat operacije %d %c %d = %d", broj, operacija, broj2, rezultat);
    //    }
    //        break;
    //    case '%':
    //        printf("Rezultat operacije %d %c %d = %d", broj, operacija, broj2, broj % broj2);
    //        break;
    //    case '<':
    //        printf("Jednakost %d %c %d je %s", broj, operacija, broj2, (broj < broj2) ? "tocna" : "netocna");
    //        break;
    //    case '>':
    //        printf("Jednakost %d %c %d je %s", broj, operacija, broj2, (broj > broj2) ? "tocna" : "netocna");
    //        break;
    //    default:
    //        printf("Kriv unos, pokusaj ponovno\n");
    //        operacija = 0;
    //        break;
    //    }
    //}
   
    /*
    2. Napisati program koji unosi 20 rezultata ocjena s kolokvija (sprema ih u niz). Ocjene mogu biti od 1-5 i 
    ako se unese krivi broj unos se ponavlja. Kada su ocjene unesene program
    računa histogram ocjena u 5 grupa (koliko je bilo kojih ocjena) i ispisuje ga na ekran.
    */
    
    /*int ocjeneKolokvija[20];
    int petice = 0, cetvorke = 0, trojke = 0, dvojke = 0, jedinice = 0;
    int ocjena = 0;
        printf("Unesi 20 ocjena\n");
        for(int i = 0; i < 20; i++) {
            while (ocjena < 1 || ocjena > 5) {
                printf("Unesi ocjenu (1-5): ");
                scanf_s("%d", &ocjena);
            }
            ocjeneKolokvija[i] = ocjena;
            switch (ocjena)
            {
            case 5:
                petice++;
                break;
            case 4:
                cetvorke++;
                break;
            case 3:
                trojke++;
                break;
            case 2:
                dvojke++;
                break;
            default:
                jedinice++;
                break;
            }
            ocjena = 0;
        }
        printf("5 - %d\n4 - %d\n3 - %d\n2 - %d\n1 - %d", petice, cetvorke, trojke, dvojke, jedinice);*/

    /*
    3. Napisati program koji za uneseni niz od 10 cijelih brojeva: 
    a) traži najmanji element niza;
    b) traži najveći element niza;
    c) sortira niz od najmanjeg prema najvećem elementu.
    Napomena: najmanji i najveći element niza se ne smiju samo ispisati nakon
    sortiranja. Potrebno ih je pronaći prije sortiranja.
    */

    //int niz[10];
    //int broj;
    //for (int i = 0; i < 10; i++) {
    //    printf("Unesi broj: ");
    //    scanf_s("%d", &broj);
    //    niz[i] = broj;
    //}
    //int min = niz[0], max = niz[0];
    //for (int i = 1; i < 10; i++) {
    //    if (min > niz[i])
    //        min = niz[i];

    //    if (max < niz[i])
    //        max = niz[i];
    //}

    //for (int i = 0; i < 10; i++) {
    //    for (int j = i; j < 10; j++) {
    //        if (niz[i] > niz[j]) {
    //            int temp = niz[i];
    //            niz[i] = niz[j];
    //            niz[j] = temp;
    //        }
    //    }
    //}
    //printf("min: %d\nmax: %d\n", min, max);
    //for (int i = 0; i < 10; i++) {
    //    printf("%d ", niz[i]);
    //}


    /*  ------------------------------------------------------  Vježba 5    ---------------------------------------------------
    /*
    1. Napravi program koji uzima znakove s tastature (sa ili bez prikaza tih znakova na
    ekranu) sve dok se ne unese znak ESC. Tada se izlazi iz programa.
    */

    //char znak = 0;
    //while(znak != 27)
    //znak = _getche();

    /*
    2. Napravit program koji iz unesenog stringa stvara novi (u novoj varijabli), na način da iz prvog prebaci sve znakove osim brojeva.
    */

    //char str1[20] = { 0 };
    //char str2[20] = { 0 };
    //printf("Unesi tekst u varijablu: ");
    //scanf(" %s", &str1);
    //for (int i = 0; str1[i] != '\0'; i++) {
    //    if (!(isdigit(str1[i]))) {
    //        str2[i] += str1[i];
    //    }
    //    else {
    //        str2[i] += ' ';
    //    }
    //}
    //printf("str1: %s\nstr2: %s", str1, str2);

    /*
    3. Napraviti program koji uneseni string mijenja u 3 koraka i rezultat svakog ispisati. Smije se koristiti samo jedan string.
    a) U stringu trebaju ostati samo slova.  -> (pise "samo slova" ali nemoze se ostavit prazan znak '', razmak smije bit ' ')? linija 408
    b) Iz tog stringa treba izbaciti sve samoglasnike (velika i mala slova).
    c) Sva velika slova pretvoriti u mala i obrnuto.
    */
    
    //char str[20] = { 0 };
    //printf("Unesi tekst: ");
    //scanf(" %s", &str);
    //for (int i = 0; str[i] != '\0'; i++) {
    //    if(isdigit(str[i]))
    //        str[i] = ' ';
    //}
    //printf("str: %s\n", str);
    //for (int i = 0; str[i] != '\0'; i++) {
    //    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
    //        str[i] = ' ';
    //}
    //printf("str: %s\n", str);
    //for (int i = 0; str[i] != '\0'; i++) {
    //    if (islower(str[i]))
    //        str[i] = str[i] - 'a' + 'A';
    //    else if (isupper(str[i]))
    //        str[i] = str[i] - 'A' + 'a';
    //}
    //printf("str: %s\n", str);

    /*
    4. Napravi program koji unesenu dekadsku vrijednost pretvara u heksadecimalnu, s tim da je znamenke potrebno 
    ispisati svaku u svom redu i to u pravom rasporedu.
    */

    //unsigned int deka;
    //const int A = 10, B = 11, C = 12, D = 13, E = 14, F = 15;
    //char heksa[9] = { '0', '0', '0', '0', '0', '0', '0', '0', '\0' };
    //int pozicija = 0;
    //printf("Unesi dekadski broj: ");
    //scanf_s("%d", &deka);
    //while(deka > 0) {
    //    int temp = deka % 16;
    //    switch (temp)
    //    {
    //    case A:
    //        heksa[pozicija] = 'A';
    //        break;
    //    case B:
    //        heksa[pozicija] = 'B';
    //        break;
    //    case C:
    //        heksa[pozicija] = 'C';
    //        break;
    //    case D:
    //        heksa[pozicija] = 'D';
    //        break;
    //    case E:
    //        heksa[pozicija] = 'E';
    //        break;
    //    case F:
    //        heksa[pozicija] = 'F';
    //        break;
    //    default:
    //        heksa[pozicija] = temp + '0';
    //        break;
    //    }
    //    pozicija++;
    //    deka /= 16;
    //}
    //for (int i = 7; i >= 0; i--)
    //    printf("%c\n", heksa[i]);


    /*-------------------------------------------------     Vježba 6    --------------------------------------------------------*/
    /*
    1. Napisati program koji unosi jednu matricu (A dimenzija 3x3) i iz te matrice
    računa matricu B = 5*A. Matricu B je potrebno ispisati.
    */

    //int A[3][3], B[3][3];
    //int broj;
    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
    //        printf("A[%d][%d]: ", i, j);
    //        scanf("%d", &broj);
    //        A[i][j] = broj;
    //        B[i][j] = 5 * A[i][j];
    //    }
    //}
    //printf("matrica B\n");
    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
    //        printf("%d ", B[i][j]);
    //    }
    //    printf("\n");
    //}

    /*
    2. Napisati program koji unosi jednu matricu (A dimenzija 3x3) i iz te matrice stvara matricu B = AT. Matricu B je potrebno ispisati.
    */

    //int A[3][3], B[3][3];
    //int broj;
    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
    //        printf("A[%d][%d]: ", i, j);
    //        scanf("%d", &broj);
    //        A[i][j] = broj;
    //    }
    //}

    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
    //        B[i][j] = A[j][i];
    //    }
    //}

    //printf("matrica B\n");
    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
    //        printf("%d ", B[i][j]);
    //    }
    //    printf("\n");
    //}

    /*
    3. Napisati program koji unosi dvije matrice (A i B dimenzija 3x3), a zatim računa matricu C = A + B i 
    matricu D = A * B. Matrice C i D je potrebno ispisati.
    */

    //int A[3][3], B[3][3], C[3][3], D[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    //int broj;
    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
    //        printf("A[%d][%d]: ", i, j);
    //        scanf("%d", &broj);
    //        A[i][j] = broj;
    //        printf("B[%d][%d]: ", i, j);
    //        scanf("%d", &broj);
    //        B[i][j] = broj;
    //    }
    //}

    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
    //        C[i][j] = A[i][j] + B[i][j];
    //    }
    //}
    //

    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
    //        for (int k = 0; k < 3; k++) {
    //            D[i][j] += A[i][k] * B[k][j];
    //        }
    //    }
    //}

    //printf("matrica C\n");
    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
    //        printf("%d ", C[i][j]);
    //    }
    //    printf("\n");
    //}
    //printf("matrica D\n");
    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
    //        printf("%d ", D[i][j]);
    //    }
    //    printf("\n");
    //}

    /*
    4. Napisati program koji unosi 5 imena i zatim:
    a) pronalazi indeks imena prvog po abecedi, te ispisuje indeks i ime; 
    b) pronalazi indeks imena zadnjeg po abecedi, te ispisuje indeks i ime; 
    c) sortira imena po abecedi i ispisuje ih.
    Pri tome rezultati pretraživanja ne smiju razlikovati velika i mala slova, tj. bez obzira je li ime uneseno
    velikim ili malim slovom treba biti na ispravnom mjestu po abecedi.
    */

    //char imena[5][20];
    //for (int i = 0; i < 5; i++) {
    //    printf("Unesi %d. ime: ", i + 1);
    //    gets_s( imena[i]);
    //}

    //int idx1 = 0, idx2 = 0;
    //for (int i = 0; i < 4; i++) {
    //    idx1 = (_strcmpi(imena[i + 1], imena[idx1]) < 0) ? i+1 : idx1;
    //    if (_strcmpi(imena[i + 1], imena[idx2]) > 0) {
    //        idx2 = i+1;
    //    }

    //}
    //printf("Prvi po abecedi je: %s, index: %d\nZadnji po abecedi je: %s, index: %d\n", imena[idx1], idx1, imena[idx2], idx2);
    
//}

