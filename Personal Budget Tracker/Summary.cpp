#include <iostream>
#include <fstream>
#include "Summary.h"

// method and elements to input my summary of income and expenses
void addSummaryOverview(Summary& summary, const Income& income, const Expenses& expenses)
{
	summary.totalIncome = income.incomeAmount;
	summary.totalExpense = expenses.expenseAmount;
	summary.totalBalance = income.incomeAmount - expenses.expenseAmount;

	cout << "Total Income: " << "$" << summary.totalIncome << endl;
	cout << "Total Expenses: " << "$" << summary.totalExpense << endl;
	cout << "Total Remaining: " << "$" << summary.totalBalance << endl;
}

void displayMenu(Income& income, Expenses& expenses, Summary& summary, std::ofstream& outputFile) {
	// budget tracker menu items
	cout << "1. Add Income Details" << endl;
	cout << "2. Add Expense" << endl;
	cout << "3. View Summary" << endl;
	cout << "4. Exit" << endl;

	// gather user input for selection of items
	while (true)
	{
		int selection;
		cout << "Enter your selection: " << flush;
		cin >> selection;

		// access menu item via user's desired selection
		switch (selection)
		{
		case 1:
			addIncomeDetails(income);
			// write the income details to text file
			outputFile << "Income Details: " << endl;
			outputFile << "Amount: $" << income.incomeAmount << endl;
			outputFile << "Date: " << income.incomeDate << endl;
			outputFile << "Category: " << income.incomeCategory << endl;
			outputFile << "Description: " << income.incomeDescription << endl;
			outputFile << "--------------- " << endl;
			break;
		case 2:
			addExpenseDetails(expenses);
			// write the expense details to text file
			outputFile << "Expense Details: " << endl;
			outputFile << "Amount: $" << expenses.expenseAmount << endl;
			outputFile << "Date: " << expenses.expenseDate << endl;
			outputFile << "Category: " << expenses.expenseCategory << endl;
			outputFile << "Description: " << expenses.expenseDescription << endl;
			outputFile << "--------------- " << endl;
			break;
		case 3:
			addSummaryOverview(summary, income, expenses); //  here we need to pass the income and expenses objects as we did in our void function 
			// write the summary details to text file
			outputFile << "Summary: " << endl;
			outputFile << "Total Income: $" << summary.totalIncome << endl;
			outputFile << "Total Expenses: $" << summary.totalExpense << endl;
			outputFile << "Remaining Balance: $" << summary.totalBalance << endl;
			outputFile << "--------------- " << endl;
			break;
			// continue after loop
		default:
			continue;
		}
		char restart;
		cout << "Viewing completed! Would you like to go back to the menu to add or review your budget? y/n: " << flush;
		cin >> restart;

		if (restart != 'y')
			break;
	}
}