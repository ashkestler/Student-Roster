#ifndef ROSTER_H
#define ROSTER_H

#include <stdio.h>
#include <iostream>
#include "student.h"
#include "degree.h"

class Roster {

public:
//Constructor
	Roster(const string studentData[], int sizeStudentData, int maxCapacity);
	~Roster();

//Define the following functions:
	void add(string studentID, string fName, string lName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

private:
	int maxCapacity;
	int numStudents;
	Student* *classRosterArray;
};

#endif
