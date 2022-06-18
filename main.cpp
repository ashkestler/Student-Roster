#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {
	//Array containing student data
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ashley,Kestler,akestle@my.wgu.edu,35,25,30,40,SOFTWARE"
	};

	//Identifying info
	cout << "=============================" << endl;
	cout << "C867: Scripting & Programming" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 001484567" << endl;
	cout << "Name: Ashley Kestler" << endl;
	cout << "=============================" << '\n' << endl;

	//Create an instance of the Roster class called classRoster 
	Roster *classRoster = new Roster(studentData, 5, 20);

	//classRoster.printAll();
	cout << "Displaying all students:" << endl;
	classRoster->printAll();
	cout << '\n' << endl;

	//classRoster.printInvalidEmails();
	cout << "Displaying invalid emails:" << '\n' << endl;
	classRoster->printInvalidEmails();
	cout << '\n' << endl;

	// classRoster.printAverageDaysInCourse(/*current_object's student id*/);
	classRoster->printAverageDaysInCourse("A1");
	classRoster->printAverageDaysInCourse("A2");
	classRoster->printAverageDaysInCourse("A3");
	classRoster->printAverageDaysInCourse("A4");
	classRoster->printAverageDaysInCourse("A5");
	cout << '\n' << endl;

	//classRoster.printByDegreeProgram(SOFTWARE);
	cout << "Showing students in degree program: SOFTWARE" << '\n' << endl;
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << '\n' << endl;

	//classRoster.remove("A3");
	classRoster->remove("A3");
	cout << endl;

	//classRoster.printAll();
	classRoster->printAll();
	cout << '\n' << endl;

	//classRoster.remove("A3");
	classRoster->remove("A3");

	//Destructor
	delete classRoster;

	return 0;
}