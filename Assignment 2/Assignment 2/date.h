//Ryan Milrad
//DATE.H file
//Assignment 2
//September 15, 2020

/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Ryan Milrad
TOTAL POINTS:  25
DUE DATE:  09/16/2020
COURSE:  COP 3530
Assignment Name:  Assignment#2
Professor:  Dr. Bullard

Description:  Header file for date assignment
******************************************************************************************************************************************************/

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date {
public:
	Date(); //default constructor
	Date(unsigned m, unsigned d, unsigned y); //explicit value constructor
	void display(); //prints the date in MM/DD/YYYY format
	int getMonth(); //accessor function to get the month
	int getDay(); //accessor function to get the day
	int getYear(); //accessor function to get the year
	void setMonth(int m); //mutator function to set the month
	void setDay(unsigned d); //mutator function to set the day	
	void setYear(unsigned y); //mutator function to set the year
	bool checkMonth(); //function to check if a given month is valid
	bool checkDay(); //function to check if a given day is valid
	bool checkYear(); //function to check if a given year is valid
	friend ostream& operator<<(ostream& out, Date& dateObj); //overload operator << with chaining. Prints the date in given output

private:
	int myMonth, myDay, myYear; //private variables to store the month, day and year for a date
};

#endif DATE_H