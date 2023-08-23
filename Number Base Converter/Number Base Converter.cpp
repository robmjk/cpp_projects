// Number Base Converter
// You can choose between converting a numerical value to binary, decimal or hexadecimal
// Program will only accept numerical values
// Once you complete conversion, you can return back to the selection menu to continue converting

#include <iostream>
#include <string> // more string methods
#include <algorithm> // allows us to use reverse method
#include <cmath> // allows us to use pow
#include <sstream> // allows us to use stringstream
#include <limits> // allows us to set a limit for values

using namespace std;

class Binary
{
public:
    string binaryStr;
};

class Decimal
{
public:
    int decimalNo;
};

class Hexadecimal
{
public:
    string hexStr;
};

void binaryConverter(Binary& binary, int number)
{
    if (number == 0)
    {
        binary.binaryStr = "0"; // special case for input 0
        return;
    }

    while (number > 0)
    {
        int remainder = number % 2;
        binary.binaryStr += to_string(remainder);
        number /= 2;
    }
    reverse(binary.binaryStr.begin(), binary.binaryStr.end());
}

void decimalConverter(Decimal& decimal, const string& binaryStr)
{
    int decimalNo = 0;
    int length = binaryStr.length();

    // converting binary to decimal
    for (int d = 0; d < length; d++)
    {
        int digit = binaryStr[d] - '0'; // converting char '0' to int 0 or 1
        decimalNo += digit * pow(2, length - d - 1); // summing digits based on position
    }
    decimal.decimalNo = decimalNo; // storing decimal number
}

void hexadecimalConverter(Hexadecimal& hexadecimal, const string& binaryStr)
{
    // convert binary to decimal first
    Decimal decimal;
    decimalConverter(decimal, binaryStr);

    // convert decimal to hexadecimal using stringstream
    stringstream ss;
    ss << hex << decimal.decimalNo; // convert decimal to hexadecimal and store in stringstream
    hexadecimal.hexStr = ss.str(); // store the hexadecimal string in the class member
}

int main()
{
    Binary binary;
    Decimal decimal;
    Hexadecimal hexadecimal;

    double number;
    int selection;
    char returnToMenu;

    do
    {
        cout << "Choose conversion" << endl;
        cout << "-----------------" << endl;
        cout << "1. Convert to Binary" << endl;
        cout << "2. Convert to Decimal" << endl;
        cout << "3. Convert to Hexadecimal" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter selection: ";
        cin >> selection;

        // check if user input is a valid numerical value
        if (cin >> number)
        {
            // if input is valid
            cout << "You entered: " << number << endl;
        }
        else
        {
            // if input is invalid
            cout << "Invalid input. Please enter a valid numberical value" << endl;

            // clear the error state and flush the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (selection)
        {
        case 1:
            cout << "Enter number to begin conversion to binary: ";
            cin >> number;
            binaryConverter(binary, number);
            cout << "Binary value is: " << binary.binaryStr << endl;
            break;
        case 2:
            cout << "Enter binary string to convert to decimal: ";
            cin >> binary.binaryStr;
            decimalConverter(decimal, binary.binaryStr);
            cout << "Decimal value is: " << decimal.decimalNo << endl;
            break;
        case 3:
            cout << "Enter binary string to convert to hexadecimal: ";
            cin >> binary.binaryStr;
            hexadecimalConverter(hexadecimal, binary.binaryStr);
            cout << "Hexadecimal value is: " << hexadecimal.hexStr << endl;
            break;
        case 4:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid selection." << endl;
        }

        cout << "Return back to menu to convert more numerical values? y/n: ";
        cin >> returnToMenu;
    } while (returnToMenu == 'y');

    return 0;
}