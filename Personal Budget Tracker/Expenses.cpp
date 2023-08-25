#include <iostream>
#include <string>
#include "Expenses.h"

using namespace std;

// method and elements to input my expenses
void addExpenseDetails(Expenses& expenses)
{
	// adding expense details
	cout << "Expense Amount: " << "$" << flush;
	cin >> expenses.expenseAmount;

	cout << "--------------" << endl;

	cout << "Expense Date: " << flush;
	cin >> expenses.expenseDate;

	cout << "--------------" << endl;

	cout << "Select Your Expense Category (1, 2, 3 or 4)" << endl;
	cout << "1. Groceries" << endl;
	cout << "2. Water Bill" << endl;
	cout << "3. Electricity Bill" << endl;
	cout << "4. Miscellaneous" << endl;

	int categoryExpenseSelection;
	cout << "Enter the category number: " << flush;
	cin >> categoryExpenseSelection;

	switch (categoryExpenseSelection)
	{
	case 1:
		expenses.expenseCategory = "Groceries";
		break;
	case 2:
		expenses.expenseCategory = "Water Bill";
		break;
	case 3:
		expenses.expenseCategory = "Electricity Bill";
		break;
	case 4:
		expenses.expenseCategory = "Miscellaneous";
		break;
	default:
		cout << "Invalid category selection" << endl;
	}

	cout << "--------------" << endl;

	cout << "Expense Description: " << flush;
	cin.ignore(); // ensures that any leftover newline character is cleared	
	getline(cin, expenses.expenseDescription); // captures the entire line of description, including spaces

	cout << "--------------" << endl;

	cout << "Expense Details" << endl;
	cout << "--------------" << endl;
	cout << "Expense Amount: " << expenses.expenseAmount << endl;
	cout << "Expense Date: " << expenses.expenseDate << endl;
	cout << "Expense Category: " << expenses.expenseCategory << endl;
	cout << "Expense Description: " << expenses.expenseDescription << endl;
}