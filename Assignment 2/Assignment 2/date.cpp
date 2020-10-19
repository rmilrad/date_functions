//Ryan Milrad
//DATE.CPP file
//September 15, 2020
//Assignment 2

/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Ryan Milrad
TOTAL POINTS:  25
DUE DATE:  09/16/2020
COURSE:  COP 3530
Assignment Name:  Assignment#2
Professor:  Dr. Bullard

Description:  Declaration CPP file for date assignment
******************************************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include "date.h"
using namespace std;

//checks month if valid
bool Date::checkMonth() {
	if (myMonth < 1 || myMonth > 12) {
		return false;
	}
	else
		return true;
}

//checks day if valid, includes leap year calculation
bool Date::checkDay() {
	if (myDay < 1) {
		return false;
	}
	else if (myDay > 31) {
		return false;
	}
	if ((myMonth == 1) || (myMonth == 3) || (myMonth == 5) || (myMonth == 7) || (myMonth == 8) || (myMonth == 10) || (myMonth == 12)) {
		if ((myDay < 1 || myDay > 31)) {
			return false;
		}
	}
	else if ((myMonth == 4) || (myMonth == 6) || (myMonth == 9) || (myMonth == 11)) {
		if ((myDay < 1 || myDay > 30)) {
			return false;
		}
	}
	else if (myMonth == 2) {
		if ((myYear % 4 != 0) || ((myYear % 4 == 0) && (myYear % 100 == 0) && (myYear % 400 != 0))) {
			if (myDay > 28) {
				return false;
			}
		}
		else if (((myYear % 4 == 0) && (myYear % 100 == 0) && (myYear % 400 == 0)) || ((myYear % 4 == 0) && (myYear % 100 != 0))) {
			if (myDay > 29) {
				return false;
			}
			else {
				cout << "Leap Year" << endl;
				return true;
			}
		}
	}
	else
		return true;
}

//checks year if valid, also includes leap year calculation
bool Date::checkYear() {
	if (myYear < 1) {
		return false;
	}
	else if (myMonth == 2) {
		if ((myYear % 4 == 0) && (myYear % 100 == 0) && (myYear % 400 == 0)) {
			cout << "Leap Year" << endl;
			return true;
		}
	}
	else
		return true;
}

//default date constructor, sets date to 01/01/0001
Date::Date() {
	cout << "Default constructor has been called.\n" << endl;
	myMonth = 1;
	myDay = 1;
	myYear = 1;
}

//explicit value date constructor
Date::Date(unsigned m, unsigned d, unsigned y) {
	cout << "Explicit value constructor has been called." << endl;
	myMonth = m;
	myDay = d;
	myYear = y;
	if (checkMonth() == false) {
		cout << "Month = " << setfill('0') << setw(2) << myMonth << " is incorrect" << endl;
	}
	if (checkDay() == false) {
		cout << "Day = " << setfill('0') << setw(2) << myDay << " is incorrect" << endl;
	};
	if (checkYear() == false) {
		cout << "Year = " << setfill('0') << setw(4) << myYear << " is incorrect" << endl;
	};
	cout << endl;
}

//prints the date requested
void Date::display() {
	cout << setfill('0') << setw(2) << myMonth << "/";
	cout << setfill('0') << setw(2) << myDay << "/";
	cout << setfill('0') << setw(4) << myYear << endl;
}

//accessor to private month variable
int Date::getMonth() {
	return myMonth;
}

//accessor to private day variable
int Date::getDay() {
	return myDay;
}

//accessor to private year variable
int Date::getYear() {
	return myYear;
}

//mutator to private month variable
void Date::setMonth(int m) {
	myMonth = m;
	checkMonth();
}

//mutator to private day variable
void Date::setDay(unsigned d) {
	myDay = d;
	checkDay();
}

//mutator to priavte year variable
void Date::setYear(unsigned y) {
	myYear = y;
	checkYear();
}

//overload operator << with chaining, prints data requested
ostream& operator<<(ostream& out, Date& dateObj) {
	out << setfill('0') << setw(2) << dateObj.myMonth << "/";
	out << setfill('0') << setw(2) << dateObj.myDay << "/";
	out << setfill('0') << setw(4) << dateObj.myYear << endl;
	return out;
}