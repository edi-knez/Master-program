#pragma once


class KlNiz {
public:
    KlNiz();
    ~KlNiz();
    int sumaNiza();
    int sumaNiza(int iA[]);

public:
    int operator[](int idx);


private:
    int* iA;
};