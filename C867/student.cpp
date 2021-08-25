#include "student.h"
#include "degree.h"

Student::Student(string studentID, string fName, string lName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->fName = fName;
	this->lName = lName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysToComplete = new int[NUMCOURSES];
	for (int i = 0; i < NUMCOURSES; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degreeProgram = degreeProgram;
}

//garbage collection
Student::~Student() {
	delete[] daysToComplete;
}

//Getter Implementations
string Student::GetStudentID() {
	return studentID;
}

string Student::GetFName() {
	return fName;
}

string Student::GetLName() {
	return lName;
}

string Student::GetEmailAddress() {
	return emailAddress;
}

int Student::GetAge() {
	return age;
}

int *Student::GetDaysToComplete() {
	return daysToComplete;
}

DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

//Setter Implementations
void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
	return;
}

void Student::SetFName(string fName) {
	this->fName = fName;
	return;
}

void Student:: SetLName(string lName) {
	this->lName = lName;
	return;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}

void Student::SetAge(int age) {
	this->age = age;
	return;
}

void Student::SetDaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < NUMCOURSES; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	return;
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
	return;
}

//Print function to print student data in the specified format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]Days In Course: {35, 40, 55}[tab] Degree Program: Security.
void Student::Print() {
	cout << studentID << '\t' << "First Name: " << fName << '\t' << "Last Name: " << lName << '\t';
	cout << "Age: " << age << '\t' << "Days In Course: {";

		for (int i = 0; i < NUMCOURSES; ++i) {
			cout << daysToComplete[i];
			if (i != (NUMCOURSES - 1)) {
				cout << ", ";
			}
		}
	cout << "}" << '\t' << "Degree Program: ";

	switch (degreeProgram) {
	case DegreeProgram::SECURITY :
		cout << "SECURITY";
		break;
	case DegreeProgram::NETWORK :
		cout << "NETWORK";
		break;
	case DegreeProgram::SOFTWARE :
		cout << "SOFTWARE";
		break;
	case DegreeProgram::INVALID :
		cout << "INVALID";
		break;
	}
	cout << endl;

	return;
}