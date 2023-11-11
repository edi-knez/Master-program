#include <iostream>
#include <string>
#include <cstdlib>


static void no_mem() {
    std::cout << "Greska pri alokaciji memorije!" << std::endl;
    exit(1);
}

static void my_copy_char(const char* source, char* destination, uint8_t length) {
    for (uint8_t i = 0; i < length; ++i)
    {
        destination[i] = source[i];
    }
    destination[length] = '\0';
}

void bonus()
{
    char** txt;
    int maxSize = 5;
    int numStrings = 0;
    char str[256] = { "\0" };

    std::set_new_handler(no_mem);

    txt = new char* [maxSize];

    while (true) 
    {
        std::cin.getline(str, 255, '\n');
        int len = strlen(str);
        if (str[0] == '\0') break; // samo se enter stisnuo
        char* s = new char[len + 1];
        //strcpy_s(s, len, str);
        my_copy_char(str, s, len);
        std::cout << "\n s = " << s << '\n';
        txt[numStrings] = s;
        numStrings++;
        if (numStrings >= maxSize) 
        {
            char** p = new char* [maxSize + 5];
            ////std::cout << "\ntxt:\n";
            ////for (int i = 0; i < numStrings; i++) {
            ////    std::cout << txt[i] << "\n";
            ////}
            ////std::cout << '\n';

            // prekopiraj adrese u novo alocirani blok memorije
            memcpy(p, txt, numStrings * sizeof(char*));
            //for (int i = 0; i < numStrings; i++) {
            //    p[i] = txt[i];
            //}
            delete[] txt;
            txt = p;
            maxSize += 5;
            ////std::cout << "\nPoslje p:\n";
            ////for (int i = 0; i < numStrings; i++) {
            ////    std::cout << txt[i] << "\n";
            ////}
            ////std::cout << '\n';
        }
    }
    std::cout << "Unos zavrsen\n";  

    for (int i = 0; i < numStrings; i++) {
        std::cout << txt[i] << '\n';
        delete txt[i];
    }
    delete[] txt;
}
