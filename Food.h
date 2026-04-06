/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 4:4
Module: 4
Filename: Food.h
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
#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

#include <iostream>
#include "Billable.h"

namespace seneca {

    class Food : public Billable {
        char m_name[51];
        double m_price;
        int m_size;              
        char m_instructions[101];


    public:
        Food();

        std::ostream& print(std::ostream& os) const;
        bool order();
        double price() const;
        Billable* clone() const;

        std::ifstream& read(std::ifstream& in);
        const char* name() const;
    };

}

#endif