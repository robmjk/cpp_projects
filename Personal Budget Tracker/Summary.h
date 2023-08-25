#ifndef SUMMARY_H
#define SUMMARY_H

#include <string>
#include "Income.h"
#include "Expenses.h"

using namespace std;

class Summary {
public:
    double totalIncome;
    double totalExpense;
    double totalBalance;
    string recAction;
};

void addSummaryOverview(Summary& summary, const Income& income, const Expenses& expenses);
void displayMenu(Income& income, Expenses& expenses, Summary& summary, ofstream& outputFile);

#endif
