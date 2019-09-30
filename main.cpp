//Ryan Peterson
//Professor William Clements
//CSC 160 Comp Sci I
//27 July, 2018

//Analysis:
//The program needs to take in data from a file, that includes names and test scores, and determines certain facts, such as letter grade and top test score, 
// about the inputted data then outputs the original data along with additional data to an out file. 
//The data that is available is the student’s first and last name along with their test score. 
//The output that is desired is the original data along with the letter grade corresponding with the score, the highest test score of the students, 
// and the students with the highest test score.

//Algorithm:
//Create record (struct) that will include the student's data of name, test score, and grade
//function prototypes (initializer, student grade, high score, top student functions)
//define variables for the high score and the input and output files
//define array for a class size of 20 students based upon the record (struct) already created
//open the files
//call all functions in order of initializer, student grade, high score, top student
//close files
//function initializer takes in parameters of the student array and the input file
//-perform a loop 20 times for the number of students in the class (and array) and assign input from the in file to the member variable of the student record. The inputs
//  should be ordered for the first name, last name, and test score variables since this is the input order from the file.This will intialize the array with data.
//function student grade takes in data of the output file variable, as reference, and the student array.
//-declare new variable to hold the student's full name in order of last name, first name
//-loop through the full array of 20 students and determine the grade by using elif structure to compare the testScore variable to the values of the letter grade of
//  A, B, C, D, or F then set the grade member variable equal to the corresponding letter grade of the test score
//-output data to the out file via a loop through the now complete array
//-during loop set name variable equal to last name, first name
//-output name, test score, and letter grade for each student
//function high score takes in the out file variable as a reference parameter, the high score variable as another reference parameter, and the array as a value parameter
//-set high score variable equal to the first test score in the array
//-loop through the array checking each test score against the the high score, if the test score is greater than the high score then the high score is set equal to the
//  test score
//-due to being a reference parameter changes to the high score variable in this funtion are done to the variable that was passed to the function, therefore, 
//  the changes done here are permanent to the variable
//-output the high score to the out file
//function top student passes the parameters of the out file as reference, the high score and array as value
//-loop through the entire array of students, if the test score is equal to the high score then out put the student name (last, first) to the out file

//User Documentation:
//Enter all desired input of students and grades to file: Ch9_Ex2Data.txt
//Open the program from either the file system or by searching for CSC160_Prog_CH9.exe or by searching for the file. Once found double click on CSC160_Prog_CH9.exe to run program.
//View file: Ch9_Ex2Out.txt for output
//To terminate the file either press enter when prompted or by pressing the x in the top right corner of the window.

//header
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//build struct data type to include all relevant student information
struct studentType
{
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
};
//function prototypes for initialization of data, grade, highest grades, and students with highest grades
void initialize(ifstream& inData, studentType student[]);
void studentgrade(ofstream& outData, studentType student[]);
void highscore(ofstream& outData, int& high_score, studentType student[]);
void top_students(ofstream& outData, int high_score, studentType student[]);

int main()
{
	//declare variables
	int high_score;
	ifstream inData;
	ofstream outData;
	//set student array as struct data type and include size of 20 for total number of students
	studentType student[20];
	//open text files
	inData.open("Ch9_Ex2Data.txt");
	outData.open("Ch9_Ex2Out.txt");
	//call functions and pass parameters
	initialize(inData, student);
	studentgrade(outData, student);
	highscore(outData, high_score, student);
	top_students(outData, high_score, student);
	//close files
	inData.close();
	outData.close();

	system("pause");

	return 0;
}//end

//function to receive input from in file and initialize the student array with applicable information that is contained in the input file, parameters passed include the
// reference of the input data file and the value parameter of the array
void initialize(ifstream& inData, studentType student[])
{
	//declare index variable
	int i;
	//for loop that steps through the array and set all data to member variables of the structure data type 
	for (i = 0; i < 20; i++)
	{
		inData >> student[i].studentFName >> student[i].studentLName >> student[i].testScore;
	}
}

//void function that determines the student's letter grade and outputs the student data to the out file. This function takes in the out data variable as a reference parameter,
// so changes can be made to the out file, and takes in the student array as a value parameter
void studentgrade(ofstream& outData, studentType student[])
{
	//declare variables for the index and student's name
	int i;
	string name;

	//for loop that determines letter grade based on the test score member variable then sets the member variable 'grade' equal to the corresponding letter grade 
	for (i = 0; i < 20; i++)
	{
		if (student[i].testScore >= 90)
			student[i].grade = 'A';
		else if (student[i].testScore >= 80)
			student[i].grade = 'B';
		else if (student[i].testScore >= 70)
			student[i].grade = 'C';
		else if (student[i].testScore >= 60)
			student[i].grade = 'D';
		else
			student[i].grade = 'F';
	}
	//outputs the column headers
	outData << "Student Name" << setw(20) << "Test Score" << setw(10) << "Grade" << endl;
	//for loop to itterate through the array and output the member variable data to the out file. Set variable 'name' equal to the combination of student last and first name.
	// output also sets columns so that the data is easier to read.
	for (i = 0; i < 20; i++)
	{
		name = student[i].studentLName +  ", " + student[i].studentFName;
		outData << left << setw(20) <<  name << right << setw(10) << student[i].testScore << setw(10) << student[i].grade << endl;

	}

	outData << endl;

}

//void function to find the highest grade from the student's test scores. Takes in the outdata reference parameter so that data can be written to the outfile, the high score
// variable is passed as reference as well so that the high score can be set and referenced in a later function, and the array is passed as value.
void highscore(ofstream& outData, int& high_score, studentType student[])
{
	//variable declaration of index
	int i;
	//set high score equal to the first score in the array
	high_score = student[0].testScore;
	//for loop to determine the highest score in the class. The value of the high score is what is needed and not the index value, therfore, only integer of the high score
	// is determined, set to the variable, and eventually output to the file
	for (i = 0; i < 20; i++)
		if (student[i].testScore > high_score)
		{
			high_score = student[i].testScore;
		}
	//output the high test score to file
	outData << "Highest test score: " <<  high_score << endl;
}

//void function that determines which of the students has the highest test score and outputs their names to the file. Takes in the parameters of the out file as reference,
// the high score variable but only as value because it is only used to compare with other variables, and the array as a value parameter.
void top_students(ofstream& outData, int high_score,  studentType student[])
{
	//declare index variable
	int i;
	//output prompt to out file
	outData << "Students having the highest test score:" << endl;
	//for loop to itterate through the array and check the test scores against the highest score, if the test score matches the highest score that student's name is output
	// to the out file
	for (i = 0; i < 20; i++)
		if (student[i].testScore == high_score)
		{
			outData << student[i].studentLName << ", " << student[i].studentFName << endl;
		}
}