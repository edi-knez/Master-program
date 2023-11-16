#include "iarray.hpp"

/// <summary>
///		Koristi init funkciju da smanji ponavljanje koda u konstruktorima
/// </summary>
/// <param name="array"></param>
/// <param name="size"></param>
void iarray::init(const int* array, int size) {
    m_size = size;
    m_arr = new int[size];

    if (array != 0) 
    {
        for (int index = 0; index < size; index++)
        {
            m_arr[index] = array[index];
        }
    }
}

iarray& iarray::operator= (const iarray& rhs) {
    if (this != &rhs) {	// sprijeci brisanje memorije ako se slucajno objekt pridruzi sam sebi
        delete[] m_arr;
        init(rhs.m_arr, rhs.m_size);
    }
    return *this;
}

/// <summary>
///		Operator oveload za += , ali gubi se sadrzaj niza [[BUG]]
/// </summary>
/// <param name="size">zeljena velicina</param>
/// <returns></returns>
iarray& iarray::operator+= (const int& size) {
    delete m_arr;
    m_size += size;
    init(m_arr, m_size);
    return *this;
}