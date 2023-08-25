#ifndef INCOME_H
#define INCOME_H

#include <string>

using namespace std;

class Income {
public:
    double incomeAmount;
    string incomeDate;
    string incomeCategory;
    string incomeDescription;
};

void addIncomeDetails(Income& income);

#endif