// Calculator source
// Featured operators: add +, minus -, divide /, multiply *
// Calculator will test for valid inputs and restart if invalid
// Once calculation is complete the program will prompt user to begin a new calculation or quit with (y/n)

#include <iostream>
#include <limits> // include the limits header for numeric_limits

using namespace std;

int main()
{
    // display welcome message to application
    cout << "Welcome to a simple Calculator application by Kribz1k!" << endl;
    cout << "======================================================" << endl;

    // number input value - we are using doubles to take in more precise calculations and sacrificing mem - can switch to floats if necessary
    double a = 0;
    double b = 0;

    // operator input value
    char op;

    // loop function so user must input valid operands and operators
    while (true)
    {
        // first numeric value user must input
        cout << "Enter first number: " << flush;
        cin >> a;

        // check for valid numeric value != valid numeric value then restart
        if (cin.fail()) {
            cout << "Invalid number. Please enter a numeric value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // operator user must input
        cout << "Enter operator: " << flush;
        cin >> op;

        // check for valid operator != valid operator then restart
        if (op != '+' && op != '-' && op != '/' && op != '*') {
            cout << "You used an invalid operator...please use one from the list: +, -, /, *" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // second numeric value user must input
        cout << "Enter second number: " << flush;
        cin >> b;

        // check for valid numeric value != valid numeric value then restart
        if (cin.fail()) {
            cout << "Invalid number. Please enter a numeric value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // calculating desired output based on operator chosen
        switch (op)
        {
        case '+':
            cout << a << " " << op << " " << b << " " << "= " << a + b << endl;
            break;
        case '-':
            cout << a << " " << op << " " << b << " " << "= " << a - b << endl;
            break;
        case '/':
            cout << a << " " << op << " " << b << " " << "= " << a / b << endl;
            break;
        case '*':
            cout << a << " " << op << " " << b << " " << "= " << a * b << endl;
            break;
        default:
            cout << "Input/s invalid...please use valid values" << endl;
            continue;
        }

        // restarts or ends program depending on user choice
        char restart;
        cout << "Would you like to begin another calculation? y/n: " << flush;
        cin >> restart;

        // breaks out of whole loop and ends runtime of calculator
        if (restart != 'y')
            break;
    }

    return 0;
}
