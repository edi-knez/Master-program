#pragma once

/// <summary>
///		Base klasa za informacije tocke u 2D prostoru
///		Sadrzi metode za postavljanje i citanje polozaja tocke
/// </summary>
class Tocka2D {
public:
    Tocka2D(double x, double y) : m_x(x), m_y(y) {};
    //  ~Tocka2D();
    void setX(double x);
    void setY(double y);
    double getX() const; 
    double getY() const;

protected:
    double m_x, m_y;
};