#pragma once

const int def_iarray_size = 5;

class iarray {
public:
    iarray(int def_size = 5) {
        init((const int*)0, def_size);
        //init(nullptr, def_size);
    }

    iarray(const iarray& rhs) {
        init(rhs.m_arr, rhs.m_size);
    }

    iarray(const int* array, int size) {
        init(array, size);
    }

    ~iarray(void) {
        delete[] m_arr;
    }

    iarray& operator= (const iarray& rhs);
    iarray& operator+= (const int& size);
    int size() { return m_size; }
    int& operator[] (int index) { return m_arr[index]; }
    const int& operator[] (int index) const { return m_arr[index]; }

private:
    void init(const int* array, int size);
    int* m_arr;
    int m_size;

};


