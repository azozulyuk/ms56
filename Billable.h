/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 4:4
Module: 4
Filename: Billable.h
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
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include <iostream>

namespace seneca {

    class Billable {
    public:
        virtual ~Billable() {}

        virtual std::ostream& print(std::ostream& os) const = 0;
        virtual bool order() = 0;
        virtual double price() const = 0;
        virtual Billable* clone() const = 0;
    };

}

#endif