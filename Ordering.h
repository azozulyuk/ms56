/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 4:4
Module: 4
Filename: Ordering.h
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

#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H
#include <iostream>
#include "Food.h"
#include "Drink.h"
#include "constants.h"
#include "Billable.h"
#include "Utils.h"


namespace seneca {
	class Ordering {
		unsigned int m_counter_food;
		unsigned int m_counter_drink;
		unsigned int m_counter_billable;
		unsigned int m_bilSerialNum;

		Food* m_foods;    
		Drink* m_drinks;


		Billable* m_billItems[MaximumNumberOfBillItems];


	private:
		void printBillTitle(std::ostream& os) const;
		void printAmount(std::ostream& os, double total) const;
		size_t countRecords(const char* file) const;


	public:
		void printBill(std::ostream& os) const;
		void resetBill();
		void orderFood();   
		void orderDrink();
		bool hasUnsavedBill() const;
		Ordering(const char* drinkF, const char* foodF);
		~Ordering();

		operator bool() const;
		bool isEmpty() const;

		void listFoods() const;
		void listDrinks() const;
		size_t noOfBillItems() const {
			return m_counter_billable;
		}
	};
}
#endif