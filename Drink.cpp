/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 4:4
Module: 4
Filename: Drink.cpp
-----------------------------------------------------------
Author: Anastasiya Zozulyuk
Student number: 139,230,247
Email: azozulyuk@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/04/1  Completing code
V0.8    2025/04/4  Debugged
V0.9    -         Asked prof for help for XYZ
V1.0    2026/04/6  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function main,ect.
-----------------------------------------------------------
*/
#include "Drink.h"
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
namespace seneca {
    Drink::Drink() {
        m_name[0] = '\0';
        m_price = 0.0;
        m_size = 0;
    }

    ifstream& Drink::read(ifstream& in) {
        in.getline(m_name, 51, ',');
        in >> m_price;
        in.ignore(1000, '\n');
        return in;
    }
    ostream& Drink::print(ostream& os) const {
        os << m_name;

        int dots = 28 - strlen(m_name);
        if (dots < 0) dots = 0;

        for (int i = 0; i < dots; i++) os << '.';

        if (m_size == 1) os << "SML..";
        else if (m_size == 2) os << "MID..";
        else if (m_size == 3) os << "LRG..";
        else if (m_size == 4) os << "XLG..";

        os << setw(7) << right << fixed << setprecision(2) << price();

        return os;
    }
    bool Drink::order() {
        cout << "         Drink Size Selection" << endl;
        cout << "          1- Small" << endl;
        cout << "          2- Medium" << endl;
        cout << "          3- Larg" << endl;
        cout << "          4- Extra Large" << endl;
        cout << "          0- Back" << endl;
        cout << "         > ";
        cin >> m_size;
        if (m_size == 0) return false;
        return true;
    }
    double Drink::price() const {
        if (m_size == 1) return m_price * 0.5;
        if (m_size == 2) return m_price * 0.75;
        if (m_size == 3) return m_price;
        if (m_size == 4) return m_price * 1.5;
        return m_price;
    }
    Billable* Drink::clone() const {
        return new Drink(*this);
    }
    const char* Drink::name() const {
        return m_name;
    }
}
