#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

#define NUMCOURSES 3

//Student class definition
class Student {
public: 

//Constructor
	Student(string studentID, string fName, string lName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram);
	~Student();  
	
//Getters
	string GetStudentID();
	string GetFName();
	string GetLName();
	string GetEmailAddress();
	int GetAge();
	int *GetDaysToComplete();
	DegreeProgram GetDegreeProgram();

//Setters
	void SetStudentID(string studentID);
	void SetFName(string fName);
	void SetLName(string lName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int age);
	void SetDaysToComplete(int daysToComplete[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);

//Print function
	void Print();

private:
	string studentID;
	string fName;
	string lName;
	string emailAddress;
	int age;
	int *daysToComplete;
	DegreeProgram degreeProgram;
};

#endif