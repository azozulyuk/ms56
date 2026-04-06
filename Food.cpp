/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 4:4
Module: 4
Filename: Food.cpp
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
V1.0    2026/04/4  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function main,ect.
-----------------------------------------------------------
*/
#include "Food.h"
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
namespace seneca {
    Food::Food() {
        m_name[0] = '\0';
        m_price = 0.0;
        m_size = 0;
        m_instructions[0] = '\0';
    }
    ifstream& Food::read(ifstream& in) {
        in.getline(m_name, 51, ',');
        in >> m_price;
        in.ignore(1000, '\n');
        return in;
    }
    ostream& Food::print(ostream& os) const {
        os << m_name;

        int dots = 33 - strlen(m_name);
        if (dots < 0) dots = 0;

        for (int i = 0; i < dots; i++) os << '.';

        if (m_size == 1) os << "Adult";
        else if (m_size == 2) os << "Child";

        os << setw(7) << right << fixed << setprecision(2) << price();

        if (&os == &cout && m_instructions[0] != '\0') {
            os << " >> " << m_instructions;
        }

        return os;
    }
    bool Food::order() {
        cout << "         Food Size Selection" << endl;
        cout << "          1- Adult" << endl;
        cout << "          2- Child" << endl;
        cout << "          0- Back" << endl;
        cout << "         > ";
        cin >> m_size;
        if (m_size == 0) return false;
        cin.ignore(1000, '\n');
        cout << "Special instructions" << endl;
        cout << "> ";
        cin.getline(m_instructions, 100);
        return true;
    }
    double Food::price() const {
        if (m_size == 2) return m_price * 0.5;
        return m_price;
    }
    Billable* Food::clone() const {
        return new Food(*this);
    }
    const char* Food::name() const {
        return m_name;
    }
}
