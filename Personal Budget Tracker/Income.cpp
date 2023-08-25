#include <iostream>
#include <string>
#include "Income.h"

using namespace std;

// method and elements to input my income
void addIncomeDetails(Income& income)
{
	// adding income details
	cout << "Income Amount: " << "$" << flush;
	cin >> income.incomeAmount;

	cout << "--------------" << endl;

	cout << "Income Date: " << flush;
	cin >> income.incomeDate;

	cout << "--------------" << endl;

	cout << "Select Your Income Category (1, 2, 3, or 4): " << endl;
	cout << "1. Main Work Income" << endl;
	cout << "2. Secondary Work Income" << endl;
	cout << "3. Cryptocurrency Income" << endl;
	cout << "4. Website Income" << endl;

	int categoryIncomeChoice;
	cout << "Enter the category number: ";
	cin >> categoryIncomeChoice;

	switch (categoryIncomeChoice)
	{
	case 1:
		income.incomeCategory = "Main Work Income";
		break;
	case 2:
		income.incomeCategory = "Secondary Work Income";
		break;
	case 3:
		income.incomeCategory = "Cryptocurrency Income";
		break;
	case 4:
		income.incomeCategory = "Website Income";
		break;
	default:
		cout << "Invalid category selection" << endl;
	}

	cout << "--------------" << endl;

	cout << "Income Description: " << flush;
	cin.ignore(); // ensures that any leftover newline character is cleared	
	getline(cin, income.incomeDescription); // captures the entire line of description, including spaces

	cout << "--------------" << endl;

	cout << "Income Details" << endl;
	cout << "--------------" << endl;
	cout << "Income Amount: " << income.incomeAmount << endl;
	cout << "Income Date: " << income.incomeDate << endl;
	cout << "Income Category: " << income.incomeCategory << endl;
	cout << "Income Description: " << income.incomeDescription << endl;
}