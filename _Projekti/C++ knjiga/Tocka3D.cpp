#include "Tocka3D.hpp"


void Tocka3D::setZ(double z) {
    m_z = z;
}

double Tocka3D::getZ() const {
    return m_z;
}

bool Tocka3D::operator== (const Tocka3D& t) const {
    return (sqrt(pow(m_x - t.m_x, 2) + pow(m_y - t.m_y, 2) + pow(m_z - t.m_z, 2)) == 0);
    //if
    //    return true;
    //else
    //    return false;
}

Tocka3D& Tocka3D::operator= (const Tocka3D& t) {
    m_x = t.m_x;
    m_y = t.m_y;
    m_z = t.m_z;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Tocka3D& t)
{
    return (os << "(" << t.getX() << "," << t.getY() << "," << t.getZ() <<")");
}