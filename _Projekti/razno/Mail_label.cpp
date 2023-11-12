#include "Mail_label.hpp"

std::ostream& operator<<( std::ostream& out, const Mail_label& mlab )
{
    out << "ID: " << mlab.m_data[0] << "\nFrom: " << mlab.m_data[1] << "\nTo: " << mlab.m_data[2] << "\nStreet: " << mlab.m_data[3]
        << "\nState: " << mlab.m_data[4] << "\n\n";
    return out;
}

std::istream& operator>>( std::istream& in, Mail_label& mlab )
{
    std::cout << "Unesi ID: ";
    std::cin >> mlab.m_data[0];
    std::cout << "Unesi From: ";
    std::cin >> mlab.m_data[1];
    std::cout << "Unesi To: ";
    std::cin >> mlab.m_data[2];
    std::cout << "Unesi Street: ";
    std::cin >> mlab.m_data[3];
    std::cout << "Unesi State: ";
    std::cin >> mlab.m_data[4];
    return in;
}

