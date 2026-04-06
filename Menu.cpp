/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 4:4 
Module: 4
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace seneca {
    Menu::Menu(const char* title, const char* exit, int indent) {
        strcpy(m_title, title);
        strcpy(m_exit, exit);
        m_indent = indent;
        m_count = 0;
    }
    Menu& Menu::operator<<(const char* item) {
        if (m_count < 20) {
            strcpy(m_items[m_count], item);
            m_count++;
        }
        return *this;
    }
      int Menu::run() const {
        int choice;

        for (int i = 0; i < m_indent; i++) cout << ' ';
        if (m_indent == 0)
            cout << m_title << " " << endl;
        else
            cout << m_title << endl;
        for (int i = 0; i < m_count; i++) {
            for (int j = 0; j < m_indent + 1; j++) cout << ' ';
            cout << (i + 1) << "- " << m_items[i] << endl;
        }

        for (int i = 0; i < m_indent + 1; i++) cout << ' ';
        cout << "0- " << m_exit << endl;

        if (m_indent > 0)
            for (int i = 0; i < m_indent; i++) cout << ' ';


        cout << "> ";

        cin >> choice;
        return choice;
    }
}
