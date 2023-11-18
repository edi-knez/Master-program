#include "Tocka2D.hpp"

/// <summary>
///		Implementacija metoda za postavljanje i citanje polozaja tocke u 2D prostoru
/// </summary>

void Tocka2D::setX(double x) {
    m_x = x;
}

void Tocka2D::setY(double y) {
    m_y = y;
}

double Tocka2D::getX() const {
    return m_x;
}

double Tocka2D::getY() const {
    return m_y;
}