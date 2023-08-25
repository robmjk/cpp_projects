// Personal Budget Tracker

#include <iostream>
#include <fstream> // to save elements to a file
#include <string> // string toolset which allows us to use getline 
#include "Income.h"
#include "Expenses.h"
#include "Summary.h"

using namespace std;

// main function to gather user input and save to text file
int main()
{
	// open a text file for writing
	ofstream outputFile("personalbudgettracker.txt");

	if (!outputFile)
	{
		cout << "Error opening file..." << endl;
		return 1;
	}

	// including classes and assigning variable to use within main function
	Income income;
	Expenses expenses;
	Summary summary;

	displayMenu(income, expenses, summary, outputFile);

	// close the file
	outputFile.close();

	return 0;
}
