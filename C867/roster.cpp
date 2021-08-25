#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"

using namespace std;

Roster::Roster(const string studentData[], int sizeStudentData, int maxCapacity) {
	this->numStudents = sizeStudentData;
	this->maxCapacity = maxCapacity;
	this->classRosterArray = new Student*[maxCapacity];

	//Parse each set of data identified in the studentData table
	int studentRecord = 0;
	while (studentRecord < sizeStudentData) {
		vector <string> dataStrings;
		//Read data sections into string objects
		stringstream dataStream(studentData[studentRecord]);
		string nextDataString;
		//Using comma as delimiter
		while (getline(dataStream, nextDataString, ',')) {
			dataStrings.push_back(nextDataString);
		}

		//string to int conversion
		int age = stoi(dataStrings[4]);
		int daysToComplete[3] = { stoi(dataStrings[5]), stoi(dataStrings[6]), stoi(dataStrings[7]) };

		//string to enum conversion
		DegreeProgram degreeProgram = DegreeProgram::INVALID;
		if (dataStrings[8].compare("SECURITY") == 0) {
			degreeProgram = DegreeProgram::SECURITY;
		}
		else if (dataStrings[8].compare("NETWORK") == 0) {
			degreeProgram = DegreeProgram::NETWORK;
		}
		else if (dataStrings[8].compare("SOFTWARE") == 0) {
			degreeProgram = DegreeProgram::SOFTWARE;
		}
		else {
			degreeProgram = DegreeProgram::INVALID;
		}

		//Add each student object to classRosterArray
		classRosterArray[studentRecord] = new Student(dataStrings[0], dataStrings[1], dataStrings[2], dataStrings[3], age, daysToComplete, degreeProgram);
		++studentRecord;
	}
}	

//Define add function
void Roster::add(string studentID, string fName, string lName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[numStudents] = new Student(studentID, fName, lName, emailAddress, age, daysToComplete, degreeProgram);
	++numStudents;
}
//Define remove function
void Roster::remove(string studentID) {
	bool idExists = false;
	for (int i = 0; (i < numStudents) && !idExists; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			classRosterArray[i] = classRosterArray[numStudents - 1];
			for (int j = i; j < numStudents - 1; ++j) {
				classRosterArray[j] = classRosterArray[j + 1];
				}
			--numStudents;
			idExists = true;
		}
	}
	if (idExists) {
		cout << "Student ID " << studentID << " has been removed." << endl;
	}
	else {
		cout << "Error: Student ID " << studentID << " does not exist." << endl;
	}
}

//Define printAll function
void Roster::printAll() {
	for (int i = 0; i < numStudents; ++i) {
		classRosterArray[i]->Print();
	}
	return;
}

//Define printAverageDaysInCourse Function
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			cout << "Student ID " << classRosterArray[i]->GetStudentID() << ": ";
			int* days = classRosterArray[i]->GetDaysToComplete();
			cout << "Average number of days to complete course: " << (days[0] + days[1] + days[2]) / 3 << endl;
			return;
		}
	}
}

//Define printInvalidEmails function
void Roster::printInvalidEmails() {
	for (int i = 0; i < numStudents; ++i) {
		string email = classRosterArray[i]->GetEmailAddress();
		size_t atSign = email.find('@');
		size_t dot = email.find('.', atSign);
		// if @ is not found
		if (atSign == string::npos) {
			cout << "Invalid email address. Must contain '@' : " << email << endl;
		}
		// if dot is not found
		else if (dot == string::npos) {
			cout << "Invalid email address. Must contain '.' : " << email << endl;
		}
		// if space is found
		else if (email.find(' ') != string::npos) {
			cout << "Invalid email address. Cannot contain space : " << email << endl;
		}
	}
}

// Define printByDegreeProgram function
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}
}

//Implement the destructor to release the memory that was allocated dynamically in Roster.
Roster::~Roster() {
	delete[] classRosterArray;
}