// Personal Budget Tracker
// Allow users to add their income and expenses
// Allow users to view their summary of income, expenses and the difference
// Allow users to go back to menu after viewing or adding records


#include <iostream>
#include <fstream> // to save elements to a file
#include <string> // string toolset which allows us to use getline 

using namespace std;

// objects for calculating my income and details
class Income
{
public:
	double incomeAmount; // income amount
	string incomeDate; // income date
	string incomeCategory; // category for income
	string incomeDescription; // description of income
};

// objects for calculating my expenses and details
class Expenses
{
public:
	double expenseAmount; // expense amount
	string expenseDate; // expense date
	string expenseCategory; // category for expenses
	string expenseDescription; // description of expenses
};

// objects for calculating the summary of my income and expenses 
class Summary
{
public:
	double totalIncome; // total income
	double totalExpense; // total expenses
	double totalBalance; // difference between income and expenses
	string recAction; // recommended action to take
};

// method and elements to input my income
void addIncomeDetails(Income &income)
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

// method and elements to input my summary of income and expenses
void addSummaryOverview(Summary &summary, const Income &income, const Expenses &expenses)
{
	summary.totalIncome = income.incomeAmount;
	summary.totalExpense = expenses.expenseAmount;
	summary.totalBalance = income.incomeAmount - expenses.expenseAmount;

	cout << "Total Income: " << "$" << summary.totalIncome << endl;
	cout << "Total Expenses: " << "$" << summary.totalExpense << endl;
	cout << "Total Remaining: " << "$" << summary.totalBalance << endl;
}

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

	// close the file
	outputFile.close();

	return 0;
}
