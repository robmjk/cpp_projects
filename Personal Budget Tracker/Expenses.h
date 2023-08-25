#ifndef EXPENSES_H
#define EXPENSES_H

#include <string>

using namespace std;

class Expenses {
public:
    double expenseAmount;
    string expenseDate;
    string expenseCategory;
    string expenseDescription;
};

void addExpenseDetails(Expenses& expenses);

#endif