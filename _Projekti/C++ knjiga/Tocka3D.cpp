#include "Tocka3D.hpp"

/// <summary>
///		Postavi podatkovni clan na novu vrijednost
/// </summary>
/// <param name="z">nova vrijednost</param>
void Tocka3D::setZ(double z) {
    m_z = z;
}

/// <summary>
///		Pogledaj vrijednost privatnog podatkovnog clana
/// </summary>
/// <returns>m_z podatkovni clan</returns>
double Tocka3D::getZ() const {
    return m_z;
}

/// <summary>
///		overload operator == za usporedit da li se dvije tocke u 3D prostoru nalaze na istom mjestu
/// </summary>
/// <param name="t">tocka koju usporedujes</param>
/// <returns>True/False</returns>
bool Tocka3D::operator== (const Tocka3D& t) const {
    return (sqrt(pow(m_x - t.m_x, 2) + pow(m_y - t.m_y, 2) + pow(m_z - t.m_z, 2)) == 0);
}

/// <summary>
///		operator overload operatora = da jednostavno moze postavit tocku na novu vrijednost
/// </summary>
/// <param name="t">Nova pozicija tocke</param>
/// <returns>*this objekt, omogucuje chainanje</returns>
Tocka3D& Tocka3D::operator= (const Tocka3D& t) {
    m_x = t.m_x;
    m_y = t.m_y;
    m_z = t.m_z;

    return *this;
}

/// <summary>
///		overload operator < , jednostavno ispisivanje polozaj tocke na konzolu
/// </summary>
/// <param name="os">ouput strean objekt</param>
/// <param name="t">zeljena tocka</param>
/// <returns>output stream, omogucuje chainanje</returns>
std::ostream& operator<<(std::ostream& os, const Tocka3D& t)
{
    return (os << "(" << t.getX() << "," << t.getY() << "," << t.getZ() <<")");
}