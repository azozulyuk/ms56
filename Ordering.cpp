/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 4:4
Module: 4
Filename: Ordering.cpp
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

#include "Ordering.h"
#include "Food.h"
#include "Drink.h"
#include "Utils.h"
#include "Billable.h"
#include "Menu.h"
#include <fstream>
#include <iomanip>
#include "constants.h"
using namespace std;

namespace seneca {

    size_t Ordering::countRecords(const char* file) const {
        size_t count = 0;
        ifstream fin(file);
        char ch;
        while (fin.get(ch)) {
            if (ch == '\n') count++;
        }
        return count;
    }

    Ordering::Ordering(const char* drinkF, const char* foodF) {
        m_counter_food = 0;
        m_counter_drink = 0;
        m_counter_billable = 0;
        m_bilSerialNum = 1;
        m_hasBill = false;

        m_foods = nullptr;
        m_drinks = nullptr;

        for (unsigned int i = 0; i < MaximumNumberOfBillItems; i++) {
            m_billItems[i] = nullptr;
        }

        ifstream foodFile(foodF);
        ifstream drinkFile(drinkF);

        if (!drinkFile || !foodFile) {
            return;
        }

        size_t drinkCount = countRecords(drinkF);
        size_t foodCount = countRecords(foodF);

        m_drinks = new Drink[drinkCount];
        m_foods = new Food[foodCount];

        size_t i;
        for (i = 0; i < drinkCount; i++) {
            if (!m_drinks[i].read(drinkFile)) break;
        }
        if (i != drinkCount) {
            delete[] m_drinks;
            delete[] m_foods;
            m_drinks = nullptr;
            m_foods = nullptr;
            return;
        }

        for (i = 0; i < foodCount; i++) {
            if (!m_foods[i].read(foodFile)) break;
        }
        if (i != foodCount) {
            delete[] m_drinks;
            delete[] m_foods;
            m_drinks = nullptr;
            m_foods = nullptr;
            return;
        }

        m_counter_drink = drinkCount;
        m_counter_food = foodCount;
    }

    Ordering::~Ordering() {
        delete[] m_foods;
        delete[] m_drinks;
        for (unsigned int i = 0; i < m_counter_billable; i++) {
            delete m_billItems[i];
        }
    }

    bool Ordering::isEmpty() const {
        return m_counter_food == 0 || m_counter_drink == 0;
    }

    Ordering::operator bool() const {
        return m_counter_food > 0 && m_counter_drink > 0;
    }

    bool Ordering::hasUnsavedBill() const {
        return m_counter_billable > 0;
    }

    void Ordering::printBillTitle(ostream& os) const {
        os << "Bill # ";
        os << setw(3) << setfill('0') << m_bilSerialNum;
        os << setfill(' ');
        os << " =============================" << endl;
    }

    void Ordering::printAmount(ostream& os, double total) const {
        double tax = total * Tax;
        double grand = total + tax;

        os << "                     Total:         "
            << fixed << setprecision(2) << total << endl;

        os << "                     Tax:           "
            << tax << endl;

        os << "                     Total+Tax:     "
            << grand << endl;

        os << "========================================" << endl;
    }

    void Ordering::listFoods() const {
        cout << "List Of Avaiable Meals" << endl;
        cout << "========================================" << endl;
        for (unsigned int i = 0; i < m_counter_food; i++) {
            m_foods[i].print(cout);
            cout << endl;
        }
        cout << "========================================" << endl;
    }

    void Ordering::listDrinks() const {
        cout << "List Of Avaiable Drinks" << endl;
        cout << "========================================" << endl;
        for (unsigned int i = 0; i < m_counter_drink; i++) {
            m_drinks[i].print(cout);
            cout << endl;
        }
        cout << "========================================" << endl;
    }
    void Ordering::orderFood() {

        Menu foodMenu("Food Menu", "Back to Order", 6);

        for (unsigned int i = 0; i < m_counter_food; i++) {
            foodMenu << m_foods[i].name();
        }

        int choice = foodMenu.run();

        if (choice != 0) {

            Billable* item = m_foods[choice - 1].clone();

            if (item->order()) {  

                m_billItems[m_counter_billable] = item;
                m_counter_billable++;
                m_hasBill = true;

            }
            else {
                delete item;
            }
        }
    }

    void Ordering::orderDrink() {

        Menu drinkMenu("Drink Menu", "Back to Order", 6);
        drinkMenu << "Pepsi" << "Orange Juice" << "Coffee";

        int popChoice = drinkMenu.run();

        if (popChoice != 0) {

            Billable* item = m_drinks[popChoice - 1].clone();

            if (item->order()) {
                m_billItems[m_counter_billable++] = item;
                m_hasBill = true;
            }
            else {
                delete item;
            }
        }
    }

    void Ordering::printBill(ostream& os) const {
        double total = 0.0;
        printBillTitle(os);

        for (unsigned int i = 0; i < m_counter_billable; i++) {
            m_billItems[i]->print(os);
            os << endl;
            total += m_billItems[i]->price();
        }

        printAmount(os, total);
    }

    void Ordering::resetBill() {

        if (m_counter_billable > 0) {
            char filename[50];
            ut.makeBillFileName(filename, m_bilSerialNum);

            ofstream file(filename);
            printBill(file);

            cout << "Saved bill number " << m_bilSerialNum << endl;
                m_bilSerialNum++;   
        }
        cout << "Starting bill number " << m_bilSerialNum << endl;
for (unsigned int i = 0; i < m_counter_billable; i++) {
            delete m_billItems[i];
            m_billItems[i] = nullptr;
        }

        m_counter_billable = 0;
    }
} 
