//Katarina Lukic
//Assignment 2 Project V

//libraires 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//using namepsace std
using namespace std;
#define PRE_RELEASE
#ifdef PRE_RELEASE
#define DATA_FILE "StudentData_Emails.txt"
#else 
#define DATA_FILE "StudentData.txt"
#endif // PRE_RELEASE

// a struct to hold student data with first and last name and email with pre release 
typedef struct STUDENT_DATA {
	string firstName;
	string lastName;
#ifdef PRE_RELEASE
	string email;
#endif // PRE_RELEASE
}STUDENT_DATA;

// A bool function to student data from file
bool parseFromFile(string fileName, vector<STUDENT_DATA>& studentDataList) {
	// open the student data file
	ifstream myFile(DATA_FILE);
	// Validate if the file can be opened and if not then do an error
	if (!myFile.is_open()) {
		cout << "Unable to open the file " << DATA_FILE << endl;
		return false;
	}


	string studentLi;
	// read student data file line by line
	while (getline(myFile, studentLi)) {
		STUDENT_DATA StudentData;	// create STUDENT_DATA object
		istringstream iss(studentLi);
		// first and last name that is separated by a comma and email with pre release 
		getline(iss, StudentData.firstName, ',');
		getline(iss, StudentData.lastName, ',');
#ifdef PRE_RELEASE
		getline(iss, StudentData.email, ',');
#endif // PRE_RELEASE
		// add the parsed student data to the vector
		studentDataList.push_back(StudentData);

	}

	// close the file after use
	myFile.close();
	return true;

}

#ifdef _DEBUG	// print student data from vector. only for debug
void printStudentData(vector<STUDENT_DATA> studentDataList) {
	for (int i = 0; i < studentDataList.size(); i++) {
		//student first and last name 
		cout << "Student Name:" << studentDataList[i].lastName << ", " << studentDataList[i].firstName << endl;
		//pre release has the email included 
#ifdef PRE_RELEASE
		cout << ", " << studentDataList[i].email << endl;
#else
		cout << endl;
#endif // PRE_RELEASE
	}
}
#endif // DEBUG


int main(void) {

//main code print statements that indicate what version its running on 
#ifdef PRE_RELEASE
	cout << "This application is running on pre-release source code" << endl;
#else
	cout << "This application is running on standard source code" << endl;
#endif // PRE_RELEASE
	
	// vector to store list of student data
	vector<STUDENT_DATA> studentData;
	// student data from the text file
	parseFromFile(DATA_FILE, studentData);

#ifdef _DEBUG	// print student data from vector, only for debug 
	printStudentData(studentData);
#endif // DEBUG
	return 0;

}