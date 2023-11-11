#include "iarray.h"


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
    if (this != &rhs) {
        delete[] m_arr;
        init(rhs.m_arr, rhs.m_size);
    }
    return *this;
}

iarray& iarray::operator+= (const int& size) {
    delete m_arr;
    m_size += size;
    init(m_arr, m_size);
    return *this;
}