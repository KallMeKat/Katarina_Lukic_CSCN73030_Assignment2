//Katarina Lukic
//Assignment 2 Project V

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// a struct to hold student data with first and last name 
typedef struct STUDENT_DATA {
	string firstName;
	string lastName;
}STUDENT_DATA;

// A helper function to student data from file
bool parseFromFile(string fileName, vector<STUDENT_DATA>& studentDataList) {
	// open the student data file
	ifstream myFile("StudentData.txt");
	// Validate if the file can be opened
	if (!myFile.is_open()) {
		cout << "Unable to open the file " << "StudentData.txt" << endl;
		return false;
	}

	string studentLi;
	// read student data file line by line
	while (getline(myFile, studentLi)) {
		STUDENT_DATA StudentData;	// create STUDENT_DATA object
		istringstream iss(studentLi);
		// parse first and last name that is separated by a comma (deliminator)
		getline(iss, StudentData.firstName, ',');
		getline(iss, StudentData.lastName, ',');
		// add the parsed student data to the vector
		studentDataList.push_back(StudentData);

	}


	// close the file after use
	myFile.close();
	return true;
}

int main(void) {
	
	// vector to store list of student data
	vector<STUDENT_DATA> studentDataList;
	// parse student data from the text file
	parseFromFile("StudentData.txt", studentDataList);
	return 1;

}